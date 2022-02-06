/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/31/2017 21:08                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/784/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char n[100];
    while(cin>>n)
    {
        int i;
        for(i=0;i<strlen(n);i++)
        {
            cout<<n[i]-'0'-1;
            cout<<((n[i]-'0')*2+1);
        }
        cout<<endl;
    }
       return 0;
}