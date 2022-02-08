/****************************************************************************************
*  @author: kzvd4729                                         created: 09-04-2019 17:39:15                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.53 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/APRIL19A/problems/KLPM
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
bool ck(string s)
{
  string k=s;reverse(s.begin(),s.end());
  return k==s;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;int n=s.size();int ans=0;
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    {
      for(int k=j+1;k<n;k++)
      {
        for(int l=k;l<n;l++)
        {
          ans+=ck(s.substr(i,j-i+1)+s.substr(k,l-k+1));
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}