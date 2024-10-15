# Discussion 6

The goal of this discussion is to explore generic C++ programming. Generic programming
is a style of programming that allows for code to be written in a way that is (more) independent
of the data types it operates on. This allows for greater code reuse and less code duplication. (For example,
imagine having to write a `max()` function for every type of number, and every type of container for
every type of number). 

In the bootcamp, we wrote some code to calculate an integral using the midpoint rule.
A variation of that code is in `integration_virtual.cpp`.
This single function takes in the bounds and number of points, and calculates the integral of a function.

This isn't very useful, though, as it is hardcoded to the `sin` function and to the midpoint rule.

There are a couple ways we can make this more flexible:

## Runtime polymorphism with virtual functions

We can create a base class that defines an `evaluate()` function as a pure virtual.
The integration function can then take a reference or pointer to this base class,
and call the evaluate() function. Then we can create derived classes that implement the evaluate function.

First, create the class structure above from the existing code. Then, create some derived classes that
implement various functions.

1. Other trigonometric functions
2. A quadratic function a*x*x + b*x + c. Class must store a, b, c
3. A general polynomial (ie, the user specifies the coefficients to some polynomial of arbitrary power).
   **HINT**: you can assume that all the coefficients are in order from the lowest power to the highest power

## Compile-time polymorphism with templates

An alternate way to provide flexibility is to use templates.

The file `integration_templates.cpp` also contains the code for the midpoint rule, except this function
is modified such that it can take an argument of any type that can be called like a function.
That is, `func(x)` must be a valid expression, and take a double and return a double. 

In main, there is an example of calling this kind of function with the `sin` function.

Fill in the rest of the midpoint rule function using templates. In this case, does the class need to derive
from the base class? Why or why not?

## Functors

Functors are a way to create objects that can be called like functions.
In C++, a functor is created by overloading the `operator()` function.
For example, a functor for the square function would look like this:

```C++
class SquareFunctor {
public:
    double operator()(double x) {
        return x*x;
    }
};
```

Then you can create an object of this class and call it like a function:

```C++
SquareFunctor f;
double y = f(5); // y = 25
```

In the context of this integration code, functors can be used to create objects that represent functions,
but contain some internal state. This would be similar to the classes you created in the first part.

Create a functor for the quadratic function from above. The functor should store the coefficients a, b, and c.
Then call the integration code with this functor.

Report out: What are the advantages and disadvantages of this over the derived class method?
Why would you use a functor over a plain function? Which one feels more like Python?


