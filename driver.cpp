// include libraries here (STL not allowed)
#include <iostream>
#include <string>
#include "playlist.h"

//${fileBasenameNoExtension}"

using namespace std;

int main(int argc, char *argv[]){

    // Iniatlize playlist to a nullpointer outside loop so that it isnt being set every command
    Playlist* iPod_Nano = nullptr;

    while (true){

        // Receive User input
        string userInput = "";
        getline (cin,userInput);

        // Take first letter of string as command
        char userCommand = userInput[0];

        if (userCommand == 'i'){

            // Seperating song title and artist and calling add song function
            string input_title = userInput.substr(2, userInput.find(";")-2);
            string input_artist = userInput.substr(userInput.find(";")+1);

            iPod_Nano->add_song(input_title, input_artist);
            

        } else if (userInput[1] == ' '  && (userCommand == 'm' || userCommand == 'p' || userCommand == 'e' )){
            
            // Extract parameter from userInput string and convert to int
            string numbersOnly = userInput.substr(2,string::npos);
            int parameter = stoi(numbersOnly);

            // Call appropriate functions
            switch(userCommand){
                case 'm':
                    iPod_Nano = new Playlist(parameter);
                    cout << "success" << endl;
                    break;

                case 'p':
                    iPod_Nano->play_song(parameter);
                    break;

                case 'e':
                    iPod_Nano->erase_song(parameter);
                    break;
            }

        } else if(userInput == "done"){
            // End the program and deallocate the playlist
            delete iPod_Nano;
            iPod_Nano = nullptr;
            break;
        } 
    }
    
}

