/****************************************************************************************
*  @author: JU_Quanta: kzvd4729, tariqiitju, mh755628#       created: Sep/26/2019 14:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/690/problem/F1
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 vector<int> adj[100005];
long long res=0;
#define SZ(a)   ((int)(a).size())
void dfs(int u,int p){
     res+= (SZ(adj[u])*(SZ(adj[u])-1))/2;
   // else res+= ((SZ(adj[u])-2)*(SZ(adj[u])-1))/2;
    for(int v : adj[u])if(v!=p)dfs(v,u);
}
int main(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
     dfs(1,0);
    cout<<res<<endl;
    return 0;
}