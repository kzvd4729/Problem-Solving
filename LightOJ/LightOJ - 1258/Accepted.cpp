/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-24 14:23:02                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 385                                        memory_used (MB): 17.8                            
*  problem: https://vjudge.net/problem/LightOJ-1258
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2000006;
string s,ss;
int t,tc;
/********* Knuth Morris Pratt **************/
int Kmp[N+2];
void KMP(string s)
{
  Kmp[0]=0;int n=s.size();
  for(int i=1;i<n;i++)
  {
    int now=Kmp[i-1];
    while(true)
    {
      if(s[now]==s[i])
      {
        Kmp[i]=now+1;break;
      }
      if(!now)break;
      now=Kmp[now-1];
    }
  }
}
///////////////////////////////////////////////
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
    KMP(s);
    printf("Case %d: %d\n",++tc,2*(l-Kmp[2*l])+Kmp[2*l]);
  }
  return 0;
}