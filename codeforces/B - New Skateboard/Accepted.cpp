/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/19/2017 14:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1000 KB                              
*  problem: https://codeforces.com/contest/628/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
long ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    if((s[0]-'0')%4==0)ans=1;
    for(long i=1;i<s.size();i++)
    {
        if((s[i]-'0')%4==0)ans++;
        long x=(s[i-1]-'0')*10+s[i]-'0';
        if(x%4==0)ans+=i;
    }
    cout<<ans<<endl;
    return 0;
}