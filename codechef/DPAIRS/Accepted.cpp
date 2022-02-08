/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2019 09:14:33                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.09 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/JAN19A/problems/DPAIRS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;vector<pair<int,int> >v1,v2;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    v1.push_back({x,i-1});
  }
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    v2.push_back({x,i-1});
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  for(auto x:v1)
    cout<<x.second<<" "<<v2[0].second<<"\n";
  for(int i=1;i<v2.size();i++)
    cout<<v1[n-1].second<<" "<<v2[i].second<<"\n";
  return 0;
}