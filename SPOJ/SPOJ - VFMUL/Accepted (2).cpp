/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-17 20:57:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 270                                        memory_used (MB): 27.6                            
*  problem: https://vjudge.net/problem/SPOJ-VFMUL
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
    int bit=n/2;
    for( ;bit&j;bit/=2)
      j^=bit;
    j^=bit;
    if(i<j)swap(a[i],a[j]);
  }
  for(int ln=1;ln<=n;ln*=2)
  {
    double ang=2*pi/ln*(inv?-1:1);
    complex<double>wlen(cos(ang),sin(ang));
    for(int i=0;i<n;i+=ln)
    {
      complex<double>w(1);
      for(int j=0;j<ln/2;j++)
      {
        complex<double>u=a[i+j],v=a[i+j+ln/2]*w;
        a[i+j]=u+v;a[i+j+ln/2]=u-v;w*=wlen;
      }
    }
  }
  if(inv)for(auto &x:a)x/=n;
}
vector<int>multiply(vector<int>&a,vector<int>&b)
{
  int sz=a.size()+b.size();
  int n=1;while(n<sz)n*=2;
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
    string a,b;cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    vector<int>c,d;
    for(auto x:a)
      c.push_back(x-'0');
    for(auto x:b)
      d.push_back(x-'0');
    vector<int>ans=multiply(c,d);
    vector<int>pr;int cr=0;
    for(auto x:ans)
    {
      cr+=x;pr.push_back(cr%10);
      cr/=10;
    }
    while(cr)
    {
      pr.push_back(cr%10);
      cr/=10;
    }
    int f=0;
    for(int i=pr.size()-1;i>=0;i--)
    {
      if(pr[i])f=1;
      if(f)cout<<pr[i];
    }
    if(!f)cout<<0;
    cout<<endl;
  }
  return 0;
}