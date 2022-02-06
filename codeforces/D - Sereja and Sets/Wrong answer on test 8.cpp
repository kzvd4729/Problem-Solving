/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/13/2018 16:14                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/367/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int arr[N+2],cnt[22];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,d,ans=1,msk=0;cin>>n>>m>>d;
  for(int i=0;i<m;i++)
  {
    int x;cin>>x;
    while(x--)
    {
      int z;cin>>z;
      arr[z]=i;
    }
  }
  for(int i=1;i<=d;i++)
    cnt[arr[i]]++;
  for(int i=0;i<m;i++)
    if(cnt[i]==0)msk|=(1<<i);
  for(int i=d+1;i<=n;i++)
  {
    cnt[arr[i]]++;cnt[arr[i-d]]--;
    if(cnt[arr[i-d]]==0)msk|=(1<<arr[i-d]);
    if(msk==((1<<m)-1))ans++,msk=0;
  }
  cout<<ans<<endl;
  return 0;
}