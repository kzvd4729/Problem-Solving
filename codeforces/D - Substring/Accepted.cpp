/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/31/2018 20:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 390 ms                                          memory_used: 103200 KB                            
*  problem: https://codeforces.com/contest/919/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,color[300005],fr[300005],mark[300005],f,ans,u,v;
vector<int>adj[300005],root;
string s;
struct data
{
    int dp[30];
}tmp[300005];
data dfs(int node)
{
    if(mark[node]==1)return tmp[node];
    mark[node]=1;
    ///tmp[node].dp[color[node]]++;
    for(auto xx:adj[node])
    {
        data xxx=dfs(xx);
        for(int i=0;i<26;i++)
        {
            tmp[node].dp[i]=max(tmp[node].dp[i],xxx.dp[i]);
        }
    }
    tmp[node].dp[color[node]]++;
    return tmp[node];
}
class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isCyclic();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
         list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
     }
    recStack[v] = false;
    return false;
}
 bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
     return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    cin>>s;
    for(int i=1; i<=n; i++)color[i]=(int)(s[i-1]-'a');
    Graph g(300005);
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        g.addEdge(u,v);
        adj[u].push_back(v);
        fr[v]++;
    }
    if(g.isCyclic())
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)if(fr[i]==0)root.push_back(i);
    for(auto x:root)
    {
        data sss=dfs(x);
        for(int i=0;i<26;i++)
        {
            ans=max(ans,sss.dp[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}