/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/25/2018 16:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 42800 KB                             
*  problem: https://codeforces.com/contest/955/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long inf=1e18;
long p,sq,q,l,r;
vector<long>v;
set<long>st;
void precal(void)
{
  for(long i=2;i<=1000000;i++)
  {
    p=i*i;
    for(long j=3;j<=64;j++)
    {
      if((inf/p)<i)break;
      p=p*i;
      sq=sqrt(p*1.0);
      if(sq*sq==p)continue;
      st.insert(p);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   precal();
  vector<long>v=vector<long>(st.begin(),st.end());
  cin>>q;
  while(q--)
  {
    cin>>l>>r;
    long print=upper_bound(v.begin(),v.end(),r)-lower_bound(v.begin(),v.end(),l)+(long)sqrt(r*1.0)-(long)sqrt((l-1)*1.0);
    cout<<print<<"\n";
  }
  return 0;
}