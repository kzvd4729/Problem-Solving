/****************************************************************************************
*  @author: kzvd4729                                         created: 08-11-2017 14:08:01                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/NOV17/problems/CHEFHPAL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /// "aaababbbabaaababbb";
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k>=3)
        {
            cout<<1<<" ";
            for(long i=1; i<=n; i++)
            {
                long x=(i-1)%k;
                cout<<char(x+'a');
            }
            cout<<endl;
        }
        else if(k==1)
        {
            cout<<n<<" ";
            for(long i=1; i<=n; i++)cout<<"a";
            cout<<endl;
        }
        else
        {
            if(n==1)
            {
                cout<<1<<" ";
                cout<<"a"<<endl;
            }
            else if(n==2)
            {
                cout<<1<<" ";
                cout<<"ab"<<endl;
            }
            else if(n==3)
            {
                cout<<2<<" ";
                cout<<"aab"<<endl;
            }
            else if(n==4)
            {
                cout<<2<<" ";
                cout<<"aabb"<<endl;
            }
            else
            {
                cout<<3<<" ";
                for(long i=1; i<=n; i++)
                {
                    long x=i%10;
                    if(x==1||x==2||x==3||x==5||x==9)cout<<"a";
                    else cout<<"b";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}