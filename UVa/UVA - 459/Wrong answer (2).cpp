/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-03 15:25:01                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-459
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
char ch[12];
int vis[202],t,ans,sr;
vector<int>adj[202];
void dfs(int node)
{
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])continue;
    dfs(x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {

    for(int i=0;i<=200;i++)adj[i].clear();
    memset(vis,0,sizeof(vis));

    cin>>ch;
    sr=ch[0]-'A';
    //gets(ch);

    while(gets(ch)&&strlen(ch))
    {
      //cout<<"**"<<ch[0]<<ch[1]<<endl;
      adj[int(ch[0]-'A')].push_back(ch[1]-'A');
      adj[int(ch[1]-'A')].push_back(ch[0]-'A');
    }
    ans=0;
    for(int i=0;i<=sr;i++)
    {
      if(vis[i]==0)
      {
        //cout<<i<<endl;
        dfs(i);
        ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}