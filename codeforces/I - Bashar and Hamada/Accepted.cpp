/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/08/2019 16:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 265 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/gym/102263/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
 #define SP(x) cerr<<#x<<" = "<<x<<endl
#define DP(x) cerr<<#x<<" = "<<x.first<<" "<<x.second<<endl
#define F cerr<<"flag"<<endl
template<typename T>//container
void _p(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
const int N=1e6;
 int pr[N+2],aa[N+2];
long ok[N+2];
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=0;i<n;i++)cin>>aa[i];
 //  for(int i=0;i<(1<<n);i++)
//  {
//    int cnt=__builtin_popcount(i);
//    if(cnt<2)continue;
//    vector<int>v;int ans=0;
//    for(int j=0;j<n;j++)
//      if(i&(1<<j))v.push_back(aa[j]);
//    for(int j=0;j<v.size();j++)
//      for(int k=j+1;k<v.size();k++)
//        ans+=abs(v[j]-v[k]);
//    pr[cnt]=max(pr[cnt],ans);
//  }
//  for(int i=2;i<=n;i++)
//    cout<<pr[i]<<" ";
//  cout<<endl;
  sort(aa,aa+n);
  long ad=0;int pt=0;
  for(int i=2;i<=n;i+=2)
  {
    ad+=(aa[n-1-pt]-aa[pt])*1LL;pt++;
    ok[i]=ok[i-1]+ad;ok[i+1]=ok[i]+ad;
  }
//  for(int i=2;i<=n;i++)
//    if(pr[i]!=ok[i])assert(0);
  for(int i=2;i<=n;i++)
    cout<<ok[i]<<" ";
  cout<<endl;
  return 0;
}