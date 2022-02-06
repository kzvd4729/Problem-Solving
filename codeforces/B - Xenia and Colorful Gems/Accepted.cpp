/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/16/2020 12:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 186 ms                                          memory_used: 3200 KB                              
*  problem: https://codeforces.com/contest/1336/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long ans;
vector<int>aa,bb,cc;
long solve(int i,int j,int k)
{
  long ret=1LL*(aa[i]-bb[j])*(aa[i]-bb[j]);
  ret+=1LL*(bb[j]-cc[k])*(bb[j]-cc[k]);
  ret+=1LL*(cc[k]-aa[i])*(cc[k]-aa[i]);
  return ret;
}
void cal()
{
  int a=aa.size(),b=bb.size(),c=cc.size();
  for(int i=0;i<a;i++)
  {
    int j=lower_bound(bb.begin(),bb.end(),aa[i])-bb.begin();
    if(j<b)
    {
      long md=(aa[i]+bb[j])/2;
      int k=lower_bound(cc.begin(),cc.end(),bb[j])-cc.begin();
      if(k<c)ans=min(ans,solve(i,j,k));
      if(k-1>=0)ans=min(ans,solve(i,j,k-1));
    }
    j--;
    if(j>=0)
    {
      long md=(aa[i]+bb[j])/2;
      int k=lower_bound(cc.begin(),cc.end(),bb[j])-cc.begin();
      if(k<c)ans=min(ans,solve(i,j,k));
      if(k-1>=0)ans=min(ans,solve(i,j,k-1));
    }
  }
  aa.clear(),bb.clear(),cc.clear();
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,c;cin>>a>>b>>c;vector<int>d(a),e(b),f(c);
    for(int i=0;i<a;i++)cin>>d[i];sort(d.begin(),d.end());
    for(int i=0;i<b;i++)cin>>e[i];sort(e.begin(),e.end());
    for(int i=0;i<c;i++)cin>>f[i];sort(f.begin(),f.end());
     ans=4e18;
    aa=d,bb=e,cc=f;cal();
    aa=d,bb=f,cc=e;cal();
    aa=e,bb=d,cc=f;cal();
    aa=e,bb=f,cc=d;cal();
    aa=f,bb=d,cc=e;cal();
    aa=f,bb=e,cc=d;cal();
     cout<<ans<<"\n";
  }
  return 0;
}