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
	//不写virtual关键字 将是静态联编 C++根据HeroFighter类型去执行power函数 在编译阶段就已经决定函数的调用
	//写了virtual动态联编 迟绑定 运行时 根据传入的不同对象执行不同的对象的函数 表现为多态
	if (hf.power() > ef.attack())
	{
		cout << "win" << endl;
	}
	else
	{
		cout << "lose" << endl;
	}
}

//多态的思想
//封装:突破C函数的概念 用类做函数参数的时候 可以使用对象的属性和方法
//继承:代码的复用
//多态:可以使用未来
//实现多态的三个条件
//C语言 间接赋值 指针存在的最大意义
//是C语言特有的（1 定义两个变量 2 建立关联 3 在被调用函数中间接修改实参的值）

//1 要有继承
//2 要有虚函数重写
//3 用父类指针（父类引用）指向子类对象
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
