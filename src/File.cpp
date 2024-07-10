#include "Types.h"
#include "stdio.h"
#include "stdlib.h"
#include "fstream"
#include "Shared.h"
#include "File.h"
//
//using namespace std;
//fstream file;
//
//sint32_t CreatingFileUsingCPPStyle(){
//	char FileName[FILE_NAME_LENGTH];
//	size_t	fileFormatLength = strlen(FILE_FORMAT),
//			Length = 0, 
//			availableLength = FILE_NAME_LENGTH -1;
//	fputs("Please enter file name: ", stdout);
//	if (!fgets(FileName, FILE_NAME_LENGTH, stdin))
//	{
//		fputs("The user termites the operation\n", stderr);
//		return FILE_CREATION_FAILED_CODE;
//	}
//	FileName[(Length = strspn(FileName, "\r\n"))] = 0;
//	if (availableLength - Length < fileFormatLength)
//	{
//		fprintf(stderr, "error: insufficient space available for '%s'.\n", FILE_FORMAT);
//		return FILE_CREATION_FAILED_CODE;
//	}
//
//	strcat_s(FileName, sizeof(FileName) / sizeof(FileName[0]), FILE_FORMAT);
//	file.open(FileName, ios::out);
//
//}