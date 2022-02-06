/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/24/2017 20:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/855/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n;
string s;
map<string,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    while(n--)
    {
        cin>>s;
        if(mp[s]==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        mp[s]=1;
    }
     return 0;
}