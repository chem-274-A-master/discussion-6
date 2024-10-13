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