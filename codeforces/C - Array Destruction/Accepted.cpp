/****************************************************************************************
*  @author: * kzvd4729                                       created: Jan/19/2021 21:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 468 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1474/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9,mod=1e9+7;
int a[N+2],n;
vector<pair<int,int> >ans;
bool ck(int x)
{
  multiset<int>st;ans.clear();
  for(int i=1;i<=n;i++)st.insert(a[i]);
   while((int)st.size())
  {
    int b=*st.rbegin();st.erase(st.find(b));
    if(st.find(x-b)==st.end())return false;
     st.erase(st.find(x-b));ans.push_back({b,x-b});
    x=b;
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    cin>>n;n+=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
     int f=0,x;
    for(int i=1;i<n;i++)
    {
      if(ck(a[i]+a[n])){x=a[i]+a[n];f=1;break;}
    }
    if(f==0)cout<<"NO\n";
    else
    {
      cout<<"YES\n"<<x<<'\n';
      for(auto x:ans)cout<<x.first<<" "<<x.second<<'\n';
    }
  }
  return 0;
}