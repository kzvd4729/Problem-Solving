/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-02-14 16:30:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12596
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
string s[12];
long dp[1000][22];
void calculate(void)
{
  for(char i='A';i<='Z';i++)
    dp[i][0]=1;
  for(int j=1;j<=20;j++)
  {
    for(char i='A';i<='Z';i++)
    {
      if(i=='A'||i=='B'||i=='C')
        dp[i][j]=dp['T'][j-1]+dp['W'][j-1]+dp['O'][j-1];
      if(i=='D'||i=='E'||i=='F')
        dp[i][j]=dp['T'][j-1]+dp['H'][j-1]+dp['R'][j-1]+dp['E'][j-1]+dp['E'][j-1];
      if(i=='G'||i=='H'||i=='I')
        dp[i][j]=dp['F'][j-1]+dp['O'][j-1]+dp['U'][j-1]+dp['R'][j-1];
      if(i=='J'||i=='K'||i=='L')
        dp[i][j]=dp['F'][j-1]+dp['I'][j-1]+dp['V'][j-1]+dp['E'][j-1];
      if(i=='M'||i=='N'||i=='O')
        dp[i][j]=dp['S'][j-1]+dp['I'][j-1]+dp['X'][j-1];
      if(i=='P'||i=='Q'||i=='R'||i=='S')
        dp[i][j]=dp['S'][j-1]+dp['E'][j-1]+dp['V'][j-1]+dp['E'][j-1]+dp['N'][j-1];
      if(i=='T'||i=='U'||i=='V')
        dp[i][j]=dp['E'][j-1]+dp['I'][j-1]+dp['G'][j-1]+dp['H'][j-1]+dp['T'][j-1];
      if(i=='W'||i=='X'||i=='Y'||i=='Z')
        dp[i][j]=dp['N'][j-1]+dp['I'][j-1]+dp['N'][j-1]+dp['E'][j-1];
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calculate();int t,tc=0;cin>>t;
  s[1]="ONE";s[2]="TWO";s[3]="THREE";s[4]="FOUR";s[5]="FIVE";
  s[6]="SIX";s[7]="SEVEN";s[8]="EIGHT";s[9]="NINE";
  while(t--)
  {
    string x;cin>>x;int n,k;cin>>n>>k;
    while(true)
    {
      for(auto i:x)
      {
        if(dp[i][n]>=k)
        {
          if(i=='A'||i=='B'||i=='C')x=s[2];
          if(i=='D'||i=='E'||i=='F')x=s[3];
          if(i=='G'||i=='H'||i=='I')x=s[4];
          if(i=='J'||i=='K'||i=='L')x=s[5];
          if(i=='M'||i=='N'||i=='O')x=s[6];
          if(i=='P'||i=='Q'||i=='R'||i=='S')x=s[7];
          if(i=='T'||i=='U'||i=='V')x=s[8];
          if(i=='W'||i=='X'||i=='Y'||i=='Z')x=s[9];
          break;
        }
        else k-=dp[i][n];
      }
      n--;
      if(!n)
      {
        cout<<"Case "<<++tc<<": "<<x[k-1]<<"\n";
        break;
      }
    }
  }
  return 0;
}