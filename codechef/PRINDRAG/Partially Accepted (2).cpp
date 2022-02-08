/****************************************************************************************
*  @author: kzvd4729                                         created: 03-08-2018 19:39:02                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.26 sec                                        memory_used: 24.9M                                
*  problem: https://www.codechef.com/AUG18A/problems/PRINDRAG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=5e5;
long t,n,pp,arr[N+2],mx,x,xx;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n>>pp;
    set<pair<long,long> >st,tmp;
    pair<long,long>p;
    for(long i=1;i<=n;i++)
    {
      cin>>x;
      st.insert({-x,i});
    }
    p=*st.begin();
    st.erase(p);
    mx=-p.first;
    if(mx>=pp)
    {
      for(long i=1;i<=n;i++)
        cout<<n<<" ";
      cout<<endl;
      continue;
    }
    long cnt1=0,cnt2=0,sum1=mx,sum2=mx,id=0;
    while(st.size())
    {
      p=*st.begin();
      xx=-p.first;
      if(sum1+xx<pp)
      {
        sum1+=xx;
        cnt1++;
        st.erase(p);
      }
      else break;
    }
    set<pair<long,long> >::iterator it;
    p={0,0};
    for(it=st.begin();it!=st.end();it++)
    {
      if(-it->first+sum1>=pp)
        p=*it;
    }
    sum1+=(-p.first);
    if(st.find(p)!=st.end())st.erase(p);
    cnt1++;
    while(st.size())
    {
      p=*st.begin();
      sum2+=(-p.first);
      st.erase(p);
      cnt2++;
      if(sum2>=pp)break;
    }
    for(long i=1;i<=n;i++)
    {
      long rgt=n-i;
      long lft=i-1;
      long ans=0;
      if(lft>rgt)swap(lft,rgt);
      if(sum1>=pp&&cnt1<=rgt)ans+=(rgt-cnt1+1);
      if(sum2>=pp&&cnt2<=lft)ans+=(lft-cnt2+1);
      cout<<ans<<" ";
    }
    cout<<endl;
  }
  return 0;
}