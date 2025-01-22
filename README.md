c-hoc-memoized-factorial
========================
[Memoization - Wikipedia](https://en.wikipedia.org/wiki/Memoization)
- ```
  function factorial (n is a non-negative integer)
      if n is 0 then
          return 1 [by the convention that 0! = 1]
        else if n is in lookup-table then
          return lookup-table-value-for-n
      else
          let x = factorial(n – 1) times n [recursively invoke factorial with the parameter 1 less than n]
          store x in lookup-table in the nth slot [remember the result of n! for later]
          return x
      end if
  end function

  function construct-memoized-functor (F is a function object parameter)
      allocate a function object called memoized-version;

      let memoized-version(arguments) be
          if self has no attached array values then [self is a reference to this object]
              allocate an associative array called values;
              attach values to self;
          end if;

          if self.values[arguments] is empty then
              self.values[arguments] = F(arguments);
          end if;

          return self.values[arguments];
      end let;

      return memoized-version;
  end function
  ```
### Notes
- Since function in C language is not a first-class citizen, it is not possible to do HOC the JavaScript way (to return a hacked / enhanced function of same signature of target function):
  - ```js
    fucntion hoc(sumFunction) {
      return function (a, b) {
        // extra logic here
        return sumFunction(a, b)
      }
    }
    ```
  - Therefore, to mimic the above in C, we should share the function scope of `hoc`:
    - ```c
      int hoc(int (*fptr)(int, int), int a, b) {
        // extra logic here instead
        return fptr(a, b);
      }
      ```
      - This kind off solved the problem. BUT
        - if the target function called itself inside, we cannot modify the target function code inside
          - in [./src/main.c](./src/main.c) we have to do `hoc(&factorial, n - 1);`
            - And this means hoc is not 100% working in C, because we expected not having to modify the target function code
            - Why it works in JavaScript?
              - It works because Javascript supports function-identifier-overriding:
                - ```javascript
                  // This looks works in C, but it is not, because in C, when
                  // we cannot reassign classic function (see the code block after this)
                  recursiveFibonacci = memoize(recursiveFibonacci);
                  ```
                  ```c
                  int square(int num) {
                      return num * num;
                  }
                  
                  int main() {
                      int a = 10;
                      &square = &a; // we cannot do this in C
                  }
                  ```
                    - to make C works this way, we need extra hacks (maybe in Assembly language level)
