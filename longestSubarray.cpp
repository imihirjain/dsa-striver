#include <bits/stdc++.h>
using namespace std;

vector<int> longestSubarrayWithSumK(vector<int> a, long long k) {
    map<long long, int> preSum;
    long long sum = 0;
    int maxLen = 0;
    int startIdx = -1; // To store the start index of the subarray
    int endIdx = -1;   // To store the end index of the subarray
    
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        
        if (sum == k) {
            maxLen = i + 1;
            startIdx = 0;
            endIdx = i;
        }
        
        long long remain = sum - k;
        if (preSum.find(remain) != preSum.end()) {
            int len = i - preSum[remain];
            if (len > maxLen) {
                maxLen = len;
                startIdx = preSum[remain] + 1;
                endIdx = i;
            }
        }
        
        if (preSum.find(sum) == preSum.end()) {
            preSum[sum] = i;
        }
    }
    
    if (startIdx != -1 && endIdx != -1) {
        // If a valid subarray is found, return the elements in the subarray
        return vector<int>(a.begin() + startIdx, a.begin() + endIdx + 1);
    } else {
        // If no subarray is found, return an empty vector
        return {};
    }
}

int main() {
    vector<int> a = {1, 2, 3, 7, 5};
    long long k = 12;
    vector<int> result = longestSubarrayWithSumK(a, k);
    
    cout << "The longest subarray with sum " << k << " is: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
