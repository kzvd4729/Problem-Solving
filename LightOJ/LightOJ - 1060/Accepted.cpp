/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-20 21:08:51                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 12                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1060
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,k,fre[30],l;
long fac[22];
char s[22];
void factorial(void)
{
  fac[0]=1;
  for(long i=1;i<=20;i++)
    fac[i]=fac[i-1]*i;
}
long cal(int x)
{
  long up,dw=1,sum=0;
  for(int i=0;i<26;i++)
  {
    sum+=fre[i];
    if(i==x)
      dw*=fac[fre[i]-1];
    else dw*=fac[fre[i]];
  }
  up=fac[sum-1];
  return up/dw;
}
int main()
{
  factorial();
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s%d",s,&k);
    l=strlen(s);
    memset(fre,0,sizeof(fre));
    for(int i=0;i<l;i++)
      fre[s[i]-'a']++;
    string ans;
    for(int i=0;i<l;i++)
    {
      for(int j=0;j<26;j++)
      {
        if(!fre[j])continue;
        long tmp=cal(j);
        if(k<=tmp)
        {
          ans.push_back(char(j+'a'));
          fre[j]--;
          break;
        }
        else k-=tmp;
      }
    }
    if(ans.size()!=l)cout<<"Case "<<++tc<<": "<<"Impossible"<<endl;
    else cout<<"Case "<<++tc<<": "<<ans<<endl;
  }
  return 0;
}