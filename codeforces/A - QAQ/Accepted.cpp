/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/19/2017 20:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/894/problem/A
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
    long l=s.size();
    long ans=0;
    for(long i=0;i<l;i++)
    {
        for(long j=i+1;j<l;j++)
        {
            for(long k=j+1;k<l;k++)
            {
                if(s[i]=='Q'&&s[k]=='Q'&&s[j]=='A')ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}