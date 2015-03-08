#ifndef NUMGUESS
#define NUMGUESS
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;

class numguess
{
private:
	char * c;
	char * p;
	int num;
	int times;
	void gameset();
	void gameinit();
	int gamechoose();
	int gameinput();
	int gamejudge();
//	void gameanser();
	void autogame();
public:
	numguess();
	~numguess();
	void play();
	void gamerun();

};
#endif