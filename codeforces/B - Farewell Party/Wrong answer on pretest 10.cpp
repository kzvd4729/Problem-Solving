/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/16/2018 20:52                        
*  solution_verdict: Wrong answer on pretest 10              language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1081/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2],ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];aa[i]=n-aa[i];
  }
  sort(aa+1,aa+n+1);
  int cl=1;int f=0;
  for(int i=1;i<=n; )
  {
    int x=aa[i];
    for(int j=i;j<i+aa[i];j++)
    {
      if(aa[j]!=x)f=1;
      ans[j]=cl;
    }
    i+=aa[i];cl++;
  }
  if(f)cout<<"Impossible"<<endl;
  else
  {
    cout<<"Possible"<<endl;
    for(int i=1;i<=n;i++)
      cout<<ans[i]<<" ";
    cout<<endl;
  }
  return 0;
}