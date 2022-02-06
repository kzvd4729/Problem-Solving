/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/08/2019 15:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102263/problem/B
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
void p(int f)
{
  if(f)cout<<"Ayoub\n";
  else cout<<"Kilani\n";
}
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    if(n>=k+2)p(0);
    else if(n%2)p(0);
    else p(1);
  }
  return 0;
}