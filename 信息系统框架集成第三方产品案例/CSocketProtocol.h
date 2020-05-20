#define _CRT_SECURE_NO_WARNINGS  
#pragma once
#include<iostream>
using namespace std;

class CSocketProtoco 
{
public:
	virtual int cltSocketInit() = 0;

	virtual int cltSocketSend(unsigned char*buf, int buflen) = 0;
	
	virtual int cltSocketRev(unsigned char*buf, int*buflen) = 0;

	virtual int cltSocketDestroy() = 0;
};
