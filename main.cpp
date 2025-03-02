/*
This program will track whether I worked out or not. 
Later on, this will also track my exact workouts. 
*/

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// Functions
bool didYouWorkout(string prompt, bool& rest);
void writeLogFile(int str, bool restDay);
void readLogFile(int& str, bool& input, string& lastDate);
string getCurrentDate();


int main(int argc, char* argv[]) {
    string lastDate;
    int streak = 0;
    bool input = false;

    // read from file to get tracked data
    readLogFile(streak, input, lastDate);

    // program code
    string currentDate = getCurrentDate();
    if (currentDate != lastDate) {
        input = false;
    }

    string prompt = "Hey man! You know the dream; get ripped and make software. A true tech bro's dream.\n"
                    "So for starters, have you worked out today? If today is a rest day enter 'r'(y/n/r): ";

    if (input) {
        cout << "You already responded today. Come back tomorrow." << endl;
        return 0;
    }

    bool restDay = false;
    bool status = didYouWorkout(prompt, restDay);

    if (restDay) {
        cout << "\nRest day, understandable. Gotta let the body heal and stuff." << endl;
        input = true;
    } else if (status) {
        cout << "\nYESUHHHH\nKEEP IT UP MAN! COME BACK TOMORROW TO KEEP YOUR STREAK." << endl;
        streak++;
        input = true;
    } else {
        cout << "\nbruh... Come on, how are we suppose to be eat wings and sip martinis at this rate. LOCK IN!" << endl;
        streak = 0;
        input = true;
    }

    cout << "Your streak is now " << streak << " days(excluding rest days)." << endl;

    // output to file for readability
    writeLogFile(streak, restDay);

    return 0;
}

// Function Declaration
bool didYouWorkout(string prompt, bool& rest) {
    char response = ' ';

    cout << prompt << endl;
    cin >> response;

    if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter 'y','n', or 'r'." << endl;
        cin >> response;
    }

    switch (response) {
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
            cout << "Invalid input. Please enter 'y','n', or 'r'." << endl;
            return 0;
            break;
    }
    return false;
}

void writeLogFile(int str, bool restDay) {
    ofstream writer("workoutLog.txt");
    writer << "Streak: " << str << " days" << endl;
    writer << "Rest Day?: " << boolalpha << restDay << endl;
    writer << "LastDate: " << getCurrentDate() << endl;
}

void readLogFile(int& str, bool& input, string& lastDate) {
    ifstream reader("workoutLog.txt");
    if (!reader) {
        cout << "Invalid file name. Check log file." << endl;
        exit;
    }

    string line;
    while (getline(reader, line)) {
        if (line.find("Streak:") != string::npos) {
            str = stoi(line.substr(line.find(":") + 1));
        } else if (line.find("Input:") != string::npos) {
            input = (line.substr(line.find(":") + 1) == "true");
        } else if (line.find("LastDate:") != string::npos) {
            lastDate = line.substr(line.find(":") + 2);
        }
    }
    reader.close();
}

string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char date[11];
    strftime(date, sizeof(date), "%Y-%m-%d", ltm);
    return string(date);
}