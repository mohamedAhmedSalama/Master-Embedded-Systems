/*
 * Platform_Types.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Mohamed Ahmed Salama
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/*------------boolean definition---------------*/
#include <stdbool.h>

#ifndef _Bool
#define _Bool	unsigned char
#endif

#ifndef TRUE
#define TRUE	(boolean)true
#endif

#ifndef FALSE
#define FALSE	(boolean)false
#endif

/*------------------ Arch --------------------*/
#define CPU_TYPE_8		8
#define CPU_TYPE_16		16
#define CPU_TYPE_32		32
#define CPU_TYPE_64		64

#define MSB_FIRST		0
#define LSB_FIRST		1

#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST  1

/*----------------- Arch Config --------------*/
#define CPU_TYPE		CPU_TYPE_32
#define CPU_BIT_ORDER	MSB_FIRST
#define CPU_BYTE_ORDER	HIGH_BYTE_FIRST


/*--------------- Data Types -----------------*/

/* 	boolean data type */

typedef _Bool	boolean;

/*  Unsigned data types */

typedef unsigned char            uint8;
typedef unsigned short           uint16;
typedef unsigned int             uint32;


/*  Signed data types */

typedef signed char            sint8;
typedef signed short           sint16;
typedef signed int             sint32;


/*  Volatile Unsigned data types */

typedef volatile unsigned char            vuint8;
typedef volatile unsigned short           vuint16;
typedef volatile unsigned int             vuint32;


/*  Volatile Signed data types */

typedef volatile signed char            vsint8;
typedef volatile signed short           vsint16;
typedef volatile signed int             vsint32;


typedef  double           int64;
typedef  long double      int80;
typedef volatile  double          vint64;
typedef volatile  long double     vint80;

#endif /* PLATFORM_TYPES_H_ */
