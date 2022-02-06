/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/20/2017 16:33                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/862/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,HD,hd,pos1,pos2;
string s;
void gen(long lo,long mid)
{
    for(long i=1; i<=n; i++)
    {
        s[i-1]='0';
    }
    for(long i=lo; i<=mid; i++)
    {
        s[i-1]='1';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1; i<=n; i++)s.push_back('0');
    cout<<"? "<<s<<endl;
    fflush(stdout);
    cin>>HD;
     long lo=0;
    long hi=n;
    long mid;
     while(true)
    {
        mid=(lo+hi)/2;
        gen(lo,mid);
        cout<<"? "<<s<<endl;
        fflush(stdout);
        cin>>hd;
        if(hd+(hi-lo+1)==HD||hd-(hi-lo+1)==HD)
        {
            lo=mid;
        }
        else hi=mid;
        if(hi-lo<=1)
        {
            gen(lo,lo);
            cout<<"? "<<s<<endl;
            fflush(stdout);
            cin>>hd;
            if(hd==HD)
            {
                pos1=lo;
            }
            else pos2=lo;
             if(lo>=2)
            {
                gen(lo-1,lo-1);
                cout<<"? "<<s<<endl;
                fflush(stdout);
                cin>>hd;
                if(hd==HD)
                {
                    pos1=lo;
                }
                else pos2=lo;
            }
            gen(hi,hi);
            cout<<"? "<<s<<endl;
            fflush(stdout);
            cin>>hd;
            if(hd==HD)
            {
                pos1=lo;
            }
            else pos2=lo;
            cout<<"! "<<pos1<<" "<<pos2<<endl;
            return 0;
         }
     }
    return 0;
}