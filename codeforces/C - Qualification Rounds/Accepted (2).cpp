/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:46                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 2200 KB                              
*  problem: https://codeforces.com/contest/868/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2][5],n,m;
set<int>st;
void dfs(int ii,int tst,int msk)
{
  if(ii>=m)
  {
    if(st.find(msk)!=st.end())
    {
      //cout<<tst<<" "<<msk<<endl;
      cout<<"YES"<<endl,exit(0);
    }
    return ;
  }
  dfs(ii+1,tst,msk);
  if(!(tst&(1<<ii)))
    dfs(ii+1,tst,msk|(1<<ii));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    int f=0;int msk=0;
    for(int j=1;j<=m;j++)
    {
      int x;cin>>x;f|=x;
      msk|=(x<<(j-1));
    }
    st.insert(msk);
    if(!f)cout<<"YES"<<endl,exit(0);
  }
  //cout<<"here"<<endl;
  for(auto x:st)
    dfs(0,x,0);
  cout<<"NO"<<endl;
  return 0;
}