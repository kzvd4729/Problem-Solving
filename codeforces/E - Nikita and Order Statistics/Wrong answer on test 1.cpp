/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2019 18:57                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/993/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
 const double pi=acos(-1.0);
struct complx
{
  double x,y;
  complx(double a=0,double b=0):x(a),y(b){}
  complx operator+(complx c){return complx(x+c.x,y+c.y);}
  complx operator-(complx c){return complx(x-c.x,y-c.y);}
  complx operator*(complx c){return complx(x*c.x-y*c.y,x*c.y+y*c.x);}//complx
  complx operator/(double d){return complx(x/d,y/d);}
  void operator*=(complx c){double a=x*c.x-y*c.y,b=x*c.y+y*c.x;x=a,y=b;}
  void operator/=(double d){x/=d,y/=d;}
};
vector<int>r;
void bitReverse(int n)//n is power of 2
{
  r.resize(n,0);
  int p=0;while((1<<p)<n)p++;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<p;j++)
      if(i&(1<<j))r[i]|=(1<<(p-i-1));
  }
}
void dft(vector<complx>&a,bool inv)
{
  int n=a.size();
  for(int i=0;i<n;i++)
    if(r[i]<i)swap(a[i],a[r[i]]);
   for(int ln=2;ln<=n;ln*=2)//1 doesn't need to be calculated.
  {
    double ang=2*pi/n*(inv?-1:1);
    complx m(cos(ang),sin(ang));//multiplier, roots of unity
    for(int i=0;i<n;i+=ln)//every ln length segment in this level
    {
      complx r(1),u,v;//unit angle
      for(int j=0;j<ln/2;j++)
      {
        u=a[i+j],v=a[i+j+ln/2];//even and odd
        a[i+j]=u+v,a[i+j+ln/2]=u-v;//positive in the first half
        r*=m;
      }
    }
  }
}
//polynomial of the form a0x^0+a1x^1+a2x^2+a3x^3+.....
vector<long>multiply(vector<int>&a,vector<int>&b)
{
  vector<complx>fa(a.begin(),a.end());//all real part
  vector<complx>fb(b.begin(),b.end());//all real part
  int n=1;while(n<a.size()+b.size())n*=2;
  fa.resize(n);fb.resize(n);//padding higher degree with 0 coefficient
   bitReverse(n);
   dft(fa,false);dft(fb,false);//now in sample form
   for(int i=0;i<n;i++)//scalar operation on sample
    fa[i]*=fb[i];
   dft(fa,true);//inverse transform
   vector<long>ret(n);
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