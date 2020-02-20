#include "sort.h"

void print(int* data,int sum) {
	for(int i = 0; i < sum; i++) {
		std::cout<<data[i]<<" ";
	}
};

//void bubbleSort(int* data,int sum) {
//
//	int curMax; // 最大值的下标
//	int temp;
//
//	for(int i = sum; i > 1; i--) {
//		int curMax = 0;
//		for(int ii = 1; ii < i; ii++) {
//			// 选择出最大的
//			if(data[ii] > data[curMax]) {
//				curMax = ii;
//			}
//			// 到最后一个，如果最大不是自己，交换一下
//			if(ii == i-1&&curMax != ii) {
//				temp = data[ii];
//				data[ii] = data[curMax];
//				data[curMax] = temp;
//			}
//		}
//	}
//
//}

// 最佳
void bubbleSort(int* data,int sum) {

	bool modify = false;
	int temp = 0;

	for(int i = sum; i > 1; i--) {
		modify = false;
		for(int ii = 0; ii < i-1; ii++) {

			// 如果走一遍，都不用修改，说明已经平衡了
			if(data[ii] > data[ii+1] ) {
				temp = data[ii];
				data[ii] = data[ii+1];
				data[ii+1] = temp;
				modify = true;
			}
		}
		if(modify == false) return;
	}
}


void quickSort(int* data,int start,int sum) {

	if(sum < 2) return;

	int leftPoint = start; // 左指针
	int rightPoint = start + sum -1; // 右指针

	bool left = false;

	int basic = data[leftPoint];

	while(leftPoint != rightPoint) {
		if(left) {
			if(data[leftPoint] >= basic) {
				data[rightPoint] = data[leftPoint];

				rightPoint--;
				left = false;
			} else {
				leftPoint++;
			}
		} else {
			if(data[rightPoint] < basic) {

				data[leftPoint] = data[rightPoint];

				leftPoint++;
				left = true;
			} else {
				rightPoint--;
			}
		}
	}

	// 两个指针相遇，说明左边小于 右边大于等于
	data[leftPoint] = basic;

	// 左边的继续排

	quickSort(data,start,leftPoint - start);

	// 右边的继续排
	// 这里存在一个问题，由于对比的数放到右边，左边一直为零，可能进入死循环
	if(sum - (leftPoint-start) == sum) {
		quickSort(data,leftPoint+1,sum - (leftPoint-start)-1);
	} else {
		quickSort(data,leftPoint,sum - (leftPoint-start));
	}
}

void baseSort(int* data,int sum) {
	
}


