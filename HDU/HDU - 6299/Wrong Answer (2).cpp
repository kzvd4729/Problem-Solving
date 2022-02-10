/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-20 00:53:24                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HDU-6299
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
string ss[N+2];
struct data
{
  int id,bl,dl;
}aa[N+2];
bool cmp(data a,data b)
{
  if(a.bl<=a.dl&&b.bl<=b.dl)
    return a.bl>b.bl;
  if(a.bl<=a.dl&&b.bl>=b.dl)
    return false;
  if(a.bl>=a.dl&&b.bl<=b.dl)
    return true;
  return a.dl<b.dl;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;int bl=0,mn=0;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='(')bl++;
        else bl--;mn=min(mn,bl);
      }
      aa[i]={i,bl,-mn};ss[i]=s;
    }
    sort(aa+1,aa+n+1,cmp);
    int ans=0,bl=0;
    for(int i=1;i<=n;i++)
    {
      int id=aa[i].id;
      for(int j=0;j<ss[id].size();j++)
      {
        if(ss[id][j]=='(')bl++;
        else if(bl)bl--,ans+=2;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}