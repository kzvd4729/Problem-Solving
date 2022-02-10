/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-08-31 19:09:10                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 10                                         memory_used (MB): 4.2                             
*  problem: https://vjudge.net/problem/SPOJ-MSUBSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;

//od[i] is largest palindromic substring centered at i;
vector<int>od;
//ev[i] is largest palindromic substring centered at i and i+1;
vector<int>ev;
void manachar(string s)
{
  string x="@#";
  for(auto c:s)
    x.push_back(c),x.push_back('#');
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
  int t;cin>>t;
  while(t--)
  {
    od.clear();ev.clear();string s;cin>>s;
    vector<int>fr((int)s.size()+1,0);
    manachar(s);
    for(auto x:od)fr[x]++;
    for(auto x:ev)fr[x]++;
    for(int i=s.size(); ;i--)
    {
      if(fr[i])
      {
        cout<<i<<" "<<fr[i]<<"\n";
        break;
      }
    }
  }
  return 0;
}