/****************************************************************************************
*  @author: kzvd4729                                         created: 08-11-2017 19:50:18                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/NOV17/problems/CHEFHPAL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,k;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    s="aaaababbaa";
    while(s.size()<=200000)s+="babbaa";
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
            if(n==1)cout<<1<<" a"<<endl;
            else if(n==2)cout<<1<<" ab"<<endl;
            else if(n==3)cout<<2<<" abb"<<endl;
            else if(n==4)cout<<2<<" aabb"<<endl;
            else if(n==5)cout<<3<<" aaabb"<<endl;
            else if(n==6)cout<<3<<" aaabab"<<endl;
            else if(n==7)cout<<3<<" aaababb"<<endl;
            else if(n==8)cout<<3<<" aaababbb"<<endl;
            else
            {
                cout<<4<<" ";
                for(long i=0;i<n;i++)cout<<s[i];
                cout<<endl;
            }
        }
    }
    return 0;
}