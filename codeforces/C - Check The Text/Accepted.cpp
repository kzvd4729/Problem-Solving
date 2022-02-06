/****************************************************************************************
*  @author: kzvd4729#                                        created: Oct/08/2019 14:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/gym/102263/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
 #define SP(x) cerr<<#x<<" = "<<x<<endl
#define DP(x) cerr<<#x<<" = "<<x.first<<" "<<x.second<<endl
#define F cerr<<"flag"<<endl
template<typename T>//container
void _p(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
 const int N=1e6;
int main()
{
  //freopen("inp.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;string s,k,x;cin>>s;
  for(int i=1;i<n;i++)
  {
    cin>>x;s=s+" "+x;
  }
  cin>>n;int cp=0;
  while(n--)
  {
    cin>>x;
    if(x=="CapsLock")cp^=1;
    else if(x=="Backspace")
    {
      if(k.size()>0)k.pop_back();
    }
    else if(x=="Space")k.push_back(' ');
    else
    {
      if(cp)x[0]=x[0]-'a'+'A';
      k.push_back(x[0]);
    }
  }
  if(k==s)cout<<"Correct"<<endl;
  else cout<<"Incorrect"<<endl;
  return 0;
}