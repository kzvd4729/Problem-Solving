/****************************************************************************************
*  @author: kzvd4729                                         created: 29-02-2020 21:53:36                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 1.03 sec                                        memory_used: 22.9M                                
*  problem: https://www.codechef.com/LTIME81A/problems/MONSTBAT
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;long s1=0,s2=0;
    for(int i=1;i<=n;i++)cin>>aa[i],s1+=aa[i];string a;cin>>a;
    for(int i=1;i<=m;i++)cin>>bb[i],s2+=bb[i];string b;cin>>b;
    multiset<int>adf,aat,bdf,bat;
    for(int i=0;i<a.size();i++)
    {
      if(a[i]=='A')aat.insert(aa[i+1]);
      else adf.insert(aa[i+1]);
    }
    for(int i=0;i<b.size();i++)
    {
      if(b[i]=='A')bat.insert(bb[i+1]);
      else bdf.insert(bb[i+1]);
    }
    int tr=0;long c=s1-s2,ans=s1-s2,mn=1LL*inf*inf,mx=-1LL*inf*inf;
    while(true)
    {
      if(tr==0)
      {
        mx=max(mx,c);ans=max(ans,min(c,mn));
        if(aat.size()==0||bdf.size()==0)break;
        int vl=*aat.begin();aat.erase(aat.find(vl));
        adf.insert(vl);
        int dl=*bdf.rbegin();bdf.erase(bdf.find(dl));
        c+=dl;
      }
      else
      {
        mn=min(mn,c);ans=min(ans,max(c,mx));
        if(bat.size()==0||adf.size()==0)break;
        int vl=*bat.begin();bat.erase(bat.find(vl));
        bdf.insert(vl);
        int dl=*adf.rbegin();adf.erase(adf.find(dl));
        c-=dl;
      }
      tr^=1;
    }
    cout<<ans<<"\n";
  }
  return 0;
}