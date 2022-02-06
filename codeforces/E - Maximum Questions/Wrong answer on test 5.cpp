/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/14/2019 22:10                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 26500 KB                             
*  problem: https://codeforces.com/contest/900/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
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
int cnt[N+2],ok[N+2],dp[N+2],st[N+2],an[N+2];
int dfs(int i)
{
  //cout<<i<<" --> "<<dp[i]<<endl;getchar();
  if(!dp[i])return 0;
  if(an[i]!=-1)return an[i];
  int now=1e9;
  if(dp[i]==dp[i+1])now=min(now,dfs(i+1));
  //cout<<i<<" "<<st[dp[i]-1]<<endl;getchar();
  if(ok[i])now=min(now,cnt[i]+dfs(st[dp[i]-1]));
  return an[i]=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n;string s;cin>>s>>m;
  if(m>n)cout<<0<<endl,exit(0);
   for(int i=0;i<m;i++)if(s[i]=='?')cnt[0]++;
  int id=0;
  for(int i=m;i<n;i++)
  {
    cnt[i-m+1]=cnt[i-m];
    if(s[i]=='?')cnt[i-m+1]++;
    cnt[i-m+1]-=(s[id++]=='?');
  }
  vector<int>a(m,0),b(n,0),c,d;
  for(int i=0;i<m;i+=2)a[i]=1;
  for(int i=0;i<n;i++)
    if(s[i]=='a')b[i]=1;
  reverse(b.begin(),b.end());
   c=multiply(a,b);
   for(int i=0;i<m;i++)a[i]^=1;
  for(int i=0;i<n;i++)s[i]=='b'?b[i]=1:b[i]=0;
  reverse(b.begin(),b.end());
  d=multiply(a,b);
  id=0;
  for(int i=n-1;i>m-2;i--)
  {
    if(c[i]+d[i]==m-cnt[id])ok[id]=1;
    id++;
  }
  for(int i=n-1;i>=0;i--)
  {
    dp[i]=dp[i+1];
    if(ok[i])dp[i]=max(dp[i],dp[i+m]+1);
    st[dp[i]]=i;
  }
  st[0]=n;
  memset(an,-1,sizeof(an));
  cout<<dfs(0)<<endl;
  return 0;
}