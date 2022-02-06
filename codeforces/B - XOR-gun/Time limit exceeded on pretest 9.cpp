/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2020 14:05                        
*  solution_verdict: Time limit exceeded on pretest 9        language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1456/problem/B
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
const int N=1e5;
int n,a[N+2];
void gen(int tk,int sz,vector<int>a)
{
  int nn=a.size();
  if(tk==sz)
  {
    for(int i=0;i<nn-1;i++)if(a[i]>a[i+1])cout<<sz<<endl,exit(0);
    return ;
  }
  for(int i=0;i<nn-1;i++)
  {
    vector<int>b=a;
    b[i]=(b[i]^b[i+1]);
    for(int j=i+1;j<nn-1;j++)b[j]=b[j+1];
    b.pop_back();
     gen(tk+1,sz,b);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  a[0]=-1;a[n+1]=2e9+2;
  for(int i=1;i<n;i++)
  {
    int x=(a[i]^a[i+1]);
    if((x<a[i-1])||(x>a[i+2]))cout<<1<<endl,exit(0);
  }
  for(int i=2;i<n;i++)
  {
    vector<int>v;
    for(int i=1;i<=n;i++)v.push_back(a[i]);
    gen(0,i,v);
  }
  cout<<-1<<endl;
  return 0;
}