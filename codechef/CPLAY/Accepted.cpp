/****************************************************************************************
*  @author: kzvd4729                                         created: 01-12-2017 19:07:24                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.67 sec                                        memory_used: 14.9M                                
*  problem: https://www.codechef.com/DEC17/problems/CPLAY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>s)
    {
        long cnt1=0,cnt2=0,t1=0,t2=0,f=0;
        for(long i=1;i<=10;i++)
        {
            if(i%2==1)cnt1+=s[i-1]-'0',t1++;
            else cnt2+=s[i-1]-'0',t2++;
            if(cnt1>cnt2+5-t2)
            {
                cout<<"TEAM-A "<<i<<endl;
                f=1;
                break;
            }
            else if(cnt2>cnt1+5-t1)
            {
                cout<<"TEAM-B "<<i<<endl;
                f=1;
                break;
            }
        }
        if(f)continue;
        for(long i=11;i<=20;i+=2)
        {
            if(s[i-1]=='1'&&s[i]=='0')
            {
                cout<<"TEAM-A "<<i+1<<endl;
                f=1;
                break;
            }
            else if(s[i-1]=='0'&&s[i]=='1')
            {
                cout<<"TEAM-B "<<i+1<<endl;
                f=1;
                break;
            }
        }
        if(f==0)cout<<"TIE"<<endl;
    }
    return 0;
}