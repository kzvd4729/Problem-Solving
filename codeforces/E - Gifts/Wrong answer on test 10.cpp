/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/25/2020 19:51                        
*  solution_verdict: Wrong answer on test 10                 language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 40300 KB                             
*  problem: https://codeforces.com/contest/229/problem/E
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
//#define long long long
using namespace std;
const int N=1e3;
long double ncr[1000+2][1000+2];
void calNCR(int n)
{
  for(int i=1;i<=n;i++)ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
      ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
  }
  ncr[0][0]=1;
}
int a[N+2],t[N+2][N+2],m;long double pr[N+2][N+2],d[N+2][N+3];
bool vs[N+2][N+2];
long double dfs(int i,int rq)
{
  if(i>m)return rq==0;
  //if(vs[i][rq])return d[i][rq];
  long double ret=0;
  for(int j=0;j<=a[i]&&j<=rq;j++)
    ret+=pr[i][j]*dfs(i+1,rq-j);
  //ret=max(ret,pr[i][0]*dfs(i+1,rq));
   vs[i][rq]=1;long double mn=1.0;
  return d[i][rq]=min(mn,ret);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cout<<setprecision(9)<<fixed;
  calNCR(1000);vector<int>v;
  int n;cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    cin>>a[i];
    for(int j=1;j<=a[i];j++)
    {
      cin>>t[i][j];
      v.push_back(t[i][j]);
    }
  }
  sort(v.begin(),v.end(),greater<int>());
  int l=v[n-1];
  for(int i=1;i<=m;i++)
  {
    int g=0,s=0;
    for(int j=1;j<=a[i];j++)
      g+=(t[i][j]>l),s+=(t[i][j]==l);
     pr[i][0]=1.0/ncr[a[i]][g];
    for(int j=1;j<=s;j++)pr[i][j]=ncr[s][j]/ncr[a[i]][g+j];
  }
  int rq=0;
  for(int i=0;i<n;i++)rq+=(v[i]==l);
   //cout<<pr[1][0]<<endl;
   cout<<dfs(1,rq)<<endl;
    return 0;
}