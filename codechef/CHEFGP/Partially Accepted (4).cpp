/****************************************************************************************
*  @author: kzvd4729                                         created: 07-10-2017 00:04:29                      
*  solution_verdict: Partially Accepted                      language: C++14                                   
*  run_time: 0.03 sec                                        memory_used: 15.2M                                
*  problem: https://www.codechef.com/OCT17/problems/CHEFGP
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,a,b,x,y,ga,gb;
string s,ans;
void case1(void)
{
    if(ga==1)for(long i=1; i<=a; i++)ans.push_back('a');
    else for(long i=1; i<=x; i++)ans.push_back('a');
    ga--;
    while(true)
    {
        if(!ga)
        {
            for(long i=1;i<=b;i++)ans.push_back('b');
            break;
        }
        if(b>=(ga-1)+y)
        {
            for(long i=1; i<=y; i++)ans.push_back('b');
            b-=y;
        }
        else if(b>(ga-1))
        {
            for(long i=(ga-1); i<=b; i++)ans.push_back('b');
            b=ga-1;
        }
        else if(b>=1)
        {
            ans.push_back('b');
            b--;
        }
        else if(ga)ans.push_back('*');
        if(ga)
        {
            if(ga==1)
            {
                if(a%x==0)for(long i=1; i<=x; i++)ans.push_back('a');
                else for(long i=1; i<=a%x; i++)ans.push_back('a');
            }
            else
            {
                for(long i=1; i<=x; i++)ans.push_back('a');
            }
            ga--;
        }
        else break;
    }
    cout<<ans<<endl;
}
void case2(void)
{
    if(gb==1)for(long i=1; i<=b; i++)ans.push_back('b');
    else for(long i=1; i<=y; i++)ans.push_back('b');
    gb--;
    while(true)
    {
        if(!gb)
        {
            for(long i=1;i<=a;i++)ans.push_back('a');
            break;
        }
        else if(a>=(gb-1)+x&&gb)
        {
            for(long i=1; i<=x; i++)ans.push_back('a');
            a-=x;
        }
        else if(a>(gb-1)&&gb)
        {
            for(long i=(gb-1); i<=a; i++)ans.push_back('a');
            a=gb-1;
        }
        else if(a>=1)
        {
            ans.push_back('a');
            a--;
        }
        else if(gb)ans.push_back('*');
        if(gb)
        {
            if(gb==1)
            {
                if(b%y==0)for(long i=1; i<=y; i++)ans.push_back('b');
                else for(long i=1; i<=b%y; i++)ans.push_back('b');
            }
            else
            {
                for(long i=1; i<=y; i++)ans.push_back('b');
            }
            gb--;
        }
        else break;
    }
    cout<<ans<<endl;
}
void init(void)
{
    a=0;
    b=0;
    ans.clear();
    cin>>s;
    cin>>x>>y;
    for(auto z:s)
    {
        if(z=='a')a++;
        else b++;
    }
    if(a%x==0)ga=a/x;
    else ga=(a/x)+1;
    if(b%y==0)gb=b/y;
    else gb=(b/y)+1;
    ///cout<<a<<" "<<b<<endl;
    if(ga>=gb)case1();
    else case2();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        init();
    }
    return 0;
}