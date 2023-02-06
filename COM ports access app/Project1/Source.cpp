#include "MyForm.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;




void hello() {
	cout << "Hello World";
}

void get_key_number(string strkey) {
	ifstream file("D:\\cpp\\keys.txt");
	if (!file.is_open())
		cout << "Error, the file with keys doesn't seem to exist!";
	else {
		int key = stoi(strkey);
		file >> key;
	}
}

void key_update(string strkey) {
	int key = stoi(strkey);
	int step, act;
	srand(time(NULL));
	step = rand() % 155 + 100;
	act = rand() % 2 + 1;

	cout << act;

	switch (act) {
	case 1:
		key += step;
		break;
	case 2:
		key -= step;
		break;
	}
	ofstream file("D:\\cpp\\keys.txt");
	file << key;
	file.close();
}

/// /////////////////////////////////////////////////////////////////
#ifndef SERIALPORT_H
#define SERIALPORT_H

#define STM_WAIT_TIME 0
#define MAX_DATA_LENGTH 255

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

class Port
{
private:
    HANDLE handler;
    bool connected;
    COMSTAT status;
    DWORD errors;
public:
    Port(char* portName);
    ~Port();

    int readSerialPort(uint8_t buffer[], unsigned int buf_size);
    bool writeSerialPort(uint8_t buffer[], unsigned int buf_size);
    bool isConnected();
};

#endif
Port::Port(char* portName)
{
    this->connected = false;

    this->handler = CreateFileA(static_cast<LPCSTR>(portName),
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);
    if (this->handler == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            printf("ERROR: Handle was not attached. Reason: %s not available\n", portName);
        }
        else
        {
            printf("ERROR!!!");
        }
    }
    else {
        DCB dcbSerialParameters = { 0 };

        if (!GetCommState(this->handler, &dcbSerialParameters)) {
            printf("failed to get current serial parameters");
        }
        else {
            dcbSerialParameters.BaudRate = 9600;
            dcbSerialParameters.ByteSize = 8;
            dcbSerialParameters.StopBits = ONESTOPBIT;
            dcbSerialParameters.Parity = NOPARITY;
            dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

            if (!SetCommState(handler, &dcbSerialParameters))
            {
                printf("ALERT: could not set Serial port parameters\n");
            }
            else {
                this->connected = true;
                PurgeComm(this->handler, PURGE_RXCLEAR | PURGE_TXCLEAR);
                Sleep(STM_WAIT_TIME);
            }
        }
    }
}

Port::~Port()
{
    if (this->connected) {
        this->connected = false;
        CloseHandle(this->handler);
    }
}

int Port::readSerialPort(uint8_t buffer[], unsigned int buf_size)
{
    DWORD bytesRead;
    unsigned int toRead = 0;

    ClearCommError(this->handler, &this->errors, &this->status);

    if (this->status.cbInQue > 0) {
        if (this->status.cbInQue > buf_size) {
            toRead = buf_size;
        }
        else toRead = this->status.cbInQue;
    }

    if (ReadFile(this->handler, buffer, toRead, &bytesRead, NULL)) return bytesRead;
    delete[] buffer;
    return 0;
}

bool Port::writeSerialPort(unsigned char buffer[], unsigned int buf_size)
{
    DWORD bytesSend;

    if (!WriteFile(this->handler, (void*)buffer, buf_size, &bytesSend, 0)) {
        ClearCommError(this->handler, &this->errors, &this->status);
        return false;
    }
    else return true;
}

bool Port::isConnected()
{
    return this->connected;
}
////////////////////


uint8_t output[8];
uint8_t incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
//char* port = "\\\\.\\COM3";

void portCommunicate(char* port) {
    unsigned char data[] = { 0x01, 0x00, 0x00, 0x00, 0x01, 0x00 };
    Port stm(port);
    if (stm.isConnected()) {
        cout << "\nConnection made" << endl << endl;
    }
    else {
        cout << "\nError in port name" << endl << endl;
    }
    if (stm.isConnected()) {

    

        stm.writeSerialPort(data, MAX_DATA_LENGTH);
        stm.readSerialPort(output, MAX_DATA_LENGTH);

        for (int i = 0; i < (sizeof(output) / sizeof(output[0])); i++) {
            printf("%d ", output[i]);
            //free( output);

        }
         
        //delete[] charArray;
    }
}

/*#include <iostream>


using namespace std;

int get_number;

*/