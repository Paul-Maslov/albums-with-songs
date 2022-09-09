#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <ostream>
using namespace std;

class Song
{
private:
	char* name = nullptr;
	int durate = 0;
public:
	Song();
	Song(const char* n, int d);
	Song(const Song& obj);
	Song(Song&& obj);
	~Song();
	Song& operator=(const Song& obj);
	Song& operator=(Song&& obj);
	const char* getName()const;
	int getDurate()const;
	void setName(const char* value);
	void setDurate(int value);
	void Show()const;//  в принципе в функции Шоу нет необходимости, так как можем выводить с помощью перегруж оператора <<
	friend ostream& operator<<(ostream& os, const Song& obj);

};

