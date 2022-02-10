/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-07-26 23:02:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1024                                       memory_used (MB): 1.9                             
*  problem: https://vjudge.net/problem/LightOJ-1199
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int gr[N+2],t,tc,n,x;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  gr[1]=0;
  gr[2]=0;
  for(int i=3;i<=N;i++)
  {
    vector<int>v;
    for(int j=1;j<(i+1)/2;j++)
    {
      v.push_back(gr[j]^gr[i-j]);
    }
    sort(v.begin(),v.end());
    vector<int>::iterator it;
    it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(int j=0;j<v.size();j++)
    {
      if(j!=v[j])
      {
        gr[i]=j;
        break;
      }
      if(j==v.size()-1)
        gr[i]=j+1;
    }
  }
  cin>>t;
  while(t--)
  {
    cin>>n;
    int xx=0;
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      xx^=gr[x];
    }
    if(xx)cout<<"Case "<<++tc<<": Alice"<<endl;
    else cout<<"Case "<<++tc<<": Bob"<<endl;
  }
  return 0;
}