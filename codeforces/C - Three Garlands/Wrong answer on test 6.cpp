/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/29/2017 10:27                        
*  solution_verdict: Wrong answer on test 6                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/911/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
long arr[5];
cin>>arr[1]>>arr[2]>>arr[3];
sort(arr+1,arr+4);
if(arr[1]==1)
{
cout<<"YES"<<endl;
return 0;        
}
if(arr[1]==2&&arr[2]==2)
{
cout<<"YES"<<endl;
return 0;                
}
if(arr[1]==3&&arr[2]==3&&arr[3]==3)
{
cout<<"YES"<<endl;
return 0;        
}
cout<<"NO"<<endl;
return 0;
}