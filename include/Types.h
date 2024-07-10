#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

	typedef enum Bool {
		False = 0, True
	}_bool;

typedef unsigned char  uint8_t;
typedef signed char sint8_t;

typedef unsigned short uint16_t;
typedef signed short sint16_t;

typedef unsigned int uint32_t;
typedef signed int sint32_t;

typedef unsigned long long uint64_t;
typedef signed long long sint64_t;

typedef long double double64_t;


#ifdef __cplusplus
}
#endif
#endif // !TYPES_H
