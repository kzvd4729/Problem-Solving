/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-11-25 22:18:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 842                                        memory_used (MB): 9.6                             
*  problem: https://vjudge.net/problem/LightOJ-1277
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int aa[N+2],bit[N+2],dp[N+2];
map<int,int>mp;
void upd(int x,int vl)
{
  for( ;x>0;x-=x&-x)
    bit[x]=max(bit[x],vl);
}
int qry(int x)
{
  int ret=0;
  for( ;x<=N;x+=x&-x)
    ret=max(ret,bit[x]);
  return ret;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n,q;scanf("%d%d",&n,&q);vector<int>v;
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&aa[i]);v.push_back(aa[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    mp.clear();int cnt=0;
    for(auto x:v)
      mp[x]=++cnt;
    memset(bit,0,sizeof(bit));
    for(int i=n;i>=1;i--)
    {
      int x=mp[aa[i]];
      dp[i]=qry(x+1)+1;upd(x,dp[i]);
    }
    printf("Case %d:\n",++tc);
    while(q--)
    {
      vector<int>v;
      int x;scanf("%d",&x);int last=-1e9;
      for(int i=1;i<=n;i++)
      {
        if(!x)break;
        if(dp[i]>=x&&aa[i]>last)
        {
          v.push_back(aa[i]);x--;
          last=aa[i];
        }
      }
      if(v.size()==0)printf("Impossible\n");
      else
      {
        printf("%d",v[0]);
        for(int i=1;i<v.size();i++)
          printf(" %d",v[i]);
        printf("\n");
      }
    }
  }
  return 0;
}