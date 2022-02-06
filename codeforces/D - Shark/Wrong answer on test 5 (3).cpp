/****************************************************************************************
*  @author: kzvd4729                                         created: May/19/2018 00:24                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 800 KB                               
*  problem: https://codeforces.com/contest/982/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long n,arr[N+2],mn=2e9,id,ans,now,loc;
vector<long>tmp,lft,rgt;
bool check(long xx,long sz)
{
  long here=0;
  loc=0;
  for(long i=1;i<=n;i++)
  {
    if(arr[i]>=xx)
    {
      if(here)loc++;
      if(here!=0&&here!=sz)return false;
      here=0;
    }
    else here++;
  }
  if(here)loc++;
  if(here!=0&&here!=sz)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)
  {
    cin>>arr[i];
    tmp.push_back(arr[i]);
    if(arr[i]<mn)
    {
      mn=arr[i];
      id=i;
    }
  }
  sort(tmp.begin(),tmp.end());
  for(long i=id;i<=n;i++)
    rgt.push_back(arr[i]);
  for(long i=id;i>=1;i--)
    lft.push_back(arr[i]);
  for(long i=1;i<lft.size();i++)
    lft[i]=max(lft[i],lft[i-1]);
  for(long i=1;i<rgt.size();i++)
    rgt[i]=max(rgt[i],rgt[i-1]);
  ans=2e9;
  long lcc=0;
  for(long i=1;i<=n;i++)
  {
    if(i==id)continue;
    now=arr[i];
    long les=lower_bound(tmp.begin(),tmp.end(),now)-tmp.begin();
    long llt=lower_bound(lft.begin(),lft.end(),now)-lft.begin();
    long lrt=lower_bound(rgt.begin(),rgt.end(),now)-rgt.begin();
     if(les%(llt+lrt-1))continue;
     if(check(arr[i],llt+lrt-1))
    {
      if(loc==lcc)
        ans=min(ans,arr[i]);
      if(loc>lcc)
      {
        lcc=loc;
        ans=arr[i];
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}