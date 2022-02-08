/****************************************************************************************
*  @author: kzvd4729                                         created: 24-11-2018 21:04:23                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.19 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/LTIME66A/problems/BPS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=20;
int lt[N+2],rt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    vector<int>v,aa,bb,cc;
    int n,m,cnt=0;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;aa.push_back(x);
    }
    bb=aa;
    for(int i=1;i<=m;i++)
    {
      cin>>lt[i]>>rt[i];
    }
    for(int i=1;i<=m;i++)
    {
      reverse(bb.begin()+lt[i]-1,bb.begin()+rt[i]);
    }
    // for(auto x:bb)
    //   cout<<x<<" ";
    // cout<<endl;
    for(int i=1;i<=m;i++)v.push_back(i);
    do
    {
      cc=aa;
      for(auto i:v)
        reverse(cc.begin()+lt[i]-1,cc.begin()+rt[i]);
      if(cc==bb)cnt++;
    }while(next_permutation(v.begin(),v.end()));
    int q=1;
    for(int i=2;i<=m;i++)q*=i;
    int gcd=__gcd(cnt,q);
    cout<<cnt/gcd<<"/"<<q/gcd<<"\n";
  }
  return 0;
}