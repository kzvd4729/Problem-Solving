/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-09-05 19:42:29                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12060
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
int tc,n;
int digit(int x)
{
  x=abs(x);
  int ret=0;
  while(x)
  {
    x/=10;ret++;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n)
  {
    if(!n)break;int sum=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      sum+=x;
    }
    int f=0;
    if(sum>=0)f=1;sum=abs(sum);
    cout<<"Case "<<++tc<<":"<<endl;
    if(sum%n==0)
    {
      if(sum>=0)cout<<sum/n<<endl;
      else cout<<"− "<<abs(sum/n)<<endl;
    }
    else if(sum<n)
    {
      int gcd=__gcd(sum,n);
      sum/=gcd;n/=gcd;
      if(f)
      {
        int dg=digit(n);
        for(int i=1;i<=dg-digit(sum);i++)
          cout<<" ";
        cout<<sum<<endl;
        for(int i=1;i<=dg;i++)
          cout<<"-";
        cout<<endl;
        cout<<n<<endl;
      }
      else
      {
        int dg=digit(n);
        for(int i=1;i<=dg-digit(sum)+2;i++)
          cout<<" ";
        cout<<sum<<endl;
        cout<<"− ";
        for(int i=1;i<=dg;i++)
          cout<<"-";
        cout<<endl;
        cout<<"  "<<n<<endl;
      }
    }
    else
    {
      int ex=sum/n;sum=sum-n*ex;
      int gcd=__gcd(sum,n);
      sum/=gcd;n/=gcd;
      if(f)
      {
        int dg=digit(n);
        for(int i=1;i<=dg-digit(sum)+digit(ex);i++)
          cout<<" ";
        cout<<sum<<endl;
        cout<<ex;
        for(int i=1;i<=dg;i++)
          cout<<"-";
        cout<<endl;
        for(int i=1;i<=digit(ex);i++)
          cout<<" ";
        cout<<n<<endl;
      }
      else
      {
        int dg=digit(n);
        for(int i=1;i<=dg-digit(sum)+2+digit(ex);i++)
          cout<<" ";
        cout<<sum<<endl;
        cout<<"− "<<ex;
        for(int i=1;i<=dg;i++)
          cout<<"-";
        cout<<endl;
        for(int i=1;i<=digit(ex);i++)
          cout<<" ";
        cout<<"  "<<n<<endl;
      }
    }
  }
  return 0;
}