#include <iostream>
#include <cmath>
using namespace std;

double round_to_2(float number) {
    return int(number*100) / 100.0;
}

double find_discriminant(float a, float b, float c) {
    return pow(b, 2) - 4*a*c;
}

float find_solution(int sign, float a, float b, float discriminant) {
    return round_to_2((-b + sign*sqrt(discriminant)) / (2*a));
}

void print_welcome() {
    cout << "Hello!\n\nThis program finds solutions of quadratic formula.";
}

void print_discriminant(float discriminant) {
    cout << "\n\nDicriminant: " << discriminant;
}

void print_solutions(float a, float b, float discriminant) {
    if (discriminant > 0) {
        cout << "\n\nx1 = " << find_solution(1, a, b, discriminant);
        cout << "\n\nx2 = " << find_solution(-1, a, b, discriminant);
    } else if (discriminant == 0) {
        cout << "\n\nx = " << find_solution(1, a, b, discriminant);
    } else {
        cout << "\n\nThere is no real solutions as discriminant is less than zero.";
    }
    cout << "\n\n";
}

tuple<float, float, float> get_values() {
    float a, b, c;
    cout << "\n\nFirst, write value of a: ";
    cin >> a;
    cout << "\n\nSecond, write value of b: ";
    cin >> b;
    cout << "\n\nThird, write value of c: ";
    cin >> c;
    return make_tuple(a, b, c);
}

int main()
{
    float a, b, c, discriminant;
    
    print_welcome();
    tie(a, b, c) = get_values();
    discriminant = find_discriminant(a, b, c);
    print_discriminant(discriminant);
    print_solutions(a, b, discriminant);
    
    return 0;
}
