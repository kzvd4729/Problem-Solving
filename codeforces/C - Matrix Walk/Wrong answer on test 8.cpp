/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/27/2018 18:11                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++17                               
*  run_time: 77 ms                                           memory_used: 11400 KB                             
*  problem: https://codeforces.com/contest/954/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,arr[2000005],c=1,tr;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>arr[i];
  for(int i=1;i<n;i++)if(arr[i]==arr[i+1])cout<<"NO"<<endl,exit(0);
  for(int i=1;i<n;i++)c=max(c,abs(arr[i]-arr[i+1]));
  tr=arr[1]%c;
  if(!tr)tr=c;
   for(int i=2;i<=n;i++)
  {
    if(arr[i-1]+1==arr[i])tr++;
    else if(arr[i-1]-1==arr[i])tr--;
    else if(abs(arr[i-1]-arr[i])!=c)cout<<"NO"<<endl,exit(0);
     if(tr>c||tr<1)cout<<"NO"<<endl,exit(0);
   }
  cout<<"YES"<<endl;
  cout<<1000000000<<" "<<c<<endl;
  return 0;
}