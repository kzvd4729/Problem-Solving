/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2018 14:58:15                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/APRIL18A/problems/GOODPREF
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,t,last,x,cnt[1003];
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>s>>n;
    int last=0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='a')cnt[i]=last+1;
      else cnt[i]=last-1;
      last=cnt[i];
      ///cout<<cnt[i]<<endl;
    }
    long ans=0;
    for(int i=0;i<s.size();i++)
    {
      if(cnt[i]>0&&last>=0)ans+=(n*1LL);
      else if(cnt[i]<=0&&last>0)
      {
        for(int j=1;j<=n;j++)
        {
          x=(j-1)*last+cnt[i];
          if(x>0)
          {
            ans+=((n-j+1)*1LL);
            break;
          }
        }
      }
      else if(cnt[i]>0&&last<0)
      {
        for(int j=1;j<=n;j++)
        {
          x=(j-1)*last+cnt[i];
          if(x<=0)
          {
            ans+=((j-1)*1LL);
            break;
          }
        }
        ans+=(n*1LL);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}