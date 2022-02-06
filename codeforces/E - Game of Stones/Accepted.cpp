/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 15:19                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 249 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/768/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e2;
const int W=26;
map<pair<long,int>,int>dp;
int grundy(long msk,int xx)
{
  if(!xx)return 0;
  if(dp[{msk,xx}])return dp[{msk,xx}];
  set<int>st;
  for(long i=1;i<=xx;i++)
  {
    if(msk&(1LL<<i))continue;
    st.insert(grundy(msk|(1LL<<i),xx-i));
  }
  for(int i=0;i<N;i++)
    if(st.find(i)==st.end())return dp[{msk,xx}]=i;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 //  for(int i=1;i<=60;i++)
//    cout<<grundy(0,i)<<endl;
  vector<int>gr;
  for(int i=1;i<=10;i++)
  {
    int tmp=i+1;
    while(tmp--)
      gr.push_back(i);
  }
  int n,xxr=0;cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    xxr^=gr[x-1];
  }
  if(xxr)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}