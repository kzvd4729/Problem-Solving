/****************************************************************************************
*  @author: kzvd4729                                         created: 25-09-2019 14:51:07                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 3.17 sec                                        memory_used: 24.1M                                
*  problem: https://www.codechef.com/problems/GERALD07
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int par[N+2],sq,com,ans[N+2],vis[N+2],par2[N+2];
vector<pair<int,int> >ed;
bool cmp(vector<int>&a,vector<int>&b)
{
  if(a[0]/sq!=b[0]/sq)return a[0]<b[0];
  return a[1]<b[1];
}
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
int get2(int x)
{
  if(x==par2[x])return x;
  return par2[x]=get2(par2[x]);
}
int bruteForce(int l,int r)
{
  vector<int>clr;
  for(int i=l;i<=r;i++)
  {
    int u=ed[i].first,v=ed[i].second;
    if(!vis[u])vis[u]=1,clr.push_back(u);
    if(!vis[v])vis[v]=1,clr.push_back(v);
  }
  for(auto x:clr)
  {
    int r=get(x);par2[x]=get(x);
    par2[r]=r;
  }
  int ret=0;
  for(int i=l;i<=r;i++)
  {
    int u=ed[i].first,v=ed[i].second;
    int r1=get2(u),r2=get2(v);
    if(r1!=r2)
      ret++,par2[r1]=r2;
  }
  for(auto x:clr)vis[x]=0;
  return ret;
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("algo.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,q;cin>>n>>m>>q;sq=sqrt(m)+2;
    ed.resize(m);
    for(int i=0;i<m;i++)
    {
      cin>>ed[i].first>>ed[i].second;
      //cout<<ed[i].first<<" "<<ed[i].second<<endl;
      ed[i].first--,ed[i].second--;
    }
    vector<vector<int> >qq(q);
    for(int i=0;i<q;i++)qq[i].resize(3);
    for(int i=0;i<q;i++)
    {
      cin>>qq[i][0]>>qq[i][1];qq[i][0]--,qq[i][1]--;
      //cout<<qq[i][0]<<" ** "<<qq[i][1]<<endl;
      qq[i][2]=i;
    }
    sort(qq.begin(),qq.end(),cmp);
    //for(auto x:qq)
      //cout<<x[0]<<" --> "<<x[1]<<endl;
    int pt=0;
    for(int bl=0; ;bl++)
    {
      int l=bl*sq,r=min((bl+1)*sq-1,m-1);
      for(int i=0;i<n;i++)par[i]=i;
      com=n;
      while(pt<q&&qq[pt][1]<=r&&qq[pt][0]>=l)
        ans[qq[pt][2]]=com-bruteForce(qq[pt][0],qq[pt][1]),pt++;
      for(int i=r+1;i<m;i++)
      {
        int r1=get(ed[i].first),r2=get(ed[i].second);
        if(r1!=r2)com--,par[r1]=r2;
        while(pt<q&&qq[pt][0]<=r&&qq[pt][0]>=l&&qq[pt][1]==i)
        {
          //cout<<"got it"<<endl;
          ans[qq[pt][2]]=com-bruteForce(qq[pt][0],r),pt++;
        }
      }
      if(r==m-1)break;
    }
    for(int i=0;i<q;i++)
      cout<<ans[i]<<"\n";
  }
  return 0;
}