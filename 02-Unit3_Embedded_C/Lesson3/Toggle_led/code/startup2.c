/* learn-in-depth
	startup cortex M3
	Eng.Mohamed Ahmed Salama
*/
#include <stdint.h>
#define STACK_START_SP	0x20001000
extern int main(void);

void Rest_Handler(void);

void Default_Handler()
{
	Rest_Handler();
}
void H_Fault_Handler(void) __attribute__((weak,alias("Default_Handler")));;
void MM_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void NMI_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void Bus_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;

extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
extern unsigned int _stack_top;
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Rest_Handler,
	(uint32_t) &NMI_Fault_Handler,
	(uint32_t) &H_Fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault_Handler,
	(uint32_t) &Usage_Fault_Handler
};



void Rest_Handler(void){
	// copy data from ROM to RAM
	unsigned int Data_Size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* P_src = (unsigned char*)& _E_text;
	unsigned char* P_dst = (unsigned char*)& _S_data;
	int i;
	for(i = 0 ; i < Data_Size ; i++){
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	// init .bss with zero in RAM
	unsigned int BSS_Size  = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for( i = 0 ; i < BSS_Size ; i++){
		*((unsigned char*)P_dst++) = 0 ;
	}
	main();
}

