/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/25/2018 19:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1934 ms                                         memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1029/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,c,ans=1e18;
void upd(long a)
{
 vector<int>vv;
 for(int i=1;i<=sqrt(a+1);i++)
  if(a%i==0)vv.push_back(i);
 for(int i=1,sq=sqrt(c+1);i<=sq;i++)
 {
  if(c%i)continue;
  for(int j=0,sz=vv.size();j<sz;j++)
  {
   if(vv[j]<=i&&(a/vv[j])<=(c/i))
    ans=min(ans,2*(i+(c/i)));
  }
 }
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 cin>>a>>b;c=a+b;upd(a);upd(b);
 cout<<ans<<endl;
 return 0;
}