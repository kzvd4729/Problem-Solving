/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2018 19:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1278 ms                                         memory_used: 126500 KB                            
*  problem: https://codeforces.com/contest/5/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],sp[N+1][21],n;
vector<int>vc[N+N+2];
void sparse(void)
{
  for(int i=1;i<=n;i++)
    sp[i][0]=aa[i];
  for(int j=1;j<=20;j++)
  {
    for(int i=1;i<=n;i++)
    {
      sp[i][j]=sp[i][j-1];
      if(i+(1<<(j-1))<=n)
        sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
    }
  }
}
int qry(int lt,int rt)
{
  int df=rt-lt+1;
  int bt=31-__builtin_clz(df);
  return min(sp[lt][bt],sp[rt-(1<<bt)+1][bt]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;
   int bl=N;n=s.size();aa[0]=bl;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='(')bl++;
    else bl--;aa[i]=bl;
    vc[bl].push_back(i);
  }
  sparse();int ans=0,cnt=0;
  for(int i=0;i<n;i++)
  {
    if(vc[aa[i]].size()==0)continue;
     int lo=i+1,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      if(qry(i+1,md)<aa[i])hi=md;
      else lo=md;
    }
    for(md=lo;md<=hi;md++)
      if(qry(i+1,md)<aa[i])break;
    md--;
    int id=upper_bound(vc[aa[i]].begin(),vc[aa[i]].end(),md)-vc[aa[i]].begin();
    id--;
    if(id>=0&&id<vc[aa[i]].size())
    {
      int here=vc[aa[i]][id]-i;
      if(here>ans)
      {
        ans=here;cnt=1;
      }
      else if(here==ans)
        cnt++;
    }
  }
  if(ans==0)cnt=1;
  cout<<ans<<" "<<cnt<<endl;
  return 0;
}