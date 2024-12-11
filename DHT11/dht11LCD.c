#include <xc.h>

#include <stdint.h>


#include "supporing_cfile/lcd.h"


#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)

#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)

#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)

#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)

#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)

#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)



/*

 Program Flow related definition

 */

#define DHT11_Data_Pin   PORTDbits.RD5

#define DHT11_Data_Pin_Direction  TRISDbits.TRISD5

#define FIRST_LINE 0x80

#define SECOND_LINE 0xC0



#define _XTAL_FREQ 20000000 //20 Mhz


unsigned char Check_bit, Temp_byte_1, Temp_byte_2, RH_byte_1, RH_byte_2;

unsigned char Himudity, RH, Sumation ;


//Dht11 related definition


void dht11_init();

void find_response();

char read_dht11();


// System related definitions


void system_init(void);

void introduction_screen(void);

void clear_screen(void);


void main() { 

 system_init();

 

 while(1){

     __delay_ms(800);

    dht11_init();

    find_response();

    if(Check_bit == 1){

        RH_byte_1 = read_dht11();

        RH_byte_2 = read_dht11();

        Temp_byte_1 = read_dht11();

        Temp_byte_2 = read_dht11();

        Sumation = read_dht11();

        if(Sumation == ((RH_byte_1+RH_byte_2+Temp_byte_1+Temp_byte_2) & 0XFF)){

            Himudity = Temp_byte_1;

            RH = RH_byte_1;                        

            lcd_com (0x80);                   

            lcd_puts("Temp: ");

            //lcd_puts("                ");

            lcd_data(48 + ((Himudity / 10) % 10));

            lcd_data(48 + (Himudity % 10));

            lcd_data(0xDF);

            lcd_puts("C   ");

            lcd_com (0xC0);            

            lcd_puts("Humidity: ");

             //lcd_puts("                ");

            lcd_data(48 + ((RH / 10) % 10));

            lcd_data(48 + (RH % 10));

            lcd_puts("%  ");

            }

        else{

            lcd_puts("Check sum error");

        }

    }

    else {

        clear_screen();

        lcd_com (0x80);

        lcd_puts("Error!!!");

        lcd_com (0xC0);

        lcd_puts("No Response.");

     }

    __delay_ms(1000);

 }

}


/*

 * This will initialize the dht22 sensor.

 */


void dht11_init(){

 DHT11_Data_Pin_Direction= 0; //Configure RD0 as output

 DHT11_Data_Pin = 0; //RD0 sends 0 to the sensor

 __delay_ms(18);

 DHT11_Data_Pin = 1; //RD0 sends 1 to the sensor

 __delay_us(30);

 DHT11_Data_Pin_Direction = 1; //Configure RD0 as input

 }


/*

 * This will find the dht22 sensor is working or not.

 */


 void find_response(){

 Check_bit = 0;

 __delay_us(40);

 if (DHT11_Data_Pin == 0){

 __delay_us(80);

 if (DHT11_Data_Pin == 1){

    Check_bit = 1;

 }     

 __delay_us(50);}

 }

 

 /*

 This Function is for read dht22.

 */

 

 char read_dht11(){

 char data, for_count;

 for(for_count = 0; for_count < 8; for_count++){

     while(!DHT11_Data_Pin); 

    __delay_us(30);

    if(DHT11_Data_Pin == 0){

        data&= ~(1<<(7 - for_count)); //Clear bit (7-b)

    }

    else{

        data|= (1 << (7 - for_count)); //Set bit (7-b)

        while(DHT11_Data_Pin);

    } //Wait until PORTD.F0 goes LOW

    }

 return data;

 }

 

 void system_init(){

     TRISB = 0; // LCD pins set to out. 

     lcd_init();

     introduction_screen();

     //dht11_init();

 }

 

 /*

 This Function is for Clear screen without command.

 */


void clear_screen(void){

    lcd_com(FIRST_LINE);

    lcd_puts("                ");

    lcd_com(SECOND_LINE);

    lcd_puts("                "); 

}


 

 /*

 This Function is for playing introduction.

 */


void introduction_screen(void){

    lcd_com(FIRST_LINE);

    lcd_puts("Welcome to");

    lcd_com(SECOND_LINE);

    lcd_puts("circuit Digest");

    __delay_ms(1000);

    __delay_ms(1000);

    clear_screen();

    lcd_com(FIRST_LINE);

    lcd_puts("DHT11 Sensor");

    lcd_com(SECOND_LINE);

    lcd_puts("with PIC16F877A");

    __delay_ms(1000);

    __delay_ms(1000);

}

