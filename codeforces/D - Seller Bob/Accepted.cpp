/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/21/2019 18:22                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 124 ms                                          memory_used: 48500 KB                             
*  problem: https://codeforces.com/contest/18/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
/************* Big Integer ***************/
string NumtoString(long x)
{
  string ret;
  while(x)
  {
    ret.push_back((char)(x%10+'0'));
    x/=10;
  }
  reverse(ret.begin(),ret.end());
  if(ret.size()==0)ret.push_back('0');
  return ret;
}
long StringtoNum(string s)
{
  long ret=0;
  for(auto x:s)
    ret=ret*10+(x-'0');
  return ret;
}
int Compare(string a,string b)
{
  int x=a.size(),y=b.size();
  if(x<y)return -1;if(x>y)return 1;
  for(int i=0;i<x;i++)
  {
    if(a[i]<b[i])return -1;
    if(a[i]>b[i])return 1;
  }
  return 0;
}
string Abs(string s)
{
  if(s[0]=='-')
    s.erase(s.begin());
  return s;
}
string Add(string a,string b)
{
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  int x=a.size(),y=b.size();
  while(x<y)a.push_back('0'),x++;
  while(y<x)b.push_back('0'),y++;
  int c=0;string r;
  for(int i=0;i<x;i++)
  {
    int x=c+a[i]-'0'+b[i]-'0';
    c=x/10;x%=10;
    r.push_back((char)(x+'0'));
  }
  if(c)r.push_back((char)(c+'0'));
  reverse(r.begin(),r.end());return r;
}
string Sub(string a,string b)
{
  //assuming a>=b;
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  int x=a.size(),y=b.size();
  while(y<x)b.push_back('0'),y++;
  int c=0;string r;
  for(int i=0;i<x;i++)
  {
    int x=(a[i]-'0')-(b[i]-'0'+c);
    if(x<0)x+=10,c=1;
    else c=0;
    r.push_back((char)(x+'0'));
  }
  while(r.size()>1)
  {
    if(r.back()=='0')r.pop_back();
    else break;
  }
  reverse(r.begin(),r.end());return r;
}
string Mul(string a,string b)
{
  int x=a.size(),y=b.size();string ret="0";
  for(int i=x-1;i>=0;i--)
  {
    int c=0;string tmp;
    for(int j=i;j<x-1;j++)tmp.push_back('0');
    for(int j=y-1;j>=0;j--)
    {
      int p=a[i]-'0',q=b[j]-'0';
      int xx=p*q+c;c=xx/10;
      tmp.push_back((char)(xx%10+'0'));
    }
    if(c)tmp.push_back((char)(c+'0'));
    reverse(tmp.begin(),tmp.end());
    ret=Add(ret,tmp);
  }
  reverse(ret.begin(),ret.end());
  while(ret.size()>1)
  {
    if(ret.back()=='0')ret.pop_back();
    else break;
  }
  reverse(ret.begin(),ret.end());
  return ret;
}
string Mul(string a,long b)
{
  //b should be <= 1e17
  int x=a.size();string ret;long c=0;
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
const double pi=acos(-1.0);
void fft(vector<complex<double> >&a,bool inv)
{
  int n=a.size();
  for(int i=1,j=0;i<n;i++)
  {
    int bit=n/2;
    for( ;bit&j;bit/=2)
      j^=bit;
    j^=bit;
    if(i<j)swap(a[i],a[j]);
  }
  for(int ln=1;ln<=n;ln*=2)
  {
    double ang=2*pi/ln*(inv?-1:1);
    complex<double>wlen(cos(ang),sin(ang));
    for(int i=0;i<n;i+=ln)
    {
      complex<double>w(1);
      for(int j=0;j<ln/2;j++)
      {
        complex<double>u=a[i+j],v=a[i+j+ln/2]*w;
        a[i+j]=u+v;a[i+j+ln/2]=u-v;w*=wlen;
      }
    }
  }
  if(inv)for(auto &x:a)x/=n;
}
vector<int>multiply(vector<int>&a,vector<int>&b)
{
  int sz=a.size()+b.size();
  int n=1;while(n<sz)n*=2;
  vector<complex<double> >fa(a.begin(),a.end());
  vector<complex<double> >fb(b.begin(),b.end());
  fa.resize(n);fb.resize(n);
  fft(fa,false);fft(fb,false);
  for(int i=0;i<n;i++)fa[i]*=fb[i];
  fft(fa,true);vector<int>ret(n);
  for(int i=0;i<n;i++)
    ret[i]=round(fa[i].real());
  return ret;
}
string fftmul(string a,string b)
{
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  vector<int>c,d;
  for(auto x:a)
    c.push_back(x-'0');
  for(auto x:b)
    d.push_back(x-'0');
  vector<int>ans=multiply(c,d);
  vector<int>pr;int cr=0;
  for(auto x:ans)
  {
    cr+=x;pr.push_back(cr%10);
    cr/=10;
  }
  while(cr)
  {
    pr.push_back(cr%10);
    cr/=10;
  }
  int f=0;string ret;
  for(int i=pr.size()-1;i>=0;i--)
  {
    if(pr[i])f=1;
    if(f)ret.push_back((char)(pr[i]+'0'));
  }
  if(!f)ret.push_back('0');
  return ret;
}
pair<string,string>Div(string a,string b)
{
  //if(b=="0")assert(0);
  if(Compare(a,b)<0)return {"0",a};
  int x=a.size(),y=b.size();
  string rm="0",rt;int i=0;
  while(i<x)
  {
    if(rm=="0")rm.clear();int cnt=0;
    while(true)
    {
      if(i>=x)break;
      if(a[i]!='0')rm.push_back(a[i]);
      else if(rm.size())rm.push_back(a[i]);
      cnt++;i++;
      if(rm.size()>=b.size())
        if(Compare(rm,b)>=0)break;
      if(rt.size())rt.push_back('0');
    }
    if(Compare(rm,b)>=0)
    {
      for(int k=9;k>=1;k--)
      {
        string tmp=Mul(b,NumtoString(k));
        if(Compare(rm,tmp)>=0)
        {
          rt.push_back((char)(k+'0'));
          rm=Sub(rm,tmp);
          break;
        }
      }
    }
  }
  if(rm.size()==0)rm.push_back('0');
  return {rt,rm};
}
//Assuming all numbers are positive
//Careful for negative numbers
//Also not much optimized
///////////////////////////////////////////
string Bigmod(string b,int p)
{
  if(p<=60)
  {
    long x=(1LL<<(p*1LL));
    return NumtoString(x);
  }
  string ret="1";
  while(p)
  {
    if(p%2)ret=fftmul(ret,b);
    b=fftmul(b,b);p/=2;
  }
  return ret;
}
vector<int>win[N+2],sel[N+2];
string pw[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]="1";for(int i=1;i<=2000;i++)pw[i]=Mul(pw[i-1],2LL);
  int n;cin>>n;vector<int>gotit;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;int x;cin>>x;
    if(s=="win")win[x].push_back(i);
    else sel[x].push_back(i);
  }
  vector<pair<int,int> >vis;
  for(int i=2000;i>=0;i--)
  {
    if(sel[i].size()>1)assert(0);
    if(sel[i].size()==0)continue;
    int rt=sel[i][0],lt=-1;
    for(int j=win[i].size()-1;j>=0;j--)
    {
      if(win[i][j]<rt)
      {
        lt=win[i][j];break;
      }
    }
    if(lt==-1)continue;
    int f=0;
    for(auto x:vis)
    {
      int a=lt,b=rt,c=x.first,d=x.second;
      if(a>c)swap(a,c),swap(b,d);
      if(b>=c)f=1;
    }
    if(f==1)continue;
    gotit.push_back(i);
    vis.push_back({lt,rt});
  }
  string ans="0";
  sort(gotit.begin(),gotit.end());
  for(auto x:gotit)
    ans=Add(ans,pw[x]);
  cout<<ans<<endl;
  return 0;
}