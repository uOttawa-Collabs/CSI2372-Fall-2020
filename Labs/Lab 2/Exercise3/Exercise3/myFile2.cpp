#include "myFile2.h" 

/********************************************************************************/
/* Function menu which returns a character corresponding to the user's choice  */
/********************************************************************************/

char menu(void)
{
    char choice;

    cout << endl << endl << "\t\tMenu" << endl << endl;
    cout << "1) Strings display." << endl;
    cout << "2) Replacement of a string by an other one" << endl;
    cout << "3) Sorting strings" << endl;
    cout << "4) Exit of the program" << endl << endl;
    cout << "Your choice :";
    cin >> choice;

    return(choice);
}

/********************************************************************************/
/*
 * The replace function that replaces one string by another.
 * It takes as arguments an array of pointers on the strings "tab",
 * the number of elements of this array of pointers "nbre"
 * and the maximum size of the strings "size"
 *
/********************************************************************************/

void replace(char *tab[], int const &nbre, int const &size)
{
    int numero;  	// the string to modify 

    cout << endl << "Enter the string number to modify: ";
    cin.ignore(INT_MAX, '\n');
    cin >> numero;

    if (numero >= 0 && numero <= nbre)
    {
        cout << "Enter the new string: ";
        cin.ignore(INT_MAX, '\n');
        cin.getline(tab[numero], size, ' ');
    }
    else
    {
        // check if the number is valid 
        cout << "There is no string with this number" << endl;
    }
}

/*
 * Display the strings.
 *
 * @param tab  String array
 * @param nbre Maximum size of a string
 */
void display(char *tab[], int const &nbre)
{
    cout << "Current strings:" << endl << endl;
    for (int i = 0; i < nb_ch; ++i)
        cout << tab[i] << endl;
}


/*
 * Sort the string array using insertion sort
 *
 * @param tab  String array
 * @param nbre Maximum size of a string
 */
void sort(char *tab[], int const &nbre)
{
    for (int i = 0; i < nb_ch - 1; ++i)
        for (int j = i + 1; j < nb_ch; ++j)
            if (strncmp(tab[i], tab[j], nbre) > 0)
                // Switch two strings without temporary variable
                for (int k = 0; k < nbre; ++k)
                    tab[i][k] ^= tab[j][k] ^= tab[i][k] ^= tab[j][k];
}
