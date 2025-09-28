#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string name, pickupLocation, dropoffLocation;
    
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

}

