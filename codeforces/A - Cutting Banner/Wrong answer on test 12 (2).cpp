/****************************************************************************************
*  @author: kzvd4729#                                        created: May/09/2017 16:37                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/538/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string c;
string s;
int main()
{
    c="CODEFORCES";
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==c[0])
        {
            c.erase(c.begin()+0);
        }
    }
    if(c.empty())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}