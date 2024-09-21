#include <iostream>
#include <iomanip>
using namespace std;

// Define a class for the Clock
class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor to initialize the clock
    Clock(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    // Method to add an hour
    void addHour() {
        hours = (hours + 1) % 24;
    }

    // Method to add a minute
    void addMinute() {
        minutes = (minutes + 1) % 60;
        if (minutes == 0) {
            addHour();  // If minutes roll over, add an hour
        }
    }

    // Method to add a second
    void addSecond() {
        seconds = (seconds + 1) % 60;
        if (seconds == 0) {
            addMinute();  // If seconds roll over, add a minute
        }
    }

    // Method to display 12-hour format
    void display12HourClock() {
        int displayHour = hours % 12;
        if (displayHour == 0) displayHour = 12;
        string period = (hours >= 12) ? "PM" : "AM";
        cout << setw(2) << setfill('0') << displayHour << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << " " << period;
    }

    // Method to display 24-hour format
    void display24HourClock() {
        cout << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds;
    }
};

// Function to display both clocks
void displayClocks(Clock& clock) {
    cout << "*********************\n";
    cout << "*    12-Hour Clock   *    ";
    cout << "*    24-Hour Clock   *\n";
    cout << "*    ";
    clock.display12HourClock();
    cout << "     *    ";
    clock.display24HourClock();
    cout << "    *\n";
    cout << "*********************\n";
}

// Menu function to interact with the user
void displayMenu() {
    cout << "1 - Add One Hour\n";
    cout << "2 - Add One Minute\n";
    cout << "3 - Add One Second\n";
    cout << "4 - Exit Program\n";
    cout << "Select an option: ";
}

int main() {
    Clock clock(12, 0, 0);  // Initialize the clock with default time (12:00:00)
    int userInput = 0;

    // Main loop to keep the program running
    while (userInput != 4) {
        // Display both clocks
        displayClocks(clock);

        // Show menu and get user input
        displayMenu();
        cin >> userInput;

        // Handle user input
        switch (userInput) {
            case 1:
                clock.addHour();
                break;
            case 2:
                clock.addMinute();
                break;
            case 3:
                clock.addSecond();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

        cout << "\n";  // Add a newline for readability
    }

    return 0;
}
