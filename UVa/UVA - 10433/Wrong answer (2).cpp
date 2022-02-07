/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-16 00:18:30                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10433
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
vector<int>multiply(vector<int>&a,vector<int>&b)
{
  int sz=a.size()+b.size();
  int n=1;while(n<sz)n<<=1;
  vector<complex<double> >fa(a.begin(),a.end());
  vector<complex<double> >fb(b.begin(),b.end());
  fa.resize(n);fb.resize(n);
  fft(fa,false);fft(fb,false);
  for(int i=0;i<n;i++)fa[i]*=fb[i];
  fft(fa,true);vector<int>ret(n);
  for(int i=0;i<n;i++)
    ret[i]=round(fa[i].real());
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;
  while(cin>>s)
  {
    vector<int>a;reverse(s.begin(),s.end());
    for(auto x:s)
      a.push_back(x-'0');
    vector<int>ml=multiply(a,a);
    int c=0,f=0;
    for(int i=0;i<s.size();i++)
    {
      c+=ml[i];int r=c%10;c/=10;
      if(r!=(int)(s[i]-'0'))f=1;
    }
    if(f||s=="0"||s=="1")cout<<"Not an Automorphic number."<<endl;
    else cout<<"Automorphic number of "<<(int)s.size()<<"-digit."<<endl;
  }
  return 0;
}