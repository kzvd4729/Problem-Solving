/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-24 17:19:49                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/Kattis-4thought
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,t;
string s[20];
map<string,int>mp;
map<int,string>ans;
map<string,int>::iterator it;
void dfs(int cnt,string ans)
{
  if(ans.size()==3)
    mp[ans]=1;
  if(cnt>=4)return ;
  for(int i=1;i<=4;i++)
  {
    dfs(cnt+1,ans+s[1]);
    dfs(cnt+1,ans+s[2]);
    dfs(cnt+1,ans+s[3]);
    dfs(cnt+1,ans+s[4]);
  }
}
int main()
{
  //ofstream cout("out.txt");
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  s[1]="+";
  s[2]="-";
  s[3]="*";
  s[4]="/";
  dfs(0,"");


  ans[256]="4 * 4 * 4 * 4 = 256";
  ans[68]="4 * 4 * 4 + 4 = 68";
  ans[60]="4 * 4 * 4 - 4 = 60";
  ans[21]="4 * 4 * 4 / 4 = 21";
  ans[32]="4 * 4 + 4 * 4 = 32";
  ans[24]="4 * 4 + 4 + 4 = 24";
  ans[16]="4 * 4 + 4 - 4 = 16";
  ans[17]="4 * 4 + 4 / 4 = 17";
  ans[0]="4 * 4 - 4 * 4 = 0";
  ans[8]="4 * 4 - 4 - 4 = 8";
  ans[15]="4 * 4 - 4 / 4 = 15";
  ans[1]="4 * 4 / 4 / 4 = 1";
  ans[9]="4 + 4 + 4 / 4 = 9";
  ans[-8]="4 + 4 - 4 * 4 = -8";
  ans[7]="4 + 4 - 4 / 4 = 7";
  ans[4]="4 + 4 / 4 / 4 = 4";
  ans[-60]="4 - 4 * 4 * 4 = -60";
  ans[-16]="4 - 4 * 4 - 4 = -16";
  ans[-1]="4 - 4 - 4 / 4 = -1";
  ans[9]="4 / 4 + 4 + 4 = 9";
  ans[2]="4 / 4 + 4 / 4 = 2";
  ans[-15]="4 / 4 - 4 * 4 = -15";
  ans[-7]="4 / 4 - 4 - 4 = -7";
  ans[-4]="4 / 4 / 4 - 4 = -4";

  cin>>t;
  while(t--)
  {
    cin>>n;
    if(ans.find(n)==ans.end())
      cout<<"no solution"<<endl;
    else cout<<ans[n]<<endl;
  }



//  for(it=mp.begin();it!=mp.end();it++)
//  {
//    string x=it->first;
//    for(int i=0;i<x.size();i++)
//    {
//      cout<<"4 ";
//      cout<<x[i]<<" ";
//    }
//    cout<<4<<" = ";
//    cout<<endl;
//  }
  return 0;
}