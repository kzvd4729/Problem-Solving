/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/12/2018 13:01                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 140 ms                                          memory_used: 10400 KB                             
*  problem: https://codeforces.com/contest/990/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int n,k,x,fre[N+2];
set<int>st;
set<int>::iterator it;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n>>k;
for(int i=1;i<=n;i++)
{
cin>>x;
fre[x]++;
st.insert(x);
}
int ans=0,one,two;
for(it=st.begin(); ; )
{
one=*it;
it++;
if(it==st.end())break;
two=*it;
if(two-one>k)ans+=fre[one];
}
ans+=fre[one];
cout<<ans<<endl;
return 0;
}