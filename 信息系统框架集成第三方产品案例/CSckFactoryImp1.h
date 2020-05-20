#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#pragma once
#include "CSocketProtocol.h"
using namespace std;


class CSckFactoryImp1:public CSocketProtoco
{
public:
	virtual int cltSocketInit();

	virtual int cltSocketSend(unsigned char*buf, int buflen);

	virtual int cltSocketRev(unsigned char*buf, int*buflen);

	virtual int cltSocketDestroy();
protected:
private:
	unsigned char*m_p;
	int m_len;
};
