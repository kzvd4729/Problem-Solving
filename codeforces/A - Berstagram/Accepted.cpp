/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/27/2019 16:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 140 ms                                          memory_used: 15700 KB                             
*  problem: https://codeforces.com/contest/1250/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int pos[N+2],aa[N+2],mn[N+2],mx[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,m;cin>>n>>m;
  for(int i=1;i<=n;i++)pos[i]=aa[i]=mn[i]=mx[i]=i;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;
    int p=pos[x];if(p==1)continue;
     int above=aa[p-1];
    pos[above]++;pos[x]--;
    swap(aa[p],aa[p-1]);
    mn[above]=min(mn[above],pos[above]);
    mx[above]=max(mx[above],pos[above]);
    mn[x]=min(mn[x],pos[x]);
    mx[x]=max(mx[x],pos[x]);
  }
  for(int i=1;i<=n;i++)
    cout<<mn[i]<<" "<<mx[i]<<"\n";
  cout<<endl;
  return 0;
}