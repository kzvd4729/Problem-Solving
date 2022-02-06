/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 15:52                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/550/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long num;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>s;
    for(long i=0; i<s.size(); i++)
    {
        num=s[i]-'0';
        if(num%8==0)
        {
            cout<<"YES"<<endl;
            cout<<num<<endl;
            return 0;
        }
    }
    for(long i=0; i<s.size(); i++)
    {
        for(long j=i+1; j<s.size(); j++)
        {
            num=(s[i]-'0')*10+s[j]-'0';
            if(num%8==0)
            {
                cout<<"YES"<<endl;
                cout<<num<<endl;
                return 0;
            }
        }
    }
    for(long i=0; i<s.size(); i++)
    {
        for(long j=i+1; j<s.size(); j++)
        {
            for(long k=j+1; k<s.size(); k++)
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
    cout<<"NO"<<endl;
    return 0;
}