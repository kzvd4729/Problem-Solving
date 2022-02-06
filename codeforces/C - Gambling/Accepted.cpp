/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/06/2018 22:07                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 93 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/1038/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e5;
long a[N+2],b[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   long n;cin>>n;
  for(long i=1;i<=n;i++)
    cin>>a[i];
  for(long i=1;i<=n;i++)
    cin>>b[i];
  sort(a+1,a+n+1);sort(b+1,b+n+1);
  long id1=n,id2=n,cnt=1;long s1=0,s2=0;
  while(id1>=1||id2>=1)
  {
    if(cnt%2)
    {
      if(id1>=1&&id2>=1)
      {
        if(a[id1]>b[id2])s1+=a[id1--];
        else id2--;
      }
      else if(id1>=1)s1+=a[id1--];
      else id2--;
    }
    else
    {
      if(id1>=1&&id2>=1)
      {
        if(b[id2]>a[id1])s2+=b[id2--];
        else id1--;
      }
      else if(id2>=1)s2+=b[id2--];
      else id1--;
    }
    cnt++;
  }
  cout<<s1-s2<<endl;
  return 0;
}