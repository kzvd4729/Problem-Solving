/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/27/2018 15:16                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/999/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,m,ans[N+2],prnt;
struct data
{
  int vl,id;
}arr[N+2];
bool cmp(data a,data b)
{
  return a.vl%m<b.vl%m;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].vl;
    arr[i].id=i;
  }
  sort(arr+1,arr+n+1,cmp);
   int lt=1,rt=n,nm=n/m;
  for(int i=0;i<m;i++)
  {
    int tmp=nm;
    while(tmp--)
    {
      if(arr[lt].vl%m==i)lt++;
      else if(arr[lt].vl%m<i)
      {
        prnt+=i-arr[lt].vl%m;
        arr[lt].vl+=i-arr[lt].vl%m;
        lt++;
      }
      else
      {
        prnt+=m+i-arr[rt].vl%m;
        arr[lt].vl+=m+i-arr[rt].vl%m;
        rt--;
      }
    }
  }
  for(int i=1;i<=n;i++)
    ans[arr[i].id]=arr[i].vl;
  cout<<prnt<<endl;
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
  cout<<endl;
  return 0;
}