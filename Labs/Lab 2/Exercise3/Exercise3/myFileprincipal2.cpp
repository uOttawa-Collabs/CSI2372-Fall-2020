#include "myFile2.h"

int main()
{
    int i;
    char *chain[nb_ch];    // array of pointers on char 
    char choice;           // variable for the choice entered in menu() 

    cout << endl << "Enter the 5 character strings ending with a tab and a line return" << endl;

    for (i = 0; i < nb_ch; i++)
    {
        chain[i] = new char[size_ch];                        // memory allocation 
        cin.getline(chain[i], size_ch, '\t');    // seizure of the string 
        cin.ignore(INT_MAX, '\n');
    }
    // ignore line return 
    display(chain, nb_ch);

    while (1)
    {
        choice = menu();

        switch (choice)
        {
            case '1':
                display(chain, nb_ch);
                break;
            case '2':
                replace(chain, nb_ch, size_ch);
                break;
            case '3':
                sort(chain, nb_ch);
                break;
            case '4':
                exit(0);
            default:
                break;
        }
    }
}
