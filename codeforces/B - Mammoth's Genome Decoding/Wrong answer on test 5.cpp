/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2020 18:23                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/747/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int mn(int a,int b,int c,int d)
{
  if(a<=b&&a<=c&&a<=d)return 1;
  if(b<=a&&b<=c&&b<=d)return 2;
  if(c<=b&&c<=a&&c<=d)return 3;
  if(c<=a&&c<=b&&c<=d)return 4;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;string s;cin>>n>>s;
   int a=0,t=0,g=0,c=0;vector<int>v;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='A')a++;
    else if(s[i]=='T')t++;
    else if(s[i]=='G')g++;
    else if(s[i]=='C')c++;
    else v.push_back(i);
  }
  for(int i=0;i<v.size();i++)
  {
    int id=mn(a,t,g,c);
    if(id==1)a++,s[v[i]]='A';
    if(id==2)t++,s[v[i]]='T';
    if(id==3)g++,s[v[i]]='G';
    if(id==4)c++,s[v[i]]='C';
  }
  if(min({a,t,g,c})!=max({a,t,g,c}))cout<<"===\n";
  else cout<<s<<endl;
    return 0;
}