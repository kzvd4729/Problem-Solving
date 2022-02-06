/****************************************************************************************
*  @author: * kzvd4729                                       created: Mar/06/2021 20:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1493/problem/B
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
 int rf[N+2],H,M;
bool isValid(int h,int m)
{
  if(rf[h%10]==-1)return 0;
  if(rf[h/10]==-1)return 0;
  if(rf[m%10]==-1)return 0;
  if(rf[m/10]==-1)return 0;
   int hh=rf[m%10]*10+rf[m/10];
  int mm=rf[h%10]*10+rf[h/10];
   return (hh<H) && (mm<M);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=0;i<10;i++)rf[i]=-1;
  rf[0]=0;
  rf[1]=1;
  rf[2]=5;
  rf[5]=2;
  rf[8]=8;
   int t;cin>>t;
  while(t--)
  {
    cin>>H>>M;string s;cin>>s;
     int h=(s[0]-'0')*10+(s[1]-'0');
    int m=(s[3]-'0')*10+(s[4]-'0');
     while(true)
    {
      if(isValid(h,m))break;
      m++;
      if(m==M)m=0,h++;
      if(h==H)h=0;
    }
    if(h<10)cout<<"0"<<h;
    else cout<<h;
    cout<<":";
     if(m<10)cout<<"0"<<m;
    else cout<<m;
    cout<<endl;
   }
    return 0;
}