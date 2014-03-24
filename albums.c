// Assumption: Duplicates (artist or album) not re-inserted
// Assumption: Lines for new artists start with "*** " (3 stars and a space)

#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct AlbumsAndArtists
{
	string artist;
	vector<string> albums;
};

vector<AlbumsAndArtists> dataStore;

bool IsLessThan(string& a, string& b)
{
	//printf("IsLessThan(%s, %s)\n", a.c_str(), b.c_str());

	// do not consider any leading "The " or "A "
	int aIndex = (a.length() >= 4 && a.substr(0, 4).compare("The ") == 0? 4 : 
				  a.length() >= 2 && a.substr(0, 2).compare("A ") == 0? 2 : 0);
	int bIndex = (b.length() >= 4 && b.substr(0, 4).compare("The ") == 0? 4 : 
				  b.length() >= 2 && b.substr(0, 2).compare("A ") == 0? 2 : 0);

	//printf("aIndex=%d, bIndex=%d\n", aIndex, bIndex);
	//printf("a.substr(%d)=%s, b.substr(%d)=%s, a.substr(%d).compare(b.substr(%d)=%d\n",
	//	aIndex, a.substr(aIndex).c_str(), bIndex, b.substr(bIndex).c_str(), 
	//	aIndex, bIndex,
	//	a.substr(aIndex).compare(b.substr(bIndex)));
	return (a.substr(aIndex).compare(b.substr(bIndex)) < 0);
}

void AddAlbumEntry(string& album, AlbumsAndArtists& entry)
{
	// look through the list of albums for this artist and add it at the right place
	vector<string>::iterator it = entry.albums.begin();
	while (IsLessThan(*it, album) && it != entry.albums.end())
	{
		it++;
	}
	if (it == entry.albums.end())  // push at the end
	{
		entry.albums.push_back(album);
	}
	else if (album != *it)
	{
		// this is not a duplicate
		entry.albums.insert(it, album);
	}
}

void AddArtistEntry(string& artist, string& album)
{
	// make a new entry
	AlbumsAndArtists newArtistEntry;
	newArtistEntry.artist = artist;
	newArtistEntry.albums.push_back(album);

	vector<AlbumsAndArtists>::iterator it = dataStore.begin();
	while (IsLessThan((*it).artist, artist) && it != dataStore.end())
	{
		it++;
	}
	if (it == dataStore.end())  // push at the end
	{
		//printf("Pushing artist %s at end\n", artist.c_str());
		dataStore.push_back(newArtistEntry);
	}
	else if (artist != (*it).artist)
	{
		// this is not a duplicate
		//printf("Pushing artist %s into middle\n", artist.c_str());
		dataStore.insert(it, newArtistEntry);
	}
}

void AddAlbumAndArtist(string& album, string& artist)
{
	bool albumAdded = false;

	int numArtists = dataStore.size();
	for (int i = 0; i < numArtists; i++)
	{
		if (artist == dataStore[i].artist)
		{
			// add to the list of albums in sorted order
			AddAlbumEntry(album, dataStore[i]);
			albumAdded = true;
		}
	}

	if (!albumAdded)
	{
		// this is a new artist
		//printf("Adding new artist\n");
		AddArtistEntry(artist, album);
	}
}

int main()
{
	ifstream infile;
    infile.open ("albums.txt");

    AlbumsAndArtists newEntry;

    // read the file line by line
	string str;
	while (getline(infile, str))
	{
	    if (str.length() > 0)
	    {
		    if (str.length() >= 4 && str.substr(0, 4) == "*** ")
		    {
		    	// new artist

		    	// if any previous record, insert it into the data store
		    	if (newEntry.artist.length() > 0)
		    	{
		    		dataStore.push_back(newEntry);
		    	}

		    	// create a new entry for the artist
		    	newEntry.artist = str.substr(4);
		    	newEntry.albums.resize(0);
		    }
		    else
		    {
		    	// new album
		    	newEntry.albums.push_back(str);
		    }
		}
	}

	// Add a new entry into the list
	char artist[256], album[256];
	printf("Enter an artist name: ");
	scanf("%s", artist);
	printf("Enter an album name: ");
	scanf("%s", album);

	string albumStr(album);
	string artistStr(artist);
	AddAlbumAndArtist(albumStr, artistStr);

	// print it
	FILE *fp = fopen("albums.out.txt", "w");
	for (vector<AlbumsAndArtists>::iterator it = dataStore.begin();
		 it != dataStore.end(); it++)
	{
		// print artist name
		fprintf(fp, "*** %s\n", (*it).artist.c_str());

		// print album name
		vector<string>& albumList = (*it).albums;
		for (vector<string>::iterator it2 = albumList.begin();
			 it2 != albumList.end(); it2++)
		{
			fprintf(fp, "%s\n", (*it2).c_str());
		}

		fprintf(fp, "\n");
	}
	fclose(fp);

	return 0;
}