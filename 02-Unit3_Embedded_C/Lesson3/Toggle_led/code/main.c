// learn-in-depth
// Mohamed Ahmed Salama



/* register addres */
#define RCC_BASE	0X40021000
#define GPIOA_BASE	0X40010800
#define RCC_APB2ENR	*(volatile int *)(RCC_BASE + 0X18)
#define GPIOA_CRH	*(volatile int *)(GPIOA_BASE + 0X04)
#define GPIOA_ODR	*(volatile int *)(GPIOA_BASE + 0X0C)
/* bit fields */
#define RCC_IOPAEN	(1<<2)
#define GPIOA13		(1UL<<13)
extern void NMI_Fault_Handler(void){

}
extern void Bus_Fault_Handler(void){
	
}
typedef union{
	 volatile intall_fields;
	struct{
		volatile int reserved:13;
		volatile int P_13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE+0X0C);
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] ={4,5,6};
int main(void){
	int i;
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH &= 0XFF0FFFFF;
	GPIOA_CRH |= 0X00200000;
	while(1){
		R_ODR->pin.P_13 = 1;
		for( i = 0 ; i < 50000 ; i++); //  arbitrary delay
		R_ODR->pin.P_13 = 0;
		for( i = 0 ; i < 50000 ; i++); //  arbitrary delay
	}
}


