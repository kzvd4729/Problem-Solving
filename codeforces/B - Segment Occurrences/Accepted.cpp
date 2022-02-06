/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/03/2018 21:03                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 327 ms                                          memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1016/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int kmp[N+2],n,m,q,l,r,ln,ans;
string s,a,b;
void _kmp(void)
{
  s=b+"#"+a;
  for(int i=1;s[i];i++)
  {
    int now=kmp[i-1];
    while(true)
    {
      if(s[i]==s[now])
      {
        kmp[i]=now+1;
        break;
      }
      if(now==0)break;
      now=kmp[now-1];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m>>q;
  cin>>a>>b;
  ln=b.size();
  _kmp();
  while(q--)
  {
    cin>>l>>r;
    l+=ln;
    r+=ln;
    l+=ln-1;
    ans=0;
    for(int i=l;i<=r;i++)
    {
      if(kmp[i]==ln)ans++;
    }
    cout<<ans<<endl;
  }
   return 0;
}