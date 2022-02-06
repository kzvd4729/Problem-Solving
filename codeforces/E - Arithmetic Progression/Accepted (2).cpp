/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/24/2019 11:27                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1114/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
const long prime=1e9+7;
/********** Random Generator **********/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 Return unsigned int;
//mt19937_64 Return unsigned long int
//call rng() for random
//shuffle(v.begin(),v.end(),rng);
unsigned int Rand(unsigned int lo,unsigned int hi)
{
  unsigned int df=(hi-lo+1);
  return lo+rng()%df;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
   int lo=0,hi=1e9,md;int cnt=58;
  while(lo<hi)
  {
    md=(lo+hi)/2;
    cout<<"> "<<md<<endl;fflush(stdout);
    cnt--;int x;cin>>x;
    if(x)lo=md+1;else hi=md;
  }
  md=lo;
  srand(clock());int loop=1e5;set<int>st;
  if(n<=cnt)
  {
    for(int i=1;i<=n;i++)
      st.insert(i);
  }
  else
  {
    while(loop--)
    {
      if(cnt==0)break;
      int x=Rand(1,n);
      if(st.find(x)==st.end())
      {
        cnt--;st.insert(x);
      }
    }
  }
  vector<int>v;
  for(auto x:st)
  {
    cout<<"? "<<x<<endl;fflush(stdout);
    int z;cin>>z;v.push_back(z);
  }
  sort(v.begin(),v.end());
  int gc=0;
  for(int i=1;i<v.size();i++)
    gc=__gcd(gc,(v[i]-v[i-1]));
  if(gc==0)assert(0);/////////////
  cout<<"! "<<md-(n-1)*gc<<" "<<gc<<endl;
  return 0;
}