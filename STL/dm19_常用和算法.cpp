#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <numeric>
#include <ctime>
using namespace std;


void test191()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
		v2.push_back(i + 3);
	}
	vector<int>vTarget;
	vTarget.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itend, [](int val) {cout << val << " "; });
	
	cout << endl;
	vTarget.resize(v1.size() + v2.size());
	itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itend, [](int val) {cout << val << " "; });

	cout << endl;
	vTarget.resize(max(v1.size(), v2.size()));
	//v1差v2
	itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itend, [](int val) {cout << val << " "; });
	
	cout << endl;
	vTarget.resize(max(v1.size(), v2.size()));
	//v2差v1
	itend = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itend, [](int val) {cout << val << " "; });
}

class Competer
{
public:
	Competer(){}
	Competer(char name, int score, int id)
	{
		m_name = name;
		m_score = score;
		m_id = id;
	}
	Competer(const Competer&c)
	{
		m_name = c.m_name;
		m_score = c.m_score;
		m_id = c.m_id;
	}
	char m_name;
	int m_score;
	int m_id;

};

void test192()
{
	string namelist = "ABCDEFGHIJKLMNOPQRSTUVWX";
	vector<int>id_vector;
	map<int, Competer>competer_map;
	for (int i = 0; i < 24; ++i)
	{
		Competer temp(namelist.at(i), 0, i + 100);
		id_vector.push_back(i);
		competer_map.insert(make_pair(i + 100, temp));
	}
	int i = 0;
	int j = 0;
	int k = 0;
	int draw_id = 0;
	int score = 0;
	int final_score = 0;
	vector<int>id_drawed;
	vector<int>id_droped;
	vector<int>::iterator pos;
	vector<int>id_drawed_this_time;
	deque<int>score_this_time;
	multimap<int, int, greater<int>>score_map_this_time;
	cout << "**********************剩余比赛人数" << competer_map.size() << endl;
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 6;)
		{
			draw_id = rand() % 24 + 100;
			pos = find(id_droped.begin(), id_droped.end(), draw_id);
			if (pos != id_droped.end())
			{
				continue;
			}
			pos = find(id_drawed.begin(), id_drawed.end(), draw_id);
			if (pos == id_drawed.end())
			{
				id_drawed.push_back(draw_id);
				id_drawed_this_time.push_back(draw_id);
				++j;
			}
		}
		cout << "----------------------------第一轮第" << i << "组选手成绩----------------------------" << endl;
		for (j = 0; j < 6; ++j)
		{
			for (k = 0; k < 10; k++)
			{
				score = rand() % 101;
				score_this_time.push_back(score);
			}
			score_this_time.pop_back();
			score_this_time.pop_front();
			final_score = accumulate(score_this_time.begin(), score_this_time.end(), 0) / 8;
			competer_map[id_drawed_this_time.at(j)].m_score = final_score;
			score_map_this_time.insert(make_pair(final_score, id_drawed_this_time.at(j)));

			score_this_time.clear();
		}
		j = 0;
		for (multimap<int, int, greater<int>>::iterator it = score_map_this_time.begin(); it != score_map_this_time.end(); ++it, ++j)
		{
			cout << it->second << "号选手" << "成绩为 " << it->first << endl;
			if (j > 2)
			{
				cout << "淘汰" << endl;
				competer_map.erase(it->second);
				id_droped.push_back(it->second);
			}
		}
		
		id_drawed_this_time.clear();
		score_map_this_time.clear();
	}
	id_drawed.clear();
	cout << "**********************剩余比赛人数" << competer_map.size() << endl;
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 6;)
		{
			draw_id = rand() % 24 + 100;
			pos = find(id_droped.begin(), id_droped.end(), draw_id);
			if (pos != id_droped.end())
			{
				continue;
			}
			pos = find(id_drawed.begin(), id_drawed.end(), draw_id);
			if (pos == id_drawed.end())
			{
				id_drawed.push_back(draw_id);
				id_drawed_this_time.push_back(draw_id);
				++j;
			}
		}
		cout << "----------------------------第二轮第" << i << "组选手成绩----------------------------" << endl;
		for (j = 0; j < 6; ++j)
		{
			for (k = 0; k < 10; k++)
			{
				score = rand() % 101;
				score_this_time.push_back(score);
			}
			score_this_time.pop_back();
			score_this_time.pop_front();
			final_score = accumulate(score_this_time.begin(), score_this_time.end(), 0) / 8;
			competer_map[id_drawed_this_time.at(j)].m_score = final_score;
			score_map_this_time.insert(make_pair(final_score, id_drawed_this_time.at(j)));

			score_this_time.clear();
		}
		j = 0;
		for (multimap<int, int, greater<int>>::iterator it = score_map_this_time.begin(); it != score_map_this_time.end(); ++it, ++j)
		{
			cout << it->second << "号选手" << "成绩为 " << it->first << endl;
			if (j > 2)
			{
				cout << "淘汰" << endl;
				int flag = competer_map.erase(it->second);
				if (flag == 0)
				{
					cout << "删除失败" << endl;
				}
				else
				{
					cout << "删除成功" << endl;
				}
				id_droped.push_back(it->second);
			}
		}
		id_drawed_this_time.clear();
		score_map_this_time.clear();
	}
	id_drawed.clear();
	for (i = 0; i < 1; ++i)
	{
		for (j = 0; j < 6;)
		{
			draw_id = rand() % 24 + 100;
			pos = find(id_droped.begin(), id_droped.end(), draw_id);
			if (pos != id_droped.end())
			{
				continue;
			}
			pos = find(id_drawed.begin(), id_drawed.end(), draw_id);
			if (pos == id_drawed.end())
			{
				id_drawed.push_back(draw_id);
				id_drawed_this_time.push_back(draw_id);
				++j;
			}
		}
		cout << "**********************剩余比赛人数" << competer_map.size() << endl;
		cout << "----------------------------第三轮第" << i << "组选手成绩----------------------------" << endl;
		for (j = 0; j < 6; ++j)
		{
			for (k = 0; k < 10; k++)
			{
				score = rand() % 101;
				score_this_time.push_back(score);
			}
			score_this_time.pop_back();
			score_this_time.pop_front();
			final_score = accumulate(score_this_time.begin(), score_this_time.end(), 0) / 8;
			competer_map[id_drawed_this_time.at(j)].m_score = final_score;
			score_map_this_time.insert(make_pair(final_score, id_drawed_this_time.at(j)));

			score_this_time.clear();
		}
		j = 0;
		for (multimap<int, int, greater<int>>::iterator it = score_map_this_time.begin(); it != score_map_this_time.end(); ++it, ++j)
		{
			cout << it->second << "号选手" << "成绩为 " << it->first << endl;
			if (j > 2)
			{
				cout << "淘汰" << endl;
				int flag = competer_map.erase(it->second);
				if (flag == 0)
				{
					cout << "删除失败" << endl;
				}
				else
				{
					cout << "删除成功" << endl;
				}
				id_droped.push_back(it->second);
			}
		}
		id_drawed_this_time.clear();
		score_map_this_time.clear();
	}
	id_drawed.clear();
	//for_each(id_droped.begin(), id_droped.end(), [](int val) {cout << val << "_"; });
	cout << "**********************剩余比赛人数" << competer_map.size() << endl;
	i = 0;
	for (map<int, Competer>::iterator it = competer_map.begin(); it != competer_map.end(); ++it,i++)
	{
		switch (i)
		{
		case 0:
			cout << "冠军:";
			break;
		case 1:
			cout << "亚军:";
			break;
		case 2:
			cout << "季军:";
			break;
		default:
			break;
		}
		cout << it->first << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	test192();
	system("pause");
	return EXIT_SUCCESS;
}
