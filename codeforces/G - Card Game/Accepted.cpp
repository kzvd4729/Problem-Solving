/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/08/2019 15:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/gym/102263/problem/G
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
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;long ans=0;
  for(int i=n;i>=1;i--)
    ans+=1LL*i*(i-1);
  double pr=(ans*1.0)/(n*1.0);
  cout<<setprecision(6)<<fixed<<pr<<endl;
   return 0;
}