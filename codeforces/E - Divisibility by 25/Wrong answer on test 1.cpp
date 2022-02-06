/****************************************************************************************
*  @author: * kzvd4729                                       created: Jun/01/2018 22:33                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/988/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e8;
string s;
int case1(void)
{
  string tmp=s;
  int f=0,ret=0,po=-1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='0')
      po=i;
  }
  if(po==-1)return inf;
  for(int i=po;i<s.size()-1;i++)
  {
    ret++;
    swap(tmp[i],tmp[i+1]);
  }
  po=-1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='0')
      po=i;
  }
  if(po==-1)return inf;
  for(int i=po;i<s.size()-2;i++)
  {
    ret++;
    swap(tmp[i],tmp[i+1]);
  }
  if(tmp[0]=='0')return inf;
  return ret;
}
int case2(void)
{
  string tmp=s;
  int f=0,ret=0,po=-1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='0')
      po=i;
  }
  if(po==-1)return inf;
  for(int i=po;i<s.size()-1;i++)
  {
    ret++;
    swap(tmp[i],tmp[i+1]);
  }
  po=-1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='5')
      po=i;
  }
  if(po==-1)return inf;
  for(int i=po;i<s.size()-2;i++)
  {
    ret++;
    swap(tmp[i],tmp[i+1]);
  }
  if(tmp[0]=='0')return inf;
  return ret;
}
int case3(void)
{
  string tmp=s;
  int f=0,ret=0,po=-1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='2')
      po=i;
  }
  if(po==-1)return inf;
  for(int i=po;i<s.size()-1;i++)
  {
    ret++;
    swap(tmp[i],tmp[i+1]);
  }
  po=-1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='5')
      po=i;
  }
  if(po==-1)return inf;
  for(int i=po;i<s.size()-2;i++)
  {
    ret++;
    swap(tmp[i],tmp[i+1]);
  }
  if(tmp[0]=='0')return inf;
  return ret;
}
int case4(void)
{
  string tmp=s;
  int f=0,ret=0,po=-1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='7')
      po=i;
  }
  if(po==-1)return inf;
  for(int i=po;i<s.size()-1;i++)
  {
    ret++;
    swap(tmp[i],tmp[i+1]);
  }
  po=-1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='5')
      po=i;
  }
  if(po==-1)return inf;
  for(int i=po;i<s.size()-2;i++)
  {
    ret++;
    swap(tmp[i],tmp[i+1]);
  }
  if(tmp[0]=='0')return inf;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int ans=inf;
   cin>>s;
   ans=min(ans,case1());//00
  ans=min(ans,case2());//50;
  ans=min(ans,case3());//25;
  ans=min(ans,case4());//75;
   if(ans==inf)cout<<-1<<endl;
  else cout<<ans<<endl;
   return 0;
}