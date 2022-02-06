/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/19/2019 20:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1278/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    string a,b;cin>>a>>b;sort(a.begin(),a.end());
    int f=0;
    for(int i=0;i<(int)b.size()-(int)a.size()+1;i++)
    {
      string c=b.substr(i,(int)a.size());
      sort(c.begin(),c.end());
      if(a==c){f=1;break;}
    }
    if(f)cout<<"YES\n";else cout<<"NO\n";
  }
    return 0;
}