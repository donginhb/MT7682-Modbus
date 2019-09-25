/************************************************************************/
/*	  ��˹����Ƽ���չ���޹�˾			��Ȩ����						*/
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
/*	 �����ļ�����Svc_dev.c												*/
/*	 Filename  ��Svc_dev.c												*/
/*	 ����	   �����													*/
/*	 Author	   ��lijingfang												*/
/*	 ����	   ��2018-12-26												*/
/*	 Date	   ��2018-12-26												*/
/*	 �汾	   ��1.0													*/
/*	 Version   ��1.0													*/
/*	 ʵ��Ŀ��  ��ҵ������ȫ�����ܺ���                    				*/
/*	 Purpose   ��														*/
/*																		*/
/************************************************************************/


/************************************************************************/
/*   �ļ��޸ļ�¼:												 		*/
/*   [���, MM/DD/YYYY, �汾, �޸���, �޸�����]							*/
/*																		*/
/*	  															 		*/
/*																 		*/
/*   Modified History:													*/
/*	 [Index, MM/DD/YYYY, Version, Author, Content]						*/
/************************************************************************/


//#ifdef	INCLUDE_SVC_DEV

#if 0
#include <string.h>
#include "macro_common.h"
#include "Trace.h"
#include "toolkit.h"
#include "uart.h"
#include "uart0.h"
#include "console.h"
#include "ibc.h"
#include "ibc_rc002.h"
#include "bcm53115_drv.h"
#include "bcm53115_gphy_mii.h"
#include "xrt83vsh38.h"
#include "ra1027.h"
#include "tmr1.h"
#include "sfp.h"
#include "faultpass.h"
#include "svc_system.h"
#include "svc_dev.h"
#include "svc_rdev_ibc.h"
#include "flash.h"
#include "x_modem.h"
#include "fileloader.h"
#include "iap.h"
#include "spi.h"

#include "type_common.h"
#include "hal_gpio.h"
#include "flash.h"
#include "spi.h"
#endif

#include <string.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/* Hal includes. */
#include "hal.h"
#include "hal_dcxo.h"

#include "nvdm.h"
#include "syslog.h"
#include "io_def.h"
#include "bsp_gpio_ept_config.h"

#include "memory_map.h"
#include "memory_attribute.h"
#include "sys_init.h"

#include "type_common.h"

#include "hal_gpio.h"
#include "flash.h"
#include "spi.h"

#include "g113i_uart1.h"
#include "g113i_svc_dev.h"

/*lint -save -e534 -e641*/



/*************************************************************************/
/**UART1 ��DMA�н�����Ϣ*/
QueueHandle_t g_uart1_read_msgQ_id = NULL;
#define	UART1_RECEIVE_MSG_MAX 	20      /*UART1 ��DMA�н�����Ϣ��������*/
/*************************************************************************/
/**UART1 ���յ�ҵ��������Ϣ*/
QueueHandle_t g_svc_read_data_msgQ_id = NULL;
#define	SVC_RECEIVE_DATA_MSG_MAX 	20      /*UART1 ��DMA�н�����Ϣ��������*/
/*************************************************************************/
/**UART1 ���յ�ҵ�������Ϣ*/
QueueHandle_t g_svc_read_manage_msgQ_id = NULL;
#define	SVC_RECEIVE_MANAGE_MSG_MAX 	20    /*UART1 ��DMA�н�����Ϣ��������*/
/*************************************************************************/



#if 1
/* FLASH��дʹ�ܽ�ֹ���� */    
STATUS flash_enable(e_flash_cs_ena	cs_ena);

/*spi ����һ���ֽ�*/
STATUS flash_spi_send_byte_msb(OTP_UINT8 data);

/*spi����һ���ֽ�*/
OTP_UINT8 flash_spi_rcv_byte_msb(void);

const falsh_m25p16_create_param G_FLASH_M25P16_INIT_PARAM = {

	flash_spi_rcv_byte_msb,		/*ע��ĵײ��FALSH һ���ֽں���*/
	flash_spi_send_byte_msb,	/*ע��ĵײ�дFALSH һ���ֽں���*/
	flash_enable,				/*ע��ĵײ�FLASHоƬʹ�ܿ��ƺ���*/
};

#if 0
/*flieloader*/
const fileload_global_info G_FILELOAD_INIT_PARAM = {

	256,					/*FLASHҳ���*/
	0x10000,				/*FLASH�������*/

	0x007C0000,				/*mcu ��FLASH��������ַ0x007C0000*/
	0x007D0000,				/*mcu ��FLASH����������ַ0x007D0000*/	

	0x003E0000,				/*fpga ��FLASH��������ַ0x003E0000*/
	0x007B0000,				/*fpga ��FLASH����������ַ0x007B0000*/	

	/*��FLASH�����ṩ������Ϊ�ⲿ��ARM�ڲ�FLASH*/
	flash_sector_erase,		/*flash ����������*/
	flash_write_page,		/*flash ҳд����*/	
	flash_read_page,		/*flash ҳ������*/	

	/*��FLASH�����ṩ*/
	0x007DFF00,				/*mcu������־�洢��������ַ0x007DFF00*/
	0x007BFF00,				/*fpga������־�洢��������ַ0x007BFF00*/	
	
	flash_page_write_zero,	/*flash�����ļ���ȷ��ɺ��޸�������־����*/
};
#endif


/******************************************************************************
*flash_enable    FLASH��дʹ�ܽ�ֹ����
*
*Input:
*	cs_ena --FLASHʹ�ܽ�ֹ����
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_enable(e_flash_cs_ena	cs_ena)
{

	if(FLASH_CS_DISABLE ==cs_ena)
	{
		spi_cs_flash(0);
	}
	else
	{
		spi_cs_flash(1);
	}


	return OK;
}

/******************************************************************************
*flash_spi_send_byte_msb    FLASH����SPI����һ���ֽ�
*
*Input:
*	data --����һ���ֽ�
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_spi_send_byte_msb(OTP_UINT8 data)
{
	spi_send_byte_msb_flash(data);
	return OK;
}

/******************************************************************************
*flash_spi_rcv_byte_msb    FLASH����SPI����һ���ֽ�
*
*Input:
*	��
*Output:
*	����һ���ֽ�
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
OTP_UINT8 flash_spi_rcv_byte_msb(void)
{
	OTP_UINT8 retdata = 0;

	retdata = spi_rcv_byte_msb_flash();

	return retdata;
}


/********************************************************************
* svc_dev_init -- ҵ������ز�����ʼ��
*
* PARAMETERS - As follow:
*
* RETURNS:	
*
* EXAMPLE:
* ...
*/
void svc_dev_ibc_init(void)
{	



	/*��Ϣ���еĴ���*/
	/*�����������ݽ�����Ϣ����*/
	g_uart1_read_msgQ_id = xQueueCreate(UART1_RECEIVE_MSG_MAX, sizeof(uart1_receive_message_struct_t));

	if (NULL ==g_uart1_read_msgQ_id )
	{
		printf("\r\n xQueueCreate g_uart1_read_msgQ_id fail !\r\n");
	}


	/*��������ҵ�������Ϣ����*/
	g_svc_read_data_msgQ_id = xQueueCreate(SVC_RECEIVE_DATA_MSG_MAX, sizeof(svc_receive_data_msg_struct_t));

	if (NULL ==g_svc_read_data_msgQ_id )
	{
		printf("\r\n xQueueCreate g_svc_read_data_msgQ_id fail !\r\n");
	}


	/*��������ҵ�������Ϣ����*/
	g_svc_read_manage_msgQ_id = xQueueCreate(SVC_RECEIVE_MANAGE_MSG_MAX, sizeof(svc_receive_manage_msg_struct_t));

	if (NULL ==g_svc_read_manage_msgQ_id )
	{
		printf("\r\n xQueueCreate svc_receive_manage_msg_struct_t fail !\r\n");
	}
	 


}






/********************************************************************
* svc_dev_init -- ҵ������ز�����ʼ��
*
* PARAMETERS - As follow:
*
* RETURNS:	
*
* EXAMPLE:
* ...
*/
void svc_dev_init(void)
{	

#if 1
	OTP_UINT16 i = 0;
	LOCAL OTP_UINT8 temp[256] = {0};
#endif

	/* ��ʼ��flash  wangzaizhong add*/
	if(OK != flash_init_mx52l(&G_FLASH_M25P16_INIT_PARAM))
	{
		//ASSERT(0);
	}	

	/*flash���ʵ���*/
#if 0

	printf("\r\n ---svc_dev_init---flash test sta --- \r\n");

	memset(temp, 0, 256);
	(OTP_VOID)flash_sector_erase(0x007C0000, 0x007C0000);

	for(i = 0; i < 256; i++)
	{
		(OTP_VOID)flash_read_byte(0x007C0000+i, &temp[i]);
	}

	for(i = 0; i < 256; i++)
	{
		temp[i] = i;
	}
	(OTP_VOID)flash_write_page(0x007C0000, temp, 256);

	memset(temp, 0, 256);
	for(i = 0; i < 256; i++)
	{
		(OTP_VOID)flash_read_byte(0x007C0000+i, &temp[i]);
	}

	for(i = 0; i < 200; i++)
	{
		printf("temp[%d] = %d;  ",i,temp[i]);
	}

	(OTP_VOID)flash_sector_erase(0x007C0000, 0x007C0000);

	printf("\r\n ---svc_dev_init---flash test end--- \r\n");
	
#endif




}









#endif


/*lint -restore*/

//#endif
