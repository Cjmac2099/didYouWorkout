/*
This program will track whether I worked out or not. It will refresh with a prompt every 24 hours. 
Later on, this will also track my exact workouts. 
*/

#include <iostream>
using namespace std; 

// Functions 
bool didYouWorkout(string prompt, bool& rest);

static int streak = 0;
static bool input;

int main(int argc, char* argv[]){

    string prompt = "Hey man! You know the dream; get ripped and make software. A true tech bro's dream.\n"
                    "So for starters, have you worked out today? If today is a rest day enter 'r'(y/n/r): ";

    if(input){
        cout << "You already inputted for today. Come back tomorrow.\nYour streak is " + streak << " days." << endl;
        return 0;
    }

    bool restDay = false;
    bool status = didYouWorkout(prompt, restDay);

    if(restDay){
        cout << "\nRest day, understandable. Gotta let the body heal and blah blah... Anywho, see you back in 24hr." << endl; 
        input = true;        
    } else if(status){
        cout << "\nYESUHHHH\nKEEP IT UP MAN! COME BACK TOMORROW TO KEEP YOUR STREAK." << endl; 
        streak++;
        input = true;
    } else {
        cout << "\nbruh... Come on, how are we suppose to be eat wings and sip martinis at this rate. LOCK IN!" << endl;
        streak = 0;
        input = true;
    }

    cout << "Your streak is now " << streak << " days(excluding rest days)." << endl;

    return 0;
}

// Function Declararion
bool didYouWorkout(string prompt, bool& rest){
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
        // did workout
        case 'Y':
        case 'y':
            return true;
            break;

        // did not workout
        case 'N':
        case 'n':
            return false;
            break;

        // rest day
        case 'r':
        case 'R':
            rest = true;
            break;

        default:
            break;
    }
    return false;
}