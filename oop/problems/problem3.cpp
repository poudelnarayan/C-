/*
WAP to create a class DM and DB . DM stores distance in meters and centimeters and DB stores in feet and inches.
Using friend function , add object of DM ans DB . The object that stores result maybe DB or DM depending
upon your preferences. Display the final result .


*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
class DB;

class DM
{
    friend DM addToMeter(DM, DB);
    friend DB addToFeet(DM, DB);
    float meter;
    float centimeter;

public:
    DM() : DM(0.0, 0.0) {}
    DM(float m, float c) : meter{m}, centimeter{c} {}
    void display();
};

class DB
{
    friend DM addToMeter(DM, DB);
    friend DB addToFeet(DM, DB);

    float feet;
    float inches;

public:
    DB() : DB(0.0, 0.0) {}
    DB(float f, float i) : feet{f}, inches{i} {}
    void display();
};

DM addToMeter(DM mc, DB fi)
{
    DM temp;
    temp.centimeter = mc.centimeter + mc.meter * 100 + fi.feet * 30.48 + fi.inches * 2.54;
    temp.meter = (int)temp.centimeter / 100;
    temp.centimeter = fmod(temp.centimeter, 100);
    return temp;
}
void DM::display()
{
    cout << fixed << setprecision(2);
    cout << "meter: " << meter << " centimeter: " << centimeter << endl;
}

DB addToFeet(DM mc, DB fi)
{
    DB temp;
    temp.inches = fi.inches + fi.feet * 12 + mc.centimeter * 0.0328 + mc.meter * 3.28;
    temp.feet = (int)temp.inches / 12;
    temp.inches = fmod(temp.inches, 12);
    return temp;
}
void DB::display()
{
    cout << fixed << setprecision(2);
    cout << "feet: " << feet << " inches: " << inches << endl;
}

int main()
{
    float meter, centimeter, feet, inch;
    DM mks, convertedMks;
    DB fps, convertedFps;
    cout << "Enter meters and centimeters: ";
    cin >> meter >> centimeter;
    cout << "Enter feet and inches: ";
    cin >> feet >> inch;
    mks = DM(meter, centimeter);
    fps = DB(feet, inch);
    convertedMks = addToMeter(mks, fps);
    convertedFps = addToFeet(mks, fps);
    cout << "Conversion to meter and centimer: " << endl;
    convertedMks.display();
    cout << "Conversion to feet and inches: " << endl;
    convertedFps.display();

    return 0;
}