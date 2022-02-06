/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2020 20:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1221/problem/E
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
const int N=2e5;
bool solve(vector<int>v,int a,int b)
{
  sort(v.begin(),v.end(),greater<int>());
  while((int)v.size()&&v.back()<b)v.pop_back();
  if((int)v.size()==0)return false;
  if(v.back()<a)return false;
  if(v[0]>=a+4*b-1)return false;
  if((int)v.size()>1&&v[1]>=2*b)return false;
   int f1=0,f2=0,f3=0;int x=v[0];
   if(x<=a+2*b-2)f1=1;
  if(x>=2*a&&2*b>a&&x<=b-1+a+2*b-1)f2=1;
  if(x>=3*a&&2*b>a&&x<=2*b-1+a+2*b-1)f3=1;
   int sz=(int)v.size();sz--;
  if(sz%2)return f2;
  else return f1|f3;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;
    string s;cin>>s;vector<int>v;
    int cnt=0;
    for(auto x:s)
    {
      if(x=='.')cnt++;
      else
      {
        v.push_back(cnt);
        cnt=0;
      }
    }
    v.push_back(cnt);
    if(solve(v,a,b))cout<<"YES\n";else cout<<"NO\n";
   }
  return 0;
}