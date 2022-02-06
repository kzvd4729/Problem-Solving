/****************************************************************************************
*  @author: JU_Troubleshooer: tariqiitju, the0dd1out, kzvd4729 created: Oct/20/2018 15:04                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 1700 KB                              
*  problem: https://codeforces.com/contest/1070/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2];
void no(void)
{
  cout<<"No"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k;cin>>n>>k;int sum=0;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];sum+=aa[i];
  }
  if(sum%k)no();
  sum/=k;int sm=0;
  vector<int>ans;int last=0;
  for(int i=1;i<=n;i++)
  {
    sm+=aa[i];
    if(sm>sum)no();
    if(sm==sum)
    {
      ans.push_back(i-last);
      sm=0;last=i;
    }
  }
  cout<<"Yes"<<endl;
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}