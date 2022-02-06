/****************************************************************************************
*  @author: kzvd4729#                                        created: May/09/2017 16:32                        
*  solution_verdict: Wrong answer on test 12                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/538/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
queue<char>q;
string s;
int main()
{
    q.push('C');
    q.push('O');
    q.push('D');
    q.push('E');
    q.push('F');
    q.push('O');
    q.push('R');
    q.push('C');
    q.push('E');
    q.push('S');
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==q.front())
        {
            q.pop();
        }
    }
    if(q.empty())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}