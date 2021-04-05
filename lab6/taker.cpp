#define _CRT_SECURE_NO_WARNINGS
#include "pers.h"
#include<stdio.h>  
#include<string>
#include "pers.h"
#include <iostream>
#include <malloc.h>

using namespace std;

void p_gap(int l, char* b);

int taker(int n, char* base)
{
	users p, p_u;
	users* dubls = new users[n];

	FILE* data = fopen(base, "r");
	int count = 0, count_u = 0;
	cout << "Самые мощные компьютеры:\n";
	while (fread(&p, 1, sizeof(p), data))
	{
		while (fread(&p_u, 1, sizeof(p_u), data))
		{
			if (p.surname == p_u.surname && count != count_u)
			{
				dubls[count_u] = p;
			}
			count_u++;
		}

		int k = 0, m = 0;

		for (int i=0; i < n; i++)
		{
			if (dubls[i].surname != 0)
			{
				if (k < dubls[i].number * dubls[i].memory)
				{
					k = dubls[i].number * dubls[i].memory;
					m = i;
				}
			}
		}

		char s[80];

		cout << "|";
		p_gap(14, dubls[m].surname);

		sprintf(s, "%d", dubls[m].number);
		p_gap(17, s);

		p_gap(15, dubls[m].type);

		sprintf(s, "%d", dubls[m].memory);
		p_gap(14, s);

		p_gap(16, dubls[m].video);

		sprintf(s, "%d", dubls[m].video_volume);
		p_gap(9, s);

		p_gap(5, dubls[m].type_video);

		sprintf(s, "%d", dubls[m].num_vinchesters);
		p_gap(10, s);

		sprintf(s, "%d", dubls[m].volume_vichesters);
		p_gap(10, s);

		sprintf(s, "%d", dubls[m].num_controllers);
		p_gap(26, s);

		sprintf(s, "%d", dubls[m].out_devices);
		p_gap(16, s);

		p_gap(14, dubls[m].operation);

		cout << "\n";

		memset(dubls, 0, sizeof dubls);

		count_u = 0;
		count++;
	}
	return 0;
}