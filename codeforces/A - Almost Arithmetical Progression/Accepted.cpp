/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2019 19:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 12200 KB                             
*  problem: https://codeforces.com/contest/256/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>v;int ans=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;po[x].push_back(i);
    v.push_back(x);ans=max(ans,(int)po[x].size());
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  n=v.size();
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int x=v[i],y=v[j],ls,ii=0,jj=0,now=1;
      if(po[x][0]<po[y][0])ii=1,ls=i;
      else jj=1,ls=j;
      while(true)
      {
        if(ii>=po[x].size()||jj>=po[y].size())break;
        if(ls==i)
        {
          if(po[y][jj]<po[x][ii])
            now++,jj++,ls=j;
          else ii++;
        }
        else
        {
          if(po[x][ii]<po[y][jj])
            now++,ii++,ls=i;
          else jj++;
        }
      }
      if(ls==i&&jj<po[y].size())now++;
      if(ls==j&&ii<po[x].size())now++;
      ans=max(ans,now);
    }
  }
  cout<<ans<<endl;
  return 0;
}