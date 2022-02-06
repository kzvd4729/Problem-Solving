/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2017 21:16                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 0 ms                                            memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/784/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    while(cin>>n)
    {
        if(n<10)cout<<(n*10)-n<<endl;
        else cout<<(n*100)-n<<endl;
    }
    return 0;
}