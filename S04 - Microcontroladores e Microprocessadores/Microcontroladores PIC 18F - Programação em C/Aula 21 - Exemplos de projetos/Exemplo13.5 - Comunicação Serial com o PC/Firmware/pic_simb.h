//***************************************************************
// Arquivo de símbolos utilizados no livro PIC18 Detalhado
// Autor: Fábio Pereira
//***************************************************************

#define BIT7		0x80
#define BIT6		0x40
#define BIT5		0x20
#define BIT4		0x10
#define BIT3		0x08
#define BIT2		0x04
#define BIT1		0x02
#define BIT0		0x01

// INTCON

#define bGIE		BIT7
#define bGIEH		BIT7
#define bPEIE		BIT6
#define bGIEL		BIT6
#define bTMR0IE		BIT5
#define bINT0IE		BIT4
#define bRBIE		BIT3
#define bTMR0IF		BIT2
#define bINT0IF		BIT1
#define bRBIF		BIT0

#define bNRBPU		BIT7
#define bINTEDG0	BIT6
#define	bINTEDG1	BIT5
#define bINTEDG2	BIT4
#define bTMR0IP		BIT2
#define bRBIO		BIT0

#define bINT2IP		BIT7
#define bINT1IP		BIT6
#define bINT2IE		BIT4
#define bINT1IE		BIT3
#define bINT2IF		BIT1
#define bINT1IF		BIT0

#define bPSPIF		BIT7
#define bADIF		BIT6
#define bRCIF		BIT5
#define bTXIF		BIT4
#define bSSPIF		BIT3
#define bCCP1IF		BIT2
#define bTMR2IF		BIT1
#define bTMR1IF		BIT0

#define bOSCFIF		BIT7
#define bCMIF		BIT6
#define bEEIF		BIT4
#define bBCLIF		BIT3
#define bLVDIF		BIT2
#define bTMR3IF		BIT1
#define bCCP2IF		BIT0

#define bPSPIE		BIT7
#define bADIE		BIT6
#define bRCIE		BIT5
#define bTXIE		BIT4
#define bSSPIE		BIT3
#define bCCP1IE		BIT2
#define bTMR2IE		BIT1
#define bTMR1IE		BIT0

#define bOSCFIE		BIT7
#define bCMIE		BIT6
#define bEEIE		BIT4
#define bBCLIE		BIT3
#define bLVDIE		BIT2
#define bTMR3IE		BIT1
#define bCCP2IE		BIT0

#define bPSPIP		BIT7
#define bADIP		BIT6
#define bRCIP		BIT5
#define bTXIP		BIT4
#define bSSPIP		BIT3
#define bCCP1IP		BIT2
#define bTMR2IP		BIT1
#define bTMR1IP		BIT0

#define bOSCFIP		BIT7
#define bCMIP		BIT6
#define bEEIP		BIT4
#define bBCLIP		BIT3
#define bLVDIP		BIT2
#define bTMR3IP		BIT1
#define bCCP2IP		BIT0

// RCON ********************

#define bIPEN		BIT7
#define bSBOREN		BIT6
#define bNRI		BIT4
#define bNTO		BIT3
#define bNPD		BIT2
#define bNPOR		BIT1
#define bNBOR		BIT0

// WDTCON

#define bSWDTEN		BIT0

// HLVDCON

#define VDIRMAQ		BIT7
#define bIRVST		BIT5
#define bHLVDEN		BIT4
#define bHLVD2V17	0
#define bHLVD2V23	1
#define bHLVD2V36	2
#define bHLVD2V44	3
#define bHLVD2V60	4
#define bHLVD2V79	5
#define bHLVD2V89	6
#define bHLVD3V12	7
#define bHLVD3V39	8
#define bHLVD3V55	9
#define bHLVD3V71	10
#define bHLVD3V90	11
#define bHLVD4V11	12
#define bHLVD4V33	13
#define bHLVD4V59	14
#define bHLVD_EXT	15

// OSCCON **************

#define bIDLEN			BIT7
#define bCLKINT_31k		0
#define bCLKINT_125k	BIT4
#define bCLKINT_250k	BIT5
#define bCLKINT_500k	(BIT5 | BIT4)
#define bCLKINT_1M		BIT6
#define bCLKINT_2M		(BIT6 | BIT4)
#define bCLKINT_4M		(BIT6 | BIT5)
#define bCLKINT_8M		(BIT6 | BIT5 | BIT4)
#define bOSTS			BIT3
#define bIOFS			BIT2
#define bOSC_PRI		0
#define bOSC_SEC		1
#define bOSC_INT		3

// OSCTUNE *************
#define bINTSRC		BIT7
#define bPLLEN		BIT6

// T0CON ***************
#define bTMR0ON			BIT7
#define bT08BIT			BIT6
#define bT0CS			BIT5
#define bT0SE			BIT4
#define bPSA			BIT3
#define bT0CLK_PRE2	0
#define bT0CLK_PRE4	1
#define bT0CLK_PRE8	2
#define bT0CLK_PRE16	3
#define bT0CLK_PRE32	4
#define bT0CLK_PRE64	5
#define bT0CLK_PRE128	6
#define bT0CLK_PRE256	7

// T1CON ***************
#define bRD16			BIT7
#define bT1RUN			BIT6
#define bT1CLK_PRE1		0
#define bT1CLK_PRE2		BIT4
#define bT1CLK_PRE4		BIT5
#define bT1CLK_PRE8		(BIT5 | BIT4)
#define bT1OSCEN		BIT3
#define bT1SYNC			BIT2
#define bT1CLK_EXT		BIT1
#define bTMR1ON			BIT0

// T2CON ***************
#define bT2OUTPS_1		0
#define bT2OUTPS_2		1<<3
#define bT2OUTPS_3		2<<3
#define bT2OUTPS_4		3<<3
#define bT2OUTPS_5		4<<3
#define bT2OUTPS_6		5<<3
#define bT2OUTPS_7		6<<3
#define bT2OUTPS_8		7<<3
#define bT2OUTPS_9		8<<3
#define bT2OUTPS_10		9<<3
#define bT2OUTPS_11		10<<3
#define bT2OUTPS_12		11<<3
#define bT2OUTPS_13		12<<3
#define bT2OUTPS_14		13<<3
#define bT2OUTPS_15		14<<3
#define bT2OUTPS_16		15<<3
#define bTMR2ON			BIT2
#define bT2CLK_PRE1		0
#define bT2CLK_PRE2		1
#define bT2CLK_PRE4		2
#define bT2CLK_PRE8		3

// T3CON ***************
#define bT3CLK_PRE1		0
#define bT3CLK_PRE2		BIT4
#define bT3CLK_PRE4		BIT5
#define bT3CLK_PRE8		(BIT5 | BIT4)
#define bT1CCP12		0
#define bT1CCP1_T3CCP2		BIT3
#define bT3CCP12		(BIT3 | BIT6)
#define bT3SYNC			BIT2
#define bT3CLK_EXT		BIT1
#define bTMR3ON			BIT0

// CCP1CON *********************
// CCP2CON *********************
#define bECCP_PWM_SINGLE	0
#define bECCP_PWM_FULL_FWD	BIT6
#define bECCP_PWM_HALF		BIT7
#define bECCP_PWM_FULL_REV	(BIT7 | BIT6)
#define bCCP_OFF		0
#define bCCP_COMPARE_TOGGLE	2
#define bCCP_CAPTURE_FALLING	4
#define bCCP_CAPTURE_RISING	5
#define bCCP_CAPTURE_4RISING	6
#define bCCP_CAPTURE_16RISING	7
#define bCCP_COMPARE_SET	8
#define bCCP_COMPARE_RESET	9
#define bCCP_COMPARE_INT	10
#define bCCP_COMPARE_SPECIAL	11
#define bCCP_PWM		12
#define bECCP_PWM_ABCD_HIGH	12
#define bECCP_PWM_AC_HIGH	13
#define bECCP_PWM_BD_HIGH	14
#define bECCP_PWM_LOW		15

// PWM1CON *********************
#define bPRSEN			BIT7

// ECCPAS **********************
#define bECCPASE		BIT7
#define bAS_OFF			0
#define bAS_CMP1		1<<4
#define bAS_CMP2		2<<4
#define bAS_CMP			3<<4
#define bAS_INT0		4<<4
#define bAS_INT0CMP1	5<<4
#define bAS_INT0CMP2	6<<4
#define bAS_INT0CMP		7<<4
#define bAS_AC_LOW		0
#define bAS_AC_HIGH		BIT2
#define bAS_AC_HIGHZ	3<<2
#define bAS_BD_LOW		0
#define bAS_BD_HIGH		1
#define bAS_BD_HIGHZ	3

// CVRCON *********************
#define bCVREN			BIT7
#define bCVROE			BIT6
#define bCVRR			BIT5
#define bCVRSS			BIT4

// CMCON **********************
#define bC2OUT			BIT7
#define bC1OUT			BIT6
#define bC2INV			BIT5
#define bC1INV			BIT4
#define bCIS			BIT3

// ADCON0 *********************
#define bADC_CH0		0<<2
#define bADC_CH1		1<<2
#define bADC_CH2		2<<2
#define bADC_CH3		3<<2
#define bADC_CH4		4<<2
#define bADC_CH5		5<<2
#define bADC_CH6		6<<2
#define bADC_CH7		7<<2
#define bADC_CH8		8<<2
#define bADC_CH9		9<<2
#define bADC_CH10		10<<2
#define bADC_CH11		11<<2
#define bADC_CH12		12<<2
#define bADC_GO			BIT1
#define bADC_ON			BIT0

// ADCON1 *********************
#define bADC_EXT_NREF	BIT5
#define bADC_EXT_PREF	BIT4

//ADCON2 **********************
#define bADFM			BIT7
#define bADC_ACQ0		0<<3
#define bADC_ACQ2		1<<3
#define bADC_ACQ4		2<<3
#define bADC_ACQ6		3<<3
#define bADC_ACQ8		4<<3
#define bADC_ACQ12		5<<3
#define bADC_ACQ16		6<<3
#define bADC_ACQ20		7<<3
#define bADC_CLK_DIV2	0
#define bADC_CLK_DIV8	1
#define bADC_CLK_DIV32	2
#define bADC_CLK_RC		3
#define bADC_CLK_DIV4	4
#define bADC_CLK_DIV16	5
#define bADC_CLK_DIV64	6 

// EECON1
#define bEEPGD			BIT7
#define bCFGS			BIT6
#define bFREE			BIT4
#define bWRERR			BIT3
#define bWREN			BIT2
#define bWR				BIT1
#define bRD				BIT0

// TXSTA
#define	bCSRC			BIT7
#define bTX9			BIT6
#define bTXEN			BIT5
#define bSYNC			BIT4
#define bSENDB			BIT3
#define bBRGH			BIT2
#define bTRMT			BIT1
#define bTX9D			BIT0

// RCSTA
#define bSPEN			BIT7
#define bRX9			BIT6
#define bSREN			BIT5
#define bCREN			BIT4
#define bADDEN			BIT3
#define bFERR			BIT2
#define bOERR			BIT1
#define bRX9D			BIT0

// BAUDCON
#define bABDOVF			BIT7
#define bRCIDL			BIT6
#define bRXDTP			BIT5
#define bTXCKP			BIT4
#define bBRG16			BIT3
#define bWUE				BIT1
#define bABDEN			BIT0

// SSPSTAT
#define bSMP				BIT7
#define bCKE				BIT6
#define bDATA				BIT5
#define bSTOP				BIT4
#define bSTART			BIT3
#define bRW					BIT2
#define bUA					BIT1
#define bBF					BIT0

//SSPCON1
#define bWCOL				BIT7
#define bSSPOV			BIT6
#define bSSPEN			BIT5
#define bCKP				BIT4
#define bSPI_MST_4			0
#define bSPI_MST_16			1
#define bSPI_MST_64			2
#define bSPI_MST_TMR2		3
#define bSPI_SLAVE_SS		4
#define bSPI_SLAVE			5
#define bI2C_SLV_ADD7		6
#define bI2C_SLV_ADD10	7
#define bI2C_MST_1			8
#define bI2C_MST_2			11
#define bI2C_SLV_ADD7I	14
#define bI2C_SLV_ADD10I	15