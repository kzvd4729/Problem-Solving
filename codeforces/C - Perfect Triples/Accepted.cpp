/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/13/2020 09:51                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 218 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1338/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=1e6;
void dfs1(long bg,long ed,long n)
{
  if(n==1)
  {
    cout<<bg<<"\n";return ;
  }
  long pr=(ed-bg+1)/4;
  if(n<=pr)dfs1(bg,bg+pr-1,n);
  else if(n<=pr+pr)dfs1(bg+pr+pr,bg+pr+pr+pr-1,n-pr);
  else if(n<=pr+pr+pr)dfs1(bg+pr+pr+pr,bg+pr+pr+pr+pr-1,n-pr-pr);
  else dfs1(bg+pr,bg+pr+pr-1,n-pr-pr-pr);
}
void dfs2(long bg,long ed,long n)
{
  if(n==1)
  {
    cout<<bg<<"\n";return ;
  }
  long pr=(ed-bg+1)/4;//cout<<n<<endl;
  if(n<=pr)dfs2(bg,bg+pr-1,n);
  else if(n<=pr+pr)dfs2(bg+pr+pr+pr,bg+pr+pr+pr+pr-1,n-pr);
  else if(n<=pr+pr+pr)dfs2(bg+pr,bg+pr+pr-1,n-pr-pr);
  else dfs2(bg+pr+pr,bg+pr+pr+pr-1,n-pr-pr-pr);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long t;cin>>t;
  while(t--)
  {
    long n;cin>>n;
    if(n%3==1)
    {
      n/=3;n++;
      for(long i=0; ;i+=2)
      {
        long cn=(1LL<<i);
        if(n>cn)n-=cn;
        else
        {
          cout<<cn+n-1<<endl;
          break;
        }
      }
    }
    else if(n%3==2)
    {
      n/=3;n++;
      for(long i=0; ;i+=2)
      {
        long cn=(1LL<<i);
        if(n>cn)n-=cn;
        else
        {
          dfs1(cn+cn,cn+cn+cn-1,n);
          //cout<<cn+cn<<" "<<cn+cn+cn-1<<endl;
          break;
        }
      }
    }
    else
    {
      n/=3;
      for(long i=0; ;i+=2)
      {
        long cn=(1LL<<i);
        if(n>cn)n-=cn;
        else
        {
          //cout<<cn+cn+cn<<" "<<cn+cn+cn+cn-1<<endl;
          dfs2(cn+cn+cn,cn+cn+cn+cn-1,n);
          //cout<<cn+cn<<" "<<cn+cn+cn-1<<endl;
          break;
        }
      }
    }
  }
  return 0;
}