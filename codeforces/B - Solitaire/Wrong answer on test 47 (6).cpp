/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/28/2018 17:38                        
*  solution_verdict: Wrong answer on test 47                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/208/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,con=6;
string s[70];
map<pair<long,pair<long,long> >,int>mp;
long hash1(int n,string one,string two,string th,string fr)
{
  long b=31,mod=1e9+7,sum=1;
   sum=(sum*b+one[0])%mod;
  sum=(sum*b+one[1])%mod;
   sum=(sum*b+two[0])%mod;
  sum=(sum*b+two[1])%mod;
   sum=(sum*b+th[0])%mod;
  sum=(sum*b+th[1])%mod;
   sum=(sum*b+fr[0])%mod;
  sum=(sum*b+fr[1])%mod;
   sum=(sum+n)%mod;
   return sum;
 }
long hash2(int n,string one,string two,string th,string fr)
{
  long b=37,mod=1e9+9,sum=1;
   sum=(sum*b+one[0])%mod;
  sum=(sum*b+one[1])%mod;
   sum=(sum*b+two[0])%mod;
  sum=(sum*b+two[1])%mod;
   sum=(sum*b+th[0])%mod;
  sum=(sum*b+th[1])%mod;
   sum=(sum*b+fr[0])%mod;
  sum=(sum*b+fr[1])%mod;
   sum=(sum+n)%mod;
   return sum;
 }
long hash3(int n,string one,string two,string th,string fr)
{
  long b=39,mod=1e9+11,sum=1;
   sum=(sum*b+one[0])%mod;
  sum=(sum*b+one[1])%mod;
   sum=(sum*b+two[0])%mod;
  sum=(sum*b+two[1])%mod;
   sum=(sum*b+th[0])%mod;
  sum=(sum*b+th[1])%mod;
   sum=(sum*b+fr[0])%mod;
  sum=(sum*b+fr[1])%mod;
   sum=(sum+n)%mod;
   return sum;
 }
void dfs(int n,string one,string two,string th,string fr)
{
  if(n<=1+con)cout<<"YES"<<endl,exit(0);
  long a=hash1(n,one,two,th,fr);
  long b=hash2(n,one,two,th,fr);
  long c=hash2(n,one,two,th,fr);
  if(mp[{a,{b,c}}]==1)return ;
  mp[{a,{b,c}}]=1;
   if(fr[0]==th[0]||fr[1]==th[1])
    dfs(n-1,s[n-4],one,two,fr);
  if(fr[0]==one[0]||fr[1]==one[1])
    dfs(n-1,s[n-4],fr,two,th);
  }
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   for(int i=0;i<=con;i++)
    s[i]="11";
   cin>>n;
  n+=con;
  for(int i=con+1;i<=n;i++)
    cin>>s[i];
  if(n==1+con)cout<<"YES"<<endl,exit(0);
   dfs(n,s[n-3],s[n-2],s[n-1],s[n]);
   cout<<"NO"<<endl;
   return 0;
}