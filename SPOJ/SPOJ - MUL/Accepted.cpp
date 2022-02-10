/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-21 17:26:28                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 130                                        memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-MUL
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
  //a^0+a^1+a^2+a^3+... format
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
  int t;cin>>t;
  while(t--)
  {
    string a,b;cin>>a>>b;vector<int>c,d;
    for(int i=a.size()-1;i>=0;i--)
      c.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)
      d.push_back(b[i]-'0');
    vector<int>x=multiply(c,d);
    string pr;int cr=0;
    for(int i=0;i<x.size();i++)
    {
      cr+=x[i];pr.push_back((cr%10)+'0');
      cr/=10;
    }
    while(cr)
    {
      pr.push_back((cr%10)+'0');
      cr/=10; 
    }
    while(pr.size()>1&&pr.back()=='0')pr.pop_back();
    reverse(pr.begin(),pr.end());
    cout<<pr<<"\n";
  }
  return 0;
}