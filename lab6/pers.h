#ifndef __person_h__
#define __person_h__

#pragma once
int taker();
void p_gap(int l, char* s);
const int sur_l = 50;

typedef struct
{
    char surname[sur_l];
    int number;
    char type[10];
    int memory;
    char video[10];
    //int vin_num;
    int video_volume;
    char type_video[20];
    int num_vinchesters;
    int volume_vichesters;
    int num_controllers;
    int out_devices;
    char operation[20];
} users;
#endif
