/*
 * Shell Simulator
 * 2010.08.18 by alex
 */

#ifndef BASE_MACRO_H_
#define BASE_MACRO_H_
#pragma once 

#define ZERO 0

#define SUCCESS 1
#define FAILURE 0

#define NEW_OPERATOR_ERROR 0

#if defined(_WIN32)
#define OS_WIN
#define NULL 0
#elif defined(__GNUC__)
#define OS_GNU
#endif



#endif /* BASE_MACRO_H_ */