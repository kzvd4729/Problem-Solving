/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-04 21:06:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11137
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main() 
{
    long long int n;
    while(cin>>n) 
    {
        long long int i,coin[25],j,x;
        j=0;
        for(i=1; i<=25; i++) 
        {
            x=i*i*i;
            if(x>n)break;
            else 
            {
                coin[j]=x;
                j++;
            }

        }
        long long int l=j-1;

        long long int mat[25][10003];
        memset(mat,0,sizeof(mat));
        mat[0][0]=1;

        for(i=0; i<=l; i++)
        {
            for(j=0; j<=n; j++)
            {
                if(i==0)
                {
                    if(j>=coin[i])mat[i][j]=mat[i][j-coin[i]];
                }
                else
                {
                    if(j>=coin[i])mat[i][j]=mat[i-1][j]+mat[i][j-coin[i]];
                    else mat[i][j]=mat[i-1][j];
                }
            }
        }

        cout<<mat[l][n]<<endl;

    }

    return 0;
}