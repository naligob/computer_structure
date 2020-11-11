// 205883721 Ilan Bogomolnik 
#include <stdio.h>
#include <stdbool.h>
#include "ex1.h"

/* defining pointer to be unsigned char* 
 * so we can for each increasment advance in one byte
 */
typedef unsigned char *pointer;

int is_big_endian() {
   long a = 0x0000006d;
   // setting the pointer to point on the a value
   pointer start = (pointer) &a;
   // checking the first byte value of variable 'a'
   if (0x6d == start[0]){
        return 0;
    }
	return 1;	
}

unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    pointer pointerX = (pointer) &x;
    pointer pointerY = (pointer) &y;
    int len = sizeof(unsigned long);
    int middle = len / 2;
    bool status = is_big_endian();
    // diffrent treatment for big endian or little endian 
    if (status) {
        // updating from last memory place to match big endian   
        for (int i = len; i >= middle; i--)
        {
            pointerX[i] = pointerY[i];            
        }
    } else {    
        // updating from first memory place to match little endian
        for (int i = 0; i < middle; i++)
        {
            pointerX[i] = pointerY[i];            
        }     
    }     
    return x;    
}
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    pointer pointerX = (pointer) &x;
    bool status = is_big_endian();
    int len = sizeof(unsigned long) - 1;
    // diffrent treatment for big endian or little endian 
    if (status) {
        //case big endian
        pointerX[i] = b;    
    } else {
        //case little endian
        pointerX[len - i] = b;
    }
    return x;
}
