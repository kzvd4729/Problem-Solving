/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/08/2021 15:28                        
*  solution_verdict: Wrong answer on test 43                 language: GNU C++17 (64)                          
*  run_time: 31 ms                                           memory_used: 4300 KB                              
*  problem: https://codeforces.com/contest/1537/problem/E1
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
 const int N=1e6,inf=1e9;
  /*
z[i] means maximum length of substring starting from i matches with prefix.
*/
vector<int>zFunction(string s)
{
  int n=s.size();vector<int>z(n);
  z[0]=0;//l,r maintains a window with maximum r
  for(int i=1,l=0,r=0;i<n;i++)
  {
    if(i<=r)z[i]=min(r-i+1,z[i-l]);//inside the window
    while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;//brute-force
    if(i+z[i]-1>r)l=i,r=i+z[i]-1;//r update
  }
  return z;
}
  int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n,k;cin>>n>>k;
   string s;cin>>s;
  vector<int>z=zFunction(s);
   for(int i=0;i<n;i++)z[i]=min(z[i],i-1);
  //for(int i=0;i<n;i++)cout<<z[i];cout<<endl;
   string ans;ans.push_back(s[0]);
  s.push_back('a');
   for(int i=1;i<n;i++)
  {
    if(s[z[i]]<s[i+z[i]])break;
    ans.push_back(s[i]);
  }
   while((int)ans.size()<k)ans+=ans;
  while((int)ans.size()>k)ans.pop_back();
   cout<<ans<<endl;
    return 0;
}