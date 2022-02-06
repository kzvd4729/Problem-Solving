/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/23/2019 23:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1131/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int h1,w1,h2,w2;cin>>h1>>w1>>h2>>w2;
        int ans=2*h1+2*w1+4+2*h2+2*w2+4;
    ans-=h2;ans-=h2;ans-=4;
        cout<<ans<<endl;
        return 0;
}