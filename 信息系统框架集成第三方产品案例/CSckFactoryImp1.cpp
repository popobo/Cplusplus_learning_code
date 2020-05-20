#include "CSckFactoryImp1.h"


int CSckFactoryImp1::cltSocketInit()
{
	m_p = NULL;
	m_len = 0;
	return 0;
}

int CSckFactoryImp1::cltSocketSend(unsigned char*buf, int buflen)
{
	m_p = (unsigned char*)malloc(sizeof(unsigned char)*buflen);
	if (m_p == NULL)
	{
		return -1;
	}
	memcpy(m_p, buf, buflen);

	return 0;
}

int CSckFactoryImp1::cltSocketRev(unsigned char*buf, int*buflen)
{
	if (buf == NULL || buflen == NULL)
	{
		return -1;
	}
	*buflen = m_len;
	memcpy(buf, m_p, m_len);
	return 0;
}

int CSckFactoryImp1::cltSocketDestroy()
{
	if (m_p == NULL)
	{
		return -1;
	}
	free(m_p);
	m_p = NULL;
	return 0;
}