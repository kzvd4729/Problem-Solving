/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/02/2021 21:01                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1494/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
bool ck(char a,char b,char c,string s)
{
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='A')s[i]=a;
    if(s[i]=='B')s[i]=b;
    if(s[i]=='C')s[i]=c;
  }
  int bl=0;
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='(')bl++;
    else bl--;
    if(bl<0)return false;
  }
  return bl==0;
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string s;cin>>s;
    int ret=0;
    ret+=ck('(','(','(',s);
    ret+=ck('(','(',')',s);
    ret+=ck('(',')','(',s);
    ret+=ck('(',')',')',s);
     ret+=ck(')','(','(',s);
    ret+=ck(')','(',')',s);
    ret+=ck(')',')','(',s);
    ret+=ck(')',')',')',s);
     if(ret)cout<<"YES\n";else cout<<"NO\n";
   }
     return 0;
}