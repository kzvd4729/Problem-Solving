/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/08/2019 02:13                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/1185/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    string a,b;cin>>a>>b;
    int p=0,q=0,f=0;
    while(true)
    {
      if(p>=a.size()&&q>=b.size())break;
      if(p>=a.size()||q>=b.size()){f=1;break;}
      if(a[p]!=b[q]){f=1;break;}
      int c1=1;
      for(int i=p+1;i<a.size();i++)
      {
        if(a[i]==a[p])c1++;
        else break;
      }
      int c2=1;
      for(int i=q+1;i<b.size();i++)
      {
        if(b[i]==b[q])c2++;
        else break;
      }
      if(c1>c2){f=1;break;}
      p+=c1;q+=c2;
    }
    if(f)cout<<"NO\n";
    else cout<<"YES\n";
  }
  return 0;
}