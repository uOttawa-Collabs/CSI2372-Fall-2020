/*
CSI2372A - Fall 2020
File for Exercise 2 of Lab 2
October, 6th, 2020

@author Morris (Jun Yi) Cai: *
@author 

Using source code from "Lab1_CSI2372A_Fall2020.pdf"
*/

#include "myFile1.h"

/*
Function that uses insertion sort to sort an array
(int []) (int) --> null

ex. 
sort({2,4,88,2,3,55,87,134,2,5}, 10);

arr = {2, 2, 3, 4, 5, 55, 87, 88, 134}

*/
void sort ( int myTab[], int size_tab){
    int i, j, key;  
    for (i = 1; i < size_tab; i++){  
        key = myTab[i];  
        j = i - 1;  

        while (j >= 0 && myTab[j] > key){  
            myTab[j + 1] = myTab[j];  
            j = j - 1;  
        }  
        myTab[j + 1] = key;  
    }  

}