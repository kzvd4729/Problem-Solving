/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/20/2019 20:46                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 52300 KB                             
*  problem: https://codeforces.com/contest/894/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6,R=1e7;
int n,aa[N+2];
vector<int>v[N+2][2],qm[N+2][2];
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
void dfs(int node)
{
  if(node*2<=n)
  {
    dfs(node*2);
     v[node][0].resize(v[node*2][0].size()+v[node*2][1].size()+1);
    merge(v[node*2][0].begin(),v[node*2][0].end(),v[node*2][1].begin(),v[node*2][1].end(),v[node][0].begin()+1);
    for(auto &x:v[node][0])x+=aa[node*2];
     while(v[node][0].size()&&v[node][0].back()>R)
      v[node][0].pop_back();
     qm[node][0].push_back(v[node][0][0]);
    for(int i=1;i<v[node][0].size();i++)
      qm[node][0].push_back(qm[node][0].back()+v[node][0][i]);
  }
  if(node*2+1<=n)
  {
    dfs(node*2+1);
     v[node][1].resize(v[node*2+1][0].size()+v[node*2+1][1].size()+1);
    merge(v[node*2+1][0].begin(),v[node*2+1][0].end(),v[node*2+1][1].begin(),v[node*2+1][1].end(),v[node][1].begin()+1);
    for(auto &x:v[node][1])x+=aa[node*2+1];
     while(v[node][1].size()&&v[node][1].back()>R)
      v[node][1].pop_back();
     qm[node][1].push_back(v[node][1][0]);
    for(int i=1;i<v[node][1].size();i++)
      qm[node][1].push_back(qm[node][1].back()+v[node][1][i]);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int q;cin>>n>>q;
  for(int i=2;i<=n;i++)cin>>aa[i];
  dfs(1);
   //P(v[1][0]);P(v[1][1]);
   //return 0;
   while(q--)
  {
    int a,h;cin>>a>>h;long hh=h;
     long sum=0,ad=0;int cnt=1,id;
    id=lower_bound(v[a][0].begin(),v[a][0].end(),h)-v[a][0].begin();
    if(id)cnt+=id,sum+=qm[a][0][id-1];
    id=lower_bound(v[a][1].begin(),v[a][1].end(),h)-v[a][1].begin();
    if(id)cnt+=id,sum+=qm[a][1][id-1];
     //cout<<cnt<<" "<<sum<<endl;
     while(a>1)
    {
      h-=aa[a],ad+=aa[a];if(h<=0)break;
      if(a&1)
      {
        a/=2;
        id=lower_bound(v[a][0].begin(),v[a][0].end(),h)-v[a][0].begin();
        if(id)cnt+=id,sum+=qm[a][0][id-1]+ad*id;cnt++;sum+=ad;
      }
      else
      {
        a/=2;
        id=lower_bound(v[a][1].begin(),v[a][1].end(),h)-v[a][1].begin();
        if(id)cnt+=id,sum+=qm[a][1][id-1]+ad*id;cnt++;sum+=ad;
      }
    }
    cout<<hh*cnt-sum<<"\n";
  }
  return 0;
}