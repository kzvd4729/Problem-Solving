/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2019 00:52                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/1110/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
map<int,int>mp;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  mp[3]=1;
  mp[7]=1;
  mp[15]=5;
  mp[31]=1;
  mp[63]=21;
  mp[127]=1;
  mp[255]=85;
  mp[511]=73;
  mp[1023]=341;
  mp[2047]=89;
  mp[4095]=1365;
  mp[8191]=1;
  mp[16383]=5461;
  mp[32767]=4681;
  mp[65535]=21845;
  mp[131071]=1;
  mp[262143]=87381;
  mp[524287]=1;
  mp[1048575]=349525;
  mp[2097151]=299593;
  mp[4194303]=1398101;
  mp[8388607]=178481;
  mp[16777215]=5592405;
  mp[33554431]=1082401;
  mp[67108863]=22369621;
   int q;cin>>q;
  while(q--)
  {
    int x;cin>>x;
    if(mp[x])
    {
      cout<<mp[x]<<"\n";
      continue;
    }
    int dg=32-__builtin_clz(x);
    cout<<((1<<dg)-1)<<"\n";
  }
  return 0;
}