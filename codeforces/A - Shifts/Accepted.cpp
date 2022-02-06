/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/24/2020 14:05                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 154 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/229/problem/A
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
string s;int cnt[N+2];
void cal()
{
  int m=s.size();
  vector<int>v;for(int i=0;i<m;i++)if(s[i]=='1')v.push_back(i);
  if((int)v.size()==0)cout<<-1<<endl,exit(0);
  for(int i=0;i<m;i++)
  {
    int id=lower_bound(v.begin(),v.end(),i)-v.begin();
    int mn=N;
    if(id<(int)v.size())mn=min(mn,v[id]-i);
    else mn=min(mn,m+v[0]-i);
     id--;
    if(id>=0)mn=min(mn,i-v[id]);
    else mn=min(mn,m+i-v.back());
     cnt[i]+=mn;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>s;cal();
  }
  cout<<*min_element(cnt,cnt+m)<<endl;
    return 0;
}