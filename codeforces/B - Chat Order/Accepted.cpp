/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/17/2018 15:44                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1014 ms                                         memory_used: 17700 KB                             
*  problem: https://codeforces.com/contest/637/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
string s[200002];
map<string,long>mp;
int main()
{
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(long i=n;i>=1;i--)
    {
        if(mp[s[i]]==0)
        {
            cout<<s[i]<<endl;
            mp[s[i]]=1;
        }
    }
    return 0;
}