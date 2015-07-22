/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <stdlib.h>

#define RIGHT 0
#define LEFT 1

int main()
{
  CyGlobalIntEnable;
  
  SigSelect_Start();
  DAC0_Start();
  DAC1_Start();
  DAC2_Start();
  DAC3_Start();
  OpampR_Start();
  OpampL_Start();
  UART_Start();
  
  uint8_t channel = 0;
  uint8_t channelMajor = 0;
  uint8_t channelMinor = 0;
  char *buffer;
  buffer = (char*) malloc (100);
  
  for(;;)
  {
    if (++channel == 8)
    {
      channel = 0;
    }
    lo_hi_Write(channelMinor);
    SigSelect_FastSelect(channelMajor);
    channelMinor = channel & 0x01;
    channelMajor = channel >> 1;
    sprintf(buffer, "Major: %d, minor: %d\r\n", channelMajor, channelMinor);
    UART_PutString((const char*)buffer);
    CyDelay(1500);
  }
}

/* [] END OF FILE */
