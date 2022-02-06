/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/08/2017 22:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/887/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
long cnt,f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    for(auto x:s)
    {
        if(f)if(x=='0')cnt++;
        if(x=='1')f=1;
    }
    if(cnt>=6)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}