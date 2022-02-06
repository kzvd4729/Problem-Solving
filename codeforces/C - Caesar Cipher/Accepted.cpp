/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/10/2019 17:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102222/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
   int n,m;cin>>n>>m;
   string a,b,c;cin>>a>>b>>c;
   int df=(a[0]-b[0]+26)%26;
    //cout<<df<<endl;
    cout<<"Case #"<<++tc<<": ";
   for(auto x:c)
   {
    int ad=(x-'A'+df)%26;
    cout<<(char)('A'+ad);
   }
   cout<<"\n";
  }
  return 0;
}