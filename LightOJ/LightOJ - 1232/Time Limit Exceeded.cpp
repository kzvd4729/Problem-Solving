/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-20 20:27:40                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1232
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int arr[20],n,k,t,tc,half,f,ck;
map<int,int>mp;
vector<int>tmp;
void dfs(int id,int sum)
{
  if(sum>k)return ;
  if(sum==k)f=1;
  if(ck==0)mp[sum]=1;
  else if(mp[k-sum])f=1;
  if(id>=half)return ;
  dfs(id+1,sum+tmp[id]);
  dfs(id+1,sum+tmp[id]+tmp[id]);
  dfs(id+1,sum);
}
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    mp.clear();
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);
    tmp.clear();
    for(int i=0;i<n/2;i++)
      tmp.push_back(arr[i]);
    half=tmp.size();
    ck=0;
    f=0;
    dfs(0,0);
    tmp.clear();
    for(int i=n/2;i<n;i++)
      tmp.push_back(arr[i]);
    half=tmp.size();
    ck=1;
    if(f==0)dfs(0,0);
 
    if(f)printf("Case %d: Yes\n",++tc);
    else printf("Case %d: No\n",++tc);
  }
  return 0;
}