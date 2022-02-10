/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-02-12 17:53:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 10                                         memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-cuchitunnels
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
void no()
{
  cout<<"NO\n",exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
    
  int lf=n;if(aa[n]!=1)no();
  vector<int>v;v.push_back(lf);

  for(int i=n-1;i>1;i--)
  {
    if(aa[i]==1)v.push_back(i);
    else
    {
      sort(v.begin(),v.end());
      int id=upper_bound(v.begin(),v.end(),i)-v.begin();
      if(v.size()-id<aa[i]-1)no();

      vector<int>u;
      for(int j=0;j<id;j++)u.push_back(v[j]);
      for(int j=id+aa[i]-1;j<v.size();j++)u.push_back(v[j]);

      u.push_back(i);v=u;
    }
  }
  if(v.size()!=aa[1])no();
  cout<<"YES\n";
  return 0;
}