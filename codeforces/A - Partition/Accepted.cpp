/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/06/2018 22:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/946/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,num,sum;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        sum+=abs(num);
    }
    cout<<sum<<endl;
    return 0;
}