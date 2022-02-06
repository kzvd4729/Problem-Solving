/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/17/2020 16:10                        
*  solution_verdict: Wrong answer on test 11                 language: GNU C++17                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1394/problem/C
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
int cal(int a,int b,int c,int d)
{
  int d1=a-c,d2=b-d;
  if((d1<=0&&d2<=0)||(d1>=0&&d2>=0))
  {
    d1=abs(d1),d2=abs(d2);
    return d1+d2-min(d1,d2);
  }
  return abs(d1)+abs(d2);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<pair<int,int> >v;
  int mna=inf,mxa=0,mnb=inf,mxb=0;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;int a=0,b=0;
    for(auto x:s)if(x=='B')a++;else b++;
    v.push_back({a,b});
    mna=min(mna,a),mxa=max(mxa,a);
    mnb=min(mnb,b),mxb=max(mxb,b);
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  int ans=inf,ca,cb;
  int mda=(mna+mxa)/2,mdb=(mnb+mxb)/2;
  for(int a=mda-100;a<=mda+100;a++)
  {
    for(int b=mdb-100;b<=mdb+100;b++)
    {
      if(a<0||b<0)continue;
      if(a==0&&b==0)continue;
      int mx=0;
      for(int j=0;j<v.size();j++)
        mx=max(mx,cal(v[j].first,v[j].second,a,b));
      if(mx<ans)ans=mx,ca=a,cb=b;
    }
  }
  cout<<ans<<endl;
  for(int i=1;i<=ca;i++)cout<<'B';
  for(int i=1;i<=cb;i++)cout<<'N';
  cout<<endl;
  return 0;
}