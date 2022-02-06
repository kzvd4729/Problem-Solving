/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2019 23:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 26500 KB                             
*  problem: https://codeforces.com/contest/993/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
const double pi=acos(-1.0);
struct cmp
{
  double x,y;
  cmp(double a=0,double b=0):x(a),y(b){}
  cmp operator+(cmp c){return cmp(x+c.x,y+c.y);}
  cmp operator-(cmp c){return cmp(x-c.x,y-c.y);}
  cmp operator*(cmp c){return cmp(x*c.x-y*c.y,x*c.y+y*c.x);}
  cmp operator/(double d){return cmp(x/d,y/d);}
  void operator*=(cmp c){double a=x*c.x-y*c.y,b=x*c.y+y*c.x;x=a,y=b;}
  void operator/=(double d){x/=d,y/=d;}
};
void fft(vector<cmp>&a,bool inv)
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
    cmp wlen(cos(ang),sin(ang));
    for(int i=0;i<n;i+=len)
    {
      cmp w(1);
      for(int j=0;j<len/2;j++)
      {
        cmp u=a[i+j],v=a[i+j+len/2]*w;
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
  vector<cmp>fa(a.begin(),a.end());
  vector<cmp>fb(b.begin(),b.end());
  fa.resize(n);fb.resize(n);
  fft(fa,false);fft(fb,false);
  for(int i=0;i<n;i++)fa[i]*=fb[i];
  fft(fa,true);vector<long>ret(n);
  for(int i=0;i<n;i++)
    ret[i]=round(fa[i].x);
  return ret;
}
long zeroCase(int n,int x)
{
  long ret=0,cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]>=x)cnt++;
    else ret+=(1LL*cnt*(cnt+1))/2,cnt=0;
  }
  cout<<ret+(1LL*cnt*(cnt+1))/2<<" ";
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,x;cin>>n>>x;
  for(int i=1;i<=n;i++)cin>>aa[i];
  zeroCase(n,x);
   vector<int>a,b;int cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(aa[i]>=x)cnt++;
    else a.push_back(cnt+1),cnt=0;
  }
  cnt=0;
  for(int i=n;i>=1;i--)
  {
    if(aa[i]>=x)cnt++;
    else b.push_back(cnt+1),cnt=0;
  }
  vector<long>c=multiply(a,b);
  for(int i=a.size()-1;i>=0;i--)
    cout<<c[i]<<" ";
  for(int i=a.size();i<n;i++)
    cout<<0<<" ";
  cout<<endl;
  return 0;
}