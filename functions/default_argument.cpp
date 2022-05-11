#include <iostream>
#include <iomanip>

using namespace std;
double calc_cost(double base_cost, double tax_rate = 0.06, double shipping_cost = 3.50)
{
    return base_cost += (base_cost * tax_rate) + shipping_cost;
}

void greeting(string name, string prefix = "Mr.", string suffix = "")
{
    cout << "Hello " << prefix + " " + name + " " + suffix << endl;
}

int main()
{
    double cost{0};
    cout << fixed << setprecision(2); 
    cost = calc_cost(100.0, 0.08, 4.25);
    cout << cost << endl;

    cost = calc_cost(100.0, 0.08);
    cout << cost << endl;

    cost = calc_cost(200.0);
    cout << cost << endl;

    greeting("Narayan", "Mr.", "M.D");
    greeting("Poudel");

    return 0;
}