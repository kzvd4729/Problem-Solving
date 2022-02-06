/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/09/2020 22:45                        
*  solution_verdict: Time limit exceeded on test 5           language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 4100 KB                              
*  problem: https://codeforces.com/contest/1312/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int aa[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
   int cnt=0;
  for(int i=1;i<=1000;i++)
  {
    vector<int>u;if(v.size()<2)break;
    for(int j=0;j<v.size();j++)
    {
      if(j<v.size()-1&&v[j]!=i||v[j+1]!=i)
      {
        u.push_back(v[j]);continue;
      }
      int c=0;
      for(int k=j;k<v.size();k++)
      {
        if(v[k]==i)c++;
        else break;
      }
      cnt+=c/2;
      if(c%2==0)
      {
        for(int k=1;k<=c/2;k++)u.push_back(v[j]+1);
      }
      else
      {
        int a=0,b=0;//cout<<"here"<<endl;
        for(int k=u.size()-1;k>=0;k--)
        {
          if(u[k]==v[j]+1)a++;
          else break;
        }
        for(int k=j+c;k<v.size();k++)
        {
          if(v[k]==v[j]+1)b++;
          else break;
        }
        if(b%2)
        {
          u.push_back(v[j]);
          for(int k=1;k<=c/2;k++)u.push_back(v[j]+1);
        }
        else
        {
          for(int k=1;k<=c/2;k++)u.push_back(v[j]+1);
          u.push_back(v[j]);
        }
      }
      j+=c-1;
    }
    //u.push_back(v.back());
    //for(auto x:u)cout<<x<<" ";
      //cout<<endl;
    v=u;
  }
  cout<<n-cnt<<endl;
  return 0;
}