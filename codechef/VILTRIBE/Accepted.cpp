/****************************************************************************************
*  @author: kzvd4729                                         created: 08-11-2017 11:21:48                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15M                                  
*  problem: https://www.codechef.com/NOV17/problems/VILTRIBE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,last,cnt,a,b;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        last=0;
        cnt=0;
        a=0;
        b=0;
        cin>>s;
        for(long i=0; i<s.size(); i++)
        {
            if(s[i]=='A')
            {
                a++;
                if(last==1)a+=cnt;
                last=1;
                cnt=0;
            }
            else if(s[i]=='B')
            {
                b++;
                if(last==2)b+=cnt;
                last=2;
                cnt=0;
            }
            else cnt++;
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}