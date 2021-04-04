#define _CRT_SECURE_NO_WARNINGS
#include "pers.h"
#include<stdio.h>  
#include<string>
#include "pers.h"
#include <iostream>
#include <malloc.h>



using namespace std;

int taker(int n, char* base)
{
	users p, p_u;
	users* dubls = new users[n];

	FILE* data = fopen(base, "r");
	int count = 0, count_u = 0;
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

		for (int i=0; i < n; i++)
		{
			if (dubls[i].surname != 0)
			{

			}
		}

		count_u = 0;
		count++;
	}
	return 0;
}