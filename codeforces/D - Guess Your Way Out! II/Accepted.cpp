/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/04/2018 15:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/558/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long h,q;
pair<long,long>ret(long hh,long lt,long rt)
{
  //cout<<lt<<" ----- "<<rt<<endl;
  for(long i=hh+1;i<=h;i++)
    lt=lt*2,rt=rt*2+1;
  return {lt,rt};
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>h>>q;set<pair<long,long> >st;
  while(q--)
  {
    long i,l,r,ty;cin>>i>>l>>r>>ty;
    if(ty==0)
      st.insert(ret(i,l,r));
    else
    {
      long lt=(1LL<<(i-1));
      if(l>lt)st.insert(ret(i,lt,l-1));
      long rt=(1LL<<i)-1;
      if(rt>r)st.insert(ret(i,r+1,rt));
    }
  }
  long on=(1LL<<(h-1))-1,tw=(1LL<<(h-1))-1;
  st.insert({(1LL<<h),(1LL<<h)});
  long cnt=0,ans;
  while(st.size())
  {
    pair<long,long>p=*st.begin();st.erase(p);
    if(p.first-tw>1)
      cnt+=p.first-tw-1,ans=p.first-1;
    tw=max(tw,p.second);
  }
  if(cnt>1)cout<<"Data not sufficient!"<<endl;
  else if(cnt==1)cout<<ans<<endl;
  else cout<<"Game cheated!"<<endl;
  return 0;
}