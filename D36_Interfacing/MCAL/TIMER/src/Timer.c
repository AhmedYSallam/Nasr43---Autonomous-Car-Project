

#include "Timer.h"
#include "Timer_HW.h"
static ConfigurStruct InitStruct;
/******************************************************/
/******************************************************/
void Timer_Init(ConfigurStruct* ptr){
	InitStruct.Mode = ptr->Mode;
	InitStruct.Psc = ptr->Psc;
	InitStruct.Rmode = ptr->Rmode;
	InitStruct.OCR0_Val = ptr->OCR0_Val;
	InitStruct.CTCMode = ptr->CTCMode;
	switch(InitStruct.Mode){
		case Normal:
		// Clearing TCCR0 for Normal mode
			ClearBit(TCCR0_REG,WGM00_BIT);
			ClearBit(TCCR0_REG,WGM01_BIT);
		// Setting the Interrupt Enable Bit
			if(InitStruct.Rmode == Interrupt){
				SetBit(TIMSK_REG,TOIE0_BIT);
			}else if(InitStruct.Rmode == Polling){
				ClearBit(TIMSK_REG,TOIE0_BIT);	
			}
		break;
		case CTC:
		// Enabling the WGM01 CTC Bit
			ClearBit(TCCR0_REG,WGM00_BIT);
			SetBit(TCCR0_REG,WGM01_BIT);
		//  Interrupt or polling
			if(InitStruct.Rmode == Interrupt){
				SetBit(TIMSK_REG,OCIE0_BIT);
			}else if(InitStruct.Rmode == Polling){
				ClearBit(TIMSK_REG,OCIE0_BIT);
			}
			TCCR0_REG &= 0xCF;
			TCCR0_REG |= (InitStruct.CTCMode<<4);

		break;
	}
}

void Timer_Start(void){
	TCCR0_REG &= 0xF8;
	TCCR0_REG |= (InitStruct.Psc);
}
void Timer_Stop(void){
	// Cutting the Source Clock
	ClearBit(TCCR0_REG,CS02_BIT) ;
	ClearBit(TCCR0_REG,CS01_BIT) ;
	ClearBit(TCCR0_REG,CS00_BIT) ;
	
}