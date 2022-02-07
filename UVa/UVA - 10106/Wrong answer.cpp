/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-12 23:41:38                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10106
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int arr[250][1000];
int a[300],b[300],s[1000];
int l1,l2;
void input(void)
{
    int i;
    l1=s1.size();
    l2=s2.size();
    int k=-1;
    for(i=l1-1;i>=0;i--)
    {
        a[++k]=s1[i]-'0';
    }
    k=-1;
    for(i=l2-1;i>=0;i--)
    {
        b[++k]=s2[i]-'0';
    }
}
void fx(void)
{
    int i,j;
    int m,n;
    m=-1,n=-1;
    for(i=0;i<l1;i++)
    {
        m=i;
        int c=0;
        for(j=0;j<l2;j++)
        {
            arr[i][m++]=((a[i]*b[j])+c)%10;
            c=((a[i]*b[j])+c)/10;
            if(j==l2-1)
            {
                while(c)
                {
                    arr[i][m++]=c%10;
                    c=c/10;
                }
            }
        }
    }
}
void sum(void)
{
    int i,j;
    memset(s,0,sizeof(s));
    for(i=0;i<250;i++)
    {
        for(j=0;j<1000;j++)
        {
            s[j]=s[j]+arr[i][j];
        }
    }
    int f=0;
    for(i=988;i>=0;i--)
    {
        if(s[i]!=0)f=1;
        if(f==1)
        {
            cout<<s[i];
        }
    }
    cout<<endl;
}
int main()
{
    while(cin>>s1>>s2)
    {
        memset(arr,0,sizeof(arr));
        memset(s,0,sizeof(s));
        input();
        fx();
        sum();
    }
    return 0;
}