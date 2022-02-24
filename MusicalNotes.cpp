#include <iostream>
#include <cmath>


double calculateFrequency(double twelfth, double reference, int v, int k){
    return reference * pow(2,v) * pow(twelfth,k);
}

double calculateWavelength(int soundspeed, double frequency){
  return soundspeed/frequency * 100;

}
int main() {

  const double TWELFTH = 1.059463094359;
  const double REFERENCE = 16.35;
  const int SOUNDSPEED = 345;


    std::cout << "C#0: Frequency " << calculateFrequency(TWELFTH, REFERENCE,0,1) << std::endl;
    std::cout << "C#0 Wavelength: " << calculateWavelength(SOUNDSPEED, calculateFrequency(TWELFTH, REFERENCE,0,1)) << std::endl;

    std::cout << "D0: " << calculateFrequency(TWELFTH, REFERENCE,0,2) << std::endl;
    std::cout << "D0 Wavelength: " << calculateWavelength(SOUNDSPEED, calculateFrequency(TWELFTH, REFERENCE,0,2)) << std::endl;

    std::cout << "C4: " << calculateFrequency(TWELFTH, REFERENCE,4,0) << std::endl;
    std::cout << "C4 Wavelength: " << calculateWavelength(SOUNDSPEED, calculateFrequency(TWELFTH, REFERENCE,4,0)) << std::endl;

    std::cout << "D#7: " << calculateFrequency(TWELFTH, REFERENCE,7,3) << std::endl;
    std::cout << "D#7 Wavelength: " << calculateWavelength(SOUNDSPEED, calculateFrequency(TWELFTH, REFERENCE,7,3)) << std::endl;

    std::cout << "C8: " << calculateFrequency(TWELFTH, REFERENCE,8,0) << std::endl;
    std::cout << "C8 Wavelength: " << calculateWavelength(SOUNDSPEED, calculateFrequency(TWELFTH, REFERENCE,8,0)) << std::endl;





    return 0;
}
