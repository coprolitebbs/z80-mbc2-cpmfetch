/*  #include <stdint.h>  */
#include <cpm.h>

unsigned char tpp;

unsigned char cpuid(void);

char os_bts[11]={0x00,0x20,0x21,0x22,0x25,0x28,0x30,0x31,0x33,0x41,0x50};
char os_names[12][22]={
	"1",
	"2.0",
	"2.1",
	"2.2",
	"2.5 (DOS +)",
	"2.8 (Personal CP/M-80)",
	"3.0 (MP/M II, MP/M-86)",
	"3.1 (CP/M Plus)",
	"3.3 (Apricot PCP/M-86)",
	"4.1 (DOSPLUS 1)",
	"5.0 (DOSPLUS 2)",
	"Unknown"
};

char cpu_bts[3]={0,1,2};
/*char cpu_names[4][12]={
	"Z-80 / 8080",
	"8086",
	"68000/Z8000",
	"Unknown"
};*/

char cpu_names[3][12]={
	"Unknown",
	"8080",
	"Z80"
};


char os_flags[3][6]={
	"MP/M",
	"CP/Net",
	"16-bit"
};

char logo[15][41]={
	"               @@@@@ @@@@@              ",
	"           @@@@@@       @@@@@@          ",
	"         @@@@      @@@      @@@@        ",
	"        @@@@      @@@@@      @@@@       ",
	"        @@@     @@@@ @@@@     @@@       ",
	"        @@@   @@@@    @@@@@   @@@       ",
	"        @@@@@@@    @@@    @@@@@@@       ",
	"         @@       @@@@@       @@        ",
	"                 @@@ @@@                ",
	"                @@@@-@@@@               ",
	"                                        ",
	"                 unknown                ",
	"                  8080                  ",
	"                  Z-80                  ",
/*	"               Z-80 / 8080              ",
	"                  8086                  ",
	"                 unknown                ",*/
	"                                        "
};

int tm_g_rchar();

int tm_g_rchar ()
{
  return bdos(11,0x0B);/*bios (3, 0, 0);*/
}


unsigned char cpuid(void){
#asm
	LD A, 128
	OUT (254), A
	IN A, (255)
    CP 128
    JP NZ, check_z80
	LD A, 1
    JP end_check
	
check_z80:
    LD A, 128
    OUT (253), A
    IN A, (253)
    AND 128
    JR NZ, end_check
	
	LD A, 2	
end_check:
	LD (_tpp),A
#endasm
	
  return tpp;
}
