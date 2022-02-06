/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/23/2018 19:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1058/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,d;cin>>n>>d;
  int q;cin>>q;
  while(q--)
  {
    int f1=0,f2=0,f3=0,f4=0;
    int x,y;cin>>x>>y;
    if(x+y>=d)f1=1;
    if(x+y<=n+n-d)f2=1;
    if(y-x<=d)f3=1;
    if(x-y<=d)f4=1;
    //cout<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<endl;
    if(f1&&f2&&f3&&f4)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}