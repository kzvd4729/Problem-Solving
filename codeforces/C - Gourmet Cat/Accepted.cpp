/****************************************************************************************
*  @author: * kzvd4729                                       created: Apr/16/2019 20:54                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1154/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int ar[]={1,2,3,1,3,2,1,1,2,3,1,3,2,1};
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int a,b,c;cin>>a>>b>>c;
   int wa=3,wb=2,wc=2;
   int mn=min(min(a/wa,b/wb),c/wc);
   a-=wa*mn;b-=wb*mn;c-=wc*mn;
   int ans=7*mn,mx=0;
   for(int i=0;i<7;i++)
  {
    int aa=a,bb=b,cc=c,now=0;
    for(int j=i; ;j++)
    {
      if(ar[j]==1)
      {
        if(aa)aa--,now++;
        else break;
      }
      else if(ar[j]==2)
      {
        if(bb)bb--,now++;
        else break;
      }
      else
      {
        if(cc)cc--,now++;
        else break;
      }
    }
    mx=max(mx,now);
  }
  cout<<ans+mx<<endl;
  return 0;
}