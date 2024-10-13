#include <iostream>
#include <cmath>
#include <vector>

class BaseFunction
{
  public:
    virtual double evaluate(double x) = 0;
};

class SinFunction : public BaseFunction
{
  public:
    double evaluate(double x)
    {
      return std::sin(x);
    }
};

class QuadraticFunction : public BaseFunction
{
  private:
    double a_;
    double b_;
    double c_;
  public:
    QuadraticFunction(double a, double b, double c) : a_(a), b_(b), c_(c) {}

    double evaluate(double x)
    {
        return a_*x*x + b_*x + c_;
    }
};

class PolynomialFunction : public BaseFunction
{
  private:
    std::vector<double> coefficients_;
  public:
    PolynomialFunction(std::vector<double> coefficients) : coefficients_(coefficients) {}

    double evaluate(double x)
    {
        double result = 0.0;
        double x_power = 1.0;

        // coefficients go from lowest to highest power
        // We could just call pow(x, i) where i is the current power, but that would be inefficient
        for (size_t i = 0; i < coefficients_.size(); i++)
        {
            result += coefficients_[i]*x_power;
            x_power *= x;
        }

        return result;
    }
};

double calculate_integral_midpoint(double a, double b, double npoints, BaseFunction& func)
{
  double dx = (b-a)/npoints;
  double sum = 0.0;
  
  for(int i = 0; i < npoints; i++)
  {
      // Center of a rectangle
      // first is at 0.5dx, second at 1.5dx
      double x = a + (i+0.5)*dx;

      // evaluates a function
      double y = func.evaluate(x);

      // area of the rectangle
      sum += y*dx;
  }

  return sum;
}

int main() {
    SinFunction sf;
    QuadraticFunction qf(1, 2, 3);
    PolynomialFunction pf({3, 2, 1});
    std::cout << calculate_integral_midpoint(0, 1, 1000, sf) << std::endl;
    std::cout << calculate_integral_midpoint(-5, 5, 1000, qf) << std::endl;
    std::cout << calculate_integral_midpoint(-5, 5, 1000, pf) << std::endl;
}