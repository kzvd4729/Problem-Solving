/****************************************************************************************
*  @author: kzvd4729                                         created: 2021-02-03 19:42:40                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/URAL-1732
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9;

int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  string a,b;
  getline(cin,a);
  getline(cin,b);

  int id=0;
  for(int i=0;i<(int)a.size();i++)
  {
    if(id==(int)b.size())
    {
      a[i]='_';continue;
    }
    if(a[i]==b[id])id++;
    else if(b[id]==' ')a[i]='_',id++;
    else a[i]='_';
  }
  if(id!=(int)b.size())cout<<"I HAVE FAILED!!!";
  else cout<<a<<endl;
  
  return 0;
}