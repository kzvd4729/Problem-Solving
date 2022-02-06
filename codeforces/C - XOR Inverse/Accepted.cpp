/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/27/2020 21:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 686 ms                                          memory_used: 139900 KB                            
*  problem: https://codeforces.com/contest/1416/problem/C
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
const int N=1e6;
vector<vector<int> >tr;
int sz;long bg[30+2],sm[30+2];
void insrt(int x)
{
  int now=0;
  for(int i=30;i>=0;i--)
  {
    bool z=(x&(1<<i));
    if(z==0)
    {
      if(tr[now][1])bg[i]+=tr[tr[now][1]][2];
    }
    else
    {
      if(tr[now][0])sm[i]+=tr[tr[now][0]][2]; 
    }
    if(!tr[now][z])
    {
      tr[now][z]=++sz;
      tr.push_back({0,0,0});
    }
    now=tr[now][z];tr[now][2]++;
  }
}
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;tr.push_back({0,0,0});
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;insrt(x);
  }
  long inv=0;int xx=0;
  for(int i=30;i>=0;i--)
  {
    if(bg[i]==sm[i])inv+=bg[i];
    else if(bg[i]<sm[i])inv+=bg[i];
    else inv+=sm[i],xx^=(1<<i);
  }
  cout<<inv<<" "<<xx<<endl;
  //for(int i=30;i>=0;i--)if(bg[i])cout<<i<<" "<<bg[i]<<endl;
  return 0;
}