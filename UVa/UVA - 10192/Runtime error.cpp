/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-03-07 01:49:40                      
*  solution_verdict: Runtime error                           language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10192
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char str1[10009],str2[10009],x;
long int t[10009][10009];
int main()
{
    int i,j,l1,l2,tc=0;
    while(gets(str1))
    {
        x=str1[0];
        if(x=='#')break;
        gets(str2);
        memset(t,0,sizeof(t));
        l1=strlen(str1);
        l2=strlen(str2);
        //cout<<str1[0]<<str2[0]<<endl;
        for(i=0;i<l1;i++)
        {
            for(j=0;j<l2;j++)
            {
                if(i==0)
                {
                    if(str1[i]==str2[j])t[i][j]=1;
                    else if(j>0)t[i][j]=t[i][j-1];
                }
                else
                {
                    if(str1[i]==str2[j])
                    {
                        if(j==0)t[i][j]=1;
                        else t[i][j]=t[i-1][j-1]+1;
                    }
                    else
                    {
                        if(j==0)t[i][j]=t[i-1][j];
                        else t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
                }
            }
        }

        /*for(i=0;i<l1;i++)
        {
            for(j=0;j<l2;j++)
            {
                cout<<t[i][j];
            }
            cout<<endl;
        }*/
        //cout<<t[l1-1][l2-1]<<endl;
        cout<<"Case #"<<++tc<<": you can visit at most "<<t[l1-1][l2-1]<<" cities."<<endl;



    }



    return 0;
}