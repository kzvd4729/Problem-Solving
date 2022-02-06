/****************************************************************************************
*  @author: kzvd4729#                                        created: Feb/05/2020 15:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 27400 KB                             
*  problem: https://codeforces.com/gym/101873/problem/K
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
pair<int,string>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,d,k;cin>>n>>d>>k;
  for(int i=1;i<=n;i++)
    cin>>pp[i].second>>pp[i].first;
  sort(pp+1,pp+n+1);reverse(pp+1,pp+n+1);
   int sm=d,cnt=0;
  for(int i=1;i<=k;i++)
  {
    sm-=pp[i].first;cnt++;
    if(sm<=0)break;
  }
  if(sm>0)cout<<"impossible\n",exit(0);
  cout<<cnt<<endl;
  for(int i=1;i<=cnt;i++)
    cout<<pp[i].second<<", YOU ARE FIRED!\n";
   return 0;
}