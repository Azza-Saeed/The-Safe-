


#ifndef APP_H_
#define APP_H_

#define F_CPU 8000000UL
#include <util/delay.h>

#include "keypad_driver.h"
#include "LCD.h"
#include "EEPROM_driver.h"

#define First_Location     0x20
#define Second_Location    0x21
#define Third_Location     0x22
#define Furth_Location     0x23
#define Status_Location    0x24
#define Maximum_Pass       4
#define Check_Data         0x44
#define Maximum_Tries      2

void APP_Init(void);

void APP_Main(void);

void Set_Password(void);

void Check_Password(void);


#endif /* APP_H_ */