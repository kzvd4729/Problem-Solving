/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/29/2020 21:41                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 12200 KB                             
*  problem: https://codeforces.com/contest/1081/problem/E
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
#define long long long
using namespace std;
const int N=2e5;
int a[N+2];
vector<pair<int,int> >v[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int id=0;
  for(int i=1;i<=N;i+=2)a[++id]=i;
  for(int i=1;i<=id;i++)
  {
    int sm=0;
    for(int j=i;j<=id;j++)
    {
      sm+=a[j];if(sm>N)break;
      v[sm].push_back({a[i],a[j]});
    }
  }
  int n;cin>>n;int ls=-1;vector<long>ans;
  for(int i=1;i<=n/2;i++)
  {
    cin>>a[i];int bg,ed=N+1;
    for(auto x:v[a[i]])
      if(x.first>ls+2&&x.second<ed)ed=x.second,bg=x.first;
    if(ed>N)break;long sm=0;
    for(int j=ls+2;j<bg;j+=2)sm+=j;
    ans.push_back(sm);ans.push_back(a[i]);
    ls=ed;
  }
  if(ans.size()!=n)cout<<"No\n";
  else 
  {
    cout<<"Yes\n";
    for(auto x:ans)cout<<x<<" ";cout<<endl;
  }
  return 0;
}