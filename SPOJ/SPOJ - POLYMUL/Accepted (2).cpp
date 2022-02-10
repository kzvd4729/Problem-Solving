/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-14 23:26:16                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 70                                         memory_used (MB): 18.4                            
*  problem: https://vjudge.net/problem/SPOJ-POLYMUL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const double pi=acos(-1.0);
void fft(vector<complex<double> >&a,bool invert)
{
 int n=a.size();
 for(int i=1,j=0;i<n;i++)
 {
  int bit=n>>1;
  for( ;j&bit;bit>>=1)
   j^=bit;
  j^=bit;
  if(i<j)swap(a[i],a[j]);
 }
 for(int len=2;len<=n;len<<=1)
 {
  double ang=2*pi/len*(invert?-1:1);
  complex<double>wlen(cos(ang),sin(ang));
  for(int i=0;i<n;i+=len)
  {
   complex<double>w(1);
   for(int j=0;j<len/2;j++)
   {
    complex<double>u=a[i+j],v=a[i+j+len/2]*w;
    a[i+j]=u+v;a[i+j+len/2]=u-v;
    w*=wlen;
   }
  }
 }
 if(invert)for(auto &x:a)x/=n;
}
vector<long>multiply(vector<long>&a,vector<long>&b)
{
 vector<complex<double> >fa(a.begin(),a.end()),fb(b.begin(),b.end());
 int n=1;int sz=a.size()+b.size();while(n<sz)n<<=1;
 fa.resize(n);fb.resize(n);
 fft(fa,false);fft(fb,false);
 for(int i=0;i<n;i++)fa[i]*=fb[i];
 fft(fa,true);
 vector<long>ret(n);
 for(int i=0;i<n;i++)
  ret[i]=round(fa[i].real());
 return ret;
}
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int t;cin>>t;
 while(t--)
 {
  int n;cin>>n;vector<long>a,b;
  for(int i=0;i<=n;i++)
  {
   long x;cin>>x;a.push_back(x);
  }
  for(int i=0;i<=n;i++)
  {
   int x;cin>>x;b.push_back(x);
  }
  vector<long>ans=multiply(a,b);
  for(int i=0;i<=n+n;i++)
  {
   cout<<ans[i];
   if(i==n+n)cout<<endl;
   else cout<<" ";
  }
 }
 return 0;
}