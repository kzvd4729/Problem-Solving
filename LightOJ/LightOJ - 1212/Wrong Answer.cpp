/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-18 20:01:29                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1212
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
long t,n,m,x,c,tc;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        c=0;
        cout<<"Case "<<++tc<<":"<<endl;
        while(m--)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>x;
                if(c<n)
                {
                    c++;
                    cout<<"Pushed in left: "<<x<<endl;
                }
                else cout<<"The queue is full"<<endl;
            }
            else if(s=="pushRight")
            {
                cin>>x;
                if(c<n)
                {
                    c++;
                    cout<<"Pushed in right: "<<x<<endl;
                }
                else cout<<"The queue is full"<<endl;
            }
            else if(s=="popLeft")
            {
                if(c>0)
                {
                    c--;
                    cout<<"Popped from left: "<<x<<endl;
                }
                else cout<<"The queue is empty"<<endl;
            }
            else if(s=="popRight")
            {
                if(c>0)
                {
                    c--;
                    cout<<"Popped from right: "<<x<<endl;
                }
                else cout<<"The queue is empty"<<endl;
            }
        }
    }
    return 0;
}