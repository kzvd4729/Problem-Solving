/****************************************************************************************
*  @author: kzvd4729                                         created: 08-04-2021 22:42:55                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
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
long ansx,ansy;
string ask1(long a,long b)
{
  //cout<<a<<" "<<b<<" "<<ansx<<" "<<ansy<<endl;
  cout<<1<<" "<<a<<" "<<b<<endl;
  string s;cin>>s;return s;
  if(a==ansx && b==ansy)return "O";
  if(a>ansx && b==ansy)return "PY";
  if(a<ansx && b==ansy)return "NY";
  if(a==ansx && b>ansy)return "XP";
  if(a==ansx && b<ansy)return "XN";
  if(a>ansx && b>ansy)return "PP";
  if(a>ansx && b<ansy)return "PN";
  if(a<ansx && b>ansy)return "NP";
  if(a<ansx && b<ansy)return "NN";
  if(rng()%2)ansx++;else ansy++;
  return "";
}
string ask2(long a,long b,long c,long d)
{
  cout<<2<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
  string s;cin>>s;return s;
  //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<ansx<<" "<<ansy<<endl;
  if(ansx==a || ansx==c)
  {
    if(ansy>=b && ansy<=d)return "O";
  }
  if(ansy==b || ansy==d)
  {
    if(ansx>=a && ansx<=c)return "O";
  }
  if(ansx>=a && ansx<=c && ansy>=b && ansy<=d)return "IN";
  return "OUT";
}
void tle()
{
  tle();
}
void solve()
{
  long lox=-Inf,hix=Inf,loy=-Inf,hiy=Inf;
  for(int i=1;i<=60;i++)
  {
    long mdx=(lox+hix)/2;
    long mdy=(loy+hiy)/2;
    //cout<<1<<" "<<mdx<<" "<<mdy<<endl;
    string s=ask1(mdx,mdy);
    if(s=="O")return ;
    if(s[0]=='P' || s[0]=='X')hix=mdx+1;
    else lox=mdx+1,hix++;
    if(s[1]=='P' || s[1]=='Y')hiy=mdy+1;
    else loy=mdy+1,hiy++;
  }
  //cout<<ansx<<" "<<ansy<<endl;
  //cout<<lox<<" "<<loy<<" "<<hix<<" "<<hiy<<endl;
  //cout<<lox<<" "<<hix<<endl;
  //cout<<hix<<" "<<hiy<<endl;
  for(int i=0;i<4;i++)
  {
    //cout<<2<<" "<<lox+i<<" "<<loy+i<<" "<<hix<<" "<<hiy<<endl;
    string s=ask2(lox+i,loy+i,hix,hiy);
    if(s=="O")return ;
    if(s=="OUT")tle();
  }
  assert(0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ansx=rng(),ansy=rng();
  int t,q,d;cin>>t>>q>>d;
  while(t--)
  {
    solve();
  }
  return 0;
}