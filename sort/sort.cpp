#include "sort.h"

void print(int* data,int sum) {
	for(int i = 0; i < sum; i++) {
		std::cout<<data[i]<<" ";
	}
};

//void bubbleSort(int* data,int sum) {
//
//	int curMax; // ���ֵ���±�
//	int temp;
//
//	for(int i = sum; i > 1; i--) {
//		int curMax = 0;
//		for(int ii = 1; ii < i; ii++) {
//			// ѡ�������
//			if(data[ii] > data[curMax]) {
//				curMax = ii;
//			}
//			// �����һ�������������Լ�������һ��
//			if(ii == i-1&&curMax != ii) {
//				temp = data[ii];
//				data[ii] = data[curMax];
//				data[curMax] = temp;
//			}
//		}
//	}
//
//}

// ���
void bubbleSort(int* data,int sum) {

	bool modify = false;
	int temp = 0;

	for(int i = sum; i > 1; i--) {
		modify = false;
		for(int ii = 0; ii < i-1; ii++) {

			// �����һ�飬�������޸ģ�˵���Ѿ�ƽ����
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

	int leftPoint = start; // ��ָ��
	int rightPoint = start + sum -1; // ��ָ��

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

	// ����ָ��������˵�����С�� �ұߴ��ڵ���
	data[leftPoint] = basic;

	// ��ߵļ�����

	quickSort(data,start,leftPoint - start);

	// �ұߵļ�����
	// �������һ�����⣬���ڶԱȵ����ŵ��ұߣ����һֱΪ�㣬���ܽ�����ѭ��
	if(sum - (leftPoint-start) == sum) {
		quickSort(data,leftPoint+1,sum - (leftPoint-start)-1);
	} else {
		quickSort(data,leftPoint,sum - (leftPoint-start));
	}
}

void baseSort(int* data,int sum) {
	
}


