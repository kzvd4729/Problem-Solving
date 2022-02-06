/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/21/2020 17:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 3500 KB                              
*  problem: https://codeforces.com/contest/966/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long xx;
vector<long>v[60+2],ans;
void ck(int j)
{
  for(int i=0;i<=j;i++)
  {
    if(v[i].size()==0)continue;
    if(!(xx&(1LL<<i)))
    {
      xx^=v[i].back();ans.push_back(v[i].back());
      v[i].pop_back();ck(i);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    long x;cin>>x;
    int m=63-__builtin_clzll(x);v[m].push_back(x);
  }
  for(int i=0;i<60;i++)
  {
    if(v[i].size()==0)continue;
    ans.push_back(v[i].back());v[i].pop_back();
    break;
  }
  xx=ans[0];ck(60);if(ans.size()!=n)cout<<"No\n",exit(0);
  cout<<"Yes\n";
  for(auto x:ans)cout<<x<<" ";cout<<endl;
  return 0;
}