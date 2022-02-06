/****************************************************************************************
*  @author: kzvd4729#                                        created: May/13/2017 10:59                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/731/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i,x,sum=0;
    cin>>s;
    for(i=0;i<s.size()-1;i++)
    {
        x=abs(int(s[i]-s[i+1]));
        if(x>13)x=26-x;
        sum=sum+x;
    }
    x=abs(int('a'-s[0]));
    if(x>13)x=26-x;
    cout<<sum+x<<endl;
    return 0;
}