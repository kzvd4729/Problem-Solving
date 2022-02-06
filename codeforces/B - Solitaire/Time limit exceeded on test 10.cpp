/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 16:25                        
*  solution_verdict: Time limit exceeded on test 10          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/208/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,con=4;
string s[60];
void dfs(int n,string one,string two,string th,string fr)
{
  if(n==1+con)cout<<"YES"<<endl,exit(0);
   if(fr[0]==th[0]||fr[1]==th[1])
    dfs(n-1,s[n-4],one,two,fr);
  if(fr[0]==one[0]||fr[1]==one[1])
    dfs(n-1,s[n-4],fr,two,th);
 }
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  n+=con;
  for(int i=con+1;i<=n;i++)
    cin>>s[i];
  if(n==1+con)cout<<"YES"<<endl,exit(0);
   dfs(n,s[n-3],s[n-2],s[n-1],s[n]);
   cout<<"NO"<<endl;
   return 0;
}