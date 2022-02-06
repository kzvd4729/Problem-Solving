/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/16/2019 20:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1154/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;set<int>st;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;st.insert(x);
  }
  if(st.size()==1)cout<<0<<endl;
  else if(st.size()==2)
  {
    int a=*st.begin();st.erase(a);
    int b=*st.begin();st.erase(b);
    if((b-a)%2==0)cout<<(b-a)/2<<endl;
    else cout<<b-a<<endl;
  }
  else if(st.size()==3)
  {
    int a=*st.begin();st.erase(a);
    int b=*st.begin();st.erase(b);
    int c=*st.begin();st.erase(c);
     if(b-a==c-b)cout<<b-a<<endl;
    else cout<<-1<<endl;
  }
  else cout<<-1<<endl;
  return 0;
}