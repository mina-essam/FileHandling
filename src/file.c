#include "Types.h"
#include <sys/stat.h>
#include "Shared.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "File.h"
#include "Config.h"
#define C_Func
typedef struct {
	uint8_t		s_gender[3];
	uint8_t		s_name[100];
	uint32_t	s_Age;
	double64_t	s_GPA;
}Student;
typedef struct student {
	char name[30];
	sint32_t age;
	double64_t GPA;
}student;
typedef struct Points {
	sint32_t x, y, value;
}Points;

#define student_numbers 2
static FILE* File;
static uint8_t filename[FILE_NAME_LENGTH];
sint32_t C_FileCreation(uint8_t fileFormatType) {

	errno_t error_code;
	size_t
		TXT_Format_Length = strlen(TXT_FORMAT),
		CSV_Format_Length = strlen(CSV_FORMAT),
		AvailableLength = FILE_NAME_LENGTH - 1,
		Length = 0;
	fputs("Please enter File Name:", stdout);

	if (!fgets(filename, FILE_NAME_LENGTH, stdin))
	{
		fputs("User cancelled creation operation", stderr);
		return FILE_CREATION_FAILED_CODE;
	}
	filename[(Length = strcspn(filename, "\r\n"))] = 0;

	switch (fileFormatType)
	{
	case 'c':
	case 'C':
	case 'v':
	case 'V':
	case 's':
	case 'S':

		if (AvailableLength - Length < CSV_Format_Length)
		{
			fprintf(stderr, "File name exceeds character limit allowed %s\n", CSV_FORMAT);
			return FILE_CREATION_FAILED_CODE;
		}
		strcat_s(filename, sizeof(filename) / sizeof(filename[0]), CSV_FORMAT);
		break;

	case 't':
	case 'T':
		if (AvailableLength - Length < TXT_Format_Length)
		{
			fprintf(stderr, "File name exceeds character limit allowed %s\n", TXT_FORMAT);
			return FILE_CREATION_FAILED_CODE;
		}
		strcat_s(filename, sizeof(filename) / sizeof(filename[0]), TXT_FORMAT);
		break;
	default:
		printf("you did not choose a right file format option\n");
		break;
	}



	if (isContainSpecialCharacter(filename)) {
		printf("The File with given name [%s] contains un-allowed characters\n", filename);
		return FILE_CREATION_FAILED_CODE;
	}
	if (!isFileExist(filename))
	{

		error_code = fopen_s(&File, filename, "w+");
		if (error_code == FILE_CREATION_SUCCESS_CODE)
		{
			printf("File [%s] is created successfully using C-style\n", filename);
			fprintf(File, "%s", filename);
			_fcloseall();
			return FILE_CREATION_SUCCESS_CODE;
		}
		else {
			printf("Unable to create new file with given name [%s]", filename);
			return FILE_CREATION_FAILED_CODE;
		}
	}

	else {
		printf("The File with given name [%s] already exists\n", filename);
		return FILE_CREATION_FAILED_CODE;
	}
}

void FillAnyArray(void* Array, sint32_t arrayLength, sint8_t allocationType) {

	switch (allocationType)
	{
	case 'i':
	case 'I':
		Array = (int*)malloc(arrayLength * sizeof(int));
		printf("Memory successfully allocated using malloc of type int.\n");

		break;

	case 'f':
	case 'F':
		Array = (double*)malloc(arrayLength * sizeof(double));
		printf("Memory successfully allocated using malloc of type double.\n");
		break;


	default:
		printf("Allocation unsuccessful\n");
		printf_s("You have to choose between the letters 'F', 'f' for double allocation or 'I', 'i' for integer allocation");
		break;
	}

	if (Array != NULL)
	{
		if (allocationType == 'i' || allocationType == 'I') {

			for (size_t i = 0; i < arrayLength; i++) {
				scanf_s("%d", &*((int*)Array + i));
			}
		}
		else {
			for (size_t i = 0; i < arrayLength; i++) {
				scanf_s("%lf", &*((double*)Array + i));
			}
		}

		printf("Memory elements are... :\t");
		if (Array != NULL) {
			if (allocationType == 'i' || allocationType == 'I') {
				for (size_t i = 0; i < arrayLength; i++)
				{

					printf("%d->", *((int*)Array + i));

				}

			}
			else
			{
				for (size_t i = 0; i < arrayLength; i++) {

					printf("%lf->", *((double*)Array + i));
				}

			}
		}

	}
}

void SetArrays(void* Array, int ArraySize, char ptrType)
{

	if (ArraySize <= 0)
		return;

	switch (ptrType)
	{
	case 'd':
	case 'D':
		Array = (int*)malloc(ArraySize * sizeof(int));
		if (Array == NULL) {
			printf("Memory not allocated.\n");
		}
		else {
			printf("Memory successfully allocated using malloc of type int.\n");
			for (int k = 0; k < ArraySize; ++k) {
				scanf_s("%d,", &*((int*)Array + k));
			}
			// Print the elements of the array
			printf("The elements of the array are: ");
			for (int k = 0; k < ArraySize; ++k) {
				printf("%d,", *((int*)Array + k));
			}

		}
		break;
	case 'f':
	case 'F':
		Array = (double*)malloc(ArraySize * sizeof(double));
		if (Array == NULL) {
			printf("Memory not allocated.\n");
		}
		else
		{

			printf("Memory successfully allocated using malloc.\n");
			// Get the elements of the array
			for (int k = 0; k < ArraySize; ++k) {
				scanf_s("%f,", &*((float*)Array + k));
			}
			// Print the elements of the array
			printf("The elements of the array are: ");
			for (int k = 0; k < ArraySize; ++k) {
				printf("%f,", *((float*)Array + k));

			}
			break;
	default:
		printf_s("You have to choose between the letters 'F', 'f' or 'D', 'd'");
		break;
		}
	}

}

_bool writeToCSVFile() {
	C_FileCreation('c');

	char s_Name[100] = { "" };
	char s_Gender[3] = { "" };
	if (File == NULL) {
		printf("File is not found, the operation will be terminated\n");
		return False;
	}
	else
	{
		fopen_s(&File, filename, "w+");

		Student students[student_numbers];


		fprintf_s(File, "Name, Gender, Age, GPA\n");


		printf("Please enter Student details:\n");
		/*for (int i = 0; i < 2; i++) {
			printf("Info of student %d\n", i);
			printf("Gender: ");
			fgets(s_Gender, 3, stdin);
			strcpy_s(students[i].s_gender, 3, s_Gender);

		}*/
		for (int h = 0; h < student_numbers; h++) {
			printf("Info of student %d\n", h);
			printf("Gender: ");
			fgets(s_Gender, 3, stdin);
			s_Gender[strcspn(s_Gender, "\n")] = 0; //to remove null terminator

			strcpy_s(students[h].s_gender, 3, s_Gender);

			printf("Name: ");

			fgets(s_Name, 100, stdin);
			s_Name[strcspn(s_Name, "\n")] = 0;
			strcpy_s(students[h].s_name, 100, s_Name);

		}

		for (int e = 0; e < student_numbers; e++) {
			printf("Info of student: %s \n", students[e].s_name);
			printf("Age: ");
			scanf_s("%d", &students[e].s_Age);

			printf("GPA: ");
			scanf_s("%lf", &students[e].s_GPA);

		}


		/*
		students[0].s_Age = 29;
		strcpy_s(students[0].s_name, sizeof(students[0].s_name) / sizeof(students[0].s_name[0]), "Mina Essam");
		students[0].s_gender = 'M';
		students[0].s_GPA = 89.87;

		students[1].s_Age = 26;
		strcpy_s(students[1].s_name, sizeof(students[1].s_name) / sizeof(char), "CAR SAM");
		students[1].s_gender = 'F';
		students[1].s_GPA = 89.87;

		*/
		printf("Info stored successfully to to the file\n");
		for (int i = 0; i < student_numbers; i++) {
			fprintf_s(File, "%s, %s, %d, %lf\n",
				students[i].s_name,
				students[i].s_gender,
				students[i].s_Age,
				students[i].s_GPA);

			if (ferror(File)) {
				printf("Something went wrong while writing to the file\n");
				return False;
			}
		}
		_fcloseall();
		printf("Records written successfully of [%d] Student(s)\n", student_numbers);
	}
}

_bool readfromCSVFile() {
	fopen_s(&File, filename, "r");
	if (File == NULL) {
		printf("Cannot open the file %s", filename);
		return False;
	}
	uint8_t fileBuffer[1024];
	uint8_t		s_gender[3];
	uint8_t		s_name[100];
	uint32_t	s_Age;
	double64_t	s_GPA;
	char* st = NULL;
	char* next = NULL;
	fgets(fileBuffer, sizeof(fileBuffer), File);
	printf("%s\n", fileBuffer);

	st = strtok_s(fileBuffer, ",", &next);
	printf("first token is %s\n", st);

	st = strtok_s(NULL, ",", &next);
	printf("Second token is %s\n", st);

	st = strtok_s(NULL, ",", &next);
	printf("Third token is %s\n", st);

	st = strtok_s(NULL, ",", &next);
	printf("Fourth token is %s\n", st);
	while (fgets(fileBuffer, sizeof(fileBuffer), File))
	{
		printf("%s\n", fileBuffer);
		st = strtok_s(fileBuffer, ",", &next);
		printf("first token is %s\n", st);

		st = strtok_s(NULL, ",", &next);
		printf("Second token is %s\n", st);

		st = strtok_s(NULL, ",", &next);
		printf("Third token is %s\n", st);

		st = strtok_s(NULL, ",", &next);
		printf("Fourth token is %s\n", st);
		//	/*
		//	* at first we put fileBuffer to start at the beginning of the file
		//	* and then we put NULL so that whatever comes next stop when you see a comma
		//	st = strtok(fileBuffer, ","); // stop when you see a comma
		//	strcpy_s(s_name, 100, st);

		//	st = strtok(NULL, ","); // stop when you see a
		//	strcpy(s_gender, 100, st);
		//	printf("%s%s\n", s_name, s_gender);*/
		//
		//	


	}
	printf("We reached the end of the file\n");
	fclose(File);
	printf("------------------------------------------\n");
	return True;
}

_bool WriteTXTFile() {
	fopen_s(&File, "MINA7.txt", "w+");
	uint8_t input[100];
	if (File == NULL) {
		printf("Cannot open the File\n");
		return FILE_CREATION_FAILED_CODE;
	}
	else {
		printf("enter a String to write IN FILE: ");
		gets_s(input, 100);
		fputs(input, File);
		printf("Data has been written Successfully\n");
		fclose(File);
		FILE_CREATION_SUCCESS_CODE;
	}

}
_bool READTXTFile() {
	fopen_s(&File, "mina.txt", "r");
	char input[1024];
	if (File == NULL) {
		printf("Cannot open the File\n");
		return FILE_CREATION_FAILED_CODE;
	}

		fgets(input, sizeof(input), File);
		
		while (!feof(File)) {
			Points p;
			sscanf_s(input, "%d %d %d\n", &p.x, &p.y, &p.value);
			printf("Read: %d %d %d\n", p.x, p.y, p.value);
			fgets(input, sizeof(input), File);
	    }
		fclose(File);

	return FILE_CREATION_SUCCESS_CODE;
}
_bool writeBinaryFile(char* filename, student* data, sint32_t total) {
	fopen_s(&File, filename, "wb");
	if (File == NULL) return False;
	data = malloc(sizeof(student) * total);
	if (fwrite(&total, sizeof(sint32_t), 1, File) != 1)
		return False;

	if (fwrite(data, sizeof(student), total, File) != total)
		return False;

	if (fclose(File) == EOF)
		return False;

	return True;
}

student* readBinaryFile(char* filename, sint32_t* total) {
	fopen_s(&File, filename, "rb");
	if (File == NULL) return NULL;

	

	if (fread(total, sizeof(sint32_t), 1, File) != 1)
		return NULL;
	student* data = malloc(sizeof(student) * *total);


	if (fread(data, sizeof(student), *total, File) != *total)
	{
		free(data);
		return NULL;
	}

	if (fclose(File) == EOF) {
		free(data);
		return NULL;
	}

	return data;
}