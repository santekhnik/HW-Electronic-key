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

/*#include <iostream>


using namespace std;

int get_number;

*/