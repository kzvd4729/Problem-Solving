/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2020 22:01                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 15400 KB                             
*  problem: https://codeforces.com/contest/1110/problem/E
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
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],bb[N+2],vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)cin>>bb[i];
  int l=1,r=n;
  while(l<=n&&aa[l]==bb[l])l++;
  while(r>=1&&aa[r]==bb[r])r--;
  if(l>n)cout<<"Yes",exit(0);
  if(l==1||r==n)cout<<"No\n",exit(0);
   map<int,int>mp;
  for(int i=l;i<=r;i++)
  {
    mp[aa[i-1]-aa[i]]=1;
    if(mp[bb[i]-aa[i+1]])vs[i]=1;
  }
  mp.clear();
  for(int i=r;i>=1;i--)
  {
    mp[aa[i+1]-aa[i]]=1;
    if(mp[bb[i]-aa[i-1]])vs[i]=1;
  }
  for(int i=l;i<=r;i++)if(!vs[i])cout<<"No\n",exit(0);
  cout<<"Yes\n";
   return 0;
}