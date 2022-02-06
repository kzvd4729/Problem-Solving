/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 20:45                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/1381/problem/A1
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
string a,b;
void doIt(int p)
{
  for(int i=0;i<p;i++)
  {
    if(a[i]=='0')a[i]='1';
    else a[i]='0';
  }
  reverse(a.begin(),a.begin()+p+1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n>>a>>b;
    vector<int>ans;
    for(int i=n-1;i>0;i--)
    {
      if(a[i]==b[i])continue;
      if(a[0]==b[i])
      {
        ans.push_back(1);
        if(a[0]=='1')a[0]='0';else a[0]='1';
         doIt(i);
        ans.push_back(i+1);
      }
    }
    if(a[0]!=b[0])ans.push_back(1);
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
      cout<<endl;
  }
  return 0;
}