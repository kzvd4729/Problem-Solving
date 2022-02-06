/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/22/2019 11:48                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 280 ms                                          memory_used: 14300 KB                             
*  problem: https://codeforces.com/contest/1252/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,q;cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>aa[i];
  for(int i=1;i<=n;i++)cin>>bb[i];
   set<int>a[2],b[2];
  a[0].insert(n+1),a[0].insert(0);
 a[1].insert(n+1),a[1].insert(0);
 b[0].insert(n+1),b[0].insert(0);
 b[1].insert(n+1),b[1].insert(0);
  for(int i=1;i<=n;i++)
  a[aa[i]%2].insert(i);
 for(int i=1;i<=n;i++)
  b[bb[i]%2].insert(i);
 while(q--)
 {
  int i,j,k,l;cin>>i>>j>>k>>l;
   auto it=b[(bb[j]%2)^1].lower_bound(j);
  int rt=*it;rt--;
   it=b[(bb[j]%2)^1].lower_bound(j);it--;
  int lt=*it;lt++;
   it=a[(aa[i]%2)^1].lower_bound(i);
  int dw=*it;dw--;
   it=a[(aa[i]%2)^1].lower_bound(i);it--;
  int up=*it;up++;
   if(k>=up&&k<=dw&&l>=lt&&l<=rt)cout<<"YES\n";
  else cout<<"NO\n";  
 }
  return 0;
}