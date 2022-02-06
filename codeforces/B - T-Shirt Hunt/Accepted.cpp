/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2017 22:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/807/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,x,y,xx,yy,i,z,j,zz;
    cin>>p>>x>>y;
    xx=x;
    yy=y;
    for(i=xx; i>=yy; i=i-50)
    {
        z=(i/50)%475;
        for(j=1; j<=25; j++)
        {
            z=((z*96)+42)%475;
            zz=26+z;
            if(zz==p)
            {
                cout<<0<<endl;
                return 0;
            }
        }
    }
    xx=x;
    yy=y;
    int cnt=0;
    for(i=xx+50; i<=2000000; i=i+50)
    {
        cnt++;
        if(i>=yy)
        {
            z=(i/50)%475;
            for(j=1; j<=25; j++)
            {
                z=((z*96)+42)%475;
                zz=26+z;
                if(zz==p)
                {
                    cout<<(cnt+1)/2<<endl;
                    return 0;
                }
            }
         }
    }
     return 0;
}