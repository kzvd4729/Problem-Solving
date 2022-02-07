/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-16 18:50:46                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-12403
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,n,m,total,tc;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>t)
    {
        total=0;
        while(t--)
        {
            cin>>s;
            if(s=="donate")cin>>m,total=total+m;
            else cout<<total<<endl;
        }

    }
    return 0;
}