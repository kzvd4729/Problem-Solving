/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-11 11:20:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 24                                         memory_used (MB): 1.7                             
*  problem: https://vjudge.net/problem/LightOJ-1214
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t,n,i,c,tc=0,x;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s>>n;
        if(s[0]=='-')s.erase(s.begin()+0);
        if(n<0)n=n*-1;
        c=0;
        for(i=0;i<s.size();i++)
        {
            x=s[i]-'0';
            x=c*10+x;
            c=x%n;
        }
        if(c==0)cout<<"Case "<<++tc<<": divisible"<<endl;
        else cout<<"Case "<<++tc<<": not divisible"<<endl;
    }
    return 0;
}