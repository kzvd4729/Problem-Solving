/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/22/2019 17:34                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1151/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],lt[N+2],rt[N+2],vis[N+2],rot[N+2];
vector<int>pos[N+2];
void upd(int l,int r,int vl)
{
  for(int i=l;i<=r;i++)
    aa[i]+=vl;
}
int get(int l,int r)
{
  int ret=0;
  for(int i=l;i<=r;i++)
    ret+=aa[i];
  return ret;
}
int main()
{
  don't compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
    cin>>bb[i];
   lt[1]=0;
  for(int i=2;i<=n;i++)
  {
    if(bb[i]==bb[i-1])lt[i]=lt[i-1];
    else lt[i]=i-1;
  }
  rt[n]=n+1;
  for(int i=n-1;i>=1;i--)
  {
    if(bb[i]==bb[i+1])rt[i]=rt[i+1];
    else rt[i]=i+1;
  }
  for(int i=1;i<=n;i++)
    rot[i]=lt[i]+1;
  set<int>st;
  for(int i=1;i<=n;i++)
    st.insert(rot[i]);
  for(auto x:st)
    pos[bb[x]].push_back(x);
  for(int i=1;i<=n;i++)
  {
    aa[i]=aa[i-1];
    for(auto x:pos[i])
    {
      if(vis[lt[x]]||vis[rt[x]]){}
      else aa[i]++;
      vis[lt[x]+1]=vis[rt[x]-1]=1;
    }
  }
  lt[1]=-1;rt[n]=-1;long ans=get(1,n);
  for(int i=1;i<=n;i++)
  {
    for(auto x:pos[i])
    {
      upd(i+1,n,-1);
      if(lt[x]==-1&&rt[x]==-1){};
      if(lt[x]!=-1)
      {
        int id=lt[x];
        if(lt[id]==-1)upd(bb[id],n,1);
        else upd(bb[id],n,1);
        rt[lt[x]]=1;
      }
      if(rt[x]!=-1)
      {
        int id=rt[x];
        if(lt[id]==-1)upd(bb[id],n,1);
        else upd(bb[id],n,1);
        lt[rt[x]]=-1;
      }
    }
    /*for(int j=i+1;j<=n;j++)
      cout<<aa[j]<<" ";
    cout<<endl;*/
    ans+=get(i+1,n);
  }
  cout<<ans<<endl;
  return 0;
}