/****************************************************************************************
*  @author: kzvd4729                                         created: 22-10-2021 17:04:52                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 5.3M                                 
*  problem: https://www.codechef.com/SNCK1A21/problems/BINFLIP
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
const long N=1e6+10,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n,k;cin>>n>>k;
    if(k==0)
    {
      cout<<"YES"<<endl;cout<<0<<endl;
      continue;
    }
    if(k%2==0)
    {
      cout<<"NO"<<endl;continue;
    }
    long op=-1;
    for(long i=1; ;i++)
    {
      if((1<<(i-1))<=n)
      {
        if((1<<i)-1>=k)
        {
          op=i;break;
        }
      }
      else break;
    }
    //cout<<op<<endl;
    if(op==-1)assert(0);
    long kk=k,f=0;vector<long>v;
        long x=((1<<op)-1-k)/2;
    for(long i=1;i<=op;i++)
    {
      if(x&(1<<(i-1)))
      {
        v.push_back(k+1);
        k+=(1<<(i-1));
        kk+=(1<<(i-1));
      }
      else
      {
        k-=(1<<(i-1));
        kk-=(1<<(i-1));
        v.push_back(k+1);
      }
      if(kk<0 || kk>n)f=1;
    }
    if(f)
    {
      cout<<"NO"<<endl;continue;
    }
    cout<<"YES"<<endl;cout<<op<<endl;
    for(auto x:v)cout<<x<<endl;
  }
  return 0;
}