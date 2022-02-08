/****************************************************************************************
*  @author: kzvd4729                                         created: 26-05-2018 19:41:58                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.18 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/LTIME60A/problems/SBSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,k,fre[400],mx,l,ans,dist,sum;
string s;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>s>>k;
    l=s.size();
    ans=0;
    for(int i=0;i<l;i++)
    {
      mx=0,sum=0,dist=0;
      memset(fre,0,sizeof(fre));
      for(int j=i;j<l;j++)
      {
        int c=int(s[j]);
        if(fre[c]==0)dist++;
        fre[c]++;
        mx=max(mx,fre[c]);
        sum++;
        if(dist>=k&&sum%mx==0&&sum/mx==dist)ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}