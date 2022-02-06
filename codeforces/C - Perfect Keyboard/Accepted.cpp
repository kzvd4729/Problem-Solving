/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2020 16:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 187 ms                                          memory_used: 15900 KB                             
*  problem: https://codeforces.com/contest/1303/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<int>adj[N+2];int vis[N+2];
map<pair<int,int>,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    for(int i=0;i<26;i++)adj[i].clear();
    string s;cin>>s;set<char>st;
    mp.clear();memset(vis,0,sizeof(vis));
    int ed=0;
    for(int i=1;i<s.size();i++)
    {
      st.insert(s[i]);st.insert(s[i-1]);
      int a=s[i-1]-'a',b=s[i]-'a';
      if(a==b)continue;
      if(a>b)swap(a,b);
      if(mp.count({a,b}))continue;
      adj[a].push_back(b);
      adj[b].push_back(a);
      ed=1;
      mp[{a,b}]=1;
      //cout<<a<<" "<<b<<endl;
    }
    if(!ed)
    {
      cout<<"YES\n";
      for(char i='a';i<='z';i++)
        cout<<i;
      cout<<"\n";continue;
    }
    int f=0,rt,lf=0;
    for(int i=0;i<26;i++)
    {
      if(adj[i].size()>2)f=1;
      if(adj[i].size()==1)rt=i,lf++;
    }
    if(f||lf!=2)
    {
      cout<<"NO\n";continue;
    }
    string ans;//cout<<st.size()<<endl;
    while(true)
    {
      //cout<<rt<<endl;
      ans.push_back((char)(rt+'a'));
      vis[rt]=1;
       int f=0;
      for(auto x:adj[rt])
      {
        if(vis[x])continue;
        rt=x;f=1;break;
      }
      if(!f)break;
    }
    if(st.size()!=ans.size())
    {
      cout<<"NO\n";continue;
    }
    cout<<"YES\n";
    for(int i=0;i<26;i++)
    {
      if(!vis[i])ans.push_back((char)(i+'a'));
    }
    //cout<<ans.size()<<endl;
    cout<<ans<<endl;
  }
  return 0;
}