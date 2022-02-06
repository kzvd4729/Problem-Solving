/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/27/2020 15:23                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 3700 KB                              
*  problem: https://codeforces.com/contest/1264/problem/B
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
void no(){cout<<"NO"<<endl,exit(0);}
bool try1(int a,int b,int c,int d)//0 3
{
  int mn=min(a,b);a-=mn,b-=mn;
   mn=min(c,d);c-=mn,d-=mn;
   if(a==0&&d==0&&b==c&&b>=0&&c>=0)return true;
  return false;
}
bool try2(int a,int b,int c,int d)//1 3
{
  int mn=min(a,b);a-=mn,b-=mn;b--;
   mn=min(c,d);c-=mn,d-=mn;
   if(a==0&&d==0&&b==c&&b>=0&&c>=0)return true;
  return false;
}
bool try3(int a,int b,int c,int d)//0 2
{
  int mn=min(a,b);a-=mn,b-=mn;
   mn=min(c,d);c-=mn,d-=mn;c--;
   if(a==0&&d==0&&b==c&&b>=0&&c>=0)return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int a,b,c,d;cin>>a>>b>>c>>d;
   if(try1(a,b,c,d))
  {
    cout<<"YES\n";
    for(int i=1;i<=a;i++)cout<<" 0 1",b--;
    for(int i=1;i<=b;i++)cout<<" 2 1",c--;
    for(int i=1;i<=d;i++)cout<<" 2 3";
    cout<<"\n";exit(0);
  }
  if(try2(a,b,c,d))
  {
    cout<<"YES\n";
    cout<<1;b--;
    for(int i=1;i<=a;i++)cout<<" 0 1",b--;
    for(int i=1;i<=b;i++)cout<<" 2 1",c--;
    for(int i=1;i<=d;i++)cout<<" 2 3";
    cout<<"\n";exit(0);
  }
  if(try3(a,b,c,d))
  {
    cout<<"YES\n";
    for(int i=1;i<=a;i++)cout<<" 0 1",b--;
    for(int i=1;i<=b;i++)cout<<" 2 1",c--;
    for(int i=1;i<=d;i++)cout<<" 2 3";
    cout<<" "<<2;
    cout<<"\n";exit(0);
  }
  if(a+b+c+d==1)
  {
    cout<<"YES\n";
    if(a)cout<<0;
    if(b)cout<<1;
    if(c)cout<<2;
    if(d)cout<<3;
    cout<<"\n";exit(0);
  }
  if(c==0&&d==0&&a==b+1)
  {
    cout<<"YES\n";cout<<0;
    for(int i=1;i<=b;i++)cout<<" 1 0";
    cout<<"\n";exit(0);
  }
  if(a==0&&b==0&&c+1==d)
  {
    cout<<"YES\n";cout<<3;
    for(int i=1;i<=c;i++)cout<<" 2 3";
    cout<<"\n";exit(0);
  }
  cout<<"NO\n";
  return 0;
}