/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/14/2019 18:49                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 500 KB                               
*  problem: https://codeforces.com/gym/102307/problem/I
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    string s,a;cin>>s;
    for(auto x:s)
    {
        if(x>='0'&&x<='9')a.push_back(x);
        else break;
    }
    if(a.size()==0)a="-1";
    cout<<a<<endl;
    return 0;
}