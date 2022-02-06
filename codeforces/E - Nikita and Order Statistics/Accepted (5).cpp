/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/21/2019 23:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 888 ms                                          memory_used: 39300 KB                             
*  problem: https://codeforces.com/contest/993/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
struct fastFourierTransform
{
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
  void dft(vector<cmp>&a,bool inv)
  {
    int n=a.size();if(n==1)return ;
    vector<cmp>a0(n/2),a1(n/2);
     for(int i=0;i<n/2;i++)
      a0[i]=a[2*i],a1[i]=a[2*i+1];
    dft(a0,inv);dft(a1,inv);
     double ang=2*pi/n*(inv?-1:1);
    cmp r(1),m(cos(ang),sin(ang));
    for(int i=0;i<n/2;i++)
    {
      a[i]=a0[i]+r*a1[i];
      a[i+n/2]=a0[i]-r*a1[i];
      if(inv)
        a[i]/=2,a[i+n/2]/=2;//overall divided by n
      r*=m;
    }
  }
  //polynomial of the form a0x^0+a1x^1+a2x^2+a3x^3+.....
  //can be extended to three or many
  vector<long>multiply(vector<int>&a,vector<int>&b)
  {
    vector<cmp>fa(a.begin(),a.end());//all real part
    vector<cmp>fb(b.begin(),b.end());//all real part
    int n=1;while(n<a.size()+b.size())n*=2;
    fa.resize(n);fb.resize(n);//padding higher degree with 0 coefficient
     dft(fa,false);dft(fb,false);//now in sample form
     for(int i=0;i<n;i++)//scalar operation on sample
      fa[i]*=fb[i];
     dft(fa,true);//inverse transform
     vector<long>ret(n);
    for(int i=0;i<n;i++)
      ret[i]=round(fa[i].x);
    return ret;
  }
};
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
  fastFourierTransform fft;
  vector<long>c=fft.multiply(a,b);
  for(int i=a.size()-1;i>=0;i--)
    cout<<c[i]<<" ";
  for(int i=a.size();i<n;i++)
    cout<<0<<" ";
  cout<<endl;
  return 0;
}