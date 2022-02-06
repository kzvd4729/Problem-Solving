/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/11/2019 19:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1964 ms                                         memory_used: 52500 KB                             
*  problem: https://codeforces.com/contest/954/problem/I
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
int vis[6],cnt;
vector<int>adj[6];
vector<pair<int,int> >v[N+2];
void dfs(int node)
{
  vis[node]=1,cnt++;
  for(auto x:adj[node])
    if(!vis[x])dfs(x);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s1,s2;cin>>s1>>s2;
   vector<int>a,b,m;
  for(char c='a';c<='f';c++)
  {
    for(char g='a';g<='f';g++)
    {
      if(c==g)continue;
      a.clear(),b.clear();
      for(auto x:s2)
      {
        if(x==c)a.push_back(1);
        else a.push_back(0);
      }
      for(auto x:s1)
      {
        if(x==g)b.push_back(1);
        else b.push_back(0);
      }
      reverse(b.begin(),b.end());
      m=multiply(a,b);
       for(int i=s1.size()-1;i>=s2.size()-1;i--)
        if(m[i])v[s1.size()-1-i].push_back({c-'a',g-'a'});
    }
  }
  int pt=0;
  for(int i=s2.size();i<=s1.size();i++)
  {
    for(int j=0;j<6;j++)adj[j].clear(),vis[j]=0;
    for(auto x:v[pt])
    {
      adj[x.first].push_back(x.second);
      adj[x.second].push_back(x.first);
    }
    int ans=0;
    for(int j=0;j<6;j++)
    {
      if(vis[j])continue;
      cnt=0;dfs(j);ans+=cnt-1;
    }
    pt++;cout<<ans<<"\n";
  }
  return 0;
}