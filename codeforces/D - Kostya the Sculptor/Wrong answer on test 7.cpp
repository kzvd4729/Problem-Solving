/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/06/2018 23:30                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 14900 KB                             
*  problem: https://codeforces.com/contest/733/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long double mn=0.0,tmp,vll;
int n,x,y,z;
pair<int,int>ans={-1,-1};
struct data
{
  int a,b,c;
  long double vl;
}arr[100005];
map<pair<int,int>,pair<int,int> >mp1,mp2,mp3;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>x>>y>>z;
    if(y>x)swap(x,y);
    if(z>x)swap(x,z);
    if(z>y)swap(y,z);
    arr[i].a=x;
    arr[i].b=y;
    arr[i].c=z;
    arr[i].vl=(x*1.00)*(y*1.00)*(z*1.00);
    if(arr[i].vl>mn)
    {
      mn=arr[i].vl;
      ans.first=i;
    }
  }
  for(int i=1;i<=n;i++)
  {
    x=arr[i].a;
    y=arr[i].b;
    z=arr[i].c;
      if(mp1.find({x,y})!=mp1.end())
    {
      tmp=(x*1.00)*(y*1.00)*(mp1[{x,y}].first*1.00);
      vll=arr[i].vl+tmp;
      if(vll>mn)
      {
        mn=vll;
        ans={i,mp1[{x,y}].second};
      }
    }
    if(mp2.find({x,z})!=mp2.end())
    {
      tmp=(x*1.00)*(y*1.00)*(mp2[{x,z}].first*1.00);
      vll=arr[i].vl+tmp;
      if(vll>mn)
      {
        mn=vll;
        ans={i,mp2[{x,z}].second};
      }
     }
    if(mp3.find({y,z})!=mp3.end())
    {
      tmp=(x*1.00)*(y*1.00)*(mp3[{y,z}].first*1.00);
      vll=arr[i].vl+tmp;
      if(vll>mn)
      {
        mn=vll;
        ans={i,mp3[{y,z}].second};
      }
    }
    mp1[{x,y}]=max(mp1[{x,y}],{z,i});
    mp2[{x,z}]=max(mp2[{x,z}],{y,i});
    mp3[{y,z}]=max(mp3[{y,z}],{x,i});
  }
  if(ans.second==-1)cout<<1<<endl<<ans.first<<endl;
  else cout<<2<<endl<<ans.first<<" "<<ans.second<<endl;
  return 0;
}