/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/08/2019 16:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 8100 KB                              
*  problem: https://codeforces.com/gym/102263/problem/J
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
 int fr[N+2],rv[N+2];
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;reverse(s.begin(),s.end());
  int n=s.size(),a=s[0]-'0',b=10-(s[0]-'0');
  fr[0]=min(a,10-a+1),rv[0]=min(b,10-b+1);
   for(int i=1;i<n;i++)
  {
    a=s[i]-'0',b=10-(s[i]-'0')-1;
     fr[i]=min(min(a,10-a+1)+fr[i-1],1+min(b,10-b+1)+rv[i-1]);
    rv[i]=min(min(b,10-b+1)+rv[i-1],1+min(a,10-a+1)+fr[i-1]);
     //SP(fr[i]);
   }
  cout<<fr[n-1]<<endl;
  return 0;
}