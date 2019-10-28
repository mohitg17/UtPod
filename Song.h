#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {

    private:
		string title;
		string artist;
		int size;

	static const int MAX_MEMORY = 512;

	public:
        Song();

        Song(string artist, string title, int size);

		string getTitle() const
			{ return title; }

		void setTitle(string t)
			{ title = t; }

		string getArtist() const 
			{ return artist; }

		void setArtist(string a)
			{ artist = a; }

		int getSize() const
			{ return size; }

		void setSize(int s)
			{ size = s; }
/*
		bool operator >(Song const &rhs);
		bool operator ==(Song const &rhs);
		bool operator <(Song const &rhs);
*/
		~Song();

};

ostream operator << (ostream& out, const Song &s);

#endif
