#include<bits/stdc++.h>
using namespace std;

vector<int> findSubarrayWithSum(int arr[], int n, int s) {
    int start = 0, curr_sum = arr[0];

    for (int i = 1; i <= n; i++) {
        while (curr_sum > s && start < i - 1) {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == s) {
            return {start + 1, i};
        }

        if (i < n) {
            curr_sum += arr[i];
        }
    }

    return {-1};
}

int main()
{
     int arr[] = {7,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 2;

    vector<int> result = findSubarrayWithSum(arr, n, s);
    if (result.size() == 1 && result[0] == -1) {
        cout << -1 << endl;
    } else {
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}
