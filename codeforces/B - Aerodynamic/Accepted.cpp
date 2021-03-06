/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 16:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 139 ms                                          memory_used: 15100 KB                             
*  problem: https://codeforces.com/contest/1299/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int x[N+2],y[N+2];
long dist(int i,int j)
{
  return 1LL*(x[i]-x[j])*(x[i]-x[j])+1LL*(y[i]-y[j])*(y[i]-y[j]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;set<vector<long> >st;
  for(int i=0;i<n;i++)
  {
    cin>>x[i]>>y[i];if(i==0)continue;
    int a=x[i]-x[i-1],b=y[i]-y[i-1];
     int gc=__gcd(a,b);
    a/=gc,b/=gc;if(a<0)a*=-1,b*=-1;
     st.insert({a,b,dist(i,i-1)});
  }
  int a=x[n-1]-x[0],b=y[n-1]-y[0];
  int gc=__gcd(a,b);
  a/=gc,b/=gc;if(a<0)a*=-1,b*=-1;
   st.insert({a,b,dist(0,n-1)});
   if((n%2==0)&&(st.size()==n/2))cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}