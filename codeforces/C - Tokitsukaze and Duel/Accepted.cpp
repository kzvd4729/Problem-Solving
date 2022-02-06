/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 18:05                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 11700 KB                             
*  problem: https://codeforces.com/contest/1190/problem/C
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
#define endl '\n'
#define long long long  
using namespace std;
const int N=1e6;
void tok(){cout<<"tokitsukaze"<<endl,exit(0);}
void qua(){cout<<"quailty"<<endl,exit(0);}
void aga(){cout<<"once again"<<endl,exit(0);}
int a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;string s;cin>>s;s="#"+s;
   b[n+1]=1;b[n]=1;
  for(int i=n-1;i>=1;i--)
    b[i]=(b[i+1]&(s[i]==s[i+1]));
   a[0]=1;a[1]=1;
  for(int i=2;i<=n;i++)
    a[i]=(a[i-1]&(s[i]==s[i-1]));
   int one=0,two=1;
   for(int i=1;i<=n;i++)
  {
    int j=i+k-1;if(j>n)break;
    if(a[i-1]&&b[j+1]&&(i==1||j==n||s[i-1]==s[j+1]))one=1;
     if((a[i-1]==0&&j<n)||(b[j+1]==0&&i>1))two=0;
    if(i-1>k||n-j>k)two=0;
  }
  if(one)tok();else if(two)qua();else aga();
  return 0;
}