/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/01/2019 17:39                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1267/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>v;
    for(int i=1;i<=n+n;i++)v.push_back(i);
     random_shuffle(v.begin(),v.end());
    char c;int tr;
     for(auto x:v)
    {
      int cnt=0;
      for(int i=1;i<=n+n;i++)
      {
        if(i==x)continue;
        cout<<"? "<<i<<" "<<x<<endl;
        cin>>c;if(c=='>')cnt++;
      }
      if(cnt==n)
      {
        tr=x;break;
      }
    }
    for(int i=1;i<=n+n;i++)
    {
      if(tr==i)continue;
      cout<<"? "<<i<<" "<<tr<<endl;
    }
    cout<<"!"<<endl;
  }
   return 0;
}