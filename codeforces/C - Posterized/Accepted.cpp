/****************************************************************************************
*  @author: kzvd4729                                         created: May/08/2018 22:39                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 124 ms                                          memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/980/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k,color[300],x,sz[300];
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0;i<=300;i++)
  {
    color[i]=-1;
    sz[i]=1;
  }
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    if(color[x]==-1)
    {
      int tmp=k,mn=x;
      for(int j=x;j>=0; )
      {
        if(sz[j]<=tmp)
        {
          tmp-=min(sz[j],j+1);
          j-=sz[j];
        }
        else break;
      }
      mn=x-(k-tmp)+1;
      for(int j=mn;j<=x;j++)
      {
        color[j]=mn;
        sz[j]=k-tmp;
      }
    }
    cout<<color[x]<<" ";
  }
  cout<<endl;
  return 0;
}