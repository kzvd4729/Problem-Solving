/****************************************************************************************
*  @author: kzvd4729                                         created: 18-02-2018 21:34:57                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/COOK91/problems/CCOOK
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,sum,x;
string s[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    s[0]="Beginner";
    s[1]="Junior Developer";
    s[2]="Middle Developer";
    s[3]="Senior Developer";
    s[4]="Hacker";
    s[5]="Jeff Dean";
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        sum=0;
        for(long j=1;j<=5;j++)
        {
            cin>>x;
            sum+=x;
        }
        cout<<s[sum]<<endl;
    }
    return 0;
}