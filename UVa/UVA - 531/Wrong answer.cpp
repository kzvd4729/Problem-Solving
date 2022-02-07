/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-10 19:48:24                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-531
****************************************************************************************/
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
string x[101],y[101],s[101];
int grid[101][101];
int lx,ly;
void LCS(void)
{
    int i,j;
    for(i=1;i<=lx;i++)
    {
        for(j=1;j<=ly;j++)
        {
            if(x[i]==y[j])grid[i][j]=grid[i-1][j-1]+1;
            else grid[i][j]=max(grid[i-1][j],grid[i][j-1]);
        }
    }

    /*for(i=1;i<=lx;i++)
    {
        for(j=1;j<=ly;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }*/

}
void path_printing(void)
{
    int i,j,l,k;
    l=grid[lx][ly];
    k=0;
    for(i=lx;i>=1;i--)
    {
        for(j=ly;j>=1;j--)
        {
            if(grid[i][j]==l&&x[i]==y[j])
            {
                s[++k]=x[i];
                l--;
                break;
            }
        }
    }
    for(i=k;i>=1;i--)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    string s;
    int i;
    while(cin>>s)
    {
        x[1]=s;
        for(i=2;  ;i++)
        {
            cin>>s;
            if(s=="#")break;
            x[i]=s;
        }
        lx=i-1;
        for(i=1;  ;i++)
        {
            cin>>s;
            if(s=="#")break;
            y[i]=s;
        }
        ly=i-1;
        memset(grid,0,sizeof(grid));
        LCS();
        path_printing();


    }

    return 0;
}