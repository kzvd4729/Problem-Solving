/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2020 21:37                        
*  solution_verdict: Wrong answer on test 40                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/contest/1268/problem/A
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
const int N=1e6;
int n,k;string s;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;cin>>s;string a;a.resize(n);
   for(int i=0;i<k;i++)
  {
    for(int j=i;j<n;j+=k)a[j]=s[i];
  }
  cout<<n<<endl;int f=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]==a[i])continue;
    if(a[i]>s[i])cout<<a<<endl,exit(0);
    else {f=1;break;}
  }
  if(f==0)cout<<a<<endl,exit(0);
  for(int i=k-1;i>=0;i--)
  {
    if(a[i]=='9')continue;
    for(int j=i;j<n;j+=k)a[j]++;
    cout<<a<<endl,exit(0);
  }
   return 0;
}