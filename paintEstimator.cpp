#include <iostream>
#include <conio.h>
#include <iomanip>

double inputPricePerGallon(double paintPrice);

double inputNumberOfRooms(double rooms);

double inputTotalSqFeet(double rooms, double sqrFeet);

void outputResults(double gallonsOfPaint, double hours, double total, double paintTotal, double labor);

using namespace std;

int main() {
    double paintPrice, gallonsOfPaint, hours, total, rooms, sqrFeet, paintTotal, labor;
    const double laborPerHour = 25;
    cout << "Paint Job Estimator..." << endl;
    sqrFeet = 0;

    paintPrice = inputPricePerGallon(paintPrice);
    rooms = inputNumberOfRooms(rooms);
    sqrFeet = inputTotalSqFeet(rooms, sqrFeet);

    gallonsOfPaint = sqrFeet / 115.0;
    hours = gallonsOfPaint * 8.0;
    paintTotal = paintPrice * gallonsOfPaint;
    labor = hours * laborPerHour;
    total = labor + paintTotal;

    outputResults(gallonsOfPaint, hours, total, paintTotal, labor);


    return 0;
}

void outputResults(double gallonsOfPaint, double hours, double total, double paintTotal, double labor) {
    cout << "Paint Job Estimate" << endl;
    cout << "---------------------" << endl;
    cout << "Paint... " << endl
         << left << setw(30) << "Gallons of Paint : " << gallonsOfPaint << endl

         << left << setw(30) << "Cost of Paint : " << "$" << paintTotal << endl;


    cout << "Labor... " << endl
         << left << setw(30) << "Hours of Labor : " << hours << endl

         << left << setw(30) << "Cost of Labor : " << "$" << labor << endl;

    cout << "---------------------------------------" << endl
         << left << setw(30) << "Total Cost : " << "$" << total << endl;
}

double inputTotalSqFeet(double rooms, double sqrFeet) {
    for (int i = 0; i < rooms; i++) {
        while (true) {
            double input = 0;
            cout << "Sq. Ft. of wall space :"
                 << "in room " << (i + 1) << ": ";
            cout << endl;
            cin >> input;
            sqrFeet += input;

            if (input < 25) {
                cout << "Incorrect wall space for the room. Try again..." << endl;
            } else
                break;

        }

    }
    return sqrFeet;
}

double inputNumberOfRooms(double rooms) {
    while (true) {
        cout << "Number of rooms to be painted :";
        cin >> rooms;
        if (rooms <= 0) {
            cout << "Invalid number of rooms. Try again..." << endl;
        } else
            break;
    }
    return rooms;
}

double inputPricePerGallon(double paintPrice) {
    while (true) {
        cout << "Price per gallon of paint: ";
        cin >> paintPrice;


        if (paintPrice <= 0) {
            cout << "Invalid price per gallon. Try again..." << endl;

        } else
            break;
    }
    return paintPrice;
}
