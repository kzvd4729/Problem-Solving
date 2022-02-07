/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-03-15 23:37:03                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11161
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
string fib[N+2];
string toString(long x)
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
string add(string a,string b)
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
string sub(string a,string b)
{
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
string divide(string s)
{
  int p=0;string r;
  for(auto x:s)
  {
    p=p*10+x-'0';
    r.push_back((char)(p/2+'0'));
    p%=2;
  }
  reverse(r.begin(),r.end());
  while(r.size()>1)
  {
    if(r.back()=='0')r.pop_back();
    else break;
  }
  reverse(r.begin(),r.end());return r;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  fib[0]="0";fib[1]="1";fib[2]="1";
  for(int i=3;i<=1500;i++)
    fib[i]=add(fib[i-1],fib[i-2]);
  for(int i=2;i<=1500;i++)
    fib[i]=add(fib[i-1],fib[i]);
  int n,tc=0;
  while(cin>>n)
  {
    if(!n)break;
    string df=sub(fib[n],fib[n-1]);
    int l=df.back()-'0';
    if(l%2)df=add(df,"1");
    cout<<"Set "<<++tc<<":"<<"\n";
    cout<<add(fib[n-1],sub(divide(df),"1"))<<"\n";
  }
  return 0;
}