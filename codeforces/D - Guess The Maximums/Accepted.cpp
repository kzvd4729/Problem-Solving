/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/02/2020 19:28                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 4400 KB                              
*  problem: https://codeforces.com/contest/1363/problem/D
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#define long long long
using namespace std;
const int N=1e6;
int ans[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;vector<vector<int> >v(k);
    for(int i=0;i<k;i++)
    {
      int x;cin>>x;v[i].resize(x);
      for(int j=0;j<x;j++)cin>>v[i][j];
       sort(v[i].begin(),v[i].end());
    }
    cout<<"? "<<n;
    for(int i=1;i<=n;i++)cout<<" "<<i;cout<<endl;
    int mx;cin>>mx;
     int lo=1,hi=n,md;
    while(lo<hi)
    {
      md=(lo+hi)/2;
      cout<<"? "<<md-lo+1;
      for(int i=lo;i<=md;i++)cout<<" "<<i;cout<<endl;
      int x;cin>>x;if(x==mx)hi=md;else lo=md+1;
    }
    md=lo;
    for(int i=0;i<k;i++)
    {
      int f=0;
      for(auto x:v[i])if(x==md)f=1;
       if(f)
      {
        int sz=0;//cout<<"rerte"<<endl;
        for(int j=1;j<=n;j++)
          if(!(binary_search(v[i].begin(),v[i].end(),j)))sz++;
        //cout<<"***"<<sz<<endl;
        assert(sz);
        cout<<"? "<<sz;
        for(int j=1;j<=n;j++)
          if(!binary_search(v[i].begin(),v[i].end(),j))cout<<" "<<j;
        cout<<endl;
        cin>>ans[i];
      }
      else ans[i]=mx;
    }
    cout<<"!";for(int i=0;i<k;i++)cout<<" "<<ans[i];cout<<endl;string s;cin>>s;
  }
   return 0;
}