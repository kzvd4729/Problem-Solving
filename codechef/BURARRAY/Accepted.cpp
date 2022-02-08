/****************************************************************************************
*  @author: kzvd4729                                         created: 29-06-2019 19:52:46                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.69 sec                                        memory_used: 30.2M                                
*  problem: https://www.codechef.com/LTIME73A/problems/BURARRAY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
map<long,long>mp;
long _find(long x)
{
  if(mp.find(x)==mp.end())return x;
  return mp[x]=_find(mp[x]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    mp.clear();
    long n,q,sm=0;cin>>n>>q;
    while(q--)
    {
      long ty;cin>>ty;
      if(ty==1)
      {
        long x;cin>>x;x+=sm;
        mp[x]=_find(x-1);
      }
      else
      {
        long l,r;cin>>l>>r;l+=sm;r+=sm;
        long rt=_find(r);
        if(rt>=l)
        {
          cout<<rt<<"\n";sm=(rt+sm)%n;
        }
        else cout<<0<<"\n";
      }
    }
  }
  return 0;
}