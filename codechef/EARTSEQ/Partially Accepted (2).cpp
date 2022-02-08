/****************************************************************************************
*  @author: kzvd4729                                         created: 12-01-2019 15:51:15                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.05 sec                                        memory_used: 23.3M                                
*  problem: https://www.codechef.com/JAN19A/problems/EARTSEQ
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,R=1e9;
int aa[N+2];
///////////////////////////////////
int Is_Prime[N+2];vector<int>Prime;
void Seive(void)
{
  Prime.push_back(2);Is_Prime[1]=1;
  for(int i=2;i<=N;i+=2)Is_Prime[i]=1;
  int sq=sqrt(N+1);
  for(int i=3;i<=N;i+=2)
  {
    if(Is_Prime[i])continue;Prime.push_back(i);
    if(i>sq)continue;
    for(int j=i*i;j<=N;j+=2*i)
      Is_Prime[j]=1;
  }
}
///////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  Seive();vector<int>pr=Prime;
  int t;cin>>t;
  //t=100000;
  while(t--)
  {
    int n;cin>>n;
    //for(int i=5;i<=100;i++)n=i;
    int df=1,pt=2;
    if(n==3)
    {
      cout<<"6 10 15"<<endl;
      continue;
    }
    if(n==4)
    {
      cout<<"374 595 1365 858"<<endl;
      continue;
    }
    aa[0]=6,aa[1]=15;int ls=5,f=0,in=2;
    while(true)
    {
      for(int i=++in;i<pr.size();i+=df)
      {
        long ml=((ls*1LL)*pr[i]);
        if(ml>R)break;
        aa[pt++]=ml;ls=pr[i];
        if(pt==n-2)
        {
          int nx=i+df;int a;
          if(nx<=pr.size())
          {
            long ml=((ls*1LL)*pr[nx]);
            if(ml<=R)a=pr[nx];
            else a=7;
          }
          aa[pt]=ls*a;
          aa[pt+1]=a*2;
          f=1;break;
        }
      }
      df++;if(f)break;
    }
        /*int ok=0;
    for(int i=0;i<n;i++)
    {
      int gc1=__gcd(aa[i],aa[(i+1)%n]);
      if(gc1==1)ok=1;
      if(__gcd(gc1,aa[(i+2)%n])>1)ok=1;
      int gc2=__gcd(aa[i],aa[(i-1+n)%n]);
      if(gc2==1)ok=1;
      if(__gcd(gc2,aa[(i-2+n)%n])>1)ok=1;
    }*/
    //if(ok)cout<<"NO"<<endl;
    //else cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
      cout<<aa[i]<<" ";
    cout<<endl;
  }
  return 0;
}