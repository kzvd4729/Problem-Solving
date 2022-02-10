/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-08 10:13:58                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1093
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,n,d,x,arr[100005];
set<pair<int,int> >mn,mx;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf("%d",&t);
  while(t--)
  {
    scanf("%d%d",&n,&d);
    int ans=0;
    mn.clear();
    mx.clear();
    for(int i=1;i<=n;i++)
    {
      scanf("%d",&x);
      arr[i]=x;
      mn.insert({x,i});
      mx.insert({-x,i});
      if(i>=d)
      {
        int t1=-mx.begin()->first;
        int t2=mn.begin()->first;
        ans=max(ans,t1-t2);
      }
      if(i>d)
      {
        mn.erase({arr[i-d],i-d});
        mx.erase({-arr[i-d],i-d});
      }
    }
    printf("Case %d: %d\n",++tc,ans);
  }
  return 0;
}