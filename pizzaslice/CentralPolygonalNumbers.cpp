#include <iostream>
#include <fstream>
#include <cmath>

class CentralPolygonalNumbers{
public:
  CentralPolygonalNumbers(){
      m_nMax = 0;
      mp_iNumbers = new int[m_nMax + 1];
  }
  CentralPolygonalNumbers(int max){
    m_nMax = max;
    mp_iNumbers = new int[m_nMax + 1];
  }

  ~CentralPolygonalNumbers(){
    delete[] mp_iNumbers;
    std::cout << "~CentralPolygonalNumbers Called";
  }

  void display(){
    for(int i = 0;i <= m_nMax;i++){
      mp_iNumbers[i] = (pow(i,2) + i + 2)/2;
      std::cout << "n: " <<  i << " Maximum Number of Pieces: " << mp_iNumbers[i] << std::endl;
    }
  }
  bool save(std::string fileName){
    std::ofstream file (fileName);
    for(int i = 0; i <= m_nMax;i++){
      file << "n: " << i << " Maximum Number of Pieces: " << mp_iNumbers[i] << '\n';
    }
file.close();
return true;
  }

private:
  int m_nMax;
  int* mp_iNumbers;

};

int main(){
  CentralPolygonalNumbers central(10);
  central.display();
  central.save("filename1");

  return 0;
}
