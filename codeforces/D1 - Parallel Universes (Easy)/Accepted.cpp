/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/07/2019 13:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1184/problem/D1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,k,m,t;cin>>n>>k>>m>>t;int lt=1,rt=n;
  while(t--)
  {
    int ty,nd;cin>>ty>>nd;
    if(ty==1)
    {
      rt++;
      if(lt+nd-1<=k)k++;
    }
    else
    {
      //cout<<"*"<<lt+nd-1<<endl;
      if(k<=lt+nd-1)rt=lt+nd-1;
      else lt+=nd;
    }
    //cout<<lt<<" -- "<<rt<<endl;
    cout<<rt-lt+1<<" "<<k-lt+1<<"\n";
  }
  return 0;
}