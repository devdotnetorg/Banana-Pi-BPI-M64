#include <stdio.h>
#include <stdlib.h>
#define GPIO_PATH "/sys/class/gpio"
#define GPIO_PIN_PATH "/sys/class/gpio/gpio39"
unsigned long c=0;
unsigned long i=0;
int main()
{
	FILE *fp;
	fp=fopen(GPIO_PATH"/export","w");
	fprintf(fp,"39");
	fclose(fp);
	fp=fopen(GPIO_PIN_PATH"/direction","w");
	fprintf(fp,"out");
 	fclose(fp);
	//***for LED DFRobot.com
	fp=fopen(GPIO_PIN_PATH"/active_low","w");
	fprintf(fp,"1");
	fclose(fp);
	//***
	fp=fopen(GPIO_PIN_PATH"/value","w");
	fprintf(fp,"0");
	fclose(fp);	
	printf("Набери количество циклов\n");
	scanf("%d",&c);
	for (i=c;i>0;i--)
	{
		fp=fopen(GPIO_PIN_PATH"/value","w");
		fprintf(fp,"1");
		fclose(fp);
		usleep(500000);
		fp=fopen(GPIO_PIN_PATH"/value","w");
		fprintf(fp,"0");
		fclose(fp);
		usleep(500000);
	}
	fp=fopen(GPIO_PIN_PATH"/direction","w");
	fprintf(fp,"in");
 	fclose(fp);
	fp=fopen(GPIO_PATH"/unexport","w");
	fprintf(fp,"39");
	fclose(fp);
	printf("PROFIT!\n");
return EXIT_SUCCESS;
}