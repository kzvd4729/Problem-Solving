/****************************************************************************************
*  @author: kzvd4729                                         created: 11-04-2019 16:44:48                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.35 sec                                        memory_used: 31.8M                                
*  problem: https://www.codechef.com/APRIL19A/problems/CHEFOFR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
long aa[N+2],tp[N+2],k;
vector<long>v,qm,vv[52][52];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n;cin>>n;
  for(long i=1;i<=n;i++)
    cin>>aa[i];
  long q;cin>>q;
  while(q--)
  {
    cin>>k;
    for(long i=1;i<=n;i++)
      cin>>tp[i];
    v.clear();qm.clear();
    for(long i=1;i<=n;i++)
      if(tp[i]*aa[i])
        v.push_back(tp[i]*aa[i]);
    if(k>v.size())
    {
      cout<<0<<"\n";continue;
    }
    qm.push_back(v[0]);
    for(long i=1;i<v.size();i++)
      qm.push_back(qm[i-1]+v[i]);
    for(long i=0;i<=50;i++)
      for(long j=0;j<=50;j++)
        vv[i][j].clear();
    for(long i=0;i<v.size();i++)
      vv[1][i].push_back(qm[i]);
    for(long i=2;i<=k;i++)
    {
      for(long j=0;j<v.size();j++)
      {
        for(long l=j-1;l>=0;l--)
        {
          long sm=qm[j]-qm[l];
          for(auto x:vv[i-1][l])
            vv[i][j].push_back(sm&x);
        }
        sort(vv[i][j].begin(),vv[i][j].end());
        vv[i][j].erase(unique(vv[i][j].begin(),vv[i][j].end()),vv[i][j].end());
      }
    }
    long ans=0;
    if(vv[k][v.size()-1].size()>0)
      ans=vv[k][v.size()-1].back();
    cout<<ans<<"\n";
  }
  return 0;
}