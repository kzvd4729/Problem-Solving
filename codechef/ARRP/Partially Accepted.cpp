/****************************************************************************************
*  @author: kzvd4729                                         created: 31-03-2018 20:26:02                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.96 sec                                        memory_used: 99.3M                                
*  problem: https://www.codechef.com/LTIME58A/problems/ARRP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
long t,n,arr[N+2],qm[N+2],ans[N+2],x,xx;
map<long,long>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    mp.clear();
    memset(ans,0,sizeof(ans));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>arr[i];
      qm[i]=qm[i-1]+arr[i];
      mp[qm[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
      if(qm[n]%i)continue;
      x=qm[n]/i;
      xx=x;
      int f=0;
      for(xx=x;xx<=qm[n];xx+=x)
      {
        if(!mp[xx])
        {
          f=1;
          break;
          xx+=x;
        }
      }
      if(f==0)ans[i]=1;
    }
    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<endl;
  }
  return 0;
}