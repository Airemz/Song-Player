#include <iostream>
#include <string>

using namespace std;

// Song Class which will be objects in the array
class Song{
    private:
        string title, artist;

    public:
        //Constructor
        Song();

        //Destructor
        ~Song();

        //Getter Functions
        string get_title();
        string get_artist();

        //setter Functions
        void set_title(string input_title);
        void set_artist(string input_artist);
        
};

// Playlist class which will be a dynamically allocated pointer to the array of song objects
class Playlist{
    private:
        //Creating a pointer to an array of type song objects
        Song* array;
        int size;
        int numOfsongs;
        bool isListFull;

    public:
        
        //Constructor
        Playlist(int passed_size );

        //Destructor
        ~Playlist();

        //Member Functions for user commands
        bool isSongInList(string songTitle, string songArtist);
        void add_song(string title, string artist);
        void play_song(int position_n);
        void erase_song(int position_n);
        
};