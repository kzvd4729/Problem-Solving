/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 22:17                        
*  solution_verdict: Time limit exceeded on test 13          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 131100 KB                            
*  problem: https://codeforces.com/contest/620/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2000;
long arr[N+2],srr[N+2],s1,s2,ss1,ss2,lo,hi,md1,md2,n,m,mn;
pair<long,long>a,b;
map<long,long>mp;
struct data
{
  long vl,r,c;
};
vector<data>v1,v2;
long check(long id)
{
  return abs((ss2-v2[id].vl)-(ss1+v2[id].vl));
}
bool cmp(data A,data B)
{
  return A.vl<B.vl;
}
void two(void)
{
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=n;j++)
    {
      if(i==j)continue;
      if(mp[arr[i]+arr[j]])continue;
      mp[arr[i]+arr[j]]=1;
      v1.push_back({arr[i]+arr[j],i,j});
    }
  }
  mp.clear();
  for(long i=1;i<=m;i++)
  {
    for(long j=1;j<=m;j++)
    {
      if(i==j)continue;
      if(mp[srr[i]+srr[j]])continue;
      mp[srr[i]+srr[j]]=1;
      v2.push_back({srr[i]+srr[j],i,j});
    }
  }
  sort(v2.begin(),v2.end(),cmp);
  for(auto x:v1)
  {
    ss1=s1-x.vl;
    ss2=s2+x.vl;
    lo=0;
    hi=v2.size();
    hi--;
    ///cout<<lo<<" "<<hi<<endl;
    while(hi-lo>2)
    {
      md1=lo+(hi-lo)/3;
      md2=hi-(hi-lo)/3;
      if(check(md1)<check(md2))hi=md2;
      else lo=md1;
    }
    for(long i=lo;i<=hi;i++)
    {
      if(check(i)<mn)
      {
        mn=check(i);
        a={x.r,x.c};
        b={v2[i].r,v2[i].c};
      }
    }
  }
  return ;
}
void one(void)
{
  for(long i=1;i<=n;i++)
  {
    for(long j=1;j<=m;j++)
    {
      ss1=s1-arr[i]+srr[j];
      ss2=s2-srr[j]+arr[i];
      if(abs(ss1-ss2)<mn)
      {
        mn=abs(ss1-ss2);
        a={i,-1};
        b={j,-1};
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(long i=1;i<=n;i++)cin>>arr[i],s1+=arr[i];
  cin>>m;
  for(long i=1;i<=m;i++)cin>>srr[i],s2+=srr[i];
  a={-1*1LL,-1*1LL};
  b={-1*1LL,-1*1LL};
  mn=abs(s1-s2);
   one();
  two();
   cout<<mn<<endl;
  if(a.first==-1&&a.second==-1)cout<<0<<endl;
  else if(a.second==-1)cout<<1<<endl<<a.first<<" "<<b.first<<endl;
  else cout<<2<<endl<<a.first<<" "<<b.first<<endl<<a.second<<" "<<b.second<<endl;
   return 0;
}