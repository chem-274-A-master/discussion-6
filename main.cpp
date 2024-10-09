/* The goal of this discussion is to explore virtual functions and class structure

   In the bootcamp, we wrote some code to calculate an integral using the midpoint rule.
   A variation of that code is below. The function takes in the bounds and number of points,
   and calculates the integral of a function.

   This isn't very useful, though, as it is hardcoded to the sin function.

   Let's make this more flexible.

   1.) We can create a base class that defines an evaluate() function as a pure virtual.
       The integration function can then take a reference or pointer to this base class,
       and call the evaluate() function

   2.) Create classes derived from this base class that implement the evaluate function.
       Pass those into the integration function.

   What kinds of derived classes can you make?

   1.) Try a quadratic function a*x*x + b*x + c. Class must store a, b, c
   2.) Other trigonometric functions
   3.) Report out (in google slides): How could you do a general polynomial? ie, user specifies the maximum power and coefficient? Describe how this could be done in the shared Google slides, then write code for it in your replit.
   4.) Can you implement other integration methods? Trapezoidal rule or Simpson's rule?
   5.) Report out (in google slides): Could this be done better with templates? Should it?
   6.) Report out (in google slides): Could any other method be used to achieve generic functionality like this?
*/

#include <iostream>
#include <cmath>

double calculate_integral_midpoint(double a, double b, double npoints)
{
  double dx = (b-a)/npoints;
  double sum = 0.0;
  
  for(int i = 0; i < npoints; i++)
  {
      // Center of a rectangle
      // first is at 0.5dx, second at 1.5dx
      double x = a + (i+0.5)*dx;

      // evaluates a function
      double y = std::sin(x);

      // area of the rectangle
      sum += y*dx;
  }

  return sum;
}

int main() {
  std::cout << calculate_integral_midpoint(0, 1, 100) << std::endl;
  std::cout << calculate_integral_midpoint(0, 1, 1000) << std::endl;
}