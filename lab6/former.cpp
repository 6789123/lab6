#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>                          // IN UNIX WORKS
#include<iostream>
//#include<conio.h>
#include<string>
#include "pers.h"


using namespace std;

int taker(int n, char* base);

void p_gap(int l, char* s)
{
    if (l % 2 == 0)
    {
        int z = (l - strlen(s)) / 2;
        if (strlen(s) % 2 != 0)
        {
            for (int i = 0; i < z; i++)
            {
                cout << " ";
            }
        }
        else
        {
            for (int i = 0; i < z - 1; i++)
            {
                cout << " ";
            }
        }
        cout << s;
        for (int i = 0; i < z; i++)
        {
            cout << " ";
        }
        cout << "|";
    }
    else
    {
        int z = (l - strlen(s)) / 2;
        if (strlen(s) % 2 != 0)
        {
            for (int i = 0; i < z - 1; i++)
            {
                cout << " ";
            }
        }
        else
        {
            for (int i = 0; i < z; i++)
            {
                cout << " ";
            }
        }
        cout << s;
        for (int i = 0; i < z; i++)
        {
            cout << " ";
        }
        cout << "|";
    }
}

int main(int argc, char* argv[])
{
    FILE* fi, * fo;
    printf("argc=%d\n", argc);
    if (argc == 1)
    {
        if ((fi = fopen("in.txt", "r")) == NULL)
        {
            printf("Cannot input 1"); //getch();
            return 1;
        }
        if ((fo = fopen("Base.dat", "wb")) == NULL)
        {
            printf("Cannot output"); //getch(); 
            return 1;
        }
    }
    else
        if (argc == 2)
        {
            puts(argv[1]);
            printf("%s\n", argv[1]);
            if ((fi = fopen(argv[1], "r")) == NULL)
            {
                printf("Cannot input 2"); //getch(); 
                return 1;
            }
            if ((fo = fopen("Base.dat", "wb")) == NULL)
            {
                printf("Cannot output"); //getch(); 
                return 1;
            }
        }
        else
        {
            if ((fi = fopen(argv[1], "r")) == NULL)
            {
                printf("Cannot input 3"); //getch(); 
                return 1;
            }
            if ((fo = fopen(argv[2], "wb")) == NULL)
            {
                printf("Cannot output"); //getch(); 
                return 1;
            }
        }

    users p;
    users for_print;
    int n = 0;
    while (!feof(fi))
    {
        fscanf(fi, "%s %d %s %d %s %d %s %d %d %d %d %s", &p.surname, &p.number, &p.type, &p.memory, p.video, &p.video_volume, &p.type_video, &p.num_vinchesters, &p.volume_vichesters, &p.num_controllers, &p.out_devices, &p.operation);
        //cout<< p.surname <<" "<< p.number <<" "<< p.type <<" "<< p.memory << " " << p.video << " " << p.video_volume << " " << p.type_video << " " << p.num_vinchesters << " " << p.volume_vichesters << " " << p.num_controllers << " " << p.out_devices << " " << p.operation << "\n";
        fwrite(&p, sizeof(p), 1, fo); /* write struct s to file */
        n++;
    }

    fclose(fi);
    fclose(fo);
    FILE* data = fopen(argv[2], "r");
    printf("n=%d\n", n);
    printf("=======================================================================================================================================================================\n");
    printf("|   surname   |processor number|processor type|memory volume|videocontroller|v_volume|type|num vinch|vol vinch|num interated controllers|num out devices|operation sys|\n");
    printf("=======================================================================================================================================================================\n");
    //fprintf(fo, "All in Base:\n");
    while (fread(&for_print, 1, sizeof(for_print), data))
    {
        char s[80];
        //cout << for_print.surname << "\n";
        //printf("|%-10s| %d %d %d %s %d %s %d %d %d %d %s|\n", for_print.surname, for_print.number, for_print.type, for_print.memory, for_print.video, for_print.video_volume, for_print.type_video, for_print.num_vinchesters, for_print.volume_vichesters, for_print.num_controllers, for_print.out_devices, for_print.operation);
        cout << "|";
        p_gap(14, for_print.surname);

        sprintf(s, "%d", for_print.number);
        p_gap(17, s);

        p_gap(15, for_print.type);

        sprintf(s, "%d", for_print.memory);
        p_gap(14, s);

        p_gap(16, for_print.video);

        sprintf(s, "%d", for_print.video_volume);
        p_gap(9, s);

        p_gap(5, for_print.type_video);

        sprintf(s, "%d", for_print.num_vinchesters);
        p_gap(10, s);

        sprintf(s, "%d", for_print.volume_vichesters);
        p_gap(10, s);

        sprintf(s, "%d", for_print.num_controllers);
        p_gap(26, s);

        sprintf(s, "%d", for_print.out_devices);
        p_gap(16, s);

        p_gap(14, for_print.operation);

        cout << "\n";
    }
    cout << "\n";
    printf("=======================================================================================================================================================================\n");
    taker(n, argv[2]);
}