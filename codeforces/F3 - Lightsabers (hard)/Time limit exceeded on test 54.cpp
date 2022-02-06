/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2019 21:56                        
*  solution_verdict: Time limit exceeded on test 54          language: GNU C++14                               
*  run_time: 4000 ms                                         memory_used: 92400 KB                             
*  problem: https://codeforces.com/contest/958/problem/F3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
 const double pi=acos(-1.0);
struct complx
{
  double x,y;//x=1,y=0 for unit
  complx(double a=0,double b=0):x(a),y(b){}
  complx operator+(complx c){return complx(x+c.x,y+c.y);}
  complx operator-(complx c){return complx(x-c.x,y-c.y);}
  complx operator*(complx c){return complx(x*c.x-y*c.y,x*c.y+y*c.x);}//complx
  complx operator/(double d){return complx(x/d,y/d);}
  void operator*=(complx c){double a=x*c.x-y*c.y,b=x*c.y+y*c.x;x=a,y=b;}
  void operator/=(double d){x/=d,y/=d;}
};
void dft(vector<complx>&a,bool inv)
{
  int n=a.size();if(n==1)return ;
  vector<complx>a0(n/2),a1(n/2);
   for(int i=0;i<n/2;i++)
    a0[i]=a[2*i],a1[i]=a[2*i+1];
  dft(a0,inv);dft(a1,inv);
   double ang=2*pi/n*(inv?-1:1);
  complx r(1),m(cos(ang),sin(ang));
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
vector<int>multiply(vector<int>&a,vector<int>&b)
{
  vector<complx>fa(a.begin(),a.end());//all real part
  vector<complx>fb(b.begin(),b.end());//all real part
  int n=1;while(n<a.size()+b.size())n*=2;
  fa.resize(n);fb.resize(n);//padding higher degree with 0 coefficient
   //bitReverse(n);//for iterative implementation
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
void P(vector<int>v)
{
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;
}
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
    //cout<<"---- "<<endl;
    //P(v[i]);P(v[j]);
    id++;v[id]=multiply(v[i],v[j]);
    //P(v[id]);
    pq.push({-(int)v[id].size(),id});
  }
  id=pq.top().second;
  cout<<v[id][k]<<endl;
  return 0;
}