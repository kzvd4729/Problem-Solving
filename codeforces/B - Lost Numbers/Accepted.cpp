/****************************************************************************************
*  @author: kzvd4729                                         created: May/15/2019 20:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1167/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],ans[N+2];
pair<int,int>_find(int x)
{
  for(int i=1;i<=6;i++)
  {
    for(int j=i+1;j<=6;j++)
    {
      if(aa[i]*aa[j]==x)return {aa[i],aa[j]};
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  aa[1]=4;aa[2]=8;aa[3]=15;aa[4]=16;aa[5]=23;aa[6]=42;
   cout<<"? 1 2"<<endl;fflush(stdout);
  int a12;cin>>a12;
   cout<<"? 2 3"<<endl;fflush(stdout);
  int a23;cin>>a23;
   pair<int,int>on=_find(a12);
  pair<int,int>tw=_find(a23);
   if(tw.first==on.first||tw.first==on.second)
  {
    ans[2]=tw.first;
    ans[1]=a12/tw.first;
    ans[3]=a23/tw.first;
  }
  else
  {
    ans[2]=tw.second;
    ans[1]=a12/tw.second;
    ans[3]=a23/tw.second;
  }
    cout<<"? 4 5"<<endl;fflush(stdout);
  int a45;cin>>a45;
   cout<<"? 5 6"<<endl;fflush(stdout);
  int a56;cin>>a56;
   on=_find(a45);tw=_find(a56);
   if(tw.first==on.first||tw.first==on.second)
  {
    ans[5]=tw.first;
    ans[4]=a45/tw.first;
    ans[6]=a56/tw.first;
  }
  else
  {
    ans[5]=tw.second;
    ans[4]=a45/tw.second;
    ans[6]=a56/tw.second;
  }
   cout<<"!";
  for(int i=1;i<=6;i++)
    cout<<" "<<ans[i];
  fflush(stdout);
   return 0;
}