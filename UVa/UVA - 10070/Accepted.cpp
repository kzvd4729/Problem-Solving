/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-08 14:15:12                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 250                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10070
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
pair<int,int>Div(string a,string b)
{
  //a/b
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
  return {StringtoNum(rt),StringtoNum(rm)};
}
//Assuming all numbers are positive
//Careful for negative numbers
//Also not much optimized
///////////////////////////////////////////
string bigmod(string b,long p)
{
  string ret="1";
  while(p)
  {
    if(p%2)ret=Mul(ret,b);
    b=Mul(b,b);p/=2;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  string a;int t=0;
  while(cin>>a)
  {
    if(t)cout<<endl;t=1;
    pair<int,int>p;int f=0,g=0;
    p=Div(a,"4");
    if(p.second==0)f=1;
    p=Div(a,"100");
    if(p.second==0)f=0;
    p=Div(a,"400");
    if(p.second==0)f=1;

    if(f)
    {
      cout<<"This is leap year."<<endl;
      g=1;
    }
    p=Div(a,"15");
    if(p.second==0)
    {
      cout<<"This is huluculu festival year."<<endl;
      g=1;
    }
    p=Div(a,"55");
    if(p.second==0&&f)cout<<"This is bulukulu festival year."<<endl;
    if(g==0)cout<<"This is an ordinary year."<<endl;

  }
  return 0;
}