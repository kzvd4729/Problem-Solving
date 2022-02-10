/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-22 19:04:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 604                                        memory_used (MB): 16.3                            
*  problem: https://vjudge.net/problem/LightOJ-1258
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s,ss;
int kmp[2000006],t,tc;
int main()
{
  scanf("%d",&t);
  while(t--)
  {
    cin>>s;
    int l=s.size();
    ss=s;
    reverse(s.begin(),s.end());
    s+="#"+ss;
 
    kmp[0]=0;
    for(int i=1;i<s.size();i++)
    {
      int now=kmp[i-1];
      while(true)
      {
        if(s[now]==s[i])
        {
          kmp[i]=now+1;
          break;
        }
        if(!now)break;
        now=kmp[now-1];
      }
    }
    printf("Case %d: %d\n",++tc,2*(l-kmp[2*l])+kmp[2*l]);
  }
  return 0;
}