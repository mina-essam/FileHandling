#ifndef SHARED_H
#define SHARED_H

#ifdef __cplusplus
extern "C" {
#endif
typedef _bool(*Validator)(uint8_t);
_bool isForbiddenChar(uint8_t ch);
_bool isContainSpecialCharacter(const uint8_t*);
_bool containsCharacters(const uint8_t* , Validator );
_bool isFileExist(const uint8_t*);
#ifdef __cplusplus
}
#endif

#endif