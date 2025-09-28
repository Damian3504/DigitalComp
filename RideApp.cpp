#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string name, pickupLocation, dropoffLocation;
    int rideChoice, menuChoice;
    double distance, fare;

    //base fare and per km rates for different ride types
    const double BASE_FARE_CAR = 5.0;
    const double RATE_PER_KM_CAR = 2.0;

    const double BASE_FARE_PREMIUM = 10.0;
    const double RATE_PER_KM_PREMIUM = 3.5;

    cout << "======================================\n";
    cout << "   Ride E-Hailing App\n";
    cout << "======================================\n\n";

    do {
        cin.ignore();

        //input passenger name
        cout << "Enter your name: ";
        getline(cin, name);

        //input pickup location
        cout << "Enter Pickup Location: ";
        getline(cin, pickupLocation);

        //input drop-off location
        cout << "Enter Drop-off Location: ";
        getline(cin, dropoffLocation);

        //ride type choices
        cout << "\nSelect Ride Type:\n";
        cout << "1. RideCar (Base RM5 + RM2/km)\n";
        cout << "2. RidePremium (Base RM10 + RM3.5/km)\n";
        cout << "Enter choice (1-2): ";
        cin >> rideChoice;

        //input distance
        cout << "Enter distance of trip (in km): ";
        cin >> distance;

        //validate distance
        if (distance <= 0) {
            cout << "\nInvalid distance entered!\n";
            return 0;
        }

        //calculate fare based on ride type
        switch (rideChoice) {
            case 1: //RideCar
                fare = BASE_FARE_CAR + (RATE_PER_KM_CAR * distance);
                break;
            case 2: //RidePremium
                fare = BASE_FARE_PREMIUM + (RATE_PER_KM_PREMIUM * distance);
                break;
            default:
                cout << "\nInvalid ride type selected!\n";
                return 0;
        }

        //receipt
        cout << "\n========= Trip Receipt =========\n";
        cout << "Passenger Name   : " << name << endl;
        cout << "Pickup Location  : " << pickupLocation << endl;
        cout << "Drop-off Location: " << dropoffLocation << endl;
        cout << "Distance         : " << distance << " km\n";
        cout << "Ride Type        : " << (rideChoice == 1 ? "RideCar" : "RidePremium") << endl;
        cout << "Total Fare       : RM " << fare << endl;
        cout << "===============================\n";

        //options after booking
        cout << "\nWhat would you like to do next?\n";
        cout << "1. Go back to booking\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> menuChoice;

    } while (menuChoice == 1);

    cout << "\nThank you for using Ride E-Hailing App!\n";
    return 0;
}

