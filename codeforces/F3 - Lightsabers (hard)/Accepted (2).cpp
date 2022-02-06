/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2019 02:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1231 ms                                         memory_used: 108700 KB                            
*  problem: https://codeforces.com/contest/958/problem/F3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
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
    ret[i]=((long)(round(fa[i].x)))%1009;
  return ret;
}
int cnt[N+2];
vector<int>v[24*N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m,k;cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;cnt[x]++;
  }
  int id=0;priority_queue<pair<int,int> >pq;
  for(int i=1;i<=N;i++)
  {
    if(!cnt[i])continue;++id;
    v[id].push_back(1);
    while(cnt[i]--)v[id].push_back(1);
    pq.push({-(int)v[id].size(),id});
  }
  while(pq.size()>1)
  {
    int i=pq.top().second;pq.pop();
    int j=pq.top().second;pq.pop();
    id++;v[id]=multiply(v[i],v[j]);
    pq.push({-(int)v[id].size(),id});
  }
  id=pq.top().second;
  cout<<v[id][k]<<endl;
  return 0;
}