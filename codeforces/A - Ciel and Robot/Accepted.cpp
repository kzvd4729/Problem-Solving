/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/08/2019 16:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/321/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
pair<int,int>aa[N+2];
void ya(void)
{
  cout<<"Yes"<<endl,exit(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x,y;cin>>x>>y;
  string s;cin>>s;s="#"+s;
  aa[0]={0,0};pair<int,int>p={0,0};
  for(int i=1;i<s.size();i++)
  {
    if(s[i]=='U')p.second++;
    if(s[i]=='D')p.second--;
    if(s[i]=='L')p.first--;
    if(s[i]=='R')p.first++;
    aa[i]=p;
  }
  for(int i=0;i<s.size();i++)
  {
    int xx=x-aa[i].first,yy=y-aa[i].second;
    if(xx==0&&yy==0)ya();
    int a,b;
    if(p.first==0)
    {
      if(xx==0)a=-2;
      else a=-1;
    }
    else
    {
      if(xx%p.first)a=-1;
      else
      {
        if(p.first>=0&&xx<0)a=-1;
        else if(p.first<0&&xx>=0)a=-1;
        else a=xx/p.first;
      }
    }
    if(p.second==0)
    {
      if(yy==0)b=-2;
      else b=-1;
    }
    else
    {
      if(yy%p.second)b=-1;
      else
      {
        if(p.second>=0&&yy<0)b=-1;
        else if(p.second<0&&yy>=0)b=-1;
        else b=yy/p.second;
      }
    }
    //cout<<xx<<" "<<yy<<" "<<a<<" "<<b<<endl;
    if(a==-1||b==-1)continue;
    if(a>=0&&b>=0&&a!=b)continue;
    ya();
  }
  cout<<"No"<<endl;
  return 0;
}