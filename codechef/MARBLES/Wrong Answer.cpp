/****************************************************************************************
*  @author: kzvd4729                                         created: 02-09-2019 16:22:19                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/problems/MARBLES
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
/*int ncr[1000+2][1000+2];
void NCR(int n)
{
  for(int i=1;i<=n;i++)
    ncr[i][0]=1;
  ncr[1][1]=1;
  for(int i=2;i<=n;i++)
    for(int j=1;j<=n;j++)
      ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
}*/
long ncr(long n,long k)
{
  long a=k,b=n-k;
  if(a<b)swap(a,b);
  long fac=1;
  for(long i=a+1;i<=n;i++)
  {
    fac*=i;
    while(b>1)
    {
      if(fac%b==0)
      {
        fac/=b;b--;
      }
      else break;
    }
  }
  return fac;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b;cin>>a>>b;
    cout<<ncr(a-1,b-1)<<"\n";
  }
  return 0;
}