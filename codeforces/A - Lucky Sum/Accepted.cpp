/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/13/2018 13:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/121/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long lm=1e9;
long ans,l,r;
vector<long>v;
void dfs(long n)
{
  v.push_back(n);
  if(n>lm)return ;
  dfs(n*10+4);
  dfs(n*10+7);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     dfs(0);
    sort(v.begin(),v.end());
    cin>>l>>r;
     for(auto x:v)
    {
      if(l>r)break;
      if(x>=l)
      {
        ans+=x*(min(x,r)-l+1);
        l=min(x,r)+1;
      }
    }
    cout<<ans<<endl;
    return 0;
}