# Chapter 8| Recursion and Dynamic Programming.

##### cracking the coding interview book

## How to Approach

#### generally:

- Recursive solutions built off solutions to subproblems.
- there are many ways to divide a problem into subproblems, most common Approaches are:
  - Bottom Up: The key here is to think about how you can build the solution for one case based on the previous case (or multiple previous cases).
  - Top-Down: we think about how we can divide the problem for case N into subproblems.
  - Half and Half: For example, binary search we first figure out which half of the array contains the value. Then we recurse and search for it in that half.

## Dynamic Programming & Memoization(Top-Down)

#### nth Fibonacci number "Recursive"

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
<br>
F(0) = 0, F(1) = 1
<br>
F(n) = F(n - 1) + F(n - 2), for n > 1.
<br>
ex.
<br>
0, 1, 1, 2, 3, 5, 8, 13, 21, 34

```c++
#include <iostream>
using namespace std;
```

```c++
int Fibonacci(int idx){
    if (idx == 0) return 0;
    if (idx == 1) return 1;
    return Fibonacci(idx - 1) + Fibonacci(idx - 2);
}

```

```c++
int idx;
cin >> idx;
```

```c++
Fibonacci(idx)
```

    21

#### We Should look for way to optimize this O(2^n) solution using Top-down dynamic Programming or Memoization

```c++
#include <iostream>
using namespace std;
```

```c++
int Fibonaccimemo(int idx, int memo[]){
    if (idx == 0 || idx == 1) return idx;
    if (memo[idx] == 0){//still not visited
        memo[idx] = Fibonaccimemo(idx - 1, memo) + Fibonaccimemo(idx - 2, memo);
    }
    return memo[idx];
}
```

```c++
const int MAX = 1000;
int memo[MAX];
```

```c++
int idx;
cin >> idx;
```

    9

```c++
Fibonaccimemo(idx, memo)
```

    34

#### we can also use Bottom-Up dynamic Programming

    - First, we compute fib(1) and fib( 0), which are already known from the base cases. Then we use those to compute fib(2). Then we use the prior answers to compute fib(3), then fib(4), and so on.

```c++
#include <iostream>
using namespace std;
```

```c++
int FibonacciBU(int n){
    if (n == 0 || n == 1) return n;
    int memo[n];
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i < n; i++){
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n - 1] + memo[n - 2];
}
```

```c++
int idx;
cin >> idx;
```

    9

```c++
FibonacciBU(idx)
```

    34

#### Note

-If you really think about how this works, you only use memo[i] for memo[i+1] and memo[i+2]. You don't need it after that. Therefore, we can get rid of the memo table and just store a few variables.

```c++
#include <iostream>
using namespace std;
```

```c++
int FibonacciBUI(int n){
    if (n == 0 || n == 1) return n;
    int memo[n];
    int a = 0;
    int b = 1;
    for (int i = 2; i < n; i++){
       int c = a + b;
        a = b;
        b = c;
    }
    return a + b;
}
```

```c++
int idx;
cin >> idx;
```

    9

```c++
 FibonacciBUI(idx)
```

    35
