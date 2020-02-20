#include "search.h"

int binarySearch(int* data,int length,int targer) {
	int mid;

	int result = -1; // 输出找到下角标

	int l = 0;
	int r = length - 1;
	while(r >= l) {

		mid = (r + l) / 2;

		if(data[mid] == targer) {
			result =mid;
			break;
		}
		if(data[mid] < targer) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	// 特殊情况加判断一下
	if(data[l] == targer) {
		result = l;
	}

	return result;
}

int insertionSearch(int* data,int length,int targer) {

	int mid = (float)(targer - data[0]) / (float)(data[length - 1] - data[0]) * (length -1);

	int result = -1; // 输出找到下角标

	int l = 0;
	int r = length - 1;
	while(r >= l) {
		if(data[mid] == targer) {
			result =mid;
			break;
		}
		if(data[mid] < targer) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
		mid = (r + l) / 2;
	}

	// 特殊情况加判断一下
	if(data[l] == targer) {
		result = l;
	}

	return result;
}
