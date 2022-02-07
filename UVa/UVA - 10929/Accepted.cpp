/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-11 20:24:48                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 20                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10929
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    long long int r,l,x;
    while(cin>>s)
    {
        if(s=="0")break;
        l=s.size();
        r=0;
        for(int i=0;i<l;i++)
        {
            x=s[i]-'0';
            r=(r*10+x)%11;
        }
        if(r==0)cout<<s<<" is a multiple of 11."<<endl;
        else cout<<s<<" is not a multiple of 11."<<endl;
    }
    return 0;
}