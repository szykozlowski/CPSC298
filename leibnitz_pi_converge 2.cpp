#include <iostream>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <iomanip>


int main(){
  std::cout << std::fixed;
  std::cout << std::setprecision(DBL_DIG);
  double piOver4 = 0.0;
  double pi = 0.0;
  for(int n = 2; n <= 1048576; n*= 2){
    for(int k = 0; k <= n;k++){
      piOver4 += (pow(-1,k))/(2*k+1);

  }
  pi = piOver4 * 4;
  std::cout << "PI: " << pi << ";  n: " << n << std::endl;
  piOver4 = 0;
}
  return 0;
}
