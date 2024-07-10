#include "Types.h"
#include <sys/stat.h>
#include "Shared.h"
#include "string.h"
#include "Config.h"

#ifdef C_Func
typedef _bool(*Validator)(uint8_t);

int isFileExist(const uint8_t* filename) {
	struct stat Buffer;
	return (stat(filename, &Buffer)) == 0 ? True : False;

}

_bool isForbiddenChar(uint8_t ch) {
	const uint8_t forbiddenChars[] = { '/', '?', '"', '<', '>', '\\', '>', '<', '\0'};
	if (forbiddenChars == '\0')
		return False;


	return strchr(forbiddenChars, ch) != NULL;
}

// Function to check if a string contains characters not satisfying the validator function
_bool containsCharacters(const uint8_t* str, Validator validator) {
	while (*str) {
		if (!validator(*str)) {
			return True; // Special character found
		}
		str++;
	}
	return False; // No special characters found
}
_bool isContainSpecialCharacter(const uint8_t* filename) {

	const uint8_t forbiddenChars[] = {'/', '?', '"', '<', '>', '\\', '>>', '<<'};
	uint8_t i = 0, j;
	uint8_t fileLength = strlen((const uint8_t*)filename);;
	
	for (i = 0; i < fileLength; i++) {
		for (j = 0; j < sizeof(forbiddenChars); j++) {
			if (filename[i] == forbiddenChars[j]) {
				return True;
			}
		}
	}
	return False;
}

#endif

