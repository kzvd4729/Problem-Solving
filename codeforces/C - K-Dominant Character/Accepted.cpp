/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/11/2017 00:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/888/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    long ans=999999999;
    for(long i=0;i<26;i++)
    {
        long cnt=0,mx=0;
        for(long j=0;j<s.size();j++)
        {
            if((long)(s[j]-'a')==i)cnt=0;
            else cnt++;
            mx=max(mx,cnt);
        }
        ans=min(ans,mx);
    }
    cout<<ans+1<<endl;
     return 0;
}