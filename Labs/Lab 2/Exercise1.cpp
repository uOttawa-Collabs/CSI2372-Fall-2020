/**
 * Exercise 1
 * 
 * @author Jake Wang
 */
#include <iostream> 
using namespace std;

int main()
{
	int tab[80];
    int *p;
	int i;

	for (i = 0; i < 80; i++)
		tab[i] = i * i;
	cout << tab[2] << endl;    // Insert

    tab[2] = tab[1];
	cout << tab[2] << endl;    // Insert

    tab[2] = *(tab + 1);
	cout << tab[2] << endl;    // Insert

    *(tab + 2) = tab[1];
	cout << tab[2] << endl;    // Insert

    *(tab + 2) = *(tab + 1);
	cout << tab[2] << endl;    // Insert

	p = &tab[0];
	p = tab + 1;
	tab[4] = *p;
	cout << tab[4] << endl;    // Insert

	return 0;
}
