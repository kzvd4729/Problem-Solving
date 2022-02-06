/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2017 21:09                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 158700 KB                            
*  problem: https://codeforces.com/contest/189/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,a[5],dp[4002][2002][5];
int fx(int n,int cnt,int s)
{
    if(n==0)return cnt;
    if(n<0)return 0;
    if(s>2)return 0;
    if(dp[n][cnt][s]!=-1)return dp[n][cnt][s];
    return dp[n][cnt][s]=max(fx(n-a[s],cnt+1,s),fx(n-a[s],cnt+1,s+1));
}
int main()
{
    cin>>n>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]==1)cout<<n<<endl;
    else if(n<a[0])cout<<1<<endl;
    else
    {
        memset(dp,-1,sizeof(dp));
        cout<<fx(n,0,0)<<endl;
    }
    return 0;
}