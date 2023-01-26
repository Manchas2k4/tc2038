// =================================================================
//
// File: header.h
// Author: Pedro Perez
// Description: This file contains the interface and implementation
//				of the Chronometer class, as well as the
//				implementation of some support functions. This class
//				is used to record the execution time of a program.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <sys/types.h>
#include <string>
#include <vector>

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long int lli;

struct timeval startTime, stopTime;
int started = 0;

// =================================================================
// Records the initial execution time.
// =================================================================
void startTimer() {
	started = 1;
	gettimeofday(&startTime, NULL);
}

// =================================================================
// Calculates the number of microseconds that have elapsed since
// the initial time.
//
// @returns the time passed
// =================================================================
double stopTimer() {
	long seconds, useconds;
	double duration = -1;

	if (started) {
		gettimeofday(&stopTime, NULL);
		seconds  = stopTime.tv_sec  - startTime.tv_sec;
		useconds = stopTime.tv_usec - startTime.tv_usec;
		duration = (seconds * 1000.0) + (useconds / 1000.0);
		started = 0;
	}
	return duration;
}

// =================================================================
// Swap the content of two localities (i, j) in array A.
//
// @param A, an array of T elements.
// @param i, an index in the array.
// @param j, an index in the array.
// =================================================================
template <class T>
void swap(T *A, int i, int j) {
  T aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

// =================================================================
// Converts the content of an array to a string.
//
// @param A, an array of T elements.
// @param size, the number of elements in the array.
// =================================================================
template <class T>
std::string arr2str(T *A, int size) {
  std::stringstream aux;

  aux << "[" << A[0];
  for (int i = 1; i < size; i++) {
    aux << ", " << A[i];
  }
  aux << "]";
  return aux.str();
}

#endif