/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/29/2018 19:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2400 KB                              
*  problem: https://codeforces.com/contest/51/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
string ss[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s,tx;
  while(getline(cin,s))
  {
    if(s.size()==0)break;
    tx+=s;
  }
   int id=0,pt=0;
  //cin>>tx;
   for(int i=0;tx[i];i++)
  {
    if(tx[i]=='>')
    {
      ss[++id]=tx.substr(pt,i-pt+1);
      //cout<<ss[id]<<endl;
      pt=i+1;
    }
  }
  vector<int>ans;
  for(int i=1;i<=id;i++)
  {
    if(ss[i]!="<table>")continue;
    int bl=0,cnt=0;
    for(int j=i+1;j<=id;j++)
    {
      if(ss[j]=="</td>"&&bl==0)cnt++;
      if(ss[j]=="<table>")bl++;
      if(ss[j]=="</table>")
      {
        if(bl==0)
        {
          ans.push_back(cnt);break;
        }
        bl--;
      }
    }
  }
  sort(ans.begin(),ans.end());
  for(auto x:ans)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}