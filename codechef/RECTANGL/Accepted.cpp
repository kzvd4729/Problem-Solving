/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2018 15:18:45                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/JAN18/problems/RECTANGL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,arr[10];
int main()
{
cin>>t;
while(t--)
{
for(long i=1;i<=4;i++)cin>>arr[i];
sort(arr+1,arr+5);
if(arr[1]==arr[2]&&arr[3]==arr[4])cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
return 0;
}