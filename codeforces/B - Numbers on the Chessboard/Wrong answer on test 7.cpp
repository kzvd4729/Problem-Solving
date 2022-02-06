/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/21/2018 09:32                        
*  solution_verdict: Wrong answer on test 7                  language: GNU C++14                               
*  run_time: 311 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1027/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
  int n,q;cin>>n>>q;
 while(q--)
 {
  long r,c;cin>>r>>c;
  if(n%2==0)
  {
   if((r+c)%2==0)cout<<(n/2)*(r-1)+(c+1)/2<<endl;
   else cout<<(n*n)/2+(n/2)*(r-1)+(c+1)/2<<endl;
  }
  else 
  {
   if((r+c)%2==0)
   {
    r--;
    if(r%2==1)
    {
     r--;c+=n;
    }
    cout<<(r/2)*n+(c+1)/2<<endl;
   }
   else
   {
    r--;
    if(r%2==1)
    {
     r--;c+=n;
    }
    cout<<(n/2)*n+(n+1)/2+(r/2)*n+(c+1)/2<<endl;
   }
  }
 }
 return 0;
}