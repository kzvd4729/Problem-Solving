/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2018 20:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1017/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int n,x,cnt;
struct data
{
  int sum,id;
}arr[N+2];
bool cmp(data a,data b)
{
  if(a.sum!=b.sum)return a.sum>b.sum;
  return a.id<b.id;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=4;j++)
    {
      cin>>x;
      arr[i].sum+=x;
    }
    arr[i].id=i;
  }
  sort(arr+1,arr+n+1,cmp);
  for(int i=1;i<=n;i++)
  {
    cnt++;
    if(arr[i].id==1)
    {
      cout<<cnt<<endl;
      return 0;
    }
  }
  return 0;
}