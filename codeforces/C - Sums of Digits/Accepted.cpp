/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2020 20:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 8000 KB                              
*  problem: https://codeforces.com/contest/509/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int aa[N+2];
bool isPossible(string s,int dg,int sm)
{
  if(dg*9<sm)return false;
  //cout<<dg<<" "<<sm<<endl;
   reverse(s.begin(),s.end());
  while(s.size()<dg)s.push_back('0');
  reverse(s.begin(),s.end());
   for(int i=0;i<dg;i++)
  {
    if(s[i]=='9')sm-=9;
    else if(sm>s[i]-'0')return true;
    else return false;
  }
  return false;
}
int qm[N+2];
string next(string s,int dg,int sm)
{
  reverse(s.begin(),s.end());
  while(s.size()<dg)s.push_back('0');
  reverse(s.begin(),s.end());
   string ret;ret.resize(dg);
  if(s[0]=='0')
  {
    for(int i=0;i<dg;i++)
    {
      int rm=dg-1-i;
      int mn=max(0,sm-rm*9);
      if(i==0)mn=max(mn,1);
      ret[i]=(char)(mn+'0');
      sm-=mn;
    }
    return ret;
  }
  ret=s;qm[0]=s[0]-'0';
  for(int i=1;i<dg;i++)qm[i]=qm[i-1]+s[i]-'0';
   //cout<<"ok"<<endl;
  //cout<<dg<<endl;
  for(int i=dg-1;i>=0;i--)
  {
    if(s[i]=='9')continue;
    int mn=s[i]-'0'+1,mx=(dg-i)*9;
     //cout<<mn<<" "<<mx<<endl;
     if(i)mn+=qm[i-1],mx+=qm[i-1];
     //cout<<mn<<" "<<mx<<endl;
     if(sm>=mn&&sm<=mx)
    {
      if(i)sm-=qm[i-1];
      ret[i]++;sm-=(ret[i]-'0');
      //cout<<"*"<<sm<<endl;
      for(int j=dg-1;j>i;j--)
      {
        int mx=min(sm,9);
        sm-=mx;ret[j]=(char)(mx+'0');
      }
      //cout<<ret[i]<<endl;
      ret[i]+=sm;
      //cout<<sm<<endl;
      //cout<<ret[i]<<endl;
      //cout<<"*"<<ret<<endl;
      return ret;
    }
  }
  assert(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>aa[i];
  string ls;
    while(aa[1])
  {
    int mn=min(9,aa[1]);
    aa[1]-=mn;ls.push_back((char)(mn+'0'));
  }
  reverse(ls.begin(),ls.end());
  cout<<ls<<endl;
  for(int i=2;i<=n;i++)
  {
    int id;
    for(id=ls.size(); ;id++)
    {
      //cout<<id<<endl;
      if(isPossible(ls,id,aa[i]))break;
    }
    //cout<<"**"<<id<<endl;
    ls=next(ls,id,aa[i]);
    // for(int i=0;i<ls.size();i++)
    //   aa[i]-=(ls[i]-'0');
    //if(aa[i]!=0)assert(0);
    cout<<ls<<endl;
  }
  return 0;
}