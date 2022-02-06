/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/16/2019 22:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 577 ms                                          memory_used: 51700 KB                             
*  problem: https://codeforces.com/contest/665/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
 /************* Prime Counting Function *************/
const int MAXN=1000000,PHI_N=100000,PHI_K=100;
int Pcnt,Primes[MAXN+2],Counter[MAXN+2],IsPrime[MAXN+2];
void Seive(int n)
{
  IsPrime[1]=1;int sq=sqrt(n+1);
  for(int i=4;i<=n;i+=2)IsPrime[i]=1;
  for(int i=3;i<=n;i+=2)
  {
    if(IsPrime[i])continue;if(i>sq)continue;
    for(int j=i*i;j<=n;j+=2*i)
      IsPrime[j]=1;
  }
  for(int i=1;i<=n;i++)
  {
    if(!IsPrime[i])Primes[Pcnt++] = i;
      Counter[i]=Pcnt;
  }
}
int phidp[PHI_N+2][PHI_K+2];
void LehmerInit(void)
{
  Seive(MAXN);int k,n;
  for(n=0;n<PHI_N;n++)phidp[n][0]=n;
  for(k=1;k<PHI_K;k++)
  {
    for(n=0;n<PHI_N;n++)
    {
      phidp[n][k]=phidp[n][k-1]-phidp[n/Primes[k-1]][k-1];
    }
  }
}
long LehPhi(long n, int k)
{
  if(n<PHI_N&&k<PHI_K)return phidp[n][k];
  if(k==1)return((++n)>>1);
  if(Primes[k-1]>=n)return 1;
  return LehPhi(n,k-1)-LehPhi(n/Primes[k-1],k-1);
}
long Lehmer(long n)
{
  if(n<MAXN)return Counter[n];
  long w,ret=0;int i,j,a,b,c,lim;
  b=sqrt(n),c=Lehmer(cbrt(n)),a=Lehmer(sqrt(b)),b=Lehmer(b);
  ret=LehPhi(n,a)+(((b+a-2)*(b-a+1))>>1);
  for(i=a;i<b;i++)
  {
    w=n/Primes[i];
    lim=Lehmer(sqrt(w)),ret-=Lehmer(w);
    if(i>c)continue;
    for(j=i;j<lim;j++)
      ret+=j-Lehmer(w/Primes[j]);
  }
  return ret;
}
////////////////////////////////////////////////////////////
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,ans=0;cin>>n;LehmerInit();
  for(int i=0; ;i++)
  {
    long x=Primes[i];
    if(x*x*x>n)break;ans++;
  }
  for(int i=0; ;i++)
  {
    long x=Primes[i];
    if(x*x>n)break;
    ans+=Lehmer(n/x)-Lehmer(x);
  }
  cout<<ans<<endl;
  return 0;
}