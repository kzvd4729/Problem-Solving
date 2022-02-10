/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-21 18:06:24                      
*  solution_verdict: Compilation error                       language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-POLYMUL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

const double pi=acos(-1.0);
void fft(vector<complex<double> >&a,bool inv)
{
  int n=a.size();
  for(int i=1,j=0;i<n;i++)
  {
    int bit=n>>1;
    for( ;bit&j;bit>>=1)
      j^=bit;
    j^=bit;
    if(i<j)swap(a[i],a[j]);
  }
  for(int len=2;len<=n;len<<=1)
  {
    double ang=2*pi/len*(inv?-1:1);
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
  if(inv)for(auto &x:a)x/=n;
}
vector<long>multiply(vector<int>&a,vector<int>&b)
{
  //a^0+a^1+a^2+a^3+... format
  int sz=a.size()+b.size();
  int n=1;while(n<sz)n<<=1;
  vector<complex<double> >fa(a.begin(),a.end());
  vector<complex<double> >fb(b.begin(),b.end());
  fa.resize(n);fb.resize(n);
  fft(fa,false);fft(fb,false);
  for(int i=0;i<n;i++)fa[i]*=fb[i];
  fft(fa,true);vector<long>ret(n);
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
    int n;cin>>n;vector<int>a(n+1),b(n+1);
    for(int i=0;i<=n;i++)
      cin>>a[i];
    for(int i=0;i<=n;i++)
      cin>>b[i];
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int>c=multiply(a,b);
    for(int i=n+n;i>=0;i--)
    {
      cout<<c[i];
      if(i)cout<<" ";
    }
    cout<<"\n";
  }
  return 0;
}