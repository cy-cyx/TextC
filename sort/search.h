#ifndef FIND_H
#define FIND_H

// 只能升序的数组
int binarySearch(int*,int,int);

// 插值算法 其实就是在二分算法的基础，加入自适应的初始的中值，这样更快定位到弄表值
int insertionSearch(int*,int,int);

#endif
