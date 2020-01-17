#include <iostream>
#include "sort.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	int data[] = {3,323,42,1,4,5,32,3,5,-13,-5,-32};

//	bubbleSort(data,sizeof(data)/sizeof(int));

//	quickSort(data,0,sizeof(data)/sizeof(int));

	print(data,sizeof(data)/sizeof(int));
	
	return 0;
}
