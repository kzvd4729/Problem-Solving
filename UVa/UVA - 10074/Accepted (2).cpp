/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-15 20:25:43                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 60                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10074
****************************************************************************************/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int m,n,arr[109][109],i,j,x,y,z,r,c,area,mx;
    while(cin>>m>>n)
    {
        if(m==0&&n==0)break;

        for(i=0;i<=103;i++)
        {
            for(j=0;j<=103;j++)
            {
                arr[i][j]=0;
            }
        }

        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>arr[i][j];
            }
        }

        for(i=1;i<=m;i++)
        {
            for(j=2;j<=n;j++)
            {
                arr[i][j]=arr[i][j-1]+arr[i][j];
            }
        }
        for(i=2;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                arr[i][j]=arr[i-1][j]+arr[i][j];
            }
        }

        /*for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/
        mx=0;

        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(x=i;x<=m;x++)
                {
                    for(y=j;y<=n;y++)
                    {
                        z=arr[x][y]-arr[x][j-1]-arr[i-1][y]+arr[i-1][j-1];
                        if(z==0)
                        {
                            r=abs(x-i)+1;
                            c=abs(y-j)+1;
                            area=r*c;
                            if(area>mx)mx=area;
                        }
                    }
                }
            }
        }

        cout<<mx<<endl;



    }


    return 0;
}