/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2021 22:15:10                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.32 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/APRIL21A/problems/CHAOSEMP
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
const long Inf=1LL*inf*inf;
void solve()
{
  long lox=-Inf,hix=Inf,loy=-Inf,hiy=Inf;
  for(int i=1;i<=60;i++)
  {
    long mdx=(lox+hix)/2;
    long mdy=(loy+hiy)/2;
    cout<<1<<" "<<mdx<<" "<<mdy<<endl;
    string s;cin>>s;
    if(s=="O")return ;
    if(s[0]=='P' || s[0]=='X')hix=mdx+1;
    else lox=mdx+1,hix++;
    if(s[0]=='P' || s[0]=='Y')hiy=mdy+1;
    else loy=mdy+1,hiy++;
  }
  for(int i=0;  ;i++)
  {
    cout<<2<<" "<<lox+i<<" "<<loy+i<<" "<<hix<<" "<<hiy<<endl;
    string s;cin>>s;
    if(s=="O")return ;
    if(s=="OUT")assert(0);
  }
  assert(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,q,d;cin>>t>>q>>d;
  while(t--)
  {
    solve();
  }
  return 0;
}