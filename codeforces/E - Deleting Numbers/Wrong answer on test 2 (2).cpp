/****************************************************************************************
*  @author: kzvd4729#                                        created: Apr/18/2021 23:44                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 77 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1406/problem/E
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
const int N=1e5,inf=1e9,mod=1e9+7;
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
set<int>st;
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
     int n;cin>>n;
  seive(n);
    //for(int i=1;i<=n;i++)st.insert(i);
    int ans=1;
  for(auto x:pr)
  {
    vector<int>v;long ml=1;
    while(true)
    {
      if(ml*x>n)break;
      ml*=x;
      v.push_back(ml);
    }
    reverse(v.begin(),v.end());
     for(auto xx:v)
    {
      cout<<"B "<<xx<<endl;
      int cnt;cin>>cnt;
       cout<<"A "<<xx<<endl;
      cin>>cnt;
       if(cnt){ans*=xx;break;}
     }
   }
  cout<<"C "<<ans<<endl;
    return 0;
}