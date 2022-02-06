/****************************************************************************************
*  @author: kzvd4729                                         created: May/19/2018 01:18                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/982/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,arr[N+2],mn=2e9,id,ans,now,loc,bb[N+N+2],cc[N+N+2],ckr;
vector<int>tmp,lft,rgt;
bool check(int xx,int sz)
{
  ckr++;
  if(ckr>1000)return false;
  int here=0;
  for(int i=1;i<=n;i++)
  {
    if(arr[i]>=xx)
    {
      if(here!=0&&here!=sz)return false;
      here=0;
    }
    else here++;
  }
  if(here!=0&&here!=sz)return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
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
  for(int i=id;i<=n;i++)
    rgt.push_back(arr[i]);
  for(int i=id;i>=1;i--)
    lft.push_back(arr[i]);
  for(int i=1;i<lft.size();i++)
    lft[i]=max(lft[i],lft[i-1]);
  for(int i=1;i<rgt.size();i++)
    rgt[i]=max(rgt[i],rgt[i-1]);
  ans=2e9;
  int lcc=-1;
   for(int i=1;i<=n;i++)
    bb[i]=arr[i];
  for(int i=n+1;i<=2*n;i++)
    bb[i]=arr[i-n]+1;
//  sort(bb+1,bb+2*n+1);
//  int ind=0;
//  for(int i=1;i<=2*n;i+=2)
//    cc[i]=bb[++ind];
//  ind=2*n;
//  for(int i=2;i<=2*n;i++)
//    cc[i]=bb[ind--];
//  for(int i=1;i<=2*n;i++)
//    bb[i]=cc[i];
  random_shuffle(bb+1,bb+2*n+1);
//  random_shuffle(bb+1,bb+2*n+1);
//  random_shuffle(bb+1,bb+2*n+1);
  //for(int i=2*n;i>=1;i--)
  map<int,int>mp;
  for(int i=1;i<=2*n;i++)
  {
    if(bb[i]==mn)continue;
    if(mp[bb[i]])continue;
    mp[bb[i]]=1;
    //if(bb[i]==bb[i-1])continue;
    now=bb[i];
    int les=lower_bound(tmp.begin(),tmp.end(),now)-tmp.begin();
    int llt=lower_bound(lft.begin(),lft.end(),now)-lft.begin();
    int lrt=lower_bound(rgt.begin(),rgt.end(),now)-rgt.begin();
     if(les%(llt+lrt-1))continue;
     loc=les/(llt+lrt-1);
    if(loc<lcc)continue;
    if(loc==lcc&&bb[i]>=ans)continue;
    if(check(bb[i],llt+lrt-1))
    {
      if(loc==lcc)
        ans=min(ans,bb[i]);
      if(loc>lcc)
      {
        lcc=loc;
        ans=bb[i];
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}