/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-02-28 21:31:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-623
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s[1003];
char temp[100000],order[100000];
void factorial(void)
{
    int i,j,k,x,y,z,l1,l2,c;
    s[0]="1";
    s[1]="1";
    s[2]="2";
    for(i=3;i<=1000;i++)
    {
        l1=s[i-1].size();
        //cout<<l1<<endl;
        c=0;
        k=0;
        for(j=l1-1;j>=0;j--)
        {
            x=s[i-1][j]-'0';
            //cout<<x<<endl;
            x=(x*i)+c;
            //cout<<x<<endl;
            z=x%10;
            //cout<<z<<endl;
            c=x/10;
            //cout<<c<<endl;
            temp[k]=char(z+'0');
            //cout<<temp[k]<<endl;
            k++;

        }
        while(c)
        {
            z=c%10;
            temp[k]=char(z+'0');
            k++;
            c=c/10;
        }
        temp[k]='\0';
        //cout<<temp<<endl;
        l2=strlen(temp);
        //cout<<temp<<endl;
        int cnt=0;
        //cout<<l2<<endl;
        for(j=0;j<strlen(temp);j++)
        {
            l2--;
            order[j]=temp[l2];
            cnt++;

        }
        order[j]='\0';
        //cout<<cnt<<endl;
        //cout<<order<<endl;
        s[i]=order;

        //cout<<s[i]<<endl;


    }


}
int main()
{
    factorial();
    int n;
    while(cin>>n)
    {
        cout<<n<<"!"<<endl;
        cout<<s[n]<<endl;

    }
    return 0;
}