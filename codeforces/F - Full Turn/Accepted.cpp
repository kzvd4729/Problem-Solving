/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/25/2020 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 171 ms                                          memory_used: 6100 KB                              
*  problem: https://codeforces.com/contest/1468/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
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
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    int lt=0,rt=0,up=0,dw=0;
    map<pair<int,int>,int>fr,sc,th,ft;
    for(int i=1;i<=n;i++)
    {
      int a,b,c,d;cin>>a>>b>>c>>d;
      a=c-a,b=d-b;
      int g=__gcd(abs(a),abs(b));
      a/=g,b/=g;
       if(a==0)
      {
        if(b>0)up++;else dw++;
      }
      else if(b==0)
      {
        if(a>0)rt++;else lt++;
      }
      else
      {
        if(a>0&&b>0)fr[{a,b}]++;
        else if(a<0&&b>0)sc[{a,b}]++;
        else if(a<0&&b<0)th[{-a,-b}]++;
        else ft[{-a,-b}]++;
      }
      //cout<<a<<" "<<b<<endl;
    }
    long ans=0;ans+=1LL*up*dw+1LL*lt*rt;
    for(auto x:fr)ans+=1LL*x.second*th[x.first];
    for(auto x:sc)ans+=1LL*x.second*ft[x.first];
     cout<<ans<<'\n';
  }
  return 0;
}