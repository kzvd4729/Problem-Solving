/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2018 19:02                        
*  solution_verdict: Time limit exceeded on test 6           language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 74100 KB                             
*  problem: https://codeforces.com/contest/675/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int sz=1,n,arr[N+2],ans;
struct tree
{
  int lft,rgt,vl;
}bst[60*N];
void insrt(int node,int par,int x)
{
  if(!bst[node].vl)
  {
    bst[node].vl=x;
    ans=par;
    return ;
  }
  if(x>bst[node].vl)
  {
    if(!bst[node].rgt)bst[node].rgt=++sz;
    insrt(bst[node].rgt,bst[node].vl,x);
  }
  else
  {
    if(!bst[node].lft)bst[node].lft=++sz;
    insrt(bst[node].lft,bst[node].vl,x);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    insrt(1,-1,arr[i]);
    if(i>1)cout<<ans<<" ";
  }
  cout<<endl;
  return 0;
}