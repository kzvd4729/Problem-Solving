/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-12-01 19:16:44                      
*  solution_verdict: RE                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 142 ms                                          memory_used: 384 KB                               
*  problem: https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_f
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t1,t2,a1,a2,b1,b2;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;
   if(t1*a1+t2*a2==t1*b1+t2*b2)cout<<"infinity\n",exit(0);
   double a=0,b=0;int cnt=0,fl=0;
  for(int i=1;i<=10000000;i++)
  {
    double c,d,e,f;
    c=a+t1*a1,d=b+t1*b1;
     if((a>b&&c<d)||((a<b&&c>d)))cnt++;
     e=c+t2*a2,f=d+t2*b2;
     if((c>d&&e<f)||((c<d&&e>f)))cnt++;
     //cout<<a<<" "<<b<<" "<<e<<" "<<f<<endl;
    if(e<b||f<a){fl=1;break;}
     a=e,b=f;
     //cout<<a<<" "<<b<<endl;
  }
  if(!fl)assert(0);
  cout<<cnt<<endl;
  return 0;
}