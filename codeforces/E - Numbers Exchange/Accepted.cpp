/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/10/2018 14:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 19800 KB                             
*  problem: https://codeforces.com/contest/746/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,m,arr[N+2],o,e;
set<int>odd,even,rodd,reven;
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    if(arr[i]%2)o++;
    else e++;
    if(mp[arr[i]])
    {
      if(arr[i]%2)rodd.insert(i);
      else reven.insert(i);
    }
    mp[arr[i]]=1;
  }
  for(int i=m;i>=1;i--)
  {
    if(mp[i])continue;
    if(i%2)odd.insert(i);
    else even.insert(i);
    if(odd.size()>n&&even.size()>n)break;
  }
  if(n%2)cout<<-1<<endl,exit(0);
  int ans=0;
  while(true)
  {
    int p;
    if(reven.size())
    {
      p=*reven.begin();
      reven.erase(p);
      if(o<e&&odd.size())
      {
        arr[p]=*odd.begin();
        odd.erase(*odd.begin());
        o++,e--,ans++;
      }
      else if(even.size())
      {
        arr[p]=*even.begin();
        even.erase(*even.begin());
        ans++;
      }
      else break;
    }
    else if(rodd.size())
    {
      p=*rodd.begin();
      rodd.erase(p);
      if(e<o&&even.size())
      {
        arr[p]=*even.begin();
        even.erase(*even.begin());
        e++,o--,ans++;
      }
      else if(odd.size())
      {
        arr[p]=*odd.begin();
        odd.erase(*odd.begin());
        ans++;
      }
      else break;
    }
    else break;
  }
  if(rodd.size()||reven.size())cout<<-1<<endl,exit(0);
  for(int i=1;i<=n;i++)
  {
    if(arr[i]%2)
    {
      if(e<o&&even.size())
      {
        arr[i]=*even.begin();
        even.erase(*even.begin());
        e++,o--,ans++;
      }
    }
    else
    {
      if(o<e&&odd.size())
      {
        arr[i]=*odd.begin();
        odd.erase(*odd.begin());
        o++,e--,ans++;
      }
    }
  }
  if(o!=e)cout<<-1<<endl,exit(0);
  cout<<ans<<endl;
  for(int i=1;i<=n;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}
 