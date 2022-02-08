/****************************************************************************************
*  @author: kzvd4729                                         created: 29-09-2018 19:51:37                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.49 sec                                        memory_used: 16.8M                                
*  problem: https://www.codechef.com/LTIME64A/problems/CHEFRES
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int mx[N+2];
vector<pair<int,int> >v;
vector<int>nx;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;v.clear();nx.clear();
    for(int i=1;i<=n;i++)
    {
      int l,r;cin>>l>>r;r--;
      v.push_back({l,r});
      nx.push_back(l);
    }
    sort(v.begin(),v.end());
    sort(nx.begin(),nx.end());
//    for(auto x:v)
//    {
//      cout<<x.first<<" "<<x.second<<endl;
//    }
    mx[0]=v[0].second;
    for(int i=1;i<v.size();i++)
      mx[i]=max(mx[i-1],v[i].second);
//    for(int i=0;i<v.size();i++)
//      cout<<mx[i]<<" ";
//    cout<<endl;
    while(m--)
    {
      int l,id;cin>>l;
      id=upper_bound(v.begin(),v.end(),make_pair(l+1,-1))-v.begin();
      id--;
      if(id>=0)
      {
        if(mx[id]>=l)
        {
          cout<<0<<endl;
          continue;
        }
      }
      id=upper_bound(nx.begin(),nx.end(),l)-nx.begin();
      if(id==nx.size())cout<<-1<<endl;
      else cout<<nx[id]-l<<endl;
    }
  }
  return 0;
}