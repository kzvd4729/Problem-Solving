/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-04-06 12:12:23                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 30                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11475
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manachar(string s)
{
  string x="@#";
  for(auto c:s)x.push_back(c),x.push_back('#');
  x.push_back('$');s=x;
  int n=s.size();
  int l=0,r=0;vector<int>pp(n);
  for(int i=0;i<n;i++)
  {
    pp[i]=min(r-i,pp[l+r-i]);
    while(s[i-pp[i]]==s[i+pp[i]])pp[i]++;
    if(i+pp[i]>r)l=i-pp[i],r=i+pp[i];
  }
  for(int i=2;i<n-1;i+=2)
    od.push_back(pp[i]-1);
  for(int i=3;i<n-1;i+=2)
    ev.push_back(pp[i]-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;while(cin>>s)
  {
    od.clear(),ev.clear();manachar(s);
    int b=0;
    for(int i=0;i<od.size();i++)
    {
      if(i+od[i]/2==s.size()-1)b=max(b,od[i]);
    }
    for(int i=0;i<ev.size();i++)
    {
      if(i+ev[i]/2==s.size()-1)b=max(b,ev[i]);
    }
    cout<<s;for(int i=s.size()-b-1;i>=0;i--)cout<<s[i];
    cout<<endl;
  }
  return 0;
}