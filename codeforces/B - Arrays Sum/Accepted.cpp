/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2020 21:34                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1408/problem/B
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
int a[N+2],b[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
        a[0]=-1;int ans=0;
    for(int cnt=1;cnt<=200;cnt++)
    {
      int f=0;
      for(int i=1;i<=n;i++)if(a[i])f=1;
       if(f==0){ans=1;cout<<cnt-1<<'\n';break;}
      int ds=0,mx=0;
      for(int i=1;i<=n;i++)
      {
        if(a[i]!=a[i-1])ds++;
        if(ds<=k){mx=a[i];b[i]=0;}
        else b[i]=a[i]-mx;
      }
      for(int i=1;i<=n;i++)a[i]=b[i];
      //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    }
    if(!ans)cout<<-1<<'\n';
  }
  return 0;
}