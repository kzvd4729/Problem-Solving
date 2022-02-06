/****************************************************************************************
*  @author: kzvd4729                                         created: May/14/2018 21:07                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/979/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int sc[5],n;
string s;
int cal(string s)
{
  int l=s.size(),here=0;
  map<char,int>mp;
  for(auto x:s)
    mp[x]++;
  for(char i='a';i<='z';i++)
    here=max(here,mp[i]);
  for(char i='A';i<='Z';i++)
    here=max(here,mp[i]);
  if(here==l&&n==1&&l>1)return here-1;
  return min(l,here+n);
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=3;i++)
  {
    cin>>s;
    sc[i]=cal(s);
  }
  //if(sc[1]==sc[2]||sc[2]==sc[3]||sc[1]==sc[3])cout<<"Draw"<<endl,exit(0);
  if(sc[1]>sc[2]&&sc[1]>sc[3])
    cout<<"Kuro"<<endl;
  else if(sc[2]>sc[3]&&sc[2]>sc[1])
    cout<<"Shiro"<<endl;
  else if(sc[3]>sc[1]&&sc[3]>sc[2])
    cout<<"Katie"<<endl;
  else cout<<"Draw"<<endl;
  return 0;
}