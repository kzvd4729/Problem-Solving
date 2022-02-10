/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-01 00:04:18                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1396
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc;
string s;
bool case1(void)
{
  string ss=s,tmp=s;
  for(int i=0,j=ss.size()-1;i<(ss.size()/2);i++,j--)
    tmp[j]=ss[i];
  if(tmp>s)
  {
    cout<<tmp<<endl;
    return true;
  }
  return false;
}
bool case2(void)
{
  string ss=s;

  for(int i=(ss.size()-1)/2;i>=0;i--)
  {
    if(ss[i]<'9')
    {
      ss[i]++;
      break;
    }
  }
  string tmp=ss;
  for(int i=0,j=ss.size()-1;i<(ss.size()/2);i++,j--)
    tmp[j]=ss[i];
  //cout<<tmp<<endl;
  if(tmp>s)
  {
    cout<<tmp<<endl;
    return true;
  }
  return false;
}
void case3(void)
{
  int l=s.size();
  l++;
  for(int i=1;i<=l;i++)
  {
    if(i==1||i==l)cout<<'1';
    else cout<<'0';
  }
  cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>s;

    cout<<"Case "<<++tc<<": ";

    if(case1());//Routine Check;
    else if(case2());//Increase Check;
    else case3();//Default;
  }
  return 0;
}