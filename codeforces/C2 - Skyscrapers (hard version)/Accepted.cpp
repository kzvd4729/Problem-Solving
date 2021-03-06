/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/26/2020 01:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 296 ms                                          memory_used: 16100 KB                             
*  problem: https://codeforces.com/contest/1313/problem/C2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;vector<long>aa(n+4),lft(n+4),rgt(n+4);
  for(int i=1;i<=n;i++)cin>>aa[i];
   stack<pair<int,int> >st;
  for(int i=1;i<=n;i++)
  {
    while(st.size())
    {
      if(st.top().first>=aa[i])st.pop();
      else break;
    }
    if(st.size()==0)lft[i]=1LL*aa[i]*i;
    else lft[i]=1LL*(i-st.top().second)*aa[i]+lft[st.top().second];
    st.push({aa[i],i});
  }
  // for(int i=1;i<=n;i++)cout<<lft[i]<<" ";
  //   cout<<endl;
  while(st.size())st.pop();
   for(int i=n;i>=1;i--)
  {
    while(st.size())
    {
      if(st.top().first>=aa[i])st.pop();
      else break;
    }
    if(st.size()==0)rgt[i]=1LL*aa[i]*(n-i+1);
    else rgt[i]=1LL*(st.top().second-i)*aa[i]+rgt[st.top().second];
    st.push({aa[i],i});
  }
  long mx=0,id=-1;
  for(int i=1;i<=n;i++)
  {
    long now=lft[i]+rgt[i]-aa[i];
    if(now>mx)mx=now,id=i;
  }
  for(int i=id+1;i<=n;i++)
    aa[i]=min(aa[i],aa[i-1]);
  for(int i=id-1;i>=1;i--)
    aa[i]=min(aa[i],aa[i+1]);
  for(int i=1;i<=n;i++)
    cout<<aa[i]<<" ";
  cout<<endl;
  return 0;
}