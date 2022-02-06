/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 15:48                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/550/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    long f=0;
    for(long i=0;i<s.size();i++)
    {
        if(s[i]=='0')f=1;
        for(long j=i+1;j<s.size();j++)
        {
            for(long k=j+1;k<s.size();k++)
            {
                long num=(s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0';
                if(num%8==0)
                {
                    cout<<"YES"<<endl;
                    cout<<num<<endl;
                    return 0;
                }
            }
        }
    }
    if(f==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl<<0<<endl;
    return 0;
}