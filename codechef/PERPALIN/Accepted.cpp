/****************************************************************************************
*  @author: kzvd4729                                         created: 08-11-2017 12:23:31                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/NOV17/problems/PERPALIN
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,p;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        s.clear();
        cin>>n>>p;
        if(p<3)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        if(p%2==1)
        {
            for(long i=1;i<=p/2;i++)s.push_back('a');
            s.push_back('b');
            for(long i=1;i<=p/2;i++)s.push_back('a');
        }
        else
        {
            for(long i=1;i<=(p/2)-1;i++)s.push_back('a');
            s.push_back('b');
            s.push_back('b');
            for(long i=1;i<=(p/2)-1;i++)s.push_back('a');
        }
        for(long i=1;i<=n/p;i++)cout<<s;
        cout<<endl;
    }
    return 0;
}