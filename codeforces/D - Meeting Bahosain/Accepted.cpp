/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/08/2019 15:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 452 ms                                          memory_used: 3900 KB                              
*  problem: https://codeforces.com/gym/102263/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
 #define SP(x) cerr<<#x<<" = "<<x<<endl
#define DP(x) cerr<<#x<<" = "<<x.first<<" "<<x.second<<endl
#define F cerr<<"flag"<<endl
template<typename T>//container
void _p(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
const int N=1e6;
 int aa[N+2];
void no()
{
  cout<<"No\n",exit(0);
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>aa[i];
  sort(aa+1,aa+n+1);
  int gc=0;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    gc=__gcd(gc,x);
  }
  for(int i=2;i<=n;i++)
    if((aa[i]-aa[1])%gc)no();
  cout<<"Yes\n";
  return 0;
}