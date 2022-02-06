/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/18/2020 01:02                        
*  solution_verdict: Time limit exceeded on test 15          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 108700 KB                            
*  problem: https://codeforces.com/contest/986/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
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
string mul(string a,string b)
{
  vector<int>x,y,z;
  for(int i=a.size()-1;i>=0;i--)x.push_back(a[i]-'0');
  for(int i=b.size()-1;i>=0;i--)y.push_back(b[i]-'0');
  z=multiply(x,y);string r;int c=0;
  for(int i=0;i<z.size();i++)
  {
    c+=z[i];
    r.push_back((char)((c%10)+'0'));
    c/=10;
  }
  while(r.size()>1&&r.back()=='0')r.pop_back();
  reverse(r.begin(),r.end());
  return r;
}
int compare(string a,string b)//not lexicographic
{
  int x=a.size(),y=b.size();
  if(x<y)return -1;if(x>y)return 1;
  for(int i=0;i<x;i++)
  {
    if(a[i]<b[i])return -1;//b is bigger
    if(a[i]>b[i])return 1;//a is bigger
  }
  return 0;//same
}
string mul(string a,int b)
{
  //b should be <= 1e17
  int x=a.size();string ret;int c=0;
  for(int i=x-1;i>=0;i--)
  {
    int z=a[i]-'0';c+=z*b;
    ret.push_back((char)(c%10)+'0');
    c/=10;
  }
  while(c)
  {
    ret.push_back((char)(c%10)+'0');
    c/=10;
  }
  reverse(ret.begin(),ret.end());
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;int n=s.size();
  if(s=="1")cout<<1<<endl,exit(0);
  int d=0;
  for(int i=0; ;i++)
  {
    int dg=ceil(i*log10(3));
    if(dg>=n-1){d=i;break;}
  }
  string ret="1",b="3";int ans=1e9;
  int p=d;
  while(p)
  {
    if(p&1)ret=mul(ret,b);
    b=mul(b,b);p/=2;
  }
  //cout<<d*3<<endl;
  //cout<<ret<<endl;
  for(int i=0;i<=2;i++)
  {
    string a=mul(ret,pow(2,i));int now=d*3+i*2;
    while(compare(a,s)==-1)
    {
      a=mul(a,3);now+=3;
    }
    ans=min(ans,now);
  }
  cout<<ans<<endl;
  return 0;
}