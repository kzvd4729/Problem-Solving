/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2020 19:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 18300 KB                             
*  problem: https://codeforces.com/contest/634/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
void ya(){cout<<"YES\n",exit(0);}
void no(){cout<<"NO\n",exit(0);}
int aa[N+2],bb[N+2],cc[N+2],dd[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  int f=0;
  for(int i=1;i<=n;i++)cin>>aa[i],cc[i]=aa[i];
  for(int i=1;i<=n;i++)
  {
    cin>>bb[i];if(aa[i]!=bb[i])f=1;
    dd[i]=bb[i];
  }
  if(!f)ya();
  sort(cc+1,cc+n+1);sort(dd+1,dd+n+1);
  for(int i=1;i<=n;i++)if(cc[i]!=dd[i])no();
  if(cc[1])no();
   //cout<<"here"<<endl;
   vector<int>a,b;
  for(int i=1;i<=n;i++)
    if(aa[i])a.push_back(aa[i]);
  for(int i=1;i<=n;i++)
    if(bb[i])b.push_back(bb[i]);
  n=a.size();
   // for(auto x:b)cout<<x;
  //   cout<<endl;
   int id=-1;
  for(int i=0;i<n;i++)
    if(a[0]==b[i])id=i;
  for(int i=0;i<n;i++)
  {
    if(a[i]!=b[id])no();
    id++;if(id==n)id=0;
  }
  ya();
  return 0;
}