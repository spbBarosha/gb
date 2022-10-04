#include <iostream>
#include <string>

using namespace std;

void toBin(int a, string &b)
{
    if (a > 0)
    {
        if (a % 2 == 0)
        {
            a = a / 2;
            toBin(a, b);
            b += '0';
        }
        else {
            a = a / 2;
            toBin(a, b);
            b += '1';
        }
    }
}

int deg(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return deg(a, b - 1) * a;
    else 
        return deg(a * a, b / 2);         
}

int main() {
    string b;
    toBin(25, b);
    cout << b << endl;
    cout << deg(4,6) << endl;

    return 0;
}