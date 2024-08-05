#include <bits/stdc++.h>
using namespace std;
/*
K-th Bit is Set or Not
Input: n = 4, k = 0
Output: No
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
*/

bool checkKBit(int n, int k)
{
    // return (n&(1<<k))!=0;
    return ((n >> k) & 1) != 0;
}

/*
    Power Of Two
    Example 1:

Input: n = 1
Output: true
Explanation: 2^0 = 1
*/

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}

/*
    Count Set Bits
    Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.
*/

int countSetBits(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i <<= 1)
    {
        int k = (n + 1) / (i << 1);
        cnt += k * i + max(0, (n + 1) % (i << 1) - i);
    }
    return cnt;
}

/*
Set the rightmost unset bit
Input: n = 6
Output: 7
Explanation: The binary representation of 6 is 110. After setting right most bit it becomes 111 which is 7.
*/

int setBit(int n)
{
    return (n&(n+1));
}


/*
    Divide Two integers
    Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
*/
int divide(int dividend, int divisor)
{
    if(dividend==divisor) return 1;

    bool sign=true;
    if(dividend<0 && divisor>0 || dividend>=0 && divisor<0) sign=false;

    long n=abs(dividend);
    long d=abs(divisor);

    long ans=0;

    while(n>=d)
    {
        int cnt=0;
        while(n>=(d<<cnt+1))
        cnt++;

        ans+=1<<cnt;
        n-=d<<cnt;
    }

    if(ans==(1<<31)&& sign) return INT_MAX;
    if(ans==(1<<31)&& !sign) return INT_MIN;

    return sign?ans:-ans;
}
int main()
{
    return 0;
}
