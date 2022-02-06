/****************************************************************************************
*  @author: JU_Troubleshooer: tariqiitju, the0dd1out, kzvd4729 created: Oct/20/2018 14:48                        
*  solution_verdict: Wrong answer on test 13                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 24000 KB                             
*  problem: https://codeforces.com/contest/1070/problem/A
****************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define output              freopen("output.txt","w",stdout)
#define input               freopen("input.txt","r",stdin)
#define inputfile(x)        freopen(x,"r",stdin)
#define outputfile(x)       freopen(x,"w",stdout)
#define ensure(c,m)         assert(c && m)
///C IO
#define pf                  printf
#define sc                  scanf
#define pch                 putchar
#define ssc                 sscanf
#define spf                 sprintf
 ///functions
#define pb                  push_back
#define Mid(l,r)            ((l+r)>>1)
#define present(c,x)        ((c).find(x) != (c).end())
#define cpresent(c,x)       (find(all(c),x) != (c).end())
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define endl                '\n'
 #define forr(i,n)           for(int i=0;i<n;i++)
#define forr1(i,n)          for(int i=1;i<=n;i++)
 ///memory reset
#define MEM(Array,Val,Size) memset(Array,Val,(Size)*(sizeof(Array[0])))
#define SET(Array,Val)      memset(Array,Val,sizeof(Array))
#define set0(x)             memset(x,0,sizeof(x))
#define setn1(x)            memset(x,-1,sizeof(x))
#define setinf(x)           memset(x,127,sizeof(x))
///misc
#define SZ(v)               ((int) (v).size())
#define all(v)              (v).begin(), (v).end()
///bit operation single variable :: be careful with LL and ULL
#define On(x,i)             (x|=(1<<(i)))
#define Off(x,i)            (x&= ~(1<<(i)))
#define isOn(x,i)           (x&(1<<(i)))
#define Toggle(x,i)         (x^=(1<<(i)))
#define tmod(x,i)           (x&(~(-1<<i)))
 template <class _T>inline void ina(_T a[],int n)        {forr(i,n)cin>>(a[i]);}
 #define nln                 cout<<"\n"
#define sps cout<<" "
int TEST_CASE=0;
#define tcsp                cout<<"Case "<<(++TEST_CASE)<<": "
#define tcnl                cout<<"Case "<<(++TEST_CASE)<<":\n"
#define FAST                ios_base::sync_with_stdio(false);cin.tie(NULL);
#define precice(n)          cout<<setprecision(n)
#define FIX(n)              cout<<setprecision(n)<<fixed
//data type
typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         LD;
typedef pair<int,int>       pii;
typedef pair<ll,ll>         pll;
typedef pair<double,double> pdd;
typedef vector<int>         vi;
// typedef __int128            LLL;
// typedef unsigned __int128   ULLL;
//BIG MOD / mod inverse
template<class _T>inline _T pow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans*=a,ans%=m;a*=a;a%=m;b>>=1;}return ans;}
template<class _T>inline _T pow(_T a,_T b)      {_T ans=1;while(b){if(b&1)ans*=a;a*=a;b>>=1;}return ans;}
template<class _T>inline _T add(_T a,_T b,_T m){return a>=m-b?a-(m-b):a+b;}//a,b<m
template<class _T>inline _T multiply(_T a,_T b,_T m){_T ans=0;if(b>a)swap(a,b);while(b){if(b&1)ans=add(ans,a,m);b>>=1;a=add(a,a,m);}return ans;}//a,b<m
template<class _T>inline _T bigpow(_T a,_T b,_T m){a%=m;_T ans=1%m;while(b){if(b&1)ans=multiply(ans,a,m);a=multiply(a,a,m);b>>=1;}return ans;}
template<class _T>inline _T modinvers(_T a,_T m){return m>2000000000LL?bigpow(a,m-2,m):pow(a,m-2,m);}//m is prime
//egcd / mod inverse
template<class _T> _T _egcd(_T a, _T b, _T &x,_T &y){if(!b){x=1,y=0;return a;}_T _g=_egcd(b,a%b,x,y);_T xt=x;x=y,y=xt-(a/b)*y;return _g;}
template<class _T>inline _T fmodinvers(_T a,_T m){_T x,y;_egcd(a,m,x,y);x%=m;if(x<0)x+=m;return x;} //a,m co-prime
template<class _T>inline _T _lcm(_T a, _T b){return (a*b)/__gcd(a,b);}
template <class T> inline  T SQ(T a)            {return a*a;}
ll SQRT(ll n){ll e=sqrt(n*1.0);ll l=max(0LL,e-2),r=min(n,e+2);ll ans=0;while(l<=r){ll m=Mid(l,r);if(m*m<=n)ans=m,l=m+1;else r=m-1;}return ans;}
ll CBRT(ll n){ll e=cbrt(n*1.0);ll l=max(0LL,e-2),r=min(n,e+2);ll ans=0;while(l<=r){ll m=Mid(l,r);if(m*m*m<=n)ans=m,l=m+1;else r=m-1;}return ans;}
///Random Number generator
ull __SEED=3;
ull __MULTI=6364136223846793005ULL;
ull __INC=1442695040888963407ULL;
ull lcg(){return __SEED=__SEED* __MULTI+ __INC;}
template<class _T>inline _T random(_T L,_T R){return lcg()%(R-L+1)+L;}
 //direction array
/*
knight: int dx[]={1,-1,1,-1,2,2,-2,-2}; int dy[]={2,2,-2,-2,1,-1,1,-1};
Grid Side: int dx[]={0,0,1,-1};int dy[]={1,-1,0,0};
*/
///constant
const LD EPS =              1e-9;
const LD PI=                acos(-1.0);
const int MX=               6e5+5;
ll mod=                     1e9+7;
 int mem[600][5050];
int choice[600][5050];
int M;
int dp(int rem,int s,int len)
{
 if(len>=20000)
  return 10000000;
 if(rem==0 && s==0) 
  return 0;
 int &res=mem[rem][s];
 if(~res) return res;
 res =100000000;
 for(int d=0;d<=min(9,s);d++)
 {
  if(dp( (rem*10 + d)%M,s-d,len+1 )+1<res)
   res=1+dp( (rem*10 + d)%M,s-d,len+1 ),
   choice[ rem ][s]=d;
 }
  return res;
}
 int main()
{
 int s;
 cin>>M>>s;
  setn1(mem);
 if(dp(0,s,0)<10000000)
 {
  int rem=0;
  for(int c=dp(0,s,0);c--;)
  {
    cout<<choice[rem][s];
   int rr=rem;
   rem=(rem*10 + choice[rem][s])%M;
   s-=choice[rr][s];
  }
 }else cout<<-1<<endl;
       return 0;
}
 /**
Md. Tariqul Islam
IIT,JU
fb/tariqiitju
tarik.amtoly@gmail.com
*/