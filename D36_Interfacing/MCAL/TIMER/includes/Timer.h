

#ifndef TIMER_H_
#define TIMER_H_
#include "STD_Types.h"
typedef enum{
	Normal,	
	CTC
}Timer0Mode;

typedef enum{
	Polling,
	Interrupt
}RMode;

typedef enum{
	NoCLK,
	NoPsc,
	PSC_8,
	PSC_64,
	PSC_256,
	PSC_1024	
}TimerPSC;

typedef enum{
	NoOC,
	Toggle,
	Clear,
	Set
}OCMode;

typedef struct{
	Timer0Mode Mode;
	RMode Rmode;
	TimerPSC Psc;
	OCMode CTCMode;
	Uint8 OCR0_Val;
}ConfigurStruct;

void Timer_Init(ConfigurStruct* ptr);
void Timer_Start(void);
void Timer_Stop(void);



#endif /* TIMER_H_ */