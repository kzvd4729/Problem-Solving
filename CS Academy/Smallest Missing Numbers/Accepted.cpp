/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 43 ms                                           memory_used: 776 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,m,x;
int arr[100005];
long add(long lt,long rt)
{
  return ((rt*(rt+1))/2)-((lt*(lt-1))/2);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  sort(arr+1,arr+n+1);
  arr[n+1]=2e9;
  long sum=0;
  int lt=1,rt;
  for(int i=1;i<=n+1;i++)
  {
    rt=arr[i]-1;
    if(rt>=lt)
    {
      if(rt-lt+1<m)
      {
        sum+=add(lt,rt);
        m-=(rt-lt+1);
      }
      else
      {
        rt=lt+m-1;
        sum+=add(lt,rt);
        break;
      }
    }
    lt=arr[i]+1;
  }
  cout<<sum<<endl;
  return 0;
}