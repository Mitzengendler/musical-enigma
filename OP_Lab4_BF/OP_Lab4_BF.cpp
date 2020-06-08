#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "MyWave.h"

using namespace std;

int main(int argc, char* argv[]) {

	if (argc != 4) {
		cout << "Недостаточно параметров для выполнения програмы!" << endl;
		return 0;
	}

	cout << "Program starts" << endl;
	cout << argv[0] << endl;
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	cout << argv[3] << endl;
	MyWave wav(argv[1]);
}