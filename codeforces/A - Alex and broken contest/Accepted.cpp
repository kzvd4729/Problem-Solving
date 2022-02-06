/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/05/2017 21:14                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/877/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     string s;
    cin>>s;
    string a="Danil";
    string b="Olya";
    string c="Slava";
    string d="Ann";
    string e="Nikita";
     long cnt=0;
    for(long i=0;i<s.size();i++)
    {
        for(long j=i;j<s.size();j++)
        {
            string x=s.substr(i,j-i+1);
            if(x==a||x==b||x==c||x==d||x==e)cnt++;
        }
    }
    ///cout<<cnt<<endl;
    if(cnt!=1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}