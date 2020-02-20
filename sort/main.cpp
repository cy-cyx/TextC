#include <iostream>
#include "sort.h"
#include "search.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	int data[] = {3,323,42,1,4,5,32,3,5,-13,-5,-32};

//	bubbleSort(data,sizeof(data)/sizeof(int));

	quickSort(data,0,sizeof(data)/sizeof(int));

	print(data,sizeof(data)/sizeof(int));

	int searchResult = insertionSearch(data,sizeof(data)/sizeof(int),-32);

	std::cout <<std::endl<<"查找目标数5，找到的下角标"<< searchResult;

	return 0;
}
