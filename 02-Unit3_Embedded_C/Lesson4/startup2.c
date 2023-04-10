/* learn-in-depth
	startup.c cortex M4
	Eng.Mohamed Ahmed Salama
*/
#include <stdint.h>

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

//booking 1024 B located by .bss through uninitalized array of int 256 Element (256*4 = 1024) "bss size"
static uint32_t Stack_Top[256];


void (*const g_p_fn_vectors[])()__attribute__((section(".vectors"))) =
{
	(void(*)()) ((unsigned long)Stack_Top + sizeof(Stack_Top)),
	&Rest_Handler,
	&NMI_Fault_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault_Handler,
	&Usage_Fault_Handler
	
};

extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
extern unsigned int _stack_top;
/*uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Rest_Handler,
	(uint32_t) &NMI_Fault_Handler,
	(uint32_t) &H_Fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault_Handler,
	(uint32_t) &Usage_Fault_Handler
};*/



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

