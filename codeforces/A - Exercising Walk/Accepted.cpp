/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/12/2020 11:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1332/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,c,d;cin>>a>>b>>c>>d;
    int x,y,x1,y1,x2,y2;cin>>x>>y>>x1>>y1>>x2>>y2;
     if(x2-x1==0&&(a+b)){cout<<"No\n";continue;}
    if(y2-y1==0&&(c+d)){cout<<"No\n";continue;}
    if(a-b>x-x1){cout<<"No\n";continue;}
    if(b-a>x2-x){cout<<"No\n";continue;}
    if(c-d>y-y1){cout<<"No\n";continue;}
    if(d-c>y2-y){cout<<"No\n";continue;}
     cout<<"Yes\n";
  }
  return 0;
}