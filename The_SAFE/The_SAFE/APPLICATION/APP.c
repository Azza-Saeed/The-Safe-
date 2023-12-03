#include "APP.h"

char Tem_Location[4];
char Pass=NOTPRESSED;
char i;
char tries= Maximum_Tries;
char correct=0;


void APP_Init(){
	LCD_vInit();
	keypad_vInit();
}

void APP_Main(){
	
	Set_Password();
	Check_Password();
}
	
void Set_Password(void){
		if( EEPROM_read(Status_Location) == NOTPRESSED ){
			LCD_clearscreen();
			LCD_movecursor(1,0);
			LCD_vSend_string("Set Pass:");
			for (i=0;i<Maximum_Pass;i++){
				do
				{
					Pass=keypad_u8check_press();
					
				} while ( Pass == NOTPRESSED );
				LCD_movecursor(1,10+i);
				LCD_vSend_char(Pass);
				_delay_ms(500);
				LCD_movecursor(1,10+i);
				LCD_vSend_char('*');
				EEPROM_write(First_Location+i,Pass);
			}
			EEPROM_write(Status_Location,Check_Data);
			
		}
}		
void Check_Password(void){
		while( correct==0 )
		{
			Tem_Location[0]=Tem_Location[1]=Tem_Location[2]=Tem_Location[3]=NOTPRESSED;
			LCD_clearscreen();
			LCD_movecursor(1,0);
			LCD_vSend_string("Enter Pass:");
			for (i=0;i<Maximum_Pass;i++)
			{
				do
				{
					Tem_Location[i]=keypad_u8check_press();
					
				} while ( Tem_Location[i] == NOTPRESSED );
				//LCD_movecursor(1,12+i);
				LCD_vSend_char(Tem_Location[i]);
				_delay_ms(500);
				LCD_movecursor(1,12+i);
				LCD_vSend_char('*');
			}
			if( EEPROM_read(First_Location) == Tem_Location[0] && EEPROM_read(Second_Location) == Tem_Location[1] && EEPROM_read(Third_Location) == Tem_Location[2] && EEPROM_read(Furth_Location) == Tem_Location[3] ){
				LCD_clearscreen();
				LCD_movecursor(1,0);
				LCD_vSend_string("Correct Pass");
				_delay_ms(1000);
				LCD_clearscreen();
				LCD_movecursor(1,0);
				LCD_vSend_string("The Safe Opened");
				_delay_ms(1000);
				correct=1;
			}else{
				tries--;
				if(tries>0){
					LCD_clearscreen();
					LCD_movecursor(1,0);
					LCD_vSend_string("Wrong Pass");
					_delay_ms(500);
					LCD_clearscreen();
					LCD_movecursor(1,0);
					LCD_vSend_string("Tries left:");
					_delay_ms(500);
					LCD_movecursor(1,12);
					LCD_vSend_char(tries+48);// asci code
					_delay_ms(500);
					
				}else{
					LCD_clearscreen();
					LCD_movecursor(1,0);
					LCD_vSend_string("Wrong Pass");
					_delay_ms(500);
					LCD_clearscreen();
					LCD_movecursor(1,0);
					LCD_vSend_string("The Safe Closed");
					_delay_ms(500);
					correct=1;
				}
			}
		}
}