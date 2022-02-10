/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-08 10:25:35                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 720                                        memory_used (MB): 11.5                            
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
        mn.erase({arr[i-d+1],i-d+1});
        mx.erase({-arr[i-d+1],i-d+1});
      }
    }
    printf("Case %d: %d\n",++tc,ans);
  }
  return 0;
}