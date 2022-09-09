#include "Song.h"
#include <iostream>
#include <iomanip>

using namespace std;

Song::Song()
{
}

Song::Song(const char* n, int d)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	durate = d;
}

Song::Song(const Song& obj)
{
	if (obj.name != nullptr)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy(this->name, obj.name);
	}
	this->durate = obj.durate;
	
}

Song::Song(Song&& obj)
{
	name = obj.name;
	durate = obj.durate;
	obj.name = nullptr;
}

Song::~Song()
{
	delete[] name;
}

Song& Song::operator=(const Song& obj)
{
	if (this == &obj)
		return *this;
	delete[] name;
	if (obj.name != nullptr)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy(this->name, obj.name);
	}
	this->durate = obj.durate;
	return *this;
}

Song& Song::operator=(Song&& obj)
{
	if (this == &obj)
		return *this;
	delete[] name;
	name = obj.name;
	durate = obj.durate;
	obj.name = nullptr;
	return *this;
}

const char* Song::getName() const
{
	return name;
}

int Song::getDurate() const
{
	return durate;
}

void Song::setName(const char* value)
{
	delete[]name;
	name = new char[strlen(value) + 1];
	strcpy(name, value);
}

void Song::setDurate(int value)
{
	durate = value;
}

void Song::Show() const
{
	cout << "Name of song = " << setw(20) << (name ? name : "Noname") <<  "\tDuration, sec = " << setw(6) << durate << endl;
}

ostream& operator<<(ostream& out, const Song& obj)
{
	out << "Name of song = " << setw(20) << obj.name << "\tDuration, sec = "<<setw(6) << obj.durate;
	return out;
}
