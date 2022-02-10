/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-22 12:19:20                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 7100                                       memory_used (MB): 87                              
*  problem: https://vjudge.net/problem/SPOJ-ADAMATCH
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
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
vector<int>multiply(vector<int>&a,vector<int>&b)
{
  //a^0+a^1+a^2+a^3+... format
  int sz=a.size()+b.size();
  int n=1;while(n<sz)n<<=1;
  vector<cmp>fa(a.begin(),a.end());
  vector<cmp>fb(b.begin(),b.end());
  fa.resize(n);fb.resize(n);
  fft(fa,false);fft(fb,false);
  for(int i=0;i<n;i++)fa[i]*=fb[i];
  fft(fa,true);vector<int>ret(n);
  for(int i=0;i<n;i++)
    ret[i]=round(fa[i].x);
  return ret;
}
vector<int>_find(string &s,char c)
{
  vector<int>ret;
  for(auto x:s)
  {
    if(x==c)ret.push_back(1);
    else ret.push_back(0);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string a,b;cin>>a>>b;
  vector<int>aa=_find(b,'A');
  vector<int>bb=_find(a,'A');
  reverse(bb.begin(),bb.end());

  vector<int>cc=multiply(aa,bb);

  aa=_find(b,'C');
  bb=_find(a,'C');
  reverse(bb.begin(),bb.end());

  aa=multiply(aa,bb);
  for(int i=0;i<aa.size();i++)cc[i]+=aa[i];

  aa=_find(b,'T');
  bb=_find(a,'T');
  reverse(bb.begin(),bb.end());

  aa=multiply(aa,bb);
  for(int i=0;i<aa.size();i++)cc[i]+=aa[i];

  aa=_find(b,'G');
  bb=_find(a,'G');
  reverse(bb.begin(),bb.end());


  aa=multiply(aa,bb);
  for(int i=0;i<aa.size();i++)cc[i]+=aa[i];


  int mx=0;
  for(int i=b.size()-1;i<a.size();i++)
    mx=max(mx,cc[i]);

  cout<<b.size()-mx<<endl;

  return 0;
}