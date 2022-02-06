/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/23/2019 23:36                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1131/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>aa[i];
    sort(aa+1,aa+n+1);vector<int>v;
    for(int i=1;i<=n;i++)
    {
        if(i%2)cout<<aa[i]<<" ";
        else v.push_back(aa[i]);
    }
    while(v.size())
    {
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
    return 0;
}