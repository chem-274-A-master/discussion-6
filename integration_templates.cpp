#include <iostream>
#include <cmath>

template<typename T>
double calculate_integral_midpoint(T func, double a, double b, double npoints)
{
  return 1;
}

int main() {
  std::cout << calculate_integral_midpoint(sin, 0, 1, 100) << std::endl;
}