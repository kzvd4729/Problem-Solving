/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-04-25 16:18:21                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/HackerRank-caesar-cipher-1
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,k;
string s;
vector<char>v1,v2;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for(int i=1;i<=100;i++)
    for(char j='a';j<='z';j++)
      v1.push_back(j);
  for(int i=1;i<=100;i++)
    for(char j='A';j<='Z';j++)
      v2.push_back(j);

  cin>>n;
  cin>>s;
  cin>>k;

  int x;
  for(int i=0;s[i];i++)
  {
    if(s[i]>='a'&&s[i]<='z')
    {
      x=s[i]-'a';
      x+=k;
      cout<<v1[x];
    }
    else if(s[i]>='A'&&s[i]<='Z')
    {
      x=s[i]-'A';
      x+=k;
      cout<<v2[x];
    }
    else cout<<s[i];
  }
  cout<<endl;
  return 0;
}