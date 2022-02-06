/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2018 21:59                        
*  solution_verdict: Runtime error on test 2                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/620/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2000;
long arr[N+2],srr[N+2],s1,s2,ss1,ss2,lo,hi,md1,md2,n,m,mn;
pair<long,long>a,b;
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
      v1.push_back({arr[i]+arr[j],i,j});
    }
  }
  for(long i=1;i<=m;i++)
  {
    for(long j=1;j<=m;j++)
    {
      if(i==j)continue;
      v2.push_back({srr[i]+srr[j],i,j});
    }
  }
  sort(v1.begin(),v1.end(),cmp);
  sort(v2.begin(),v2.end(),cmp);
  for(auto x:v1)
  {
    ss1=s1-x.vl;
    ss2=s2+x.vl;
    lo=0;
    hi=v2.size()-1;
    while(hi-lo>3)
    {
//      if(x.vl==7)
//      {
//        cout<<"here"<<" "<<ss1<<" "<<ss2<<endl;
//      }
//      ss1=s1-x.vl;
//      ss2=s2+x.vl;
      md1=(lo+lo+hi)/3;
      md2=(lo+hi+hi)/3;
      if(check(md1)<check(md2))hi=md2;
      else lo=md1;
    }
//    if(x.vl==7)
//    {
//      cout<<"end"<<endl;
//    }
    for(long i=lo;i<=hi;i++)
    {
//      ss1=s1-x.vl;
//      ss2=s2+x.vl;
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
  a={-1,-1};
  b={-1,-1};
  mn=abs(s1-s2);
   one();
  two();
   cout<<mn<<endl;
  if(a.first==-1&&a.second==-1)cout<<0<<endl;
  else if(a.second==-1)cout<<1<<endl<<a.first<<" "<<b.first<<endl;
  else cout<<2<<endl<<a.first<<" "<<b.first<<endl<<a.second<<" "<<b.second<<endl;
   return 0;
}