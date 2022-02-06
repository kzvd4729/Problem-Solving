/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/17/2020 19:19                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 888 ms                                          memory_used: 17900 KB                             
*  problem: https://codeforces.com/contest/1398/problem/F
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
#include<deque>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int a[N+2],b[N+2],la[N+2],lb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;s="#"+s;
   for(int i=1;i<=n;i++)
  {
    a[i]=a[i-1]+(s[i]=='0');
    b[i]=b[i-1]+(s[i]=='1');
     la[i]=la[i-1];if(s[i]=='0')la[i]=i;
    lb[i]=lb[i-1];if(s[i]=='1')lb[i]=i;
  }
  for(int d=1;d<=n;d++)
  {
    int cnt=0,p=0;
    while(true)
    {
      if(p+d>n)break;
      if(a[p+d]-a[p]==0||b[p+d]-b[p]==0)cnt++,p+=d;
      else p=min(la[p+d],lb[p+d]);
    }
    cout<<cnt<<" ";
  }
  cout<<endl;
  return 0;
}