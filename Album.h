#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Song.h"

using namespace std;

class Album
{
	char* compilate = nullptr;
	char* performer = nullptr;
	int amountOfSongs = 0;
	Song* mass = nullptr;
	

public:
	Album();
	Album(const char* c, const char* p);
	Album(const Album& obj);
	Album(Album&& obj);
	~Album();
	Album& operator=(const Album& obj);
	Album& operator=(Album&& obj);
	const char* getCompilate() const;
	const char* getPerformer() const;
	int getAmount() const;
	void setCompilate(const char* val);
	void setPerformer(const char* val);
	void addSong(const Song& val);
	void delLastSong();//указывать индекс не нужно, так как удаляется последняя песня из альбома

	void Show() const;//  в функции Шоу нет необходимости, так как можем выводить с помощью перегруженного оператора <<
	            // сделано в соответствии с заданием
	friend ostream& operator<<(ostream& out, const Album& obj);


};

