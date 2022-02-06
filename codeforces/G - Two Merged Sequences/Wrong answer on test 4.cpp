/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/02/2020 16:09                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 78 ms                                           memory_used: 39100 KB                             
*  problem: https://codeforces.com/contest/1144/problem/G
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],ans[N+2],link[N+2][2][2];
pair<int,int>inc[N+2],dic[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)inc[i]={N+1,-(N+1)},dic[i]={N+1,-(N+1)};
  inc[0]={0,N+1},dic[0]={0,N+1};
  for(int i=1;i<=n;i++)
  {
    if(aa[i]>inc[i-1].first)inc[i]={aa[i],max(inc[i-1].second,inc[i].second)};
    if(aa[i]>dic[i-1].first)inc[i]={aa[i],max(dic[i-1].second,inc[i].second)};
    if(inc[i]==make_pair(aa[i],inc[i-1].second))link[i][0][0]=1;
    if(inc[i]==make_pair(aa[i],dic[i-1].second))link[i][0][1]=1;
     if(aa[i]<inc[i-1].second)dic[i]={min(inc[i-1].first,dic[i].first),aa[i]};
    if(aa[i]<dic[i-1].second)dic[i]={min(dic[i-1].first,dic[i].first),aa[i]};
    if(dic[i]==make_pair(inc[i-1].first,aa[i]))link[i][1][0]=1;
    if(dic[i]==make_pair(dic[i-1].first,aa[i]))link[i][1][1]=1;
  }
  if(inc[n]==make_pair(N+1,-(N+1))&&dic[n]==make_pair(N+1,-(N+1)))cout<<"NO\n",exit(0);
  cout<<"YES\n";int ls=0;if(dic[n].second==aa[n])ans[n]=1,ls=1;
  for(int i=n;i>1;i--)
  {
    if(link[i][ls][0])ls=0;
    else if(link[i][ls][1])ans[i-1]=1,ls=1;
    else assert(0);
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
  return 0;
}