/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-31 18:41:52                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1346
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int t,tc,n;
double x,y,xx,xx2,yy,yy2,xx3,yy3,ax,a1,a2,b1,b2,c1,c2,ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>ax;
        xx=ax;
        yy=0;
        cin>>xx2>>yy2;
        ans=0;
        double mn=-9999999999;
        for(int i=2;i<=n;i++)
        {
            cin>>xx3>>yy3;
            double sl=(yy2-yy)/(xx2-xx);
            if(sl>=(mn-0.0001))
            {
                a1=yy2-yy;
                b1=xx-xx2;
                c1=a1*xx+b1*yy;
                mn=sl;
            }
            a2=yy3-yy2;
            b2=xx2-xx3;
            c2=a2*xx2+b2*yy2;
            double det=a1*b2-a2*b1;
            if(det!=0)
            {
                x=(b2*c1-b1*c2)/det;
                y=(a1*c2-a2*c1)/det;
                if(yy3>yy2&&x>=xx2&&x<=xx3&&y>=yy2&&y<=yy3)
                    ans+=sqrt((xx3-x)*(xx3-x)+(yy3-y)*(yy3-y));
            }
            xx2=xx3;
            yy2=yy3;
        }
        cout<<"Case "<<++tc<<": "<<setprecision(12)<<fixed<<ans<<endl;
    }
    return 0;
}