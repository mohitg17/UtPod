#include "Song.h"
#include <string>
#include <iostream>

using namespace std;

Song::Song(){
}

Song::Song(string _title, string _artist, int _size) {
	title = _title;
	artist = _artist;
	size = _size;
}

Song::~Song(){
}

/*
bool Song::operator >(Song const &rhs) {
	int title_diff = title.compare(rhs.title);
	if (title_diff > 0) {
		return true;
	} else if (title_diff < 0) {
		return false;
	}

	int artist_diff = artist.compare(rhs.artist);
	if (artist_diff > 0) {
		return true;
	} else if (artist_diff < 0) {
		return false;
	}

	if (size > rhs.size) {
		return true;
	} else if (size < rhs.size) {
		return false;
	} else {
		return false;
	} 
}

bool Song::operator <(Song const &rhs) {
	int title_diff = title.compare(rhs.title);
	if (title_diff > 0) {
		return false;
	} else if (title_diff < 0) {
		return true;
	}

	int artist_diff = artist.compare(rhs.artist);
	if (artist_diff > 0) {
		return false;;
	} else if (artist_diff < 0) {
		return true;
	}

	if (size > rhs.size) {
		return false;
	} else if (size < rhs.size) {
		return true;
	} else {
		return false;
	} 
}
	
bool Song::operator ==(Song const &rhs) {
	return ((title == rhs.title) && (artist = rhs.artist) && (size == rhs.size));
}
*/
