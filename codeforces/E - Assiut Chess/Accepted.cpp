/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/10/2021 16:34                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 46 ms                                           memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/1557/problem/E
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
 const int N=1e6,inf=1e9;
 map<string,pair<int,int> >mp;
 void pre()
{
  mp["Right"]={0,+1};
  mp["Left"]={0,-1};
  mp["Up"]={-1,0};
  mp["Down"]={+1,0};
  mp["Down-Right"]={+1,+1};
  mp["Down-Left"]={+1,-1};
  mp["Up-Left"]={-1,-1};
  mp["Up-Right"]={-1,+1};
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   pre();
   int t;cin>>t;
  while(t--)
  {
     vector<pair<int,int> >v;
    for(int i=1;i<=8;i++)
    {
      for(int j=1;j<=8;j++)v.push_back({i,j});
    }
        shuffle(v.begin(),v.end(),rng);
     int x=1+rng()%8,y=1+rng()%8;
     while(true)
    {
      //cout<<v.size()<<endl;
      cout<<x<<" "<<y<<endl;
      string s;cin>>s;
       if(s=="Done")break;
       for(auto &x:v)
      {
        x.first+=mp[s].first;
        x.second+=mp[s].second;
      }
      vector<pair<int,int> >tmp;
      for(auto z:v)
      {
        if(z.first>8 || z.second>8 || z.first<0 || z.second<0)continue;
        if(z.first==x || z.second==y)continue;
         if(abs(z.first-x)==abs(z.second-y))continue;
        tmp.push_back(z);
      }
      v=tmp;
      if((int)v.size()==0)assert(0);
       int i,j;
      if(v[0].first>x)i=+1;else i=-1;
      if(v[0].second>y)j=+1;else j=-1;
       int l=0;
      for(int k=1; ;k++)
      {
        if((x+k*i == v[0].first) || (y+k*j == v[0].second))break;
        l=k;
      }
      if(l)
      {
        x+=i*l,y+=j*l;continue;
      }
       for(int k=1; ;k++)
      {
        if((x+k*i == v[0].first))break;
        l=k;
      }
      if(l)
      {
        x+=i*l;continue;
      }
       for(int k=1; ;k++)
      {
        if((y+k*j == v[0].second))break;
        l=k;
      }
      if(l)
      {
        y+=j*l;continue;
      }
       assert(0);
    }
  }
    return 0;
}