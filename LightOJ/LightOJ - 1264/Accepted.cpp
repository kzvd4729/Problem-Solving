/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-01 16:49:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 545                                        memory_used (MB): 2.3                             
*  problem: https://vjudge.net/problem/LightOJ-1264
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int mt[14+2][14+2],cnt[(1<<14)+2];
void PB(int x)//print in binary format
{
  cerr<<setw(5)<<x<<" = ";vector<int>v;
  while(x){v.push_back(x%2);x/=2;}
  for(int i=0;i<v.size();i++)cerr<<v[i];
  //cerr<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        cin>>mt[i][j];
    }
    memset(cnt,0,sizeof(cnt));
    for(int msk=1;msk<(1<<n);msk++)
    {
      int i=31-__builtin_clz(msk);
      cnt[msk]=cnt[msk^(1<<i)];
      for(int j=0;j<n;j++)
      {
        if(msk&(1<<j))
          cnt[msk]+=mt[i][j]+mt[j][i];
      }
      //PB(msk);cout<<" "<<cnt[msk]<<endl;
    }
    for(int msk=1;msk<(1<<n);msk++)
    {
      for(int sub=msk;sub>0;sub=(sub-1)&msk)
        cnt[msk]=min(cnt[msk],cnt[sub]+cnt[(msk^sub)]);
    }
    cout<<"Case "<<++tc<<": "<<cnt[(1<<n)-1]<<"\n";
  }
  return 0;
}