#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	string macaddress = "30:C0:1B:6B:05:3B";
	string command = "bluetoothctl connect " + macaddress;
	const char *bltcom = command.c_str(); //used to convert into a string that system() can use
	system(bltcom);
	command = "play ./v1.wav";
	const char *playcom = command.c_str();
	system(playcom);
	return 0;
}
