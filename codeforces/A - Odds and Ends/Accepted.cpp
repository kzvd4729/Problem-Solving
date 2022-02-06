/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/14/2019 19:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/849/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;
 for(int i=1;i<=n;i++)
  cin>>aa[i];
 if(aa[1]%2==0||aa[n]%2==0||n%2==0)cout<<"No"<<endl;
 else cout<<"Yes"<<endl;
 return 0;
}