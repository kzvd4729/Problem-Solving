/****************************************************************************************
*  @author: kzvd4729                                         created: May/09/2019 21:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1163/problem/B1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int fr[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;multiset<int>ok;int ans=1;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    if(ok.find(fr[x])!=ok.end())
      ok.erase(ok.find(fr[x]));
    fr[x]++;ok.insert(fr[x]);
        if(ok.size()==1)ans=i;
     if(ok.size()>=2)
    {
      int p=*ok.rbegin();ok.erase(ok.find(p));
      p--;
      if(*ok.rbegin()==p&&*ok.begin()==p)
        ans=i;
      ok.insert(p+1);
       p=*ok.begin();if(p!=1)continue;
      ok.erase(ok.find(p));
      if(*ok.begin()==*ok.rbegin())ans=i;
      ok.insert(p);
    }
  }
  cout<<ans<<endl;
  return 0;
}