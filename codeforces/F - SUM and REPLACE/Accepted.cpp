/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/29/2020 01:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1403 ms                                         memory_used: 33100 KB                             
*  problem: https://codeforces.com/contest/920/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6,inf=1e9;
long dvs[N+2];
void who()
{
  for(long i=1;i<=N;i++)
  {
    for(long j=i;j<=N;j+=i)
      dvs[j]++;
  }
}
long bit[N+2];
void upd(long x,long vl)
{
  for( ;x<=N;x+=x&-x)bit[x]+=vl;
}
long get(long x)
{
  long ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
long aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  who();long n,q;cin>>n>>q;set<long>st;
  for(long i=1;i<=n;i++)
  {
    cin>>aa[i];upd(i,aa[i]);
    st.insert(i);
  }
  while(q--)
  {
    long ty,l,r;cin>>ty>>l>>r;
    if(ty==1)
    {
      while(true)
      {
        auto it=st.lower_bound(l);
        if(it==st.end()||*it>r)break;
         l=*it;st.erase(l);upd(l,-aa[l]);
        aa[l]=dvs[aa[l]];upd(l,aa[l]);
        if(aa[l]>2)st.insert(l);l++;
      }
    }
    else cout<<get(r)-get(l-1)<<"\n";
  }
  return 0;
}