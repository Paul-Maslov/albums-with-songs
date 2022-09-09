#include <iostream>
#include <iomanip>
#include "Song.h"
#include "Album.h"

using namespace std;


Song createSong(const char* name, int durate)
{
	Song tmp(name, durate);
	return tmp;
}


int main()
{
	
	Song first;
	cout << "Checking default constructor\n" << endl;
	first.Show();
	Song second("We will Rock You", 234);
	cout << "Checking constructor with parametrs\n" << endl;
	second.Show();
	Song third;
	third = second;
	cout << "Checking copy constructor \n" << endl;
	third.Show();
	Song fourth;
	fourth = createSong("I want to break free", 198);
	Song fifth = move(fourth);
	cout << "Checking transfer constructor \n" << endl;
	fourth.Show();
	fifth.Show();
	cout << "Checking getters \n" << endl;
	cout << "Get name of song fifth = " << fifth.getName() << endl;
	cout << "Get duration of song fifth = " << fifth.getDurate() << endl;
	fourth.setName("I want it all");
	fourth.setDurate(280);
	first.setName("The show must go on");
	first.setDurate(271);
	second.setName("We are the champions");
	second.setDurate(194);
	cout << "Checking setters \n" << endl;
	first.Show();
	second.Show();
	fourth.Show();
	cout << "Checking overload operator << for Song\n" << endl;
	Song sixth("Bohemian Rhapsody", 354);
	cout << sixth << endl;
	cout << "\n\n";
	cout << "Checking function Add Song to Album\n" << endl;
	Album Albumfirst("Queen", "Freddie Mercury");
	Albumfirst.addSong(first);
	Albumfirst.addSong(second);
	Albumfirst.addSong(third);
	Albumfirst.addSong(fourth);
	Albumfirst.addSong(fifth);
	Albumfirst.addSong(sixth);
	Albumfirst.Show();
	cout << "\n";
	cout << "Checking overload operator << for Album \n" << endl;
	cout << Albumfirst;
	Albumfirst.delLastSong();
	cout << "Checking function Delete last Song from Album\n" << endl;
	cout << Albumfirst;
}