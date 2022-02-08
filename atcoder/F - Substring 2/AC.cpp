/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-05-20 20:55:05                      
*  solution_verdict: AC                                      language: C++ (GCC 9.2.1)                         
*  run_time: 1151 ms                                         memory_used: 126528 KB                            
*  problem: https://atcoder.jp/contests/abc196/tasks/abc196_f
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
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
  r.resize(n);for(int i=0;i<n;i++)r[i]=0;
  int p=0;while((1<<p)<n)p++;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<p;j++)
      if(i&(1<<j))r[i]|=(1<<(p-j-1));
  }
}
void dft(vector<complx>&a,bool inv)
{
  int n=a.size();
  for(int i=0;i<n;i++)
    if(r[i]<i)swap(a[i],a[r[i]]);
   for(int ln=2;ln<=n;ln*=2)//1 doesn't need to be calculated.
  {
    double ang=2*pi/ln*(inv?-1:1);
    complx m(cos(ang),sin(ang));//multiplier, roots of unity
    for(int i=0;i<n;i+=ln)//every ln length segment in this level
    {
      complx r(1),u,v;//unit angle
      for(int j=0;j<ln/2;j++)
      {
        u=a[i+j],v=r*a[i+j+ln/2];//even and odd
        a[i+j]=u+v,a[i+j+ln/2]=u-v;//positive in the first half
        r*=m;
      }
    }
  }
  if(inv)for(auto &x:a)x/=n;
}
//polynomial of the form a0x^0+a1x^1+a2x^2+a3x^3+.....
vector<int>multiply(vector<int>&a,vector<int>&b)
{
  vector<complx>fa(a.begin(),a.end());//all real part
  vector<complx>fb(b.begin(),b.end());//all real part
  int n=1;while(n<a.size()+b.size())n*=2;
  fa.resize(n);fb.resize(n);//padding higher degree with 0 coefficient
   bitReverse(n);//for iterative implementation
   dft(fa,false);dft(fb,false);//now in sample form
   for(int i=0;i<n;i++)//scalar operation on sample
    fa[i]*=fb[i];
   dft(fa,true);//inverse transform
   vector<int>ret(n);
  for(int i=0;i<n;i++)
    ret[i]=round(fa[i].x);
  return ret;
}
 int ans[N+N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s,t;cin>>s>>t;
   reverse(t.begin(),t.end());
   vector<int>a,b;
  for(auto x:s)
  {
    if(x=='1')a.push_back(1);
    else a.push_back(0);
  }
   for(auto x:t)
  {
    if(x=='1')b.push_back(1);
    else b.push_back(0);
  }
   vector<int>c=multiply(a,b);
  for(int i=(int)t.size()-1;i<(int)s.size();i++)
  {
    ans[i]=c[i];
  }
   a.clear();
  for(auto x:s)
  {
    if(x=='1')a.push_back(0);
    else a.push_back(1);
  }
   b.clear();
  for(auto x:t)
  {
    if(x=='1')b.push_back(0);
    else b.push_back(1);
  }
   c=multiply(a,b);int mx=0;
  for(int i=(int)t.size()-1;i<(int)s.size();i++)
  {
    ans[i]+=c[i];mx=max(mx,ans[i]);
  }
   cout<<(int)t.size()-mx<<endl;
     return 0;
}