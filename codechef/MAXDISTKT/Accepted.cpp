/****************************************************************************************
*  @author: kzvd4729                                         created: 19-10-2021 12:40:58                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.25 sec                                        memory_used: 6.2M                                 
*  problem: https://www.codechef.com/SNCKQL21/problems/MAXDISTKT
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    pair<int,int>p[n+1];
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      p[i]={x,i};
    }
    sort(p+1,p+n+1);
    pair<int,int>a[n+1];
    int now=0;
    for(int i=1;i<=n;i++)
    {
      a[i]={p[i].second,now};
      if(now<p[i].first)now++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)cout<<a[i].second<<" ";cout<<endl;
  }
    return 0;
}