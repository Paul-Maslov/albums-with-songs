#include "Album.h"
# include "Song.h"

Album::Album() = default;

Album::Album(const char* c, const char* p)
{
    compilate = _strdup(c);
    performer = _strdup(p);
}

Album::Album(const Album& obj)
{
    compilate = obj.compilate ? _strdup(obj.compilate) : nullptr;
    performer = obj.performer ? _strdup(obj.performer) : nullptr;
    amountOfSongs = obj.amountOfSongs;
    mass = new Song[amountOfSongs];
    for (int i = 0; i < amountOfSongs;i++)
    {
        mass[i] = obj.mass[i];
    }
}

Album::Album(Album&& obj)
{
    compilate = obj.compilate;
    performer = obj.performer;
    amountOfSongs = obj.amountOfSongs;
    mass = obj.mass;
    obj.compilate = nullptr;
    obj.performer = nullptr;
    obj.mass = nullptr;
    obj.amountOfSongs = 0;
}

Album::~Album()
{
    delete[] compilate;
    delete[] performer;
    if (amountOfSongs != 0)
        delete[] mass;
}

Album& Album::operator=(const Album& obj)
{
    if (this == &obj)
        return *this;
    delete[] compilate;
    delete[] performer;
    if (amountOfSongs != 0)
        delete[] mass;
    compilate = obj.compilate ? _strdup(obj.compilate) : nullptr;
    performer = obj.performer ? _strdup(obj.performer) : nullptr;
    amountOfSongs = obj.amountOfSongs;
    mass = new Song[amountOfSongs];
    for (int i = 0; i < amountOfSongs;i++)
    {
        mass[i] = obj.mass[i];
    }
    return *this;
}

Album& Album::operator=(Album&& obj)
{
    if (this == &obj)
        return *this;
    delete[] compilate;
    delete[] performer;
    if (amountOfSongs != 0)
        delete[] mass;
    compilate = obj.compilate;
    performer = obj.performer;
    amountOfSongs = obj.amountOfSongs;
    mass = obj.mass;
    obj.compilate = nullptr;
    obj.performer = nullptr;
    obj.mass = nullptr;
    obj.amountOfSongs = 0;
    return *this;
}

const char* Album::getCompilate() const
{
    return compilate;
}

const char* Album::getPerformer() const
{
    return performer;
}

int Album::getAmount() const
{
    return amountOfSongs;
}

void Album::setCompilate(const char* val)
{
    delete[] compilate;
    compilate = _strdup(val);
}

void Album::setPerformer(const char* val)
{
    delete[] performer;
    performer = _strdup(val);
}

void Album::addSong(const Song& val)
{
    if (amountOfSongs == 0)
        mass = new Song[1];
    else
    {
        auto tmp = new Song[amountOfSongs + 1];
        for (int i = 0;i < amountOfSongs; i++)
        {
            tmp[i] = mass[i];
        }
        delete[] mass;
        mass = tmp;
    }
    mass[amountOfSongs] = val;
    amountOfSongs++;
 }

void Album::delLastSong()
{
    if (amountOfSongs == 1)
    {
        delete[] mass;
        amountOfSongs = 0;
        return;
    }
    auto tmp = new Song[amountOfSongs-1]; 
    for (int i = 0; i < amountOfSongs-1; i++) 
    {
       tmp[i] = mass[i];
    }
    delete[]mass; 
    mass = tmp;
    amountOfSongs--;
}

void Album::Show() const
{
    cout << "Name of Album = " << compilate << "; Name of Performer = " << performer << "\n" << endl;
    for (int i = 0;i < amountOfSongs;i++)
    {
        cout << i + 1 << ": " << mass[i] << endl;
    }
}

ostream& operator<<(ostream& out, const Album& obj)
{
    out << "Name of Album = " << obj.compilate << "; Name of Performer = " << obj.performer << "; Songs = "<<obj.amountOfSongs<< "\n" << endl;
    if (obj.amountOfSongs == 0)
    {

    }
    for (int i = 0;i < obj.amountOfSongs;i++)
    {
        out << i + 1 << ": " << obj.mass[i] << endl;
    }
    return out;
}
