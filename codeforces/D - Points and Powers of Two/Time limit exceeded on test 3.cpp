/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/01/2018 21:49                        
*  solution_verdict: Time limit exceeded on test 3           language: GNU C++11                               
*  run_time: 4000 ms                                         memory_used: 219200 KB                            
*  problem: https://codeforces.com/contest/988/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int R=1e9;
const int N=2e5;
int pw[34],n;
int arr[N+2];
map<int,int>vis;
pair<int,int>ans={R+1,R+1};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   pw[0]=1;
  for(int i=1;i<=30;i++)
    pw[i]=pw[i-1]*2;
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    vis[arr[i]]=1;
  }
  ans.first=arr[1];
  for(int i=1;i<=n;i++)
  {
    for(int p=0;p<=30;p++)
    {
      int pp=pw[p];
      if(vis[arr[i]+pp]&&vis[arr[i]-pp])
      {
        cout<<3<<endl;
        cout<<arr[i]-pp<<" "<<arr[i]<<" "<<arr[i]+pp<<endl;
        return 0;
      }
      if(vis[arr[i]+pp])
        ans={arr[i],arr[i]+pp};
      if(vis[arr[i]-pp])
        ans={arr[i],arr[i]-pp};
    }
  }
  if(ans.second==R+1)
  {
    cout<<1<<endl;
    cout<<ans.first<<endl;
    return 0;
  }
  cout<<2<<endl;
  cout<<ans.first<<" "<<ans.second<<endl;
  return 0;
}