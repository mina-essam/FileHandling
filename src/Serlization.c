#include "Types.h"
#include <sys/stat.h>
#include "Shared.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "File.h"
#include "Config.h"
#define C_Func
const char* PERSON_INFO_IN = "(%[^,], %d, %c)";
const char* PERSON_INFO_OUT = "(%s, %d, %c)\n";
typedef struct Person {
	char name[20];
	int age;
	char	gender;
	
}Person;

_bool SerializeStructData() {
	Person p1 = {
		.name = "Mina.Essam",
		.gender = 'M',
		.age = 29
	};
	FILE* file;
	Person p2;
	fopen_s(&file, "Per.dat", "w+");
	if (file == NULL) { return False; }

	fprintf_s(file, PERSON_INFO_OUT, p1.name, p1.age, p1.gender);
	printf("%s,%c,%d\n", p1.name, p1.gender, p1.age);
	fseek(file, 0, SEEK_SET);
	
	fscanf_s(file, PERSON_INFO_IN, p2.name,20, &p2.age, &p2.gender);
	
	printf("%s,%c,%d\n", p2.name, p2.gender, p2.age);
	return True;
}