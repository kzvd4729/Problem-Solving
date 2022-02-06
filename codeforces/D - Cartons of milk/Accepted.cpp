/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/05/2018 16:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 857 ms                                          memory_used: 17900 KB                             
*  problem: https://codeforces.com/contest/767/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,m,k,fr[N+2],mx;
vector<int>pr;
struct data
{
  int dt,id;
}sr[N+2];
bool cmp(data A,data B)
{
  return A.dt<B.dt;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>fr[i];
    mx=max(mx,fr[i]);
  }
  sort(fr+1,fr+n+1);
  for(int i=1;i<=m;i++)
  {
    cin>>sr[i].dt;
    sr[i].id=i;
    mx=max(mx,sr[i].dt);
  }
  sort(sr+1,sr+m+1,cmp);
  int ans=0,fp=n,sp=m;
  for(int i=mx;i>=0;i--)
  {
    int kk=k;
    while(true)
    {
      if(kk==0||fp==0)break;
      if(fr[fp]>=i)
      {
        fp--;
        kk--;
      }
      else break;
    }
    while(true)
    {
      if(kk==0||sp==0)break;
      if(sr[sp].dt>=i)
      {
        ans++;
        pr.push_back(sr[sp].id);
        sp--;
        kk--;
      }
      else break;
    }
  }
  if(fp)cout<<-1<<endl;
  else
  {
    cout<<pr.size()<<endl;
    for(auto x:pr)cout<<x<<" ";
    cout<<endl;
  }
  return 0;
}