/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/04/2020 19:47                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 202 ms                                          memory_used: 46100 KB                             
*  problem: https://codeforces.com/contest/1453/problem/C
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
const int N=1e6;
string s[N+2];
int n,rmx[N+2],rmn[N+2],cmx[N+2],cmn[N+2];
int ck(char d)
{
  for(int i=0;i<=n;i++)
  {
    rmx[i]=-1,cmx[i]=-1;
    rmn[i]=n+1,cmn[i]=n+1;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]!=d)continue;
      rmx[i]=max(rmx[i],j);rmn[i]=min(rmn[i],j);
      cmx[j]=max(cmx[j],i);cmn[j]=min(cmn[j],i);
    }
  }
  for(int i=0;i<n;i++)
  {
    rmx[n]=max(rmx[n],rmx[i]);rmn[n]=min(rmn[n],rmn[i]);
    cmx[n]=max(cmx[n],cmx[i]);cmn[n]=min(cmn[n],cmn[i]);
  }
  int ret=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]!=d)continue;
      int b=max(cmx[j]-i,i-cmn[j]);
      ret=max(ret,b*max(j,n-1-j));
       b=max(rmx[i]-j,j-rmn[i]);
      ret=max(ret,b*max(i,n-1-i));
       b=max(cmx[n]-i,i-cmn[n]);
      ret=max(ret,b*max(j,n-1-j));
       b=max(rmx[n]-j,j-rmn[n]);
      ret=max(ret,b*max(i,n-1-i));
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    for(char i='0';i<='9';i++)cout<<ck(i)<<" ";cout<<endl;
  }
  return 0;
}