/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-11 20:52:09                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 680                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10107
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,arr[10005],i=0;
    while(cin>>arr[++i])
    {
        sort(arr+1,arr+i+1);
        if(i%2==0)cout<<(arr[i/2]+arr[(i/2)+1])/2<<endl;
        else cout<<arr[(i/2)+1]<<endl;
    }
    return 0;
}