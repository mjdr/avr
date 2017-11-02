
#include "sd.h"


typedef unsigned char uchar;
#define send_func(A) SPI_send(A)



uchar SD_sendCMD(uchar cmd, uchar arg0, uchar arg1, uchar arg2, uchar arg3, uchar crc){
 uchar result;
 long int counter = 0;
 
 send_func(cmd);
 send_func(arg0);
 send_func(arg1);
 send_func(arg2);
 send_func(arg3);
 send_func(crc);
 
 do{
  result = (uchar) SPI_receive();
  counter++;
 } while((
 	(result & 0x80) != 0 &&
	counter < 0xFFFF
   	)
   );
 
 return result;

}

char SD_init(){
 for(char i = 0;i < 10;i++)
  send_func(0xFF);
 
 SS_PORT &= ~(1 << SS_PIN);
  
 if(SD_sendCMD(SD_CMD0,0,0,0,0, 0x51) != 0x01)
  return 1;
  
 send_func(0xFF);
  
 uchar result;
 long int counter = 0;
 
 do{
  result = SD_sendCMD(SD_CMD1,0,0,0,0, 0x51);
  counter++;
 } while(
 	(result != 0 &&
	counter < 0xFFFF
   	)
   );
 if(counter < 0xFFFF) return 2;
 return 0;
  
}

