/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/18/2019 18:38                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/gym/100814/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
double dp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string s,x;cin>>s;x=s;sort(s.begin(),s.end());
    int cnt=0,rank;
    do
    {
      cnt++;if(s==x)rank=cnt;
    }while(next_permutation(s.begin(),s.end()));
    int n=cnt-rank;//cout<<n<<endl;
     dp[0]=1.0/(cnt*1.0);//cout<<dp[0]<<endl;
    for(int i=1;i<n;i++)
      dp[i]=dp[i-1]+dp[i-1]*(1.0/(cnt*1.0));
    if(n==0)cout<<0<<endl;
    else cout<<setprecision(10)<<fixed<<dp[n-1]<<endl;  
  }
  return 0;
}