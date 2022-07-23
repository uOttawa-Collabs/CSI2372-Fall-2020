#include <iostream> 		
#include <cstdlib>         // for exit()  
#include <cstring>         // for strcmp, strcpy...
#include <climits>         // for INT_MAX  

using namespace std;

const int size_ch = 20;     // maximum size of a string  
const int nb_ch = 5;        // Number of of strings processed  

void display(char *tab[], int const &nbre);                     // displays strings 
char menu(void);                                                // displays a menu and return the choice 
void replace(char *tab[], int const &nbre, int const &size);  	// replace one string by an other
void sort(char *tab[], int const &nbre);                        // insert sort 
