/****************************************************************************************
*  @author: JU_AAA: aniks2645, kzvd4729, prdx9_abir          created: Sep/18/2017 19:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/847/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,ans,cnt;
string s[1003];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(long j=0;j<8;j++)
    {
        cnt=0;
        for(long i=0;i<n;i++)
        {
            if(s[i][j]=='1')cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}