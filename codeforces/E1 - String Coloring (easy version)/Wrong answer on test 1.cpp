/****************************************************************************************
*  @author: * kzvd4729                                       created: Feb/04/2020 21:49                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 21100 KB                             
*  problem: https://codeforces.com/contest/1296/problem/E1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5,inf=1e9;
int cl[N+2],mk[26][N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;string s;cin>>s;
   int mx=0;
  for(int i=0;i<n;i++)
  {
    int c=s[i]-'a';
     for(int color=1; ;color++)
    {
      int f=0;
      for(int j=25;j>c;j--)
        if(mk[j][color])f=1;
       if(!f)
      {
        cl[i]=color;mk[c][color]=1;
        mx=max(mx,color);break;
      }
    }
  }
  if(mx>2)cout<<"NO\n",exit(0);
  cout<<"YES\n";
   //cout<<mx<<endl;
  for(int i=0;i<s.size();i++)
    cout<<cl[s[i]-'a']-1;
  cout<<endl;
  return 0;
}