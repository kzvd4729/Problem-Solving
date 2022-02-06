/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2020 14:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 623 ms                                          memory_used: 24700 KB                             
*  problem: https://codeforces.com/contest/1451/problem/E2
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
void case1(int n)
{
  int id;
  for(int i=2;i<=n;i++)if(a[i]==0)id=i;
  cout<<"AND 1 "<<id<<endl;
  cin>>b[1];
   cout<<"! "<<b[1];
  for(int i=2;i<=n;i++)cout<<" "<<(a[i]^b[1]);
  cout<<endl;
  exit(0);
}
int fr[N+2];vector<int>vl[N+2];
void case2(int n)
{
  int id1,id2;
  for(int i=2;i<=n;i++)
  {
    int x=a[i];
    vl[x].push_back(i);
    if((int)vl[x].size()>=2)id1=vl[x][0],id2=vl[x][1];
  }
  cout<<"AND "<<id1<<" "<<id2<<endl;
  int x;cin>>x;
   b[1]=(x^a[id1]);
  cout<<"! "<<b[1];
  for(int i=2;i<=n;i++)cout<<" "<<(a[i]^b[1]);
  cout<<endl;
  exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=2;i<=n;i++)
  {
    cout<<"XOR 1 "<<i<<endl;
    cin>>a[i];
  }
  for(int i=2;i<=n;i++)if(a[i]==0)case1(n);
  for(int i=2;i<=n;i++)
  {
    fr[a[i]]++;if(fr[a[i]]>=2)case2(n);
  }
  int x=0;
  for(int i=2;i<=n;i++)
  {
    if(a[i]==1)
    {
      cout<<"AND 1 "<<i<<endl;
      cin>>x;
    }
  }
  for(int i=2;i<=n;i++)
  {
    if(a[i]==2)
    {
      cout<<"AND 1 "<<i<<endl;
      int vl;cin>>vl;
      x+=(vl%2);
    }
  }
  b[1]=x;
  cout<<"! "<<b[1];
  for(int i=2;i<=n;i++)cout<<" "<<(a[i]^b[1]);
  cout<<endl;
  return 0;
}