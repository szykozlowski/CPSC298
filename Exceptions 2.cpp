
#include <iostream>
#include <stdexcept>
#include <string>

unsigned long sigma(unsigned long n){
  unsigned long sum = 0;

  try{
    if(n >= 1){

    for(int i = 1; i <= n;i++){
      sum += i;
    }
    }

    else{


      std::string strMessage = "Precondition n >= 1 violated, invalid argument" + std::to_string(n) + "Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
      throw std::runtime_error(std::string(strMessage));
    }
    if(sum != n*(n+1)/2){
      throw std::runtime_error(std::string("Post Condition Not met"));
    }

  }

  catch(std::runtime_error & ex){
  std::cout << "Exceotion: " << ex.what() << std::endl;
  std::cout << "Cannot compute sum; Returning 0" << std::endl;
  sum = 0;
}
return sum;
}



int main(){

  std::cout << "Sigma(5): " << sigma(5) << std::endl;
  std::cout << "Sigma(0): " << sigma(0) << std::endl;
  return 0;
}
