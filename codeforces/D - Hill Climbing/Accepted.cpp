/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/20/2018 21:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 404 ms                                          memory_used: 16600 KB                             
*  problem: https://codeforces.com/contest/406/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int n,par[N+2],lev[N+2];
int sp[N+2][20];
vector<int>adj[N+2];
struct point
{
 long x,y;
}pt[N+2];
long cross(int i,int j,int k)
{
 point a=pt[i],b=pt[j],c=pt[k];
 b.x-=a.x;b.y-=a.y;
 c.x-=a.x;c.y-=a.y;
 return b.x*c.y-c.x*b.y;
}
void make_graph(void)
{
 stack<int>st;
 st.push(n);st.push(n-1);
 par[n]=-1;par[n-1]=n;adj[n].push_back(n-1);
 for(int i=n-2;i>=1;i--)
 {
  while(st.size()>=2)
  {
   int b=st.top();st.pop();
   if(cross(i,b,st.top())<=0)
   {
    st.push(b);
    break;
   }
  }
  par[i]=st.top();
  adj[st.top()].push_back(i);
  st.push(i);
 }
 /*for(int i=1;i<=n;i++)
  cout<<par[i]<<" ";
 cout<<endl;*/
}
void sparse(void)
{
 memset(sp,-1,sizeof(sp));
 for(int i=1;i<=n;i++)
  sp[i][0]=par[i];
 for(int j=1;j<=18;j++)
 {
  for(int i=1;i<=n;i++)
  {
   if(sp[i][j-1]==-1)continue;
   sp[i][j]=sp[sp[i][j-1]][j-1];
  }
 }
}
void dfs(int node,int h)
{
 lev[node]=h;
 for(int i=0;i<adj[node].size();i++)
  dfs(adj[node][i],h+1);
}
int lca(int u,int v)
{
 if(lev[u]<lev[v])swap(u,v);
 for(int i=18;i>=0;i--)
 {
  if(sp[u][i]==-1)continue;
  if(lev[sp[u][i]]>=lev[v])
   u=sp[u][i];
 }
 if(u==v)return u;
 for(int i=18;i>=0;i--)
 {
  if(sp[u][i]==-1||sp[v][i]==-1)continue;
  if(sp[u][i]==sp[v][i])continue;
  u=sp[u][i];v=sp[v][i];
 }
 return par[u];
}
int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
  cin>>n;
 for(int i=1;i<=n;i++)
  cin>>pt[i].x>>pt[i].y;
 make_graph();dfs(n,0);sparse();
 /*for(int i=1;i<=n;i++)
  cout<<lev[i]<<" ";
 cout<<endl;*/
  int m;cin>>m;
 while(m--)
 {
  int u,v;cin>>u>>v;
  cout<<lca(u,v)<<endl;
 }
 return 0;
}