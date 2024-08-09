/*
 * Types.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Barakat
 */

#ifndef TYPES_H_
#define TYPES_H_

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef enum{/*Error Values*/
	Types_OK,
	Types_NOK
}Error_Types;

typedef enum{/*Digital Values*/
	Types_LOW,
	Types_HIGH
}Digital_Types;

#define NULL ((void*)0)


typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef unsigned long long int u64;
typedef signed long long int s64;

typedef float f32;
typedef double f64;
typedef long double f96;

typedef const unsigned char ku8 ;
typedef const unsigned  short int ku16 ;
typedef const unsigned long ku32 ;
typedef const signed char ks8 ;
//typedef const sig;

#endif /* _LIB_TYPES_H_ */
