/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-02-28 21:01:15                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 10                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-495
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s[5001];
char temp[500001],order[500001];
void fibonacci(void)
{
    int i,l1,l2,x,c,k,z,l3,j;
    s[0]="0";
    s[1]="1";
    for(i=2;i<=5000;i++)
    {
        l1=s[i-2].size();
        l2=s[i-1].size();
        //cout<<l1<<endl<<l2<<endl;
        c=0;
        k=0;
        while(l2!=0)
        {
            l1--;
            l2--;
            if(l1<0)x=int(s[i-1][l2]-'0')+c;
            else x=int(s[i-2][l1]-'0'+s[i-1][l2]-'0')+c;
            //cout<<x<<endl;
            z=x%10;
            //cout<<z<<endl;
            c=x/10;
            //cout<<c<<endl;
            temp[k]=char(z+'0');
            //cout<<temp[k]<<endl;
            k++;
            //cout<<temp[k];
            //cout<<temp<<endl;
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
        k=strlen(temp);

        for(j=0;j<strlen(temp);j++)
        {
            k--;
            order[j]=temp[k];
        }
        //cout<<order<<endl;
        s[i]=order;

        //cout<<s[i]<<endl;

    }

}
int main()
{
    fibonacci();
    int n;
    while(cin>>n)
    {
        cout<<"The Fibonacci number for "<<n<<" is "<<s[n]<<endl;
    }
    return 0;
}