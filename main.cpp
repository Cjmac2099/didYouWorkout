/*
This program will track whether I worked out or not. It will refresh with a prompt every 24 hours. 
Later on, this will also track my exact workouts. 
*/

#include <iostream>
using namespace std; 

// Functions 
bool didYouWorkout(string prompt);

static int streak = 0;

int main(int argc, char* argv[]){

    string prompt = "Hey man! You know the dream; get ripped and make software. A true tech bro's dream.\n"
                    "So for starters, have you worked out today?(y/n): ";

    bool status = didYouWorkout(prompt);

    if(status){
        cout << "\nYESUHHHH\nKEEP IT UP MAN! COME BACK TOMORROW TO KEEP YOUR STREAK." << endl; 
        streak++;
    } else {
        cout << "\nbruh. Come on, how are we suppose to be eat wings and sip martinis at this rate. LOCK IN!" << endl;
        streak = 0;
    }

    cout << "Your streak is now " << streak << " days(including rest days)." << endl;

    return 0;
}

// Function Declararion
bool didYouWorkout(string prompt){
    char response = ' ';

    cout << prompt << endl;
    cin >> response;

    while(cin.fail()){
        cin.clear();
        cin.ignore(256,'\n');
        cout << "Invalid input. Plesse enter 'y'/'Y' or 'n'/'N'" << endl;
        cin >> response;
    }

    switch(response){
        case 'Y':
        case 'y':
            return true;
            break;

        case 'N':
        case 'n':
            return false;
            break;

        default:
            break;
    }
    return false;
}