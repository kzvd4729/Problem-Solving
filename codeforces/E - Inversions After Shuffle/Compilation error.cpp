/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/24/2019 21:01                        
*  solution_verdict: Compilation error                       language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/749/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
double ret(double n){return n*(n-1)/4.0;}
 pair<long,long>bit[N+2];
void upd(int id,int vl)
{
  for( ;id<=N;id+=id&-id)
    bit[id].first++,bit[id].second+=vl;
}
pair<long,long>get(int id)
{
  pair<long,long>ret;ret={0,0};
  for( ;id>0;id-=id&-id)
    ret.first+=bit[id].first,ret.second+=bit[id].second;
  return ret;
}
int main()
{
  dont compile
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;double ans=0;
  for(int i=1;i<=n;i++)ans+=ret(i)*(n-i+1);
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
      }
  return 0;
}