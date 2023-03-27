#include <stdio.h>
#include <string.h>
#include <cpm.h>
#include "cpmfetch.h"

int main(int argc, char *argv[]){
	unsigned char hib,lob,osver,cpu, nbl;	
	short bdosr = bdoshl(CPMVERS,0x0C);
	int i,j;
	
	/* OS type & ver & cpuid */
	
	lob = bdosr & 0xFF;
	hib = (bdosr >> 8) & 0xFF;
	
	osver=11;
	for(i=0;i<11;i++){
		if(os_bts[i] == lob) { 
			osver = i;
		}
	}
	
	/*cpu = 3;
	nbl = hib >> 4;
	for(i=0;i<3;i++){
		if(cpu_bts[i] == nbl) { 
			cpu = i;
		}
	}*/
	cpu = cpuid();
	
	printf("%s CPU: %s\n",logo[0],cpu_names[cpu]);
	printf("%s OS: %s\n",logo[1],os_names[osver]);
	printf("%s Flags: ",logo[2]);	
	
	for(i=0;i<3;i++){
		if( ((1 << (unsigned char)i) & hib) > 0){
			printf("%s ",os_flags[i]);
		}
	}
	printf("\n");	


	printf("%s RAM: %d kb\n",logo[3],128);
	printf("%s Resolution: 80x24 text mode\n",logo[4]);
	printf("%s Hardware: Z80-MBC2\n",logo[5]);
	printf("%s BDOS 0x12 flags: %xh\n",logo[6],bdosr);

	
	for(i=7;i<11;i++){
		printf("%s\n",logo[i]);
	}
	i = cpu + 11;
	printf("%s\n",logo[i]);
	printf("%s\n",logo[14]);
	
	for(i=0;i<10000000;i++){
		j = tm_g_rchar();
		printf("%d\n",j);
		if(j>31) {
			
		}
		if(j == 27) exit(0);
	} 
	
}
