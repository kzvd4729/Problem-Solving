/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/28/2019 20:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1138 ms                                         memory_used: 26500 KB                             
*  problem: https://codeforces.com/contest/1107/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5200;
string s[17],a;
int id,n;
bool aa[N+1][N+1];
bool ok(int x)
{
  for(int i=1;i<=n;i+=x)
  {
    for(int j=1;j<=n;j+=x)
    {
      int xx=-1;
      for(int ii=i;ii<i+x;ii++)
      {
        for(int jj=j;jj<j+x;jj++)
        {
          if(xx==-1)xx=aa[ii][jj];
          else if(xx!=aa[ii][jj])return false;
        }
      }
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  s[0]="0000";s[1]="0001";s[2]="0010";s[3]="0011";
  s[4]="0100";s[5]="0101";s[6]="0110";s[7]="0111";
  s[8]="1000";s[9]="1001";s[10]="1010";s[11]="1011";
  s[12]="1100";s[13]="1101";s[14]="1110";s[15]="1111";
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a;int j=1;
    for(auto x:a)
    {
      if(x>='0'&&x<='9')id=x-'0';
      else id=x-'A'+10;
      for(int k=0;k<4;k++)
        aa[i][j++]=bool(s[id][k]-'0');
    }
  }
  int ans=-1;
  for(int i=1;i<=n;i++)
  {
    if(n%i==0)
    {
      if(ok(i))ans=i;
    }
  }
  cout<<ans<<endl;
  return 0;
}