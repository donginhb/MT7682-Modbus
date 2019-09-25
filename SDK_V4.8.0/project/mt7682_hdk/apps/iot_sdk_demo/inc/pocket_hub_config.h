
/************************************************************************/
/*	  ��˹����Ƽ���չ���޹�˾			��Ȩ����		*/
/************************************************************************/
/*	 @@BEGAIN_INTERNAL_LEGAL@@											*/
/*																		*/
/*					 Copyright(C) Description							*/
/* Raisecom	 Science & Technology Development Co.,Ltd. Beijing,	China	*/
/*	   Unpublished work-rights reserved	under the China	Copyright Act.	*/
/*	   Use,duplication,	or disclosure by the government	is subject to	*/
/*	   restrictions	set	forth in the CDTT commercial license agreement.	*/
/*																		*/
/*	 @@END_INTERNAL_LEGAL@@												*/
/************************************************************************/
/*	 �����ļ����� pocket_hub_config.h								*/
/*	 Filename  �� pocket_hub_config.h								*/
/*	 ����	   �� 											*/
/*	 Author	   �� wangzaizhong										*/
/*	 ����	   �� 2019/08/08											*/
/*	 Date	   �� 2019/08/08											*/
/*	 �汾	   �� 1.0													*/
/*	 Version   �� 1.0													*/
/*	 ʵ��Ŀ��  �� pocket_hub��Ʒ�����ļ�					*/
/*	 Purpose   ��														*/
/*																		*/
/************************************************************************/


/*��Ʒ�ͺ�*/
#ifndef	_COMX_POCKET_HUB
#define	_COMX_POCKET_HUB

/********************************************************************************/
/*part1:************************��ϵ�ṹ����  ***********************************/
/********************************************************************************/
/*																							*/
/*																							*/
/*																							*/
/*********************************************************************************/


/*1Ϊ���滷����0Ϊ��ʵ����*/
#define OTP_RUN_SIMPC 		0

/*С��ģʽ*/
#define OTP_LITTLE_ENDIAN

/*����MCU����*/
#define  INCLUDE_MCU_STM32F10X

/*********************************************************************************/
/*part2:************************ƽ̨ģ�����  *******************************/
/*********************************************************************************/
/*	���Ը��ݾ����Ʒ��ƽ̨�ṩ��ģ����вü�ʹ��										  */	
/*																				*/
/*																				*/
/*********************************************************************************/
/*����DEV_MAINģ��*/
#define INCLUDE_DEV_MAIN

/*����IBCģ��*/
#define INCLUDE_IBC

/*����IBC_RC006Э�鴦��ģ��*/
#define INCLUDE_IBC_RC006

/*����SVCDEV_RC006 ģ��*/
#define INCLUDE_SVCDEV_RC006

/*����I2C����*/
#define	INCLUDE_I2C 

/*����SPI����*/
#define INCLUDE_SPI

/*�������ж�д����*/
#define	INCLUDE_MCU_RW

/*����AT24Cxxϵ������*/
#define	INCLUDE_AT24CXX

/*����FPGA����ģ��*/
#define INCLUDE_FPGALOAD

/*����OTP_TRACEģ��*/
#define INCLUDE_TRACE

/*����CLIģ��*/
#define INCLUDE_CLI

/*�˵�ʽconsole����*/
/*#define INCLUDE_CONSOLE_MENU*/

/*ϵͳָʾ��*/
#define INCLUD_SVC_SYSTEM_LED

/*�����ⲿFLASH��дģ��*/
#define INCLUDE_FLASH_COMM

/*����X_MODEMģ�� */
//#define INCLUDE_X_MODEM_COMM

/*����FPGAģ��*/
#define INCLUDE_FPGA

/*ʹ��X_MODEM����Զ���豸*/
/*#define INCLUDE_X_MODEM_REMOTE_IAP*/

/*����FILE_LOADERģ�� */
#define INCLUDE_FILE_LOADER_COMM

/*����CODECоƬģ��*/
#define INCLUDE_CODEC

/*����RA1015оƬģ��*/
#define INCLUDE_RA1015

/*����SE0111оƬģ��*/
#define INCLUDE_SE0111

/*������ȡ������Ϣģ��*/
#define INCLUDE_PRODUCT_INFO



#define  INCLUDE_UART1


#if ( OTP_RUN_SIMPC ) /* ���滷�� ROTP��ģ����� */

/*����CODECоƬ*/
/*#define INCLUDE_CODEC_DEBUG*/
#else

/*�������Ź�ģ��*/
#define INCLUDE_WATCHDOG

#endif

/*������Ʒ��Ϣͨ��Э��*/
/*#define INCLUDE_PRODUCT_MSG_COMM_PRTCL*/

/*������Ʒ��Ϣ�洢��ʽ*/
//#define INCLUDE_PRODUCT_MSG_FORMAT 

/*�����Ʒ��Ϣ����Э������ĸ�Э���д���1������RC006Э�鴮�ڣ�2������conselЭ�鴮��,3:����RC002Э�鴮��*/
//#define PRODUCT_MSG_COMM_PRTCL_TYPE       2

//#ifdef INCLUDE_PRODUCT_MSG_COMM_PRTCL

#if 0
#if	(PRODUCT_MSG_COMM_PRTCL_TYPE == 1)
#define INCLUDE_PRODUCT_MSG_COMM_PRTCL_RC006
#else
#if	(PRODUCT_MSG_COMM_PRTCL_TYPE == 2)
#define INCLUDE_PRODUCT_MSG_COMM_PRTCL_CONSEL
#else
#if	(PRODUCT_MSG_COMM_PRTCL_TYPE == 3)
#define INCLUDE_PRODUCT_MSG_COMM_PRTCL_RC002
#else
#error "PRODUCT_MSG_COMM_PRTCL_TYPE must be 1 , 2 or 3 !"
#endif
#endif
#endif
#endif
/*********************************************************************************/
/*part3:**************** ƽ̨ģ��ʹ�ò�������	**************************/
/*********************************************************************************/
/*	����ƽ̨ģ��ʹ�ò�������	���ô����岻����ɾ����	  */
/*																				*/
/*																				*/
/*********************************************************************************/

/****************************************/
/*��Ʒ����*/
#define DEVICE_NAME_ITN2100		"OPCOM3500E-Audio"
#define DEVICE_NAME_RP3000H		"RP3000H-Audio"
#define DEVICE_NAME_SLT8500		"SLT8500-Audio"

#define ITN2100_NAME			"OPCOM3500E"
#define RP3000H_NAME			"RP3000H"
#define SLT8500_NAME			"SLT"

/*�˿ڸ�������*/
#define	FXSO_PORT_NUM				16
#define MT_PORT_NUM                 4
#define AUDIO_PORT_NUM              20
/* ʶ��MTģ����λʹ�õ�оƬ��ͨ�� */
#define MT_USE_CODEC_CHIP_NUM       4
#define MT_USE_CODEC_CHANNLE_NUM    1
/* MTģ�������ⲿ����ʹ�õ�CODECоƬ */
#define MT_GAIN_ADJ_CODEC_CHIP_NUM  5

/*��Ʒ����汾*/
#define SOFTWARE_VERSION			0x11  /*wangzaizhong  201604027 ��������DEVICE_NAME_SLT8500*/

/*�豸���Ͷ���*/
#define SVC_LOCAL_DEVTYPE			0x1A4A
#define RETAIL_AUDIO_DEVTYPE        0x1A4D
#define SLT8500_AUDIO_DEVTYPE        0x1AC7

/****************************************/
/*ƽ̨��ʼ��֮ǰ���ȴ���ΧоƬ����ʱ�䣬��λms*/
#define SVC_START_DELAY				1000


/****************************************/
/*������ҵ��ĵ�����Ŀ*/
#define DEV_MAX_SERVICE_SLOT		13


/*���������uart0������ָ�����ڽ��պͷ��ͻ������ĳ���*/
#ifdef INCLUDE_UART1	/*IBCͨ��*/
/*uart0 ���ջ���ĳ���*/
#define UART1_RCV_BUFLEN		1024
/*uart0 ���ͻ���ĳ���*/
#define UART1_SEND_BUFLEN		1024
/*uart0 �����ò���*/
#define UART1_CFG_PARA			{19200, 8, 1, 0}/*����Ϊ19200bps������λ8���أ�1λֹͣλ����У��*/
#endif

#ifdef INCLUDE_UART2
/*uart0 ���ջ���ĳ���*/
#define UART2_RCV_BUFLEN		300
/*uart0 ���ͻ���ĳ���*/
#define UART2_SEND_BUFLEN		300
/*uart0 �����ò���*/
#define UART2_CFG_PARA			{19200, 8, 1, 0}/*����Ϊ9600bps������λ8���أ�1λֹͣλ����У��*/
#endif

/*���������uart3������ָ�����ڽ��պͷ��ͻ������ĳ���*/
#ifdef INCLUDE_UART3	/*���Կ�*/
/*uart3 ���ջ���ĳ���*/
#define UART3_RCV_BUFLEN		2000
#ifdef INCLUDE_CODEC_DEBUG
/*uart3 ���ͻ���ĳ���*/
#define UART3_SEND_BUFLEN		8192
#else
/*uart3 ���ͻ���ĳ���*/
#define UART3_SEND_BUFLEN		2000
#endif
/*uart3 �����ò���*/
#define UART3_CFG_PARA			{9600, 8, 1, 0}/*����Ϊ9600bps������λ8���أ�1λֹͣλ����У��*/
#endif

/****************************************/
/*��������˶�ʱ��ģ�飬��������Ķ�ʱ����Ŀ*/
#ifdef INCLUDE_TMR
#define TMR_MAX_TMR_NUM			20
#endif


/****************************************/
/*���������INCLUDE_IBC_RC006��
����ָ��RC006Э��IBCģ��ʹ�õĻ������ڸ���ҵ��ģ�����ݴ��*/
#ifdef INCLUDE_IBC_RC006
#define IBC_RC006_MSG_BUF_LEN	300
#endif


/****************************************/
/*���������TRACEģ�飬��������trace��buf��С*/
#ifdef INCLUDE_TRACE
#define TRACE_BUF_LEN_MAX		128
#endif


/*********************************************************************************/
/*part4:******************* ������IO�ܽŶ���	******************************/
/*********************************************************************************/
/*	���и���������IO���壻											  			*/
/*	���ܽŵľ��嶨�彫����ʵ�ʲ�Ʒ��������޸� ;			   					*/      
/*	���ڲ�Ʒû��Ӧ�õ���ģ��ܽţ�����ɾ����									*/
/*	�ڴ˴���Ӳ�Ʒ���й��ܵ�IO�ܽŶ��壻										*/
/*********************************************************************************/


/*ϵͳָʾ��*/
#ifdef	INCLUD_SVC_SYSTEM_LED


#endif


/******************************************/
/*CPU �������̵��ж����ŵ���ض���*/
#ifdef  INCLUDE_IBC_RC006
/*�ж�����*/

#endif


/*********************************************************************************/
/*part4:********************* ��Ʒ ģ�����	******************************/
/*********************************************************************************/
/*	���ڲ�Ʒ��ģ��ü���	���û����п��Ʋü���											  */
/*																				*/
/*																				*/
/*********************************************************************************/


#if ( OTP_RUN_SIMPC ) /* ���滷�� ��Ʒ��ģ�����  */
/*����SVC_devģ��*/
#define INCLUDE_SVC_DEV

/*����SVC_SYSTEMģ��*/
#define INCLUDE_SVC_SYSTEM

/*��RC006ģ����ʹ���ļ�����*/
#define  INCLUDE_SVCDEV_RC006_FILE_DOWNLOAD
#define  INCLUDE_RESET
#else

/*����SVC_devģ��*/
#define INCLUDE_SVC_DEV
/*����SVC_SYSTEMģ��*/
#define INCLUDE_SVC_SYSTEM

/*��RC006ģ����ʹ���ļ�����*/
#define INCLUDE_SVCDEV_RC006_FILE_DOWNLOAD
#define INCLUDE_RESET
#endif

#endif


