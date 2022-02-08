/****************************************************************************************
*  @author: kzvd4729                                         created: 29-09-2018 20:37:56                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 16.8M                                
*  problem: https://www.codechef.com/LTIME64A/problems/OPPOSITE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int arr[N+2],f;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;f=0;
    for(int i=1;i<=n;i++)
      cin>>arr[i];
    if(n%2)f=1;
    for(int i=1;i<=n/2;i++)
    {
      if(arr[i]==-1)
      {
        if(arr[i+n/2]!=-1)arr[i]=arr[i+n/2];
        else arr[i]=1,arr[i+n/2]=1;
      }
      else
      {
        if(arr[i+n/2]==-1)arr[i+n/2]=arr[i];
        else if(arr[i]!=arr[i+n/2])f=1;
      }
    }
    if(f)cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl;
      for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
      cout<<endl;
    }
  }
  return 0;
}