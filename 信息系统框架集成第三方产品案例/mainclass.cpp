#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
#include "CSocketProtocol.h"
#include "CSckFactoryImp1.h"
using namespace std;

int socket_send_recv(CSocketProtoco*sp, unsigned char*in, int inlen, unsigned char*out, int*outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketSend(in, inlen);
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketRev(out, outlen);
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketDestroy();
	if (ret != 0)
	{
		goto End;
	}
	return 0;
End:
	return ret;
}


int main()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen = 0;
	unsigned char out[4096];
	int oulen = 0;
	strcpy((char*)in, "hello world");
	inlen = 9;
	CSocketProtoco*sp = NULL;
	sp = new CSckFactoryImp1;
	ret = socket_send_recv(sp, in, inlen, out, &oulen);
	if (ret != 0)
	{
		cout << "socket_send_recv error" << endl;
	}
	delete sp;
	system("pause");
	return EXIT_SUCCESS;
}
