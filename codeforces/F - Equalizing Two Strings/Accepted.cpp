/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/09/2019 12:05                        
*  solution_verdict: Accepted                                language: GNU C++11                               
*  run_time: 31 ms                                           memory_used: 700 KB                               
*  problem: https://codeforces.com/contest/1256/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int cnt[26];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    string a,b;cin>>a>>b;memset(cnt,0,sizeof(cnt));
    for(auto x:a)cnt[x-'a']++;
    for(auto x:b)cnt[x-'a']--;
    int f=0;
    for(int i=0;i<26;i++)f|=cnt[i];
    if(f){cout<<"NO\n";continue;}
    for(auto x:a)cnt[x-'a']++;
     for(int i=0;i<26;i++)f|=(cnt[i]>1);
    if(f){cout<<"YES\n";continue;}
     int cnt=0;
    for(int i=0;i<n;i++)
    {
      int id;
      for(int j=i;j<n;j++)
        if(a[i]==b[j])id=j;
      while(id>i)
      {
        swap(b[id],b[id-1]);
        cnt++;id--;
      }
    }
    if(cnt%2==0)cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}