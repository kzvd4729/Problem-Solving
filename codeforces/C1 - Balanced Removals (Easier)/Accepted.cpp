/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/16/2019 21:37                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1237/problem/C1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
int vis[N+2];
vector<pair<int,int> >ans;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  vector<vector<int> >v(n),u;
  for(int i=0;i<n;i++)
  {
    v[i].resize(4);
    for(int j=0;j<3;j++)cin>>v[i][j];
    v[i][3]=i;
  }
  sort(v.begin(),v.end());
 //  for(int i=0;i<n;i++)
//    P(v[i]);
//  cout<<endl;
   int cnt=0;
  for(int i=1;i<n;i++)
  {
    if(v[i][0]==v[i-1][0]&&v[i][1]==v[i-1][1])cnt++;
    else
    {
      if(cnt)
      {
        int p=(cnt+1)/2;
        for(int j=i-1;p;j-=2)
        {
          vis[j]=1,vis[j-1]=1;
          ans.push_back({v[j][3],v[j-1][3]});
          p--;
        }
      }
      cnt=0;
    }
  }
  if(cnt)
  {
    int p=(cnt+1)/2;
    for(int j=n-1;p;j-=2)
    {
      vis[j]=1,vis[j-1]=1;
      ans.push_back({v[j][3],v[j-1][3]});
      p--;
    }
  }
   for(int i=0;i<n;i++)
    if(!vis[i])u.push_back(v[i]);
   v=u;u.clear();n=v.size();
//  for(int i=0;i<n;i++)
//    P(v[i]);
//  cout<<endl;
   memset(vis,0,sizeof(vis));
  cnt=0;
  for(int i=1;i<n;i++)
  {
    if(v[i][0]==v[i-1][0])cnt++;
    else
    {
      if(cnt)
      {
        int p=(cnt+1)/2;
        for(int j=i-1;p;j-=2)
        {
          vis[j]=1,vis[j-1]=1;
          ans.push_back({v[j][3],v[j-1][3]});
          p--;
        }
      }
      cnt=0;
    }
  }
  if(cnt)
  {
    int p=(cnt+1)/2;
    for(int j=n-1;p;j-=2)
    {
      vis[j]=1,vis[j-1]=1;
      ans.push_back({v[j][3],v[j-1][3]});
      p--;
    }
  }
   for(int i=0;i<n;i++)
    if(!vis[i])u.push_back(v[i]);
   v=u;n=v.size();
 //  for(int i=0;i<n;i++)
//    P(v[i]);
//  cout<<endl;
   for(int i=0;i<n;i+=2)
    ans.push_back({v[i][3],v[i+1][3]});
   for(auto x:ans)
    cout<<x.first+1<<" "<<x.second+1<<"\n";
   return 0;
}