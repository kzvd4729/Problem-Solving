/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 21:06                        
*  solution_verdict: Wrong answer on pretest 5               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 8100 KB                              
*  problem: https://codeforces.com/contest/967/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const double eps=0.000000001;
int n;
double xx,a,b,yy;
struct data
{
  double vl;
  int id;
}arr[300005];
bool cmp(data A,data B)
{
  return A.vl<B.vl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>a>>b;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i].vl;
    arr[i].id=i;
  }
  sort(arr+1,arr+n+1,cmp);
   for(int i=1;i<n;i++)
  {
    xx=(a*1.00)/(i*1.00);
    yy=(b*1.00)/((n-i)*1.00);
     if(xx<=arr[1].vl&&yy<=arr[i+1].vl)
    {
      cout<<"Yes"<<endl;
      cout<<i<<" "<<n-i<<endl;
      for(int j=1;j<=i;j++)
        cout<<arr[j].id<<" ";
      cout<<endl;
      for(int j=i+1;j<=n;j++)
        cout<<arr[j].id<<" ";
      cout<<endl;
      return 0;
    }
  }
  swap(a,b);
  for(int i=1;i<n;i++)
  {
    xx=(a*1.00)/(i*1.00);
    yy=(b*1.00)/((n-i)*1.00);
     if(xx<=arr[1].vl&&yy<=arr[i+1].vl)
    {
      cout<<"Yes"<<endl;
      cout<<n-i<<" "<<i<<endl;
      for(int j=i+1;j<=n;j++)
        cout<<arr[j].id<<" ";
      cout<<endl;
      for(int j=1;j<=i;j++)
        cout<<arr[j].id<<" ";
      cout<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}