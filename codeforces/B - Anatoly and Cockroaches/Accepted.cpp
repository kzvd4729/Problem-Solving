/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2018 16:18                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 3800 KB                              
*  problem: https://codeforces.com/contest/719/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,od,ev,oor,er,ob,eb;
string s;
int case1(void)
{
  int sw=min(ob,er);
  int ner=er-sw;
  int nd=od-oor-sw;
  return sw+nd+ner;
}
int case2(void)
{
  int sw=min(oor,eb);
  int neb=eb-sw;
  int nd=od-ob-sw;
  return sw+nd+neb;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>s;
   od=(n+1)/2;
  ev=n/2;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='r'&&(i&1))oor++;
    if(s[i-1]=='r'&&!(i&1))er++;
    if(s[i-1]=='b'&&(i&1))ob++;
    if(s[i-1]=='b'&&!(i&1))eb++;
  }
  cout<<min(case1(),case2())<<endl;
   return 0;
}