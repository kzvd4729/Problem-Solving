/****************************************************************************************
*  @author: kzvd4729                                         created: 09-12-2018 22:16:25                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/DEC18A/problems/INTXOR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int ask(int i,int j,int k)
{
  cout<<1<<" "<<i<<" "<<j<<" "<<k<<endl;
  fflush(stdout);
  int x;cin>>x;return x;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    int one=ask(1,2,3);
    int two=ask(2,3,4);
    int thr=one^two;
    aa[5]=ask(1,4,5)^thr;
    aa[6]=ask(1,4,6)^thr;
    for(int i=7;i<=n;i++)
      aa[i]=ask(i-2,i-1,i)^(aa[i-2]^aa[i-1]);
    aa[2]=ask(2,n-1,n)^(aa[n-1]^aa[n]);
    aa[3]=ask(3,5,n)^(aa[5]^aa[n]);
    aa[1]=one^(aa[2]^aa[3]);
    aa[4]=two^(aa[3]^aa[3]);
    cout<<2;
    for(int i=1;i<=n;i++)
      cout<<" "<<aa[i];
    cout<<endl;
    fflush(stdout);
    int x;cin>>x;
  }
  return 0;
}