/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/16/2019 16:41                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 889 ms                                          memory_used: 200 KB                               
*  problem: https://codeforces.com/gym/102307/problem/C
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 const int N = 100000 + 7, offset = 1001;
 int dp[2][offset * 2];
 char a[N], b[N];
  int main()
{
    scanf("%s %s", a, b); int n = strlen(a);
    int mx = 0,k=n-ceil(n*0.99);
    for(int i = 1; i <= n; i++)
    {
        int l = min(i, k), r = min(n - i, k);
        for(int j = -l; j <= r; j++)
        {
            dp[i & 1][j + offset] = max(dp[(i - 1) & 1][j + 1 + offset], dp[i & 1][j - 1 + offset]);
            if(i + j >= 1 && i + j <= n && a[i - 1] == b[i + j - 1]) dp[i & 1][j + offset] = max(dp[i & 1][j + offset], 1 + dp[(i - 1) & 1][j + offset]);
            mx = max(mx, dp[i & 1][j + offset]);
        }
        if(mx >= ceil(n * .99)) {
        printf("Long lost brothers D:\n"),exit(0);
      }
    }
    printf("Not brothers :(\n");
}