/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/15/2020 12:43                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1365/problem/G
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long
using namespace std;
const int N=2000;
int v[N+2][N+2],tmp[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;int s=n;while(__builtin_popcount(s)>1)s++;
  for(int i=1;i<=n;i++)v[i][i]=1;
   cout<<"? "<<n;
  for(int i=1;i<=n;i++)cout<<" "<<i;
  cout<<endl;int tt;cin>>tt;
   for(int j=s;j>1;j/=2)
  {
    memset(tmp,0,sizeof tmp);
    for(int i=1;i<=n;i+=j)
    {
      for(int k=i;k<i+j/2;k++)
        tmp[k]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(tmp[i]==0)cnt++;
    assert(cnt);
     cout<<"? "<<cnt;
    for(int i=1;i<=n;i++)if(tmp[i]==0)cout<<" "<<i;
    cout<<endl;
     int x;cin>>x;
    for(int i=1;i<=n;i++)
    {
      if(!tmp[i])continue;
      ans[i]|=x;
      for(int j=1;j<=n;j++)if(tmp[j]==0)v[i][j]=1;
    }
  }
  //for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  cout<<"!";
  for(int i=1;i<=n;i++)
  {
    int cnt=0;
    for(int j=1;j<=n;j++)cnt+=v[i][j];
    assert(cnt==n);cout<<" "<<ans[i];
     for(int j=i+1;j<=n;j++)ans[j]|=(ans[i]^tt),v[j][i]=1;
  }
  cout<<endl;
  return 0;
}