#include <16F877A.h>

#device ADC = 10
#fuses HS, NOLVP, NOBROWNOUT, NOWDT
#use delay(clock=20M)

#include <lcd.c>

void setup(){
   //set_tris_d(0);
   SETUP_ADC(ADC_CLOCK_INTERNAL);
   SETUP_ADC_PORTS(ALL_ANALOG);
   lcd_init();
}

float mapeo(int16 _valor_adc){
   float _voltaje=(_valor_adc/1023.0)*5.0;
   return _voltaje;
}

void main(){
   int16 valor_adc;
   float voltaje;
   setup();
   
   lcd_putc("\f*Voltimetro*");
   delay_ms(1000);
   lcd_putc("\f");
   
   while(true){
      //Primer voltaje
      SET_ADC_CHANNEL(0);
      delay_us(25);
      valor_adc=READ_ADC();
      lcd_gotoxy(1,1);
      voltaje = mapeo(valor_adc);
      printf(lcd_putc,"V1: %.3f V",voltaje);
      
      //Segundo voltaje
      SET_ADC_CHANNEL(1);
      delay_us(25);
      valor_adc=READ_ADC();
      lcd_gotoxy(1,2);
      voltaje = mapeo(valor_adc);
      printf(lcd_putc,"V2: %.3f V",voltaje);
   }
  
}
