
#include "sd.h"


typedef unsigned char uchar;



uchar SD_sendCMD(uchar cmd, uchar arg0, uchar arg1, uchar arg2, uchar arg3, uchar crc){
 uchar result;
 long int counter = 0;
 
 SPI_send(cmd);
 SPI_send(arg0);
 SPI_send(arg1);
 SPI_send(arg2);
 SPI_send(arg3);
 SPI_send(crc);
 
 do{
  result = (uchar) SPI_receive();
  counter++;
 } while((
 	(result & 0x80) != 0 &&
	counter < 0xFFFF
   	)
   );
 
 return !!result;

}

char SD_init(){
 for(char i = 0;i < 10;i++)
  SPI_send(0xFF);
 
 SS_PORT &= ~(1 << SS_PIN);
  
 if(SD_sendCMD(SD_CMD0,0,0,0,0, 0x51) != 0x01)
  return 1;
  
 SPI_send(0xFF);
  
 uchar result;
 long int counter = 0;
 
 do{
  result = SD_sendCMD(SD_CMD1,0,0,0,0, 0x51);
  counter++;
 } while((
 	(result != 0 &&
	counter < 0xFFFF
   	)
   );
 if(counter < 0xFFFF) return 2;
 return 0;
  
}

