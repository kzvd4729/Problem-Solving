/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 20:15                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 1100 KB                              
*  problem: https://codeforces.com/contest/1111/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,a,b;
vector<int>v;
int ret(int lt,int rt)
{
  int id2=upper_bound(v.begin(),v.end(),rt)-v.begin();
  int id1=lower_bound(v.begin(),v.end(),lt)-v.begin();
  return id2-id1;
}
long dfs(int lt,int rt)
{
  int nm=ret(lt,rt);
  if(!nm)return a;
  long on=b*1LL;on*=nm;on*=(rt-lt+1);
  if(lt==rt)return on;
  int md=(lt+rt)/2;
  long tw=dfs(lt,md)+dfs(md+1,rt);
  return min(on,tw);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k>>a>>b;
  for(int i=1;i<=k;i++)
  {
    int x;cin>>x;v.push_back(x);
  }
  sort(v.begin(),v.end());
  cout<<dfs(1,1<<n)<<endl;
  return 0;
}