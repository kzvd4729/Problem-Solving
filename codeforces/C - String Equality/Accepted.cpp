/****************************************************************************************
*  @author: kzvd4729#                                        created: Nov/27/2020 12:57                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/1451/problem/C
****************************************************************************************/
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
int fa[26+2],fb[26+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    string a,b;cin>>a>>b;
     memset(fa,0,sizeof fa);memset(fb,0,sizeof fb);
    for(auto x:a)fa[x-'a']++;
    for(auto x:b)fb[x-'a']++;
     int f=1;
    for(int i=0;i<25;i++)
    {
      if(fa[i]<fb[i]){f=0;break;}
      else if((fa[i]-fb[i])%k){f=0;break;}
      else fa[i+1]+=fa[i]-fb[i];
    }
    if(f)cout<<"Yes\n";else cout<<"No\n";
  }
  return 0;
}