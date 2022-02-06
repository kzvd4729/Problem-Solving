/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/09/2019 17:38                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 530 ms                                          memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/1106/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************** Matrix Expo **************/
const int M=100;
const long Mod=998244353-1;
struct matrix
{
  long m[M+2][M+2];
  matrix()
  {
    memset(m,0,sizeof(m));
  }
};
matrix Multiply(matrix a,matrix b,int n)
{
  matrix c;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      for(int k=1;k<=n;k++)
        c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%Mod;
  return c;
}
matrix Expo(long x,matrix b,int n)
{
  matrix r;//if(x<0)assert(0);
  for(int i=1;i<=n;i++)r.m[i][i]=1;
  while(x)
  {
    if(x&1)r=Multiply(r,b,n);
    b=Multiply(b,b,n);x/=2;
  }
  return r;
}
//matrix*column_vector=function_column_vector
///////////////////////////////////////
  /************* Discrete Root **************/
long Bigmod(long b,long p,long mod)
{
  long ret=1LL;
  while(p)
  {
    if(p%2)ret=(ret*b)%mod;
    b=(b*b)%mod;p/=2;
  }
  return ret;
}
int Primitive_Root(int p)//p is prime
{
  vector<int>fac;int phi=p-1;
  int n=phi;int sq=sqrt(n+1);
  for(int i=2;i<=sq;i++)
  {
    if(n%i==0)fac.push_back(i);
    while(n%i==0)n/=i;
  }
  if(n>1)fac.push_back(n);
  for(int i=2;i<=p;i++)
  {
    bool ok=true;
    for(auto x:fac)
    {
      if(Bigmod(i,phi/x,p)==1)
      {
        ok=false;break;
      }
    }
    if(ok)return i;
  }
  return -1;
  /*all number from 1 to p-1 can be 
  represented by power of primitive root*/
}
long BsGs(long a,long b,long m)
{
  int n=sqrt(m+1);long an=1;
  for(int i=0;i<n;i++)an=(an*a)%m;
  map<int,int>mp;//unordered is good choice
  long cur=an;
  for(int i=1;i<=n;i++)
  {
    if(!mp.count(cur))
      mp[cur]=i;
    cur=(cur*an)%m;
  }
  cur=b;long mn=1e18;int f=0;
  for(int i=0;i<=n;i++)
  {
    if(mp.count(cur))
    {
      long ans=mp[cur]*n-i;
      if(ans<m)mn=min(mn,ans),f=1;
      //modify for largest/smallest solution
    }
    cur=(cur*a)%m;
  }
  if(!f)return -1;
  else return mn;
}
int Discrete_Root(int k,int b,int p)
{
  int g=Primitive_Root(p);
  int pw=BsGs(Bigmod(g,k,p),b,p);
  if(pw==-1)return -1;
  int a=Bigmod(g,pw,p);
  return a;
  /*int delta=(p-1)/__gcd(k,p-1);
  vector<int>ans;
  for(int cur=a%delta;cur<p-1;cur+=delta)
  ans.push_back(Bigmod(g,cur,p));
  sort(ans.begin(), ans.end());
  for(auto x:ans)cout<<x<<endl;*/
}
//Finds such a that (a^k)%p=b;
////////////////////////////////////////////
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int k;cin>>k;matrix b;
  for(int i=1;i<=k;i++)cin>>b.m[1][i];
  for(int i=2;i<=k;i++)b.m[i][i-1]=1;
   int n,m;cin>>n>>m;
  b=Expo(n-k,b,k);int pw=b.m[1][1];
   cout<<Discrete_Root(pw,m,Mod+1)<<endl;
   return 0;
}