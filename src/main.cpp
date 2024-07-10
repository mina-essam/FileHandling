//#include "Types.h"
//#include "stdlib.h"
//#include "stdio.h"
//#include "File.h"
//#include <string.h>
//
//
////
////void printArr(void* ptr, int n) {
////	
////	for (int i = 0; i < n; i++) {
////		/*this mean you print the array element in 8 char hexadecimal
////		*whenever is space write 0 instead*/
////
////		printf("%02x ", ((char *)ptr)[i]);
////	}
////}
//sint32_t main(void) {
//
//	writingtoCSVFile();
//	
//	
//	
//	//void* arr = NULL;
//	//char type;
//	//printf("enter Type : \t");
//	//scanf_s("%c", &type);
//	//sint32_t arrSize = 3;
//
//	//FillAnyArray(arr, arrSize, type);
//	/*uint64_t  arr[] = { 7,16, 31,32,65 };
//	printArr(arr, 5 * sizeof(uint64_t));*/
//	return 0;
//}
#include "Types.h"
#include "stdlib.h"
#include "stdio.h"
#include "File.h"
#include <string.h>
#include <malloc.h>
#define ONEBIT 0x1
#define GETBIT(x, n) (((x) >>(n))&ONEBIT)

#include <algorithm>
#include <vector>
using namespace std;
int solution(vector<int>& a)
{
	int len = a.size();
	sort(a.begin(), a.end());
	bool isoneMissing = false;
	if (a[len - 1] <= 0) return 1;

	for (int i = 0; i < len; i++) {
		if (a[i] == 1)
			isoneMissing = true;
	}
	if (!isoneMissing) return 1;

	for (int i = 0; i < len; i++) {
		if (a[i] > 0 && (a[i + 1] - a[i] > 1))
			return (a[i] + 1);
	}

	return a[len - 1] + 1;
}

//
//void printArr(void* ptr, int n) {
//	
//	for (int i = 0; i < n; i++) {
//		/*this mean you print the array element in 8 char hexadecimal
//		*whenever is space write 0 instead*/
//
//		printf("%02x ", ((char *)ptr)[i]);
//	}
//}

static void ConvertToBinary(sint32_t value) {
	for (int i = sizeof(value) * 8 - 1; i >= 0; i--) {
		int bit = (value >> i) & 1;
		printf("%d", bit);
	}
	printf("\n");
}
sint32_t convertToBinary(sint32_t value) {
	sint32_t reminder = 0, temp = 1;

	while (value > 0) {
		reminder += (value % 2) * temp;

		value /= 2;
		temp *= 10;
	}
	return reminder;
}
void decimalToBinary(int decimalNumber) {
	// Array to store binary representation
	int binary[32];
	int i = 0;

	// Handle the case of zero separately
	if (decimalNumber == 0) {
		printf("Binary: 0\n");
		return;
	}

	// Convert decimal to binary
	while (decimalNumber > 0) {
		binary[i] = decimalNumber % 2;
		decimalNumber /= 2;
		i++;
	}

	// Print binary representation in reverse order
	printf("Binary: ");
	for (int j = i - 1; j >= 0; j--) {
		printf("%d", binary[j]);
	}
	printf("\n");
}
sint32_t main(void) {
	//writeToCSVFile();
//	readfromCSVFile();
	//WriteTXTFile();
	//READTXTFile();
	SerializeStructData();
	uint32_t num = 3;
	uint32_t bit_num = sizeof(num) * 8;
	for (int i = 0; i < bit_num; i++) {
		printf("%d", GETBIT(num, bit_num - i - 1));
	}
	printf("\n");
	ConvertToBinary(7);
	//decimalToBinary(5);
	//printf("value = %d\n", convertToBinary(8));
	//void* arr = NULL;
	//char type;
	//printf("enter Type : \t");
	//scanf_s("%c", &type);
	//sint32_t arrSize = 3;
	
	//FillAnyArray(arr, arrSize, type);
	/*uint64_t  arr[] = { 7,16, 31,32,65 };
	printArr(arr, 5 * sizeof(uint64_t));*/
	return 0;
}


