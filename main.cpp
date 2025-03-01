/*
This program will track whether I worked out or not. It will refresh with a prompt every 24 hours. 
Later on, this will also track my exact workouts. 
*/

#include <iostream>
using namespace std; 

// Functions 
bool didYouWorkout(string prompt);


int main(int argc, char* argv[]){

    string prompt = "Hey man! You know the dream; get ripped and make software. A true tech bro's dream.\n"
                    "So for starters, have you worked out today?";

    bool status = didYouWorkout(prompt);

    if(status){
        

    } else {

    }


    return 0;
}

// Function Declararion
bool didYouWorkout(string prompt){
    char response = ' ';
    bool error = false;

    cout << prompt << endl;
    cin >> response;

    switch(response){
        case 'Y':
        case 'y':
            cout << "";
            break;

        case 'N':
        case 'n':
            break;

        default:
            cout << "Invalid input" << endl;
            error = true;
            break;
    }

    if(!error){

    }

    return true;
}