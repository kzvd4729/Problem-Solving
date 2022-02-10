/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-04-26 17:37:48                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-1402
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int rv[N+2];
const double pi=acos(-1.0);
void bit_reverse(int n)
{
  int b=32-__builtin_clz(n-1);
  for(int i=0;i<n;i++)
  {
    rv[i]=i;
    for(int j=0;j<b/2;j++)
    {
      bool f=(i&(1<<j)),l=(i&(1<<(b-1-j)));
      if(f==l)continue;
      rv[i]^=(1<<j);rv[i]^=(1<<(b-1-j));
    }
  }
}
void fft(vector<complex<double> >&a,bool inv)
{
  vector<complex<double> >tmp=a;int n=a.size();
  bit_reverse(n);
  for(int i=0;i<n;i++)a[i]=tmp[rv[i]];
  for(int ln=2;ln<=n;ln*=2)
  {
    double ang=2*pi/ln*(inv?-1:1);
    complex<double>unt(cos(ang),sin(ang));
    for(int i=0;i<n;i+=ln)
    {
      complex<double>w(1);
      for(int j=0;j<ln/2;j++)
      {
        complex<double>u=a[i+j],v=w*a[i+j+ln/2];
        a[i+j]=u+v;a[i+j+ln/2]=u-v;
        w*=unt;
      }
    }
  }
  if(inv)for(auto &x:a)x/=n;
}
void multiply(vector<int>a,vector<int>b,vector<int>&ans)
{
  int sz=a.size()+b.size();
  int n=1;while(n<sz)n*=2;
  vector<complex<double> >fa(a.begin(),a.end());
  vector<complex<double> >fb(b.begin(),b.end());
  fa.resize(n);fb.resize(n);
  fft(fa,false);fft(fb,false);
  for(int i=0;i<n;i++)fa[i]*=fb[i];
  fft(fa,true);ans.resize(n);
  for(int i=0;i<n;i++)ans[i]=round(fa[i].real());
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;
  while(cin>>a>>b)
  {
    vector<int>aa,bb;
    for(int i=a.size()-1;i>=0;i--)
      aa.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)
      bb.push_back(b[i]-'0');
    vector<int>ans;multiply(aa,bb,ans);
    string pr;int c=0;
    for(auto x:ans)
    {
      int r=(x+c)%10;
      pr.push_back((char)(r+'0'));
      c=(x+c)/10;
    }
    while(c)
    {
      int r=c%10;
      pr.push_back((char)(r+'0'));
      c/=10;
    }
    while(pr.size())
    {
      if(pr.back()=='0')pr.pop_back();
      else break;
    }
    reverse(pr.begin(),pr.end());
    cout<<pr<<"\n";
  }
  return 0;
}