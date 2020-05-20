#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>
using namespace std;

class HeroFighter
{
public:
	virtual int power()
	{
		return 10;
	}
protected:
private:
};

class EnemyFighter
{
public:
	int attack()
	{
		return 15;
	}
protected:
private:
};

class AdvanceFighter :public HeroFighter
{
public:
	virtual int power()
	{
		return 20;
	}

};

void Test02(HeroFighter&hf,EnemyFighter&ef)
{
	//��дvirtual�ؼ��� ���Ǿ�̬���� C++����HeroFighter����ȥִ��power���� �ڱ���׶ξ��Ѿ����������ĵ���
	//д��virtual��̬���� �ٰ� ����ʱ ���ݴ���Ĳ�ͬ����ִ�в�ͬ�Ķ���ĺ��� ����Ϊ��̬
	if (hf.power() > ef.attack())
	{
		cout << "win" << endl;
	}
	else
	{
		cout << "lose" << endl;
	}
}

//��̬��˼��
//��װ:ͻ��C�����ĸ��� ����������������ʱ�� ����ʹ�ö�������Ժͷ���
//�̳�:����ĸ���
//��̬:����ʹ��δ��
//ʵ�ֶ�̬����������
//C���� ��Ӹ�ֵ ָ����ڵ��������
//��C�������еģ�1 ������������ 2 �������� 3 �ڱ����ú����м���޸�ʵ�ε�ֵ��

//1 Ҫ�м̳�
//2 Ҫ���麯����д
//3 �ø���ָ�루�������ã�ָ���������
int main02()
{
	HeroFighter hf;
	AdvanceFighter af;
	EnemyFighter ef;
	if (hf.power() > ef.attack())
	{
		cout << "win" << endl;
	}
	else
	{
		cout << "lose" << endl;
	}
	if (af.power() > ef.attack())
	{
		cout << "win" << endl;
	}
	else
	{
		cout << "lose" << endl;
	}
	Test02(hf, ef);
	Test02(af, ef);
	system("pause");
	return EXIT_SUCCESS;
}
