#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	ifstream codeInput;
	ofstream codeOut;
	codeInput.open("gcode.txt");
	codeOut.open("gcodenew.txt");
	while(!codeInput.eof())
	{
		string word;
		codeInput >> word;
		if(word.substr(0,1)=="X") codeOut << "draw(" << word.substr(1,4) <<"," ;
		if(word.substr(0,1)=="Y") codeOut << word.substr(1,4)<< ");" << endl <<"delay(100);" << endl;
	}
}
