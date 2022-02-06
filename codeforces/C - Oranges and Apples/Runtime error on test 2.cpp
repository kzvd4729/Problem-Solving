/****************************************************************************************
*  @author: kzvd4729                                         created: May/03/2020 21:42                        
*  solution_verdict: Runtime error on test 2                 language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 11900 KB                             
*  problem: https://codeforces.com/contest/23/problem/C
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+9;
struct data
{
  int a,b,id;
}aa[N+2];
long ta,tb;
void print(int n,set<int>st)
{
  cout<<"YES\n";//cout<<st.size()<<endl;
  for(int i=1;i<=n;i++)if(st.find(i)==st.end())cout<<i<<" ";
    cout<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;ta=0,tb=0;
    for(int i=1;i<=2*n-1;i++)
    {
      cin>>aa[i].a>>aa[i].b,aa[i].id=i;
      ta+=aa[i].a,tb=aa[i].b;
    }
    sort(aa+1,aa+2*n,[&](data a,data b){
      if(a.a!=b.a)return a.a>b.a;
      return a.b<b.b;
    });
    for(int i=2*n;i<=4*n;i++)aa[i]=aa[i-2*n+1];
    //for(int i=1;i<=n+n-1;i++)cout<<aa[i].a<<" ** "<<aa[i].b<<endl;
    long sa=0,sb=0;set<int>st;
    for(int i=1;i<n;i++)sa+=aa[i].a,sb+=aa[i].b,st.insert(aa[i].id);
    int f=0;
    if(sa<=ta/2&&sb<=tb/2)f=1,print(n+n-1,st);
    //cout<<ta<<" "<<tb<<" "<<sa<<" "<<sb<<endl;
    for(int i=n;i<=2*n;i++)
    {
      if(f==1)break;
      sa-=aa[i-n+1].a,sb-=aa[i-n+1].b,st.erase(aa[i-n+1].id);
      sa+=aa[i].a,sb+=aa[i].b,st.insert(aa[i].id);
      if(sa<=ta/2&&sb<=tb/2)f=1,print(n+n-1,st);
    }
    if(!f)assert(0);
  }
  return 0;
}