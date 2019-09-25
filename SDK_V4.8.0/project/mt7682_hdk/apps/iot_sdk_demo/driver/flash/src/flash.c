/****************************************************************
	Copyright(C), 1999-2004 Raisecom, Inc.
	filename: flash.c
	Author	: wangzaizhong
	version	: 1.0
	date	: 2009/02/02
	Others	:
*****************************************************************/
/*
DESCRIPTION
		flashģ�麯���ļ�,ʵ��FLASH�Ķ�д

SEE ALSO
*/


//#ifdef INCLUDE_FLASH_COMM

#include <string.h>
#include "type_common.h"
#include "spi.h"
#include "flash.h"

#define	DEBUG_MODE_FLASH   /*����ʱʹ��*/

#define	OTP_TRACE_ERROR printf( "FUNC_ENTRY:   %s L#%d \n", __func__, __LINE__);

/*
#ifdef DEBUG_MODE_FLASH
#include "tmr.h"
#include "trace.h"
#endif
*/

falsh_m25p16_info		g_flash_global_info;/*flashʹ�õ�ͨ�ñ���*/

/******************************************************************************
*tmr_delay_ms	--����msΪ��λ�ӳ�
*Input:
*	t	--��Ҫ��ʱ�ĺ�����
*Output:
*	None
*Return:
*	None
*/
OTP_VOID flash_tmr_delay_ms(OTP_UINT32 t)
{
	OTP_UINT32 i = 0;
	
	while(t--)
	{
		/* ����11.0592Mʱ�ӣ�Լ��ʱ1ms */
		for (i=0;i<7000;i++)
		{
			;	
		/*��ͬ�ĵ�Ƭ�����������ܻ��Ӧ�Ų�ͬ��ѭ������
		����LPC2103 + 11.0592MHz�Ĵ��䣬���趨ѭ������Ϊ7000*/
		/*���Ǻܾ�ȷ�������в��ԣ����е���*/
		}
	}
} 

/**********************************************************************
*flash_send_address	--flashģ�������ַ
*NOTE:
*
*Input:
*	pparam --��ʼ������
*Output:
*	��
*Return:
       ��ȡ����
*/
LOCAL STATUS flash_send_address(const OTP_UINT32 flashadd)
{
	STATUS status=ERROR;

	status = g_flash_global_info.writefunc((OTP_UINT8)((flashadd & 0xFF0000)>>16));/*addr23~addr16 ��λ��ǰ*/
	status = g_flash_global_info.writefunc((OTP_UINT8)((flashadd & 0x00FF00)>>8));
	status = g_flash_global_info.writefunc((OTP_UINT8)(flashadd & 0xFF));

	if (OK !=status)
	{
		return ERROR;
	}

	return OK;
}

/**********************************************************************
*flash_write_enable	--flashģ��дʹ��
*NOTE:
*Input:
*	��
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
LOCAL STATUS flash_write_enable(void)
{
	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);
	/*���������*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_WRITE_ENABLE))
	{
		return ERROR;
	}
	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

	return OK;
}

/**********************************************************************
*flash_write_disable	--flashģ��д��ֹ
*NOTE:
*Input:
*	��
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
LOCAL STATUS flash_write_disable(void)
{
	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);
	/*���������*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_WRITE_DISABLE))
	{
		return ERROR;
	}
	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

	return OK;
}

/**********************************************************************
*flash_read_status_register	--flashģ���״̬�Ĵ���
*NOTE:
*
*Input:
*	pdata    --��ȡ������ָ��
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
LOCAL STATUS flash_read_status_register(OTP_UINT8 *pdata)
{
	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);
	/*���������*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_READ_STATUS))
	{
		return ERROR;
	}
	/* ��flash�ж�ȡһ���ֽ� ����ȡ����ȷ������ȷ*/
	*pdata =g_flash_global_info.readfunc();	
	*pdata =g_flash_global_info.readfunc();
	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

	return OK;
}

/**********************************************************************
*flash_busy_status	--flashģ���ȡ�����Ƿ�Ϊæ״̬
*NOTE:
*
*Input:
*	��   
*Output:
*	MEMORY_BUSY =0,
*	MEMORY_OK =1
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
LOCAL e_memory_work_ret flash_busy_status(void)
{
	OTP_UINT8 readsta=0;	

	if (OK !=flash_read_status_register(&readsta))
	{
		return MEMORY_BUSY;
	}

	if (readsta &FLASH_BUSY_STATUS_VALUE)
	{
		return MEMORY_BUSY;
	}
	
	return MEMORY_OK;
}

/**********************************************************************
*flash_read_byte	--flashģ���ָ����ַ��һ���ֽں���
*NOTE:
*
*Input:
*	flashadd --ָ����ַ
*	pdata     --��ȡ������ָ��
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_read_byte(const OTP_UINT32 flashadd,OTP_UINT8 *pdata)
{
	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);
	/*���������*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_READ_BYTES))
	{
		return ERROR;
	}
	/*�����ַ*/
	if (OK !=flash_send_address(flashadd))
	{
		return ERROR;
	}	
	/* ��flash�ж�ȡһ���ֽ� */
	*pdata =g_flash_global_info.readfunc();	

	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

	return OK;
}

/**********************************************************************
*flash_read_page	--flashģ����ҳ������(256�ֽ�)
*NOTE:��ҳ��
*
*Input:
*	flashadd --ҳ����ʼ��ַ��
*	pdata     --�������ݵĻ�������ַ��
*	flashadd --�������ݵĻ��������ȣ�
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_read_page(const OTP_UINT32 flashadd,OTP_UINT8 *pdata, OTP_UINT32 len)
{
	OTP_UINT32 i=0;
	OTP_UINT32 pageadd=0;	

	/*��μ��*/
	if(pdata ==NULL)
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}

	if(len <FLASH_PAGE_SIZE)
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}
	
	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);
	/*���������*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_READ_BYTES))
	{
		return ERROR;
	}
	/*ҳ�׵�ַ���*/
	pageadd =((flashadd/FLASH_PAGE_SIZE)*FLASH_PAGE_SIZE);
	/*�����ַ*/
	if (OK !=flash_send_address(pageadd))
	{
		return ERROR;
	}	
	/* ��flash�ж�ȡһҳ����*/
	for (i=0;i<FLASH_PAGE_SIZE;i++)
	{
		pdata[i] =g_flash_global_info.readfunc();	
	}

	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

	return OK;
}

/**********************************************************************
*flash_write_page	--flashģ����ҳд����(256�ֽ�)
*NOTE:��ҳд
*
*Input:
*	flashadd --ҳ����ʼ��ַ��
*	pdata     --��Ҫд���ݵĻ�������ַ��
*	flashadd --��Ҫд���ݵĻ�������Ч���ݳ��ȣ�
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_write_page(const OTP_UINT32 flashadd,const OTP_UINT8 *pdata, const OTP_UINT32 len)
{
	OTP_UINT8 checkBuf[FLASH_PAGE_SIZE];
	OTP_UINT8 readsta=0;
	OTP_UINT32 i=0;
	OTP_UINT32 pageadd=0;	
	OTP_UINT8 cnt=0;	

	/*��μ��*/
	if(pdata ==NULL)
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}

	if(len <FLASH_PAGE_SIZE)
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}

	/*flashæ�ж�*/
	if (MEMORY_BUSY ==flash_busy_status())
	{
		/*д��ֹ*/
		if(OK !=flash_write_disable())
		{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
			return ERROR;		
		}
	}
	
/*************дʹ��******************************/	

	if(OK !=flash_write_enable())
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}	
	
/***************page write****************************/	
	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);
	/*���������*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_PAGE_PROGRAM))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;
	}
	/*ҳ�׵�ַ���*/
	/*pageadd =((flashadd/FLASH_PAGE_SIZE)*FLASH_PAGE_SIZE);*/
	/*�����ַ*/
	//if (OK !=flash_send_address(pageadd))
	if (OK !=flash_send_address(flashadd))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif	
		return ERROR;
	}	
	/* ��flash��д��һҳ����*/
	for (i=0;i<FLASH_PAGE_SIZE;i++)
	{
/*		if (OK !=g_flash_global_info.writefunc(spi_m_l(pdata[i])))		*/	
		//if (OK !=g_flash_global_info.writefunc(pdata[i]))
			if (OK !=g_flash_global_info.writefunc(i))
		{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
			return ERROR;
		}
	}

	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

/************��ҳд��������ж�*******************************/	

	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);

	/*��������֣���״̬*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_READ_STATUS))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;
	}
	
	/*����ж�*/
	readsta =g_flash_global_info.readfunc();	
	while(readsta & FLASH_BUSY_STATUS_VALUE)
	{/*write a page about 12ms */
		flash_tmr_delay_ms(1);
		readsta =g_flash_global_info.readfunc();	
		cnt ++;
		if(cnt >15)
		{
#ifdef	DEBUG_MODE_FLASH
			OTP_TRACE_ERROR;
#endif		
			break;
		}
	}

	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

/****************д��ֹ***************************/	

	if(OK !=flash_write_disable())
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}	

/******************check*************************/	

	if(OK != flash_read_page(flashadd,checkBuf,FLASH_PAGE_SIZE))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}
	for (i=0;i<FLASH_PAGE_SIZE;i++)
	{
		if (checkBuf[i] != pdata[i])
		{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif		
			return ERROR;
		}
	}

	return OK;
}

/**********************************************************************
*flash_single_sector_erase	--flashģ�鵥�������������
*NOTE:��ָ������
*
*Input:
*	flashadd --�����׵�ַ
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	BUSY	--æ��
*	ERROR 	--����
*/
STATUS flash_single_sector_erase(const OTP_UINT32 flashadd)
{
	OTP_UINT32 sectoradd=0;
	OTP_UINT8 readsta=0;	
	OTP_UINT8 cnt=0;	
#ifdef DEBUG_MODE_FLASH
	//OTP_UINT32 lasttime,nowtime;
	//lasttime= tmr_get_time(); 
#endif

	/*��μ��*/

	/*flashæ�ж�*/
	if (MEMORY_BUSY ==flash_busy_status())
	{
		/*д��ֹ*/
		if(OK !=flash_write_disable())
		{
#ifdef	DEBUG_MODE_FLASH
			OTP_TRACE_ERROR;
#endif
			return ERROR;		
		}	
	}

/*******************************************/	

	/*дʹ��*/
	if(OK !=flash_write_enable())
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}	

/*******************************************/	

	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);
	/*���������������*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_ERASE_SECTOR))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif	
		return ERROR;
	}

	/*��������׵�ַ*/
	sectoradd  =(flashadd/FLASH_SECTOR_SIZE)*FLASH_SECTOR_SIZE;
	
	/*�����ַ*/
	if (OK !=flash_send_address(sectoradd))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;
	}	
	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

/*******************************************/	

	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);

	/*��������֣���״̬*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_READ_STATUS))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;
	}
	
	/*����ж�*/
	readsta =g_flash_global_info.readfunc();	
	while(readsta & FLASH_BUSY_STATUS_VALUE)
	{/*erase a sector about 800ms */
		flash_tmr_delay_ms(5);
		readsta =g_flash_global_info.readfunc();	
		cnt ++;
		if(cnt >200)
		{
#ifdef	DEBUG_MODE_FLASH
			OTP_TRACE_ERROR;
#endif
			break;
		}
	}

	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

/*******************************************/	

	/*д��ֹ*/
	if(OK !=flash_write_disable())
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}	

#ifdef DEBUG_MODE_FLASH
	//nowtime= tmr_get_time(); 
	//OTP_TRACE("erase flash ,  delta = %u\r\n", nowtime-lasttime);
#endif

	return OK;
}

/**********************************************************************
*flash_sector_erase	--flashģ�������������
*NOTE:��ָ������
*
*Input:
*	flashadd --��������ַ
*	flashadd --ĩ������ַ
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	BUSY	--æ��
*	ERROR 	--����
*/
STATUS flash_sector_erase(const OTP_UINT32 staflashadd,const OTP_UINT32 endflashadd)
{
	OTP_UINT32 flashaddr=0;

	/*��μ��*/
	if (staflashadd >endflashadd)
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;
	}

	/*��������׵�ַ*/
	flashaddr  =(staflashadd/FLASH_SECTOR_SIZE)*FLASH_SECTOR_SIZE;	

	while(flashaddr <=endflashadd)
	{
		if (OK !=flash_single_sector_erase(flashaddr))
		{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
			return ERROR;
		}
		
		flashaddr +=FLASH_SECTOR_SIZE;
	}
	
	return OK;	
}

/**********************************************************************
*flash_bulk_erase	--flashģ��ȫ���庯��
*NOTE:�������������cmfģ����г�ʼ��
*
*Input:
*	pparam --��ʼ������
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_bulk_erase(void)
{
	OTP_UINT8 readsta=0;	
	OTP_UINT16 cnt=0;	

	/*flashæ�ж�*/
	if (MEMORY_BUSY ==flash_busy_status())
	{
		/*д��ֹ*/
		if(OK !=flash_write_disable())
		{
#ifdef	DEBUG_MODE_FLASH
			OTP_TRACE_ERROR;
#endif
			return ERROR;		
		}	
	}

/*******************************************/	
	/*дʹ��*/
	if(OK !=flash_write_enable())
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}
	
/*******************************************/	

	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);

	/*�����ȫ������������*/
	if (OK !=g_flash_global_info.writefunc(FLASH_ERASE_BULK))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;
	}
	
	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

/*******************************************/	

	/* flashƬѡѡ�� */
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_ENABLE);

	/*��������֣���״̬*/
	if (OK !=g_flash_global_info.writefunc((OTP_UINT8)FLASH_READ_STATUS))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;
	}
	
	/*����ж�*/
	readsta =g_flash_global_info.readfunc();	
	while(readsta & FLASH_BUSY_STATUS_VALUE)
	{
		readsta =g_flash_global_info.readfunc();	
		cnt ++;
		if(cnt >1000)
		{
#ifdef	DEBUG_MODE_FLASH
			OTP_TRACE_ERROR;
#endif		
			break;
		}
	}

	/* flashƬѡ��ֹ*/
	(OTP_VOID)g_flash_global_info.enablefunc(FLASH_CS_DISABLE);	

/*******************************************/	

#if 0
	/*д��ֹ*/
	if(OK !=flash_write_disable())
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}	
#endif

	return OK;	
}

/**********************************************************************
*flash_sector_copy	--flashģ��������������
*NOTE:
*
*Input:
*	dstid		--Ŀ�������ţ�
*	srcid		--Դ�����ţ�
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_sector_copy(OTP_UINT8 dstid, OTP_UINT8 srcid)
{
	OTP_UINT32 i=0;
	OTP_UINT32 busynum=0;	
	OTP_UINT32 pagenum=0;
	OTP_UINT32 destinationpageaddr=0;
	OTP_UINT32 sourcepageaddr=0;	
	OTP_UINT8	pagedata[FLASH_PAGE_SIZE];
	STATUS stetus=ERROR;
	
	/*��μ��*/
	if ((dstid >=FLASH_SECTOR_NUMBER_MAX) || (srcid >=FLASH_SECTOR_NUMBER_MAX))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;	
	}

	memset(pagedata,0,sizeof(pagedata));

	/*���ҳ����*/
	pagenum =(FLASH_SECTOR_SIZE/FLASH_PAGE_SIZE);
	/*���Ŀ�ĵ�ַ*/
	destinationpageaddr =dstid*FLASH_SECTOR_SIZE;
	/*���Դ��ַ*/	
	sourcepageaddr =srcid*FLASH_SECTOR_SIZE;	

	/*��ҳ�������ݿ���*/
	for (i=0;i<pagenum;i++)
	{
		/*��Դҳ����*/
		if (OK !=flash_read_page(sourcepageaddr+(FLASH_PAGE_SIZE*i),pagedata,FLASH_PAGE_SIZE))
		{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
			return ERROR;	
		}

/********�ڽ����������ݿ���ʱ�������ݵ�bit������˵�����**************/
/*********��ҪΪRC958�����������У�FPGA�������ļ���ʵ����****************/
/*********�ɵ�.bin�ļ���bit���ǵߵ��ģ���������������˴���**************/
/*********��������Ŀʱ��ע�⣬�ڲ���Ҫ����bit��ʱ��ʹ�øò���*******/
#if	0		
		/*���ݸ�ʽ�ı仯*/
		for (j=0;j<FLASH_PAGE_SIZE;j++)
		{
			pagedata[j] =spi_m_l(pagedata[j]);
		}
#endif
		/*дĿ��ҳ*/
		for (busynum=0;busynum<FLASH_BUSY_RENEW_WRITE_NUMBER;busynum++)	
		{
			stetus =flash_write_page(destinationpageaddr+(FLASH_PAGE_SIZE*i),pagedata,FLASH_PAGE_SIZE);
			if (OK ==stetus)
			{
				break;
			}
			else
			{
				/*�ʵ���ʱ*/
				flash_tmr_delay_ms(2);
			}
		}

		if (busynum >=FLASH_BUSY_RENEW_WRITE_NUMBER)
		{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
			return ERROR;
		}
	}

	return OK;	
}

/**********************************************************************
*flash_sector_copy	--flashģ��������������
*NOTE:
*
*Input:
*	dstid		--Ŀ�������ţ�
*	srcid		--Դ�����ţ�
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_page_write_zero(const OTP_UINT32 pageadd)
{
	OTP_UINT8 tempdata[FLASH_PAGE_SIZE];

	memset(tempdata,0,sizeof(tempdata));

	if (OK !=flash_write_page(pageadd,tempdata, (OTP_UINT32)FLASH_PAGE_SIZE))
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;	

	}
	return OK;	
}

/**********************************************************************
*flash_init_mx52l	--flashģ���ʼ������
*NOTE:�������������flash�������г�ʼ��
*��ʼ��flash����ʹ�õĻ���ͱ�����
*ע��ײ��FALSH һ���ֽں�����
*ע��ײ�дFALSH һ���ֽں�����
*ע��ײ�FLASHоƬʹ�ܿ��ƺ���
*
*Input:
*	pparam --��ʼ������
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_init_mx52l(const falsh_m25p16_create_param *pparam)
{	
	if(pparam == NULL)
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;
	}

/******ֻ��RC958ʹ�ã�������Ŀ��Ӧд��������****************************/ 
	/*flash оƬʹ�ܿ��ƣ���flash��ʼ��ʱʹ��*/
#if 0
	FLASH_OE_OUT;
	FLASH_OE_EN;
#endif
/***********************************************************************/
	memset(g_flash_global_info.databuf,0,sizeof(g_flash_global_info.databuf));

	g_flash_global_info.readfunc = pparam->readfunc;		/*�ײ��FALSH һ���ֽں���*/
	g_flash_global_info.writefunc = pparam->writefunc;		/*�ײ�дFALSH һ���ֽں���*/
	g_flash_global_info.enablefunc = pparam->enablefunc;	/*�ײ�FLASHоƬʹ�ܿ��ƺ���*/

	/*д��ֹ*/
	if(OK !=flash_write_disable())
	{
#ifdef	DEBUG_MODE_FLASH
		OTP_TRACE_ERROR;
#endif
		return ERROR;		
	}	

	printf("\r\n ---flash_init_mx52l  ok!---\r\n");

	return OK;
}

//#endif

