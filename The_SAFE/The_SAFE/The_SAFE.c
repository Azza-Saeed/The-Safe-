/*
 * The_SAFE.c
 *
 * Created: 02/12/2023 06:14:00 م
 *  Author: Azza Saeed
 */ 


#include <avr/io.h>
#include "APPLICATION/APP.h"

int main(void)
{
	APP_Init();
    while(1)
    {
        APP_Main();
    }
}