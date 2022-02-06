/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/23/2019 10:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 577 ms                                          memory_used: 28300 KB                             
*  problem: https://codeforces.com/contest/528/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,bls=2510,R=(1<<16)-1;
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
int qm[N+2],k;
vector<int>cal(string s,char c,int f)
{
  vector<int>v;;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]==c)v.push_back(1);
    else v.push_back(0);
  }
  if(!f)return v;
  qm[0]=v[0];
  for(int i=1;i<v.size();i++)
    qm[i]=qm[i-1]+v[i];
  for(int i=0;i<v.size();i++)
  {
    int rt=min(i+k,(int)v.size()-1);
    int lt=i-k-1;;
    int sm=qm[rt];if(lt>=0)sm-=qm[lt];
    if(sm)v[i]=1;
  }
  return v;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n1,n2;cin>>n1>>n2>>k;
  string a,b;cin>>a>>b;
   vector<int>aa=cal(a,'A',1);
  vector<int>bb=cal(b,'A',0);
   reverse(aa.begin(),aa.end());
  vector<int>cc=multiply(bb,aa);
   aa=cal(a,'C',1);
  bb=cal(b,'C',0);
  reverse(aa.begin(),aa.end());
  aa=multiply(bb,aa);
  for(int i=0;i<aa.size();i++)cc[i]+=aa[i];
   aa=cal(a,'T',1);
  bb=cal(b,'T',0);
  reverse(aa.begin(),aa.end());
  aa=multiply(bb,aa);
  for(int i=0;i<aa.size();i++)cc[i]+=aa[i];
   aa=cal(a,'G',1);
  bb=cal(b,'G',0);
  reverse(aa.begin(),aa.end());
  aa=multiply(bb,aa);
  for(int i=0;i<aa.size();i++)cc[i]+=aa[i];
   int ans=0;
  for(auto x:cc)
    ans+=(x==n2);
  cout<<ans<<endl;
   return 0;
}