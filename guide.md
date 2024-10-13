## Guide

The cpp files here are now filled in with some code.

The harder one is the general polynomial function. For this, it's best to use a `std::vector` to store the coefficients.
This way, you can create a polynomial of any degree by simply changing the size of the vector.
Since the coefficients are in order from lowest to highest power, you can evaluate the polynomial by summing up the terms,
multiplying by increasing power.

The naive way to do this is to loop over the coefficients, and using `std::pow` to raise `x` to the power.
However, the `std::pow` function is slow, and you can do better by keeping a running total of the power of `x`.

The template version closely mirrors the virtual function version. The main difference is that the template version
does not need to derive from a base class, and we implement the evaluation function by overloading
the `operator()` function. We do not need to derive from the base class because the compiler will generate
a different version of the function for each type that is passed in. As long as that type is callable with a double
and returns a double, the compiler will generate the correct code.

The main benefit to using the templated version is that various instantiations happen at compile time,
while the virtual function version requires a lookup at runtime. This can make the templated version faster, although
the difference is likely negligible in practice.

Why should we use functors over plain functions? Functors can store internal state (for example, the coefficients
of a polynomial). This is not possible to do (sanely) with plain functions.

The template version is most similar to python, where we can pass functions around as arguments.

Note that it is indeed possible to have a "function" type in C++, but that is a bit beyond the scope of this class
for now.