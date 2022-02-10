/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-02 20:35:30                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 46                                         memory_used (MB): 5                               
*  problem: https://vjudge.net/problem/URAL-2060
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
const int N=1e6;

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
int st[N+2],ed[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  string s;cin>>s;manacher(s);
  for(int i=0;i<s.size();i++)
  {
    st[i-od[i]/2]++,st[i+1]--;ed[i]++,ed[i+od[i]/2+1]--;
  }
  for(int i=0;i<s.size()-1;i++)
  {
    st[i-ev[i]/2+1]++,st[i+1]--;ed[i+1]++,ed[i+1+ev[i]/2]--;
  }
  for(int i=1;i<s.size();i++)st[i]+=st[i-1],ed[i]+=ed[i-1];
  //for(int i=0;i<s.size();i++)cout<<ed[i]<<" ";cout<<endl;
  long ans=0;
  for(int i=0;i<s.size()-1;i++)
    ans+=1LL*ed[i]*st[i+1];
  cout<<ans<<endl;
  return 0;
}