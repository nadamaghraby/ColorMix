#include<stdint.h>
// GPIOB address
#define GPIOB_BASE  (uint32_t)0x40020400
//Get Moder register Address
#define MODER_OFFSET (uint32_t)0x00
#define MODER_ADD (*((uint32_t*)(GPIOB_BASE+MODER_OFFSET)))
//Get Output type register address
#define OYTPUTTYPE_OFFSET (uint32_t)0x04
#define OYTPUTTYPE_ADD (*((uint32_t*)(GPIOB_BASE+OYTPUTTYPE_OFFSET)))
//Get input type register
#define INPUTTYPE_OFFSET (uint32_t)0x0C
#define INPUTTYPE_ADD (*((uint32_t*)(GPIOB_BASE+INPUTTYPE_OFFSET)))
//Get Output data register  address
#define OUTDATA_OFFSET (uint32_t)0x14
#define OUTDATA_ADD (*((uint32_t*)(GPIOB_BASE+OUTDATA_OFFSET)))
//Get input data register address
#define INDATA_OFFSET (uint32_t)0x10
#define INDATA_ADD (*((uint32_t*)(GPIOB_BASE+INDATA_OFFSET)))
//Rcc Base Address
#define	RCC_BASE 0x40023800
// Get AHB1EN Register address
#define AHB1ENR_OFFSET 0x30
#define AHB1ENR_ADD (*((uint32_t*)(RCC_BASE+AHB1ENR_OFFSET)))

int main(void)
{
	//Enable clock to GBIOB
	AHB1ENR_ADD |=(1<<1);
	// Set Mode to output  of pins GPIOB
	//MODER3: Moder ely mot7kem fl pin rkm 4 hwa bit rkm 6 w 7 w dol input type
	//MODER5 , MODER6 , MODER7
	//MODER3 : INPUT TYPE
	MODER_ADD &=~(1<<6);
	MODER_ADD &=~(1<<7);
	//MODER5:
	MODER_ADD |=(1<<10);
	MODER_ADD &=~(1<<11);
	//MODER6:
	MODER_ADD |=(1<<12);
	MODER_ADD &=~(1<<13);
	//MODER5:
	MODER_ADD |=(1<<14);
	MODER_ADD &=~(1<<15);
	//Set output Mode to (push-pull mode)  of pin 4 GPIOA
	//pin 5,6,7 GPIOB
	OYTPUTTYPE_ADD &=~(1<<5);
	OYTPUTTYPE_ADD &=~(1<<6);
	OYTPUTTYPE_ADD &=~(1<<7);

	//Input type active low (pull up) => 01 , 6->1 , 7->0
	INPUTTYPE_ADD |=(1<<6);
	INPUTTYPE_ADD &=~(1<<7);
	//set outdata
	OUTDATA_ADD&=~(1<<5);
	OUTDATA_ADD&=~(1<<6);
	OUTDATA_ADD&=~(1<<7);
	// super loop
	while(1)
	{
		if((INDATA_ADD &(1<<3)) == 0){
			if(!(OUTDATA_ADD&(1<<5)) && !(OUTDATA_ADD&(1<<6)) && !(OUTDATA_ADD&(1<<7))){
				OUTDATA_ADD&=~(1<<5);
				OUTDATA_ADD&=~(1<<6);
				OUTDATA_ADD|=(1<<7);
				for(int i =0 ; i<500000;i++){}
			}
			else if(!(OUTDATA_ADD&(1<<5)) && !(OUTDATA_ADD&(1<<6)) && (OUTDATA_ADD&(1<<7))){
				OUTDATA_ADD&=~(1<<5);
				OUTDATA_ADD|=(1<<6);
				OUTDATA_ADD&=~(1<<7);
				for(int i =0 ; i<500000;i++){}
			}
			else if(!(OUTDATA_ADD&(1<<5)) && (OUTDATA_ADD&(1<<6)) && !(OUTDATA_ADD&(1<<7))){
				OUTDATA_ADD&=~(1<<5);
				OUTDATA_ADD|=(1<<6);
				OUTDATA_ADD|=(1<<7);
				for(int i =0 ; i<500000;i++){}
			}
			else if(!(OUTDATA_ADD&(1<<5)) && (OUTDATA_ADD&(1<<6)) && (OUTDATA_ADD&(1<<7))){
				OUTDATA_ADD|=(1<<5);
				OUTDATA_ADD&=~(1<<6);
				OUTDATA_ADD&=~(1<<7);
				for(int i =0 ; i<500000;i++){}
			}
			else if((OUTDATA_ADD&(1<<5)) && !(OUTDATA_ADD&(1<<6)) && !(OUTDATA_ADD&(1<<7))){
				OUTDATA_ADD|=(1<<5);
				OUTDATA_ADD&=~(1<<6);
				OUTDATA_ADD|=(1<<7);
				for(int i =0 ; i<500000;i++){}
			}
			else if((OUTDATA_ADD&(1<<5)) && !(OUTDATA_ADD&(1<<6)) && (OUTDATA_ADD&(1<<7))){
				OUTDATA_ADD|=(1<<5);
				OUTDATA_ADD|=(1<<6);
				OUTDATA_ADD&=~(1<<7);
				for(int i =0 ; i<500000;i++){}
			}
			else if((OUTDATA_ADD&(1<<5)) && (OUTDATA_ADD&(1<<6)) && !(OUTDATA_ADD&(1<<7))){
				OUTDATA_ADD|=(1<<5);
				OUTDATA_ADD|=(1<<6);
				OUTDATA_ADD|=(1<<7);
				for(int i =0 ; i<500000;i++){}
			}
			else if((OUTDATA_ADD&(1<<5)) && (OUTDATA_ADD&(1<<6)) && (OUTDATA_ADD&(1<<7))){
				OUTDATA_ADD&=~(1<<5);
				OUTDATA_ADD&=~(1<<6);
				OUTDATA_ADD&=~(1<<7);
				for(int i =0 ; i<500000;i++){}
			}
		}

		else {

		}
		for(int i =0 ; i<50000;i++){}

	}
}
