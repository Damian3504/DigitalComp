#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string name, pickupLocation, dropoffLocation, rideType;
    int rideChoice, menuChoice, timeChoice, NumOfPassengers;
    double distance, fare, timeFare;

    //base fare and per km rates for different ride types
    const double BASE_FARE_CAR = 5.0;
    const double RATE_PER_KM_CAR = 2.0;

    const double BASE_FARE_VAN = 9.0;
    const double RATE_PER_KM_VAN = 3.0;

    const double BASE_FARE_PREMIUM = 10.0;
    const double RATE_PER_KM_PREMIUM = 3.5;

    const double BASE_FARE_PREMIUM_VAN = 12.0;
    const double RATE_PER_KM_PREMIUM_VAN = 5;
    
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

        //input distance
        cout << "Enter distance of trip (in km): ";
        cin >> distance;

        //validate distance
        if (distance <= 0) {
            cout << "\nInvalid distance entered!\n";
            return 0;
        }

        //input number of passengers
        cout << "Enter Number of Passengers (1-6): ";
        cin >> NumOfPassengers;

        
        switch (NumOfPassengers) {
            case 1 ... 3:
                //ride type choices
                cout << "\nSelect Ride Type:\n";
                cout << "1. RideCar (Base RM5 + RM2/km)\n";
                cout << "2. RidePremium (Base RM10 + RM3.5/km)\n";
                cout << "Enter choice (1-2): ";
                cin >> rideChoice;
                //calculate fare based on ride type
                switch (rideChoice) {
                    case 1: //RideCar
                        fare = BASE_FARE_CAR + ((RATE_PER_KM_CAR+timeFare) * distance);
                        rideType = "RideCar";
                        break;
                    case 2: //RidePremium
                        fare = BASE_FARE_PREMIUM + ((RATE_PER_KM_PREMIUM+timeFare) * distance);
                        rideType = "RideCar Premium";
                        break;
                    default:
                        cout << "\nInvalid ride type selected!\n";
                        return 0;
                break;
                }
                break;
            case 4 ... 6:
                //ride type choices
                cout << "\nSelect Ride Type:\n";
                cout << "1. RideVan (Base RM9 + RM3/km)\n";
                cout << "2. RidePremiumVan (Base RM12 + RM5/km)\n";
                cout << "Enter choice (1-2): ";
                cin >> rideChoice;
                //calculate fare based on ride type
                switch (rideChoice) {
                    case 1: //RideCar
                        fare = BASE_FARE_VAN + ((RATE_PER_KM_VAN+timeFare) * distance);
                        rideType = "RideVan";
                        break;
                    case 2: //RidePremium
                        fare = BASE_FARE_PREMIUM_VAN + ((RATE_PER_KM_PREMIUM_VAN+timeFare) * distance);
                        rideType = "RideVan Premium";
                        break;
                    default:
                        cout << "\nInvalid ride type selected!\n";
                        return 0;
                    break;
                }
                break;
            default:
                cout << "\nInvalid amount of passengers selected!\n";
                return 0; 
            break;
        }

        //ride time choices
        cout << "\nSelect Pickup Time:\n";
        cout << "1. 7AM\n";
        cout << "2. 8AM\n";
        cout << "3. 9AM\n";
        cout << "4. 10AM\n";
        cout << "5. 11AM\n";
        cout << "6. 12PM\n";
        cout << "7. 1PM\n";
        cout << "8. 2PM\n";
        cout << "9. 3PM\n";
        cout << "10. 4PM\n";
        cout << "11. 5PM\n";
        cout << "12. 6PM\n";
        cout << "13. 7PM\n";
        cout << "14. 8PM\n";
        cout << "15. 9PM\n";
        cout << "16. 10PM\n";
        cout << "Enter choice (1-2): ";
        cin >> timeChoice;

        //calculate fare multiplier based on ride time
        switch (timeChoice) {
            case 1 ... 3: //morningpeakhours
                timeFare = 1;
                break;
            case 4 ... 5:
                timeFare = 0; //noramalhours
                break;
            case 6 ... 8:
                timeFare = 1; //lunchhours
                break;
            case 9 ... 10:
                timeFare = 0; //normalhours
                break;
            case 11 ... 13:
                timeFare = 1; //rushhour
                break;
            case 14 ... 16:
                timeFare = 0.5; //afterhours
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
        cout << "Ride Type        : " << rideType << endl;
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

