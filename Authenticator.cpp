#include <iostream>
#include <cstring>
#include <cmath>


void compareChars(char a,char b, char c, char a1, char b1, char c1){

  if(a == a1 && b == b1 && c == c1){
    std::cout << "Message is Authentic" << std::endl;
  }
  else{
    std::cout << "Message is Invalid" << std::endl;
  }
}

void compareStrings(std::string s1, std::string s2){

  if(s1 == s2){
    std::cout << "Concurrence: Message is Authentic" << std::endl;
  }

  else{
    std::cout << "Concurrence: Message is Invalid" << std::endl;
  }
}
void checkSum(char a,char b, char c){
  const int k_iValidCodeChecksum = 5;
  int checkSumVal = (int(a) + int(b) + int(c)) % 7;
  int randVar = (int(a) + int(b) + int(c));
  if(checkSumVal == k_iValidCodeChecksum){
    std::cout << "Message Code Checksum is Valid: 5" << std::endl;
  }

    else{
      std::cout << "Message Code Checksum is Invalid: " << checkSumVal << " Expected: 5" << std::endl;
    }

    std::cout << "Sum of the Message Code Characters: " << randVar << std::endl;
}





int main(){


  const char k_cAuthenticatorCodeCharacter1 = 'E';
  const char k_cAuthenticatorCodeCharacter2 = 'C';
  const char k_cAuthenticatorCodeCharacter3 = 'A';

  char char1;
  char char2;
  char char3;

  std::string passString = "";
  std::string authString = "";


  std::cout << "Enter the First Character of the Message Code" << std::endl;

  std::cin >> char1;

  std::cout << "Enter the Second Character of the Message Code" << std::endl;

  std::cin >> char2;

  std::cout << "Enter the Third Character of the Message Code" << std::endl;

  std::cin >> char3;

  passString += char1;
  passString += char2;
  passString += char3;

  authString += k_cAuthenticatorCodeCharacter1;
  authString += k_cAuthenticatorCodeCharacter2;
  authString += k_cAuthenticatorCodeCharacter3;

  std::cout << "Authenticator Code: " << authString << std::endl;
  std::cout << "Message Code: " << passString << std::endl;

  compareChars(char1,char2,char3,k_cAuthenticatorCodeCharacter1,k_cAuthenticatorCodeCharacter2,k_cAuthenticatorCodeCharacter3);
  compareStrings(passString,authString);
  checkSum(char1,char2,char3);

  if(int(char1) != int(k_cAuthenticatorCodeCharacter1)){
    std::cout << "First Characters Do Not Match: Message; " << char1 << " Authenticator; " << k_cAuthenticatorCodeCharacter1 << std::endl;
  }
  if(int(char2) != int(k_cAuthenticatorCodeCharacter2)){
    std::cout << "First Characters Do Not Match: Message; " << char2 << " Authenticator; " << k_cAuthenticatorCodeCharacter2 << std::endl;
  }
  if(int(char3) != int(k_cAuthenticatorCodeCharacter3)){
    std::cout << "First Characters Do Not Match: Message; " << char2 << " Authenticator; " << k_cAuthenticatorCodeCharacter3 << std::endl;
  }

  if((int(char1) + int(char2) + int(char3)) < (int(k_cAuthenticatorCodeCharacter1) + int(k_cAuthenticatorCodeCharacter2) + int(k_cAuthenticatorCodeCharacter3))){
    std::cout << "The message code is lexicographically smaller than the authenitcator code" << std::endl;
  }
  if((int(char1) + int(char2) + int(char3)) > (int(k_cAuthenticatorCodeCharacter1) + int(k_cAuthenticatorCodeCharacter2) + int(k_cAuthenticatorCodeCharacter3))){
    std::cout << "The message code is lexicographically greater than the authenitcator code" << std::endl;
  }
return 0;
}
