#include "myfile1.h"

int main()
{
    cout << "Hello" << endl;
    cout << "Welcome to CSI2372A" << endl << endl;

    cout << "char: " << sizeof(char) << endl;
    cout << "int: " << sizeof(int) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << endl;
    cout << "short int: " << sizeof(short int) << endl << endl;

    int i;
    double d;
    char c;

    cout << "Enter an integer: ";
    cin >> i;
    cout << "Enter a real number: ";
    cin >> d;
    cout << "Enter a character: ";
    cin >> c;

    cout << "Integer in decimal: ";
    cout << dec << i << endl;
    cout << "Integer in octal: ";
    cout << oct << i << endl;
    cout << "Integer in hexadecimal: ";
    cout << hex << i << endl << dec << endl;

    cout << "Real number with scientific notation: " << scientific << d << endl;
    cout << "Real number without scientific notation: " << defaultfloat << d << endl << endl;

    cout << "Character: " << c << endl;
    cout << "Character decimal value: " << static_cast<int>(c) << endl;

    return 0;
}
