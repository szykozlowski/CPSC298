#include <iostream>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <iomanip>


int main(){
  std::cout << std::fixed;
  std::cout << std::setprecision(DBL_DIG);
  double piOver4 = 0.0;
  int n;
  std::cout << "Enter a number or something: "<< std::endl;
  std::cin >> n;
  for(int k = 0; k <= n;k++){
    piOver4 += (pow(-1,k))/(2*k+1);
  }
  double pi = piOver4 * 4;

  std::cout << "PI (approx): " << pi << "; n: " << std::setw(7) << n << std::endl;
  std::cout << "PI (actual): " << "3.141592653589793" << std::endl;

  std::cout << "Decimal Digits of Precision: " << DBL_DIG << std::endl;
  std::cout << "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << std::endl;
  std::cout << "Next representable number from 3.141592653589793: " << std::nextafter(3.141592653589793, 3.14) << std::endl;
  return 0;
}
