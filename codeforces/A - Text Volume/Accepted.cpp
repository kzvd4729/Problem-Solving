/****************************************************************************************
*  @author: kzvd4729                                         created: May/28/2020 14:55                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/837/problem/A
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
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;cin.ignore();
  string s;getline(cin,s);
   int ans=0,cur=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]>='A'&&s[i]<='Z')cur++;
    if(s[i]==' ')ans=max(ans,cur),cur=0;
  }
  cout<<max(ans,cur)<<endl;
    return 0;
}