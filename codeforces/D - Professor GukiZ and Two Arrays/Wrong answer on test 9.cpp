/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 22:41                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 685 ms                                          memory_used: 25300 KB                             
*  problem: https://codeforces.com/contest/620/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2000;
int arr[N+2],srr[N+2],lo,hi,md1,md2,n,m,md;
long s1,s2,ss1,ss2,mn;
pair<int,int>a,b;
map<int,int>mp;
struct data
{
  int vl,r,c;
};
vector<data>v1,v2;
long check(int id)
{
  return abs((ss2-v2[id].vl)-(ss1+v2[id].vl));
}
bool cmp(data A,data B)
{
  return A.vl<B.vl;
}
void two(void)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(i==j)continue;
      if(mp[arr[i]+arr[j]])continue;
      mp[arr[i]+arr[j]]=1;
      v1.push_back({arr[i]+arr[j],i,j});
    }
  }
  mp.clear();
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=m;j++)
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
    while(hi-lo>3)
    {
      md=(lo+hi)/2;
      if(check(md)>mn)hi=md;
      else lo=md;
     }
    for(int i=lo;i<=hi;i++)
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
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
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
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&arr[i]),s1+=arr[i];
  scanf("%d",&m);
  for(int i=1;i<=m;i++)scanf("%d",&srr[i]),s2+=srr[i];
  a={-1,-1};
  b={-1,-1};
  mn=abs(s1-s2);
   one();
  two();
   printf("%lld\n",mn);
  if(a.first==-1&&a.second==-1)cout<<0<<endl;
  else if(a.second==-1)cout<<1<<endl<<a.first<<" "<<b.first<<endl;
  else cout<<2<<endl<<a.first<<" "<<b.first<<endl<<a.second<<" "<<b.second<<endl;
   return 0;
}