/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/21/2020 18:37                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/1190/problem/D
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
const int N=1e6,R=1e9;
map<int,int>bit;
void upd(int x)
{
  for( ;x>0;x-=x&-x)bit[x]++;
}
int get(int x)
{
  int ret=0;
  for( ;x<=R;x+=x&-x)ret+=bit[x];
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;vector<pair<int,int> >v(n);
  for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
   sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
   long ans=0;
  for(int i=0;i<v.size(); )
  {
    int j;
    for(j=i;j<v.size();j++)
    {
      if(v[i].first!=v[j].first)
      {
        upd(v[j-1].second);break;
      }
      //cout<<v[j].first<<" "<<v[j].second<<endl;
       if(j==i)ans+=get(1)+1;
      else ans+=get(v[j-1].second+1)+1;
    }
    i=j;
  }
  cout<<ans<<endl;
  return 0;
}