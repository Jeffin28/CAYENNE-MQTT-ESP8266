#ifndef __CMQTT_H
#define __CMQTT_H

#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial

struct Channel
{
  unsigned char ch1;
  unsigned char ch2;
  unsigned char ch3;
  unsigned char reserve_bytes[5];
};
struct Device
{
  unsigned int device1;
  unsigned int device2;
  unsigned int device3;
  unsigned int reserve_bytes[2];
};
extern Channel Channl;
extern Device  dev;

extern void setup_Cayenne(void);
extern void Cayenne_loop(void);
 
#endif
