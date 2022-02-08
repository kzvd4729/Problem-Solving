/****************************************************************************************
*  @author: kzvd4729                                         created: 22-07-2019 09:44:17                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.93 sec                                        memory_used: 31.1M                                
*  problem: https://www.codechef.com/problems/COUNTARI
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,R=3e4;
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
int aa[N+2],prv[N+2],nxt[N+2],tmp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,bl=1000;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],nxt[aa[i]]++;
  long ans=0;int st=0,ed=0;
  while(ed<n)
  {
    st=ed+1;ed=min(st+bl,n);
    for(int i=st;i<=ed;i++)
      nxt[aa[i]]--;
    for(int i=st;i<=ed;i++)
    {
      for(int j=i+1;j<=ed;j++)
      {
        int tar=aa[j]-aa[i]+aa[j];
        if(tar>=0)ans+=nxt[tar];
        tar=aa[i]-(aa[j]-aa[i]);
        if(tar>=0)ans+=tmp[tar]+prv[tar];
      }
      tmp[aa[i]]++;
    }
    vector<int>a,b;
    for(int i=0;i<=R;i++)
      a.push_back(prv[i]);
    for(int i=0;i<=R;i++)
      b.push_back(nxt[i]);
    vector<long>c=multiply(a,b);
    for(int i=st;i<=ed;i++)
      ans+=c[2*aa[i]];
    for(int i=st;i<=ed;i++)
      prv[aa[i]]++,tmp[aa[i]]--;
  }
  cout<<ans<<endl;
  return 0;
}