#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <math.h>
#include<fstream>
#include "MyWave.h"

using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	if (argc != 4) {
		cout << "Недостаточно параметров для выполнения програмы!" << endl;
		return 0;
	}
	double interp = atof(argv[3]);
	if (interp == 0) {
		cout << "Ошибка" << endl;
		return 0;
	}

	cout << "Program starts" << endl;
	cout << argv[0] << endl;
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	cout << argv[3] << endl;
	
	MyWave wav;

	wav.readWave(argv[1]);

	wav.writeWave(argv[2]);
	
	return 0;
}