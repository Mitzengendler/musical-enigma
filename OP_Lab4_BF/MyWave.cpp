#include "MyWave.h"

using namespace std;

MyWave::MyWave() {
	cout << "Класс создан!";
}

MyWave::~MyWave() {
	delete newData;
	delete data;
	cout << "Done";
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
	fread(&this->chunkId, sizeof(this->chunkId), 1, in);
	fread(&this->chunkSize, sizeof(this->chunkSize), 1, in);
	fread(&this->format, sizeof(this->format), 1, in);
	fread(&this->subchunk1Id, sizeof(this->subchunk1Id), 1, in);
	fread(&this->subchunk1Size, sizeof(this->subchunk1Size), 1, in);
	fread(&this->audioFormat, sizeof(this->audioFormat), 1, in);
	if (this->audioFormat != 1) {
		cout << "File was compressed!" << endl;
	}
	fread(&this->numChannels, sizeof(this->numChannels), 1, in);
	if (this->numChannels != 1) {
		cout << "Works only with MONO!" << endl;
	}
	fread(&this->sampleRate, sizeof(this->sampleRate), 1, in);
	fread(&this->byteRate, sizeof(this->byteRate), 1, in);
	fread(&this->blockAlign, sizeof(this->blockAlign), 1, in);
	if (this->blockAlign != 2) {
		cout << "Works only with bitrate: 16" << endl;
	}
	fread(&this->bitsPerSample, sizeof(this->bitsPerSample), 1, in);
	if (this->bitsPerSample != 16) {
		cout << "Works only with bitrate: 16" << endl;
	}
	fread(&this->subchunk2Id, sizeof(this->subchunk2Id), 1, in);
	fread(&this->subchunk2Size, sizeof(this->subchunk2Size), 1, in);
	this->data = new int16_t[this->subchunk2Size / this->blockAlign];
	for (int i = 0; i < this->subchunk2Size / this->blockAlign; i++) {
		int16_t temp;
		fread(&temp, sizeof(this->blockAlign), 1, in);
		this->data[i] = temp;
	}
	fclose(in);
}

void MyWave::writeWave(char file[])
{
	FILE* out;
	errno_t err;
	err = fopen_s(&out, file, "wb");
	if (err) {
		cout << "Failed to write a file, error: " << err;
		return;
	}
	fwrite(&this->chunkId, sizeof(this->chunkId), 1, out);
	fwrite(&this->chunkSize, sizeof(this->chunkSize), 1, out);
	fwrite(&this->format, sizeof(this->format), 1, out);
	fwrite(&this->subchunk1Id, sizeof(this->subchunk1Id), 1, out);
	fwrite(&this->subchunk1Size, sizeof(this->subchunk1Size), 1, out);
	fwrite(&this->audioFormat, sizeof(this->audioFormat), 1, out);
	fwrite(&this->numChannels, sizeof(this->numChannels), 1, out);
	fwrite(&this->sampleRate, sizeof(this->sampleRate), 1, out);
	fwrite(&this->byteRate, sizeof(this->byteRate), 1, out);
	fwrite(&this->blockAlign, sizeof(this->blockAlign), 1, out);
	fwrite(&this->bitsPerSample, sizeof(this->bitsPerSample), 1, out);
	fwrite(&this->subchunk2Id, sizeof(this->subchunk2Id), 1, out);
	fwrite(&this->subchunk2Size, sizeof(this->subchunk2Size), 1, out);
	for (int i = 0; i < this->subchunk2Size / this->blockAlign; i++) {
		fwrite(&this->newData[i], sizeof(this->newData[i]), 1, out);
	}
	fclose(out);
}

