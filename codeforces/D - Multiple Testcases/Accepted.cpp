/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 12:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 234 ms                                          memory_used: 22000 KB                             
*  problem: https://codeforces.com/contest/1342/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],cc[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;multiset<int>st;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;st.insert(x);
  }
  for(int i=1;i<=k;i++)cin>>aa[i];
  vector<int>v;
  for(int i=k;i>=1;i--)v.push_back(aa[i]);
   vector<vector<int> >ans;
  while(st.size())
  {
    vector<int>tmp;
    int ls=*st.rbegin();st.erase(st.find(ls));
    tmp.push_back(ls);ls=1;
     while(true)
    {
      int id=upper_bound(v.begin(),v.end(),ls)-v.begin();
      if(id==v.size())break;id=k-id;
       auto x=st.upper_bound(id);
      if(x==st.begin())break;x--;
      tmp.push_back(*x);ls++;st.erase(st.find(*x));
    }
    reverse(tmp.begin(),tmp.end());
    ans.push_back(tmp);
  }
  cout<<ans.size()<<endl;
  for(auto x:ans)
  {
    cout<<x.size()<<" ";
    for(auto z:x)cout<<z<<" ";cout<<"\n";
  }
  return 0;
}