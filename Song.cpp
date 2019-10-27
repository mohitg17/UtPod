#include "Song.h"
#include <string>
#include <iostream>

using namespace std;

Song::Song() {
	title = "Untitled";
	artist = "unknown";
	size = 128;
}

Song::Song(string _title, string _artist, int _size) {
	title = _title;
	artist = _artist;
	size = _size;
}

bool Song::operator >(Song const &rhs) {
	if (title.compare(rhs.title) != 0) {
		return title.compare(rhs.title);
	} else if (artist.compare(rhs.compare) != 0) {
		return artist.compare(rhs.artist);
	} else {
		return size > rhs.size;
	}
}

bool Song::operator <(Song const &rhs) {
	if (title.compare(rhs.title) != 0) {
		return title.compare(rhs.title);
	} else if (artist.compare(rhs.compare) != 0) {
		return artist.compare(rhs.artist);
	} else {
		return size > rhs.size;
	}
}
	
bool Song::operator ==(Song const &rhs) {
	return ((title == rhs.title) && (artist = rhs.artist) && (size == rhs.size));
}
