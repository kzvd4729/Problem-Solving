/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2020 13:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2028 ms                                         memory_used: 94600 KB                             
*  problem: https://codeforces.com/contest/620/problem/D
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;long s1=0,s2=0;
  for(int i=1;i<=n;i++)cin>>a[i],s1+=a[i];
  int m;cin>>m;
  for(int i=1;i<=m;i++)cin>>b[i],s2+=b[i];
   long ans=abs(s1-s2),k=0,on,tw,th,fr;
    for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      long s3=s1-a[i]+b[j];
      long s4=s2-b[j]+a[i];
      if(abs(s3-s4)<ans)ans=abs(s3-s4),k=1,on=i,tw=j;
    }
  }
  vector<int>v;map<int,pair<int,int> >mp;
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      int x=a[i]+a[j];
      v.push_back(x);mp[x]={i,j};
    }
  }
  sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
  for(int i=1;i<=m;i++)
  {
    for(int j=i+1;j<=m;j++)
    {
      int id=lower_bound(v.begin(),v.end(),(s1-s2)/2+(b[i]+b[j]))-v.begin();
       long s3,s4;
      if(id<v.size())
      {
        s3=s1-v[id]+b[i]+b[j];
        s4=s2-(b[i]+b[j])+v[id];
        if(abs(s3-s4)<ans)
        {
          pair<int,int>p=mp[v[id]];
          ans=abs(s3-s4),k=2,on=p.first,tw=i,th=p.second,fr=j;
        }
      }
      id++;
      if(id<v.size())
      {
        s3=s1-v[id]+b[i]+b[j];
        s4=s2-(b[i]+b[j])+v[id];
        if(abs(s3-s4)<ans)
        {
          pair<int,int>p=mp[v[id]];
          ans=abs(s3-s4),k=2,on=p.first,tw=i,th=p.second,fr=j;
        }
      }
      id-=2;
      if(id>=0)
      {
        s3=s1-v[id]+b[i]+b[j];
        s4=s2-(b[i]+b[j])+v[id];
        if(abs(s3-s4)<ans)
        {
          pair<int,int>p=mp[v[id]];
          ans=abs(s3-s4),k=2,on=p.first,tw=i,th=p.second,fr=j;
        }
      }
    }
  }
  cout<<ans<<endl;
  cout<<k<<endl;
  if(k>=1)cout<<on<<" "<<tw<<endl;
  if(k==2)cout<<th<<" "<<fr<<endl;
  return 0;
}