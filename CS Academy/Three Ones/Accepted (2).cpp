/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10 ms                                           memory_used: 640 KB                               
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>s;
  int l,ans=0,cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='1')
    {
      l=i;
      break;
    }
  }
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='1')cnt++;
    if(cnt>3)
    {
      l++;
      cnt--;
      while(s[l-1]=='0')l++;
    }
    ans=max(ans,i-l+1);
  }
  cout<<ans<<endl;
  return 0;
}