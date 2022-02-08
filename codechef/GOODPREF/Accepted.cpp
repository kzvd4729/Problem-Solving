/****************************************************************************************
*  @author: kzvd4729                                         created: 07-04-2018 15:00:32                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
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
        int f=0;
        for(int j=1;j<=n;j++)
        {
          x=(j-1)*last+cnt[i];
          if(x<=0)
          {
            f=1;
            ans+=((j-1)*1LL);
            break;
          }
        }
        if(!f)ans+=(n*1LL);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}