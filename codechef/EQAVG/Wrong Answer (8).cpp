/****************************************************************************************
*  @author: kzvd4729                                         created: 31-08-2019 22:57:54                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.08 sec                                        memory_used: 22.6M                                
*  problem: https://www.codechef.com/LTIME75A/problems/EQAVG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define endl "\n"
using namespace std;
const int N=1e6;
int fr[N+2],aa[N+2];
vector<int>v;
void tle()
{
  tle();
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    for(auto x:v)fr[x]=0;v.clear();
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
      cin>>aa[i];fr[aa[i]]++;
      v.push_back(aa[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int fullCycle=n/k;int f=0,fullsm=0;
    vector<int>fullCon,extra;
    for(auto x:v)
    {
      if(fullCycle>fr[x])f=1;
      int nm=fr[x]/fullCycle;
      if(fr[x]-(nm-1)*fullCycle<=nm-1)nm--;
      fullCon.push_back(nm);
      extra.push_back(fr[x]-nm*fullCycle);
      fullsm+=fullCon.back();
    }
    if(fullsm<k)
    {
      for(int i=0;i<v.size();i++)
      {
        if(extra[i]<fullCycle)continue;
        fullCon[i]++;extra[i]-=fullCycle;
        fullsm++;
        if(fullsm==k)break;
      }
    }
    if(fullsm!=k)f=1;
    int smm=0;
    for(auto x:extra)smm+=x;
    if(fullsm*fullCycle+smm!=n)f=1;
    for(int i=0;i<v.size();i++)
      if(extra[i]>fullCon[i])f=1;
    if(f)
    {
      cout<<"NO"<<endl;continue;
    }
    vector<int>pr;
    for(int i=0;i<v.size();i++)
    {
      for(int j=0;j<extra[i];j++)
        pr.push_back(v[i]);
    }
    vector<int>tmp;
    for(int i=0;i<v.size();i++)
    {
      for(int j=0;j<fullCon[i]-extra[i];j++)
        tmp.push_back(v[i]);
    }
    for(int i=0;i<v.size();i++)
    {
      for(int j=0;j<extra[i];j++)
        tmp.push_back(v[i]);
    }
    if(tmp.size()!=k)tle();
    while(pr.size()<n)
    {
      for(auto x:tmp)
        pr.push_back(x);
    }
    if(pr.size()!=n)
    {
      //cout<<"NO\n";continue;
      assert(0);
    }
    set<int>st;int sm=0;
    for(int i=0;i<pr.size();i++)
    {
      sm+=pr[i];
      if(i+1>k)sm-=pr[i-k];
      if(i+1>=k)st.insert(sm);
    }
    //if(st.size()!=1)assert(0);
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    {
      cout<<pr[i];
      if(i==n-1)cout<<endl;
      else cout<<" ";
    }
  }
  return 0;
}