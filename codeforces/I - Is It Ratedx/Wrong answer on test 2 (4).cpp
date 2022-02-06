/****************************************************************************************
*  @author: jU_zQxRvd: iShibly, mh755628, kzvd4729           created: Apr/04/2021 18:09                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17 (64)                          
*  run_time: 124 ms                                          memory_used: 71500 KB                             
*  problem: https://codeforces.com/contest/1510/problem/I
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
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int th=2;
 string s[N+2];
char ans[N+2];
int sm[10000+2][1000+2];
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
  int p=1,pl=-1; int cr=0;
  for(int i=1;i<=m;i++)
  {
    cin>>s[i];
     if(pl==-1)cout<<rng()%2<<endl;
    else cout<<s[i][pl]<<endl;
     cin>>ans[i];
    for(int j=1;j<=n;j++)sm[i][j]=sm[i-1][j]+(ans[i]==s[i][j-1]);
      p++;
     if(p<=th)continue;
     int mx=-1;
    for(int j=1;j<=n;j++)
    {
      if(sm[i][j]-sm[i-th][j]>mx)mx=sm[i][j]-sm[i-th][j],pl=j-1;
    }
    p=1;
   }
  return 0;
}