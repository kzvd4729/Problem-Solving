/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/05/2020 19:42                        
*  solution_verdict: Time limit exceeded on test 9           language: GNU C++14                               
*  run_time: 1500 ms                                         memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/1423/problem/K
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
const int N=1e6,inf=1e9;
bool isP[N+2];vector<int>pr;
void seive(int n)
{
  pr.push_back(2);isP[1]=1;
  for(int i=4;i<=n;i+=2)isP[i]=1;
  int sq=sqrt(n+1);
  for(int i=3;i<=n;i+=2)
  {
    if(isP[i])continue;pr.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)isP[j]=1;
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive(N);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;int sq=sqrt(n)+1;
    int ans=upper_bound(pr.begin(),pr.end(),n)-lower_bound(pr.begin(),pr.end(),sq);
    cout<<1+ans<<endl;
  }
  return 0;
}