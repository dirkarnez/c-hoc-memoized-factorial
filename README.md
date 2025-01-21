c-hoc-memoized-factorial
========================
[Memoization - Wikipedia](https://en.wikipedia.org/wiki/Memoization)
```
function factorial (n is a non-negative integer)
    if n is 0 then
        return 1 [by the convention that 0! = 1]
    else if n is in lookup-table then
        return lookup-table-value-for-n
    else
        let x = factorial(n – 1) times n [recursively invoke factorial
                                         with the parameter 1 less than n]
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
