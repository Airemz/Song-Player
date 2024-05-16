#include "playlist.h"

using namespace std;
///////////////////////////////////////////////////////////////
// Song member Functions 
///////////////////////////////////////////////////////////////


// Constructor
Song::Song() {
    title = "";
    artist = "";
}

// Destructor
Song::~Song(){}

// Setters and getters
void Song::set_title(string input_title){
    title = input_title;
}

void Song::set_artist(string input_artist){
    artist = input_artist;
}

std::string Song::get_title(){
    return title;
}

std::string Song::get_artist(){
    return artist;
}

///////////////////////////////////////////////////////////////
// Playlist member Functions 
///////////////////////////////////////////////////////////////

// Constructor
Playlist::Playlist (int passed_size = 16) {
    size = passed_size;
    numOfsongs = 0;
    array = new Song[size];
    isListFull = false;
}


// Destructor
Playlist::~Playlist (){
    delete[] array;
}

// Check if song is in array
bool Playlist::isSongInList(string songTitle, string songArtist){

    // Itterate through array and compare titles and artist for exact match
    for ( int i = 0; i < size; i++){

        if (((array[i].get_title() == songTitle) && (array[i].get_artist()== songArtist))){
            return true;
        }
    }

    return false;

}

// Add song to end of playlist if possible
void Playlist::add_song(string inputTitle, string inputArtist){

    // Check for restricted entry: "Baby;Justin Bieber"
    if (((inputTitle + ";" + inputArtist)  == "Baby;Justin Bieber")){
        cout << "can not insert " << (inputTitle + ";" + inputArtist) << endl;
    } 

    // Check for restricted entry: "My Heart Will Go On": (by any artist)
    else if (inputTitle == "My Heart Will Go On"){
        cout << "can not insert " + inputTitle + ";" + inputArtist << endl;
    }
    
    // Check bool isListFull
    else if(isListFull){
        cout << "can not insert " << (inputTitle + ";" + inputArtist) << endl;
    } 

    // Call member function isSongInList using input parameters
    else if (isSongInList(inputTitle, inputArtist)){
        cout << "can not insert " << (inputTitle + ";" + inputArtist) << endl;
    }

    else{
        // add song to end of playlist by setting title and artist
        // numOfsongs begins at 0 and is incremented with every song, thus the newest song will be added to next available entry (after the latest song added)
        array[numOfsongs].set_title(inputTitle);
        array[numOfsongs].set_artist(inputArtist);
        numOfsongs++;

        // if the newly added song fills the array set the bool to true so no new songs can be added
        if (numOfsongs == size){isListFull = true;}
        cout << "success" << endl;

    }
}

// Play song at desired position
void Playlist::play_song(int position_n){

    // Check if desired position is within bounds, if so play using getter member functions
    if (position_n < numOfsongs && position_n >= 0){

        cout << "played " << position_n << ' ' <<  array[position_n].get_title() << ";" << array[position_n].get_artist() << endl;

    } else{
        cout << "can not play " << position_n << endl;
    }

}

// Erase song at desired position and move all songs after to account for gap
void Playlist::erase_song(int position_n){

    // Only take inputs less than number of songs and greater than 0
    if (position_n < numOfsongs && position_n >= 0){

            // Clear position_n
            array[position_n].set_title("");
            array[position_n].set_artist("");

            // Shift following songs in array
            for ( int i = position_n; i < numOfsongs - 1; i++) {
                array[i].set_title(array[i+1].get_title());
                array[i].set_artist(array[i+1].get_artist());
            }

            // Decrement number of songs and change list is full accounting for a full playlist
            numOfsongs--;
            cout << "success" << endl;
            isListFull = false;

    } else{
        cout << "can not erase " << position_n << endl;
    }
}