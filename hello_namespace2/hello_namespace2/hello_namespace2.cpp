/// @file <hello_namespace2.cpp> 
/// @brief <Asks for input and outputs it> 
/// @author <Szymon Kozlowski> 

#include <iostream> 
#include <string> 
using namespace std;
int main()
{
	string strMessage;
	cout << "Please type a single word message" << endl;
	cin >> strMessage;
	cout << "Message: " << strMessage << endl;
	return 0;
}