/****************************************************************************************
*  @author: kzvd4729                                         created: 29-09-2018 22:29:11                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/LTIME64A/problems/MATCH2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5,sq=400;
int aa[N+2],bb[N+2],n,q,lz[N+2],seg[sq+2];
map<int,int>mp[sq+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n>>q;int sm=0;
    for(int i=0;i<=sq;i++)mp[i].clear();
    memset(lz,-1,sizeof(lz));
    memset(seg,0,sizeof(seg));
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=n;i++)
    {
      cin>>bb[i];
      if(aa[i]==bb[i])
      {
        sm++;seg[i/sq]++;
      }
      mp[i/sq][bb[i]]++;
    }
    while(q--)
    {
      int x,y,z;cin>>x>>y>>z;
      int lt=x^sm,rt=y^sm,cc=z^sm,psm=0,nsm=0;
      for( ;lt<=min(n,rt);lt++)
      {
        int sg=lt/sq;
        if(lt%sq==0)
        {
          if(sg)seg[sg-1]-=psm+nsm;
          break;
        }
        if(lz[sg]!=-1)
        {
          for(int i=max(1,sg*sq);i<min(((sg+1)*sq),n+1);i++)
            aa[i]=lz[sg];
          lz[sg]=-1;
        }
        if(aa[lt]==bb[lt])psm++;aa[lt]=cc;
        if(aa[lt]==bb[lt])nsm++;
      }
      int t1=0,t2=0;
      for( ;rt>=max(1,lt);rt--)
      {
        int sg=rt/sq;
        if(lz[sg]!=-1)
        {
          for(int i=max(1,sg*sq);i<min(((sg+1)*sq),n+1);i++)
            aa[i]=lz[sg];
          lz[sg]=-1;
        }
        if(aa[rt]==bb[rt])psm++,t1++;aa[rt]=cc;
        if(aa[rt]==bb[rt])nsm++,t2++;
        if(rt%sq==0)
        {
          seg[sg]-=t1+t2;
          rt--;break;
        }
      }
      if(rt>lt)
      {
        for(int i=lt/sq;i<=rt/sq;i++)
        {
          psm+=seg[i];nsm+=mp[i][cc];
          seg[i]=mp[i][cc];lz[i]=cc;
        }
      }
      sm=sm-psm+nsm;
      cout<<sm<<endl;
    }
  }
  return 0;
}