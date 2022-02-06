/****************************************************************************************
*  @author: kzvd4729                                         created: May/08/2019 21:05                        
*  solution_verdict: Wrong answer on test 4                  language: PyPy 3                                  
*  run_time: 248 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/230/problem/B
****************************************************************************************/
from math import *
 n = int(input())
s = 0
y = 1
 num = [int(i) for i in input().split()]
 for i in range(n):
    y=1
    s = sqrt(num[i])
    check = (s).is_integer()
    if s == 1:
        print("NO")
    else:
        if check==False:
            print("NO")
        else:
            for j in range(2,int(sqrt(s))):
                if s % j == 0:
                    y = 0;
                    break;
                         if y == 1:
                print("YES")
            else:
                print("NO")
                               