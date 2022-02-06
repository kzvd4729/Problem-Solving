/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/02/2020 22:19                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 3804 ms                                         memory_used: 98000 KB                             
*  problem: https://codeforces.com/contest/245/problem/H
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
#define long long long 
using namespace std;
const int N=5000;
 //od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manacher(string s)
{
  int n=s.size();
  od.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?1:min(od[l+r-i],r-i+1);
    while(0<=i-k&&i+k<n&&s[i-k]==s[i+k])k++;
    od[i]=k--;
    if(i+k>r)l=i-k,r=i+k;
  }
  ev.resize(n);
  for(int i=0,l=0,r=-1;i<n;i++)
  {
    int k=(i>r)?0:min(ev[l+r-i+1],r-i+1);
    while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k])k++;
    ev[i]=k--;
    if(i+k>r)l=i-k-1,r=i+k;
  }
  for(int i=0;i<n;i++)od[i]=od[i]*2-1;
  ev.erase(ev.begin());
  for(int i=0;i<n-1;i++)ev[i]=ev[i]*2;
}
int bit[N+2][N+2];
int cnt=0;
void upd(int x,int y)
{
  //cout<<x<<" -- "<<y<<endl;
  for( ;x<=N;x+=x&-x)
  {
    int yy=y;
    for( ;y<=N;y+=y&-y)
      bit[x][y]++;
    y=yy;
  }
}
int get(int x,int y)
{
  int ret=0;
  for( ;x>0;x-=x&-x)
  {
    int yy=y;
    for( ;y>0;y-=y&-y)
      ret+=bit[x][y];
    y=yy;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;manacher(s);
   for(int i=0;i<s.size();i++)
  {
    upd(i+1,i+1);
    for(int j=1;j<=od[i]/2;j++)
      upd(i+1-j,i+1+j);
  }
  for(int i=0;i<s.size()-1;i++)
  {
    for(int j=1;j<=ev[i]/2;j++)
      upd(i-j+1+1,i+j+1);
  }
  int q;cin>>q;
  while(q--)
  {
    int a,b,c,d;cin>>a>>b;c=b,d=b;b=a;
    cout<<get(c,d)-get(a-1,d)-get(c,b-1)+get(a-1,b-1)<<'\n';
  }
  return 0;
}