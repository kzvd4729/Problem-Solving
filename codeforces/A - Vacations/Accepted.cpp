/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2017 02:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/698/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool con=false,gym=false;
    long ans=0;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(!x)
        {
            ans++;
            con=false;
            gym=false;
        }
        else if(x==1)
        {
            if(con)
            {
                ans++;
                con=false;
                gym=false;
            }
            else
            {
                con=true;
                gym=false;
            }
        }
        else if(x==2)
        {
            if(gym)
            {
                ans++;
                con=false;
                gym=false;
            }
            else
            {
                gym=true;
                con=false;
            }
        }
        else
        {
            if(gym!=con)swap(gym,con);
        }
    }
    cout<<ans<<endl;
    return 0;
}