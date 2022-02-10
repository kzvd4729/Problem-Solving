/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 17:29:52                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-icpcawards
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

map<string, int>mp;

struct node
{
    string t, u;
};
int main()
{

    int n; vector<node>u1;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        string t, u;
        cin>>t>>u;
        if(!mp[t])
        {
            mp[t]=i; u1.push_back({t, u});
        }
    }
    for(int i=0; i<12; i++) cout<<u1[i].t<<' '<<u1[i].u<<"\n";
}