/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/29/2018 20:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2100 KB                              
*  problem: https://codeforces.com/contest/918/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m;
string s1,s2;
map<string,string>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        mp[s2]=s1;
    }
    while(m--)
    {
        cin>>s1>>s2;
        cout<<s1<<" "<<s2<<" #"<<mp[s2.substr(0,s2.size()-1)]<<endl;
    }
    return 0;
}