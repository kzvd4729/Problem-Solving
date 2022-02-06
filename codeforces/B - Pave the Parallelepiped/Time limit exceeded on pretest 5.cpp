/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/13/2018 21:47                        
*  solution_verdict: Time limit exceeded on pretest 5        language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 15000 KB                             
*  problem: https://codeforces.com/contest/1007/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int t,fr[N+2],cnt[4],a,b,c;
vector<int>vv[N+2];
map<pair<pair<int,int>,int>,int>mp;
void divisors(void)
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
    {
      vv[j].push_back(i);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   divisors();
   cin>>t;
  while(t--)
  {
    cin>>a>>b>>c;
    mp.clear();
    for(int i=0;i<vv[a].size();i++)
    {
      for(int j=0;j<vv[b].size();j++)
      {
        for(int k=0;k<vv[c].size();k++)
        {
          cnt[1]=vv[a][i];
          cnt[2]=vv[b][j];
          cnt[3]=vv[c][k];
          sort(cnt+1,cnt+4);
          mp[{{cnt[1],cnt[2]},cnt[3]}]=1;
        }
      }
    }
    cout<<mp.size()<<endl;
  }
   return 0;
}