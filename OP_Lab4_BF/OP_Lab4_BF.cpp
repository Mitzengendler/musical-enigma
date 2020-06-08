#include "MyWave.h"

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    if (argc != 4) {
        cout << "Недостаточно параметров для выполнения програмы!" << endl;
        return 0;
    }
    double c = atof(argv[3]);
    if (c == 0) {
        cout << "Ошибка" << endl;
        return 0;
    }
    MyWave wavFile(argv[1]);
    wavFile.changeWave(c);
    wavFile.writeWav(argv[2]);
    return 0;
}
