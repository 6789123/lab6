#define _CRT_SECURE_NO_WARNINGS
#include "pers.h"
#include<stdio.h>  
#include<string>
#include <iostream>
#include <malloc.h>
#include <set>


using namespace std;

void p_gap(int l, char* b);

int taker(int n, char* base)
{
	users p, p_u;

	FILE* data = fopen(base, "r");
	
	set<string> names;

	int tp;
	int count = 0, count_u = 0;
	cout << "\nThe modt powerful computers:\n\n";
	printf("=======================================================================================================================================================================\n");
	printf("|   surname   |processor number|processor type|memory volume|videocontroller|v_volume|type|num vinch|vol vinch|num interated controllers|num out devices|operation sys|\n");
	printf("=======================================================================================================================================================================\n");

	while (fread(&p, 1, sizeof(p), data))
	{
		users* dubls = new users[n];
		FILE* data_u = fopen(base, "r");
		tp = 0;
		while (fread(&p_u, 1, sizeof(p_u), data_u))
		{
			if (strcmp(p.surname, p_u.surname) == 0 && count != count_u)
			{
				dubls[tp] = p_u;
				tp++;
			}
			count_u++;
		}

		if (tp == 0)
		{
			count_u = 0;
			count++;
			continue;
		}

		int k = 0, m = 0;

		for (int i=0; i < n; i++)
		{
			if (dubls[i].memory != -842150451)
			{
				if (k < dubls[i].number * dubls[i].memory)
				{
					k = dubls[i].number * dubls[i].memory;
					m = i;
				}
			}
		}

		int siz = names.size();
		names.insert(dubls[m].surname);
		if (siz == names.size())
		{
			count_u = 0;
			count++;
			continue;
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

		delete[] dubls;

		fclose(data_u);

		count_u = 0;
		count++;
	}
	printf("=======================================================================================================================================================================\n");

	return 0;
}