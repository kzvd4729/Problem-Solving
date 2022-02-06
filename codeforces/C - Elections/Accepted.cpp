/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 20:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 499 ms                                          memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1020/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=2e14;
const int N=3e3;
int n,m,p,x;
vector<int>vt[N+2];
long whore(int xx)
{
  long here=0;
  int cnt=vt[1].size();
  vector<int>tmp;
  for(int i=2;i<=m;i++)
  {
    for(int j=0;j<vt[i].size();j++)
    {
      int rem=vt[i].size()-j;
      if(rem>=xx)
      {
        here+=(vt[i][j]*1LL);
        cnt++;
      }
      else tmp.push_back(vt[i][j]);
    }
  }
  if(cnt>=xx)return here;
  sort(tmp.begin(),tmp.end());
  for(int i=0;i<tmp.size();i++)
  {
    if(cnt>=xx)break;
    cnt++;here+=(tmp[i]*1LL);
  }
  if(cnt>=xx)return here;
  else return inf;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>p>>x;
    vt[p].push_back(x);
  }
  for(int i=1;i<=m;i++)
    sort(vt[i].begin(),vt[i].end());
   long ans=inf;
  for(int i=1;i<=n+1;i++)
    ans=min(ans,whore(i));
  cout<<ans<<endl;
  return 0;
}