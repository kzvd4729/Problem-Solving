/****************************************************************************************
*  @author: kzvd4729                                         created: 03-08-2018 16:58:54                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.02 sec                                        memory_used: 15.5M                                
*  problem: https://www.codechef.com/AUG18A/problems/RIVER
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    int cl[n+2];
    memset(cl,0,sizeof(cl));
    int cnt[3];
    cnt[0]=0,cnt[1]=0;
    cnt[0]++;
    for(int i=2;i<=n;i++)
    {
      int x;cin>>x;
      cl[i]=cl[x]^1;
      cnt[cl[i]]++;
      cout<<min(cnt[0],cnt[1])+1<<" ";
    }
    cout<<endl;
  }
  return 0;
}