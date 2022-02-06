/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/06/2020 18:26                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1122 ms                                         memory_used: 72500 KB                             
*  problem: https://codeforces.com/contest/827/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6,inf=1e9;
char aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  set<int>st;
  for(int i=1;i<=N;i++)st.insert(i),aa[i]='a';
  int n;cin>>n;int mx=1;
  for(int i=1;i<=n;i++)
  {
    string a;cin>>a;
    int oc;cin>>oc;
    while(oc--)
    {
      int lt,rt;cin>>lt;rt=lt+a.size()-1;
      int in=lt;vector<int>er;lt--;
      while(true)
      {
        auto it=st.upper_bound(lt);
        if(it==st.end())break;int vl=*it;
        if(vl>rt)break;
         er.push_back(vl);lt=vl;mx=max(mx,vl);
        aa[vl]=a[vl-in];
      }
      for(auto x:er)st.erase(x);er.clear();
    }
  }
  for(int i=1;i<=mx;i++)
    cout<<aa[i];
  cout<<endl;
    return 0;
}