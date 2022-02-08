/****************************************************************************************
*  @author: kzvd4729                                         created: 22-07-2019 10:44:52                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.41 sec                                        memory_used: 38.3M                                
*  problem: https://www.codechef.com/problems/FARASA
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
long aa[N+2],qm[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i],qm[i]=qm[i-1]+aa[i];
  if(qm[n]>1000000)
  {
    unordered_set<long>st;
    for(int i=1;i<=n;i++)
      for(int j=i;j<=n;j++)
        st.insert(qm[j]-qm[i-1]);
    cout<<st.size()-1<<endl,exit(0);
  }
  vector<int>a(qm[n]+1,0);a[0]=1;
  for(int i=1;i<=n;i++)
    a[qm[i]]=1;
  vector<int>b=a;reverse(b.begin(),b.end());
  vector<int>aa=multiply(a,b);
  int ans=0;
  for(int i=1;i<=qm[n];i++)
    ans+=(bool)aa[i-1];
  cout<<ans-1<<endl;
  return 0;
}