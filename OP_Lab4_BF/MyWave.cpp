#include "MyWave.h"

using namespace std;

MyWave::MyWave(char file[]) {
	cout << "enter constr" << endl;
	cout << file << endl;
	
	readWave(file);
	cout << "leave constr" << endl;
}

MyWave::~MyWave() {
	
}

void MyWave::readWave(char file[])
{
	FILE* in;
	errno_t err;
	err = fopen_s(&in, file, "rb");
	if (err) {
		cout << "Failed to open input file, error: " << err;
		return;
	}
	fclose(in);
}