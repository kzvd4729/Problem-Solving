/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/09/2019 12:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 2300 KB                              
*  problem: https://codeforces.com/contest/1203/problem/D2
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
#define SP(x) cerr<<#x<<" = "<<x<<endl
#define DP(x) cerr<<#x<<" = "<<x.first<<" "<<x.second<<endl
#define F cerr<<"flag"<<endl
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<setw(2)<<x<<" ";
  cerr<<")"<<endl;
}
 const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string a,b;cin>>a>>b;int n=a.size(),m=b.size();
  vector<int>pre(n),suf(n);
  int pt=0;
  for(int i=0;i<n;i++)
  {
    if(pt<m&&a[i]==b[pt])pt++;
    pre[i]=pt-1;
  }
  pt=m-1;
  for(int i=n-1;i>=0;i--)
  {
    if(pt>-1&&a[i]==b[pt])pt--;
    suf[i]=pt+1;
  }
  //P(pre);P(suf);
   int ans=0,id;
  id=lower_bound(pre.begin(),pre.end(),m-1)-pre.begin();
  ans=max(ans,n-id-1);
  //SP(ans);
  id=upper_bound(suf.begin(),suf.end(),0)-suf.begin()-1;
  ans=max(ans,id);
   //SP(ans);
  for(int i=0;i<n;i++)
  {
    id=upper_bound(suf.begin(),suf.end(),pre[i]+1)-suf.begin()-1;
    ans=max(ans,id-i-1);
    //DP(make_pair(i,id));
  }
  cout<<ans<<endl;
  return 0;
}