/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2018 20:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/14/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a1,b1,a2,b2,one,two,f;
map<pair<long,long>,long>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long i=1;i<=4;i++)
    {
        cin>>a1>>b1>>a2>>b2;
        if(a1==a2)one++;
        else if(b1==b2)two++;
        else f=1;
        mp[{a1,b1}]++;
        mp[{a2,b2}]++;
    }
    if(one!=2&&two!=2)f=1;
    if(mp.size()!=4)f=1;
    for(map<pair<long,long>,long>::iterator it=mp.begin();it!=mp.end();it++)
    {
        if(it->second!=2)f=1;
    }
    if(f)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}