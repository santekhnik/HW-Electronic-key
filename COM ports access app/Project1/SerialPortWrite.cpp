#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"MyForm.h"

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
char* port = "\\\\.\\COM3";

int func() {
	SerialPort stm(port);
	if (stm.isConnected()) {
		cout << "Connection made" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}
	while (stm.isConnected()) {
		cout << "Enter your command: " << endl;
		string data;
		cin >> data;

		char* charArray = new char[data.size() + 1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		stm.writeSerialPort(charArray, MAX_DATA_LENGTH);
		stm.readSerialPort(output, MAX_DATA_LENGTH);

		cout << ">> " << output << endl;

		delete[] charArray;
	}
	return 0;
}