/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-29 23:01:09                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10286
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int main(){
    double pentagon_side;

    while (cin >> pentagon_side)
    {
        double tmp1=sqrt(5.0 + 2.0*sqrt(5.0));
        double tmp2=pentagon_side/(sqrt(2.0)*1.0);
        double square_side = .5 * tmp1 * tmp2;
        cout << fixed; cout << setprecision(10); cout << square_side << endl;
    }

    return 0;
}