/****************************************************************************************
*  @author: kzvd4729                                         created: May/24/2020 00:36                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1354/problem/G
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
#define long long long
using namespace std;
const int N=1000;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;vector<int>a;
    vector<int>tmp;for(int i=1;i<=n;i++)tmp.push_back(i);
    shuffle(tmp.begin(),tmp.end(),rng);int mx=tmp[0];
    for(int i=1;i<min(n,20);i++)
    {
      cout<<"? "<<1<<" "<<1<<endl;
      cout<<mx<<endl<<tmp[i]<<endl;
      string s;cin>>s;if(s=="SECOND")mx=tmp[i];
    }
    a.push_back(mx);//cout<<mx<<endl;
    for(int i=1;i<=n;i++)if(i!=a[0])a.push_back(i);
    int p;
    for(p=2;p<=n;p+=p)
    {
      cout<<"? "<<p/2<<" "<<p/2<<endl;
      for(int i=0;i<p/2;i++)cout<<a[i]<<" ";cout<<endl;
      for(int i=p/2;i<p;i++)cout<<a[i]<<" ";cout<<endl;
      string s;cin>>s;
      if(s=="EQUAL")continue;
    }
    int pt=p/2;//cout<<"*"<<p<<endl;
    for(int i=p/2;i>0;i/=2)
    {
      if(pt+i>n)continue;
      cout<<"? "<<i<<" "<<i<<endl;
      for(int j=0;j<i;j++)cout<<a[j]<<" ";cout<<endl;
      for(int j=pt;j<pt+i;j++)cout<<a[j]<<" ";cout<<endl;
      string s;cin>>s;
      if(s=="EQUAL")pt+=i;else break;
    }
    cout<<"! "<<a[pt+1]<<endl;
  }
    return 0;
}