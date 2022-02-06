/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2017 21:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/841/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[5000],n,k;
int main()
{
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cnt[(int)s[i]]++;
        if(cnt[(int)s[i]]>k)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
     return 0;
}