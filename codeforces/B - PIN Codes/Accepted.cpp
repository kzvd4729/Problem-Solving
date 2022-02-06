/****************************************************************************************
*  @author: * kzvd4729                                       created: Nov/29/2019 20:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 23600 KB                             
*  problem: https://codeforces.com/contest/1263/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
string s[N+2];
map<string,int>fr,bk;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;fr.clear(),bk.clear();
    for(int i=1;i<=n;i++)cin>>s[i],bk[s[i]]++;
     int cnt=0;
    for(int i=1;i<=n;i++)
    {
      bk[s[i]]--;
      if(fr[s[i]])
      {
        cnt++;
        for(char c='0';c<='9';c++)
        {
          s[i][0]=c;
          if(!fr[s[i]]&&!bk[s[i]])break;
        }
      }
      fr[s[i]]++;
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=n;i++)
      cout<<s[i]<<"\n";
  }
  return 0;
}