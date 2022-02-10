/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-21 19:32:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 630                                        memory_used (MB): 33.8                            
*  problem: https://vjudge.net/problem/SPOJ-MAXMATCH
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
  string s;cin>>s;vector<int>a,b,c,ra,rb,rc;
  for(auto x:s)
  {
    if(x=='a')a.push_back(1);
    else a.push_back(0);

    if(x=='b')b.push_back(1);
    else b.push_back(0);

    if(x=='c')c.push_back(1);
    else c.push_back(0);
  }
  ra=a;reverse(ra.begin(),ra.end());
  rb=b;reverse(rb.begin(),rb.end());
  rc=c;reverse(rc.begin(),rc.end());
  a=multiply(a,ra);
  b=multiply(b,rb);
  c=multiply(c,rc);

  vector<int>id;int mx=-1;
  for(int i=0;i<s.size()-1;i++)
  {
    int x=a[i]+b[i]+c[i];
    if(x>mx)mx=a[i]+b[i]+c[i],id.clear();
    if(x==mx)id.push_back(s.size()-1-i);
  }
  cout<<mx<<endl;
  sort(id.begin(),id.end());
  for(int i=0;i<id.size();i++)
  {
    if(i)cout<<" ";
    cout<<id[i];
  }
  cout<<endl;
  return 0;
}