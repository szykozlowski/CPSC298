#include <iostream>

class ElectronicControlUnit
{
public:

    ElectronicControlUnit()
    {
      m_bActivatedHydraulicJacks = false;
      m_bActivatedBeltTires = false;
      m_bActivatedIRIllumination = false;
    }
    ~ElectronicControlUnit(){}

    void actuateHydraulicJacks(){
      m_bActivatedHydraulicJacks = !(m_bActivatedHydraulicJacks);
      if(m_bActivatedHydraulicJacks){
        std::cout << "Hydraulic Jacks Activated" << std::endl;
        m_bActivatedBeltTires = false;
        std::cout << "Belt Tires Deactivated" << std::endl;
      }
      else{
        std::cout << "Hydraulic Jacks Deactivated" << std::endl;
      }
    }

    void actuateIRIllumination(){
      m_bActivatedIRIllumination = !(m_bActivatedIRIllumination);
      if(m_bActivatedIRIllumination){
        std::cout << "Infared Illumination Activated" << std::endl;
      }
      else{
        std::cout << "Infared Illumination Deactivated" << std::endl;
      }

    }
    void actuateBeltTires(){
      m_bActivatedBeltTires = !(m_bActivatedBeltTires);
      if(m_bActivatedBeltTires){
        std::cout << "Belt Tires Activated" << std::endl;
      }
      else{
        std::cout << "Belt Tires Deactivated" << std::endl;
      }
    }


    void handleCommand(char cCommand){

      switch (cCommand){

        case 'A':
        case 'a':
          actuateHydraulicJacks();
          break;
        case 'B':
        case 'b':
          actuateBeltTires();
          break;
        case 'E':
        case 'e':
          actuateIRIllumination();
          break;
      }
    }

private:
  bool m_bActivatedHydraulicJacks;
  bool m_bActivatedBeltTires;
  bool m_bActivatedIRIllumination;
};

int main(){
  char input;
  ElectronicControlUnit obj1;

  std::cout << "Press X to turn off ingintion, or enter a steering wheel button(A,B,E)" << std::endl;
  std::cout << "\t(A)\n(F)\t(G)\t(B)\n(E)\t\t(C)\n\t(D)" << std::endl;
  std::cin >> input;

  while(input != 'X'){
    obj1.handleCommand(input);
    std::cout << "Press X to turn off ingintion, or enter a steering wheel button(A,B,E)" << std::endl;
    std::cout << "\t(A)\n(F)\t(G)\t(B)\n(E)\t\t(C)\n\t(D)" << std::endl;
    std::cin >> input;
  }





  //std::cout << "Works" << std::endl;
  return 0;
}
