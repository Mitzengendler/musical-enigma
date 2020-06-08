#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "MyWave.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "Creating Wave file" << endl;
	cout << argv[0] << endl;
	cout << argv[1] << endl;
	cout << argv[2] << endl;
	cout << argv[3] << endl;
	cout << "Done" << endl;
	MyWave wav(argv[1]);
}