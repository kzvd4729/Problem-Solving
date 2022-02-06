/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2018 01:39                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1023/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   int n;cin>>n;
  int r=1,c=1;
  string lft,rgt;
  for(int i=1;i<n;i++)
  {
    cout<<"? "<<r+1<<" "<<c<<" "<<n<<" "<<n<<endl;
    fflush(stdout);
    string s;cin>>s;
    if(s=="YES")
    {
      lft.push_back('D');
      r++;
    }
    else
    {
      lft.push_back('R');
      c++;
    }
  }
  r=n,c=n;
  for(int i=1;i<n;i++)
  {
    cout<<"? "<<1<<" "<<1<<" "<<r<<" "<<c-1<<endl;
    fflush(stdout);
    string s;cin>>s;
    if(s=="YES")
    {
      rgt.push_back('R');
      c--;
    }
    else
    {
      rgt.push_back('D');
      r--;
    }
  }
  reverse(rgt.begin(),rgt.end());
  cout<<"! "<<lft+rgt<<endl;
  return 0;
}