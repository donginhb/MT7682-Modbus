#ifndef _SVC_FLASH_H
#define _SVC_FLASH_H

#if 0
#define IOPIN_X(X)          (*((volatile unsigned long *) (0xE0028000+(0x10*(X)))))      /* no in lpc210x*/
#define IOSET_X(X)          (*((volatile unsigned long *) (0xE0028004+(0x10*(X)))))     /* no in lpc210x*/
#define IODIR_X(X)          (*((volatile unsigned long *) (0xE0028008+(0x10*(X)))))      /* no in lpc210x*/
#define IOCLR_X(X)          (*((volatile unsigned long *) (0xE002800C+(0x10*(X)))))      /* no in lpc210x*/
#define FLASH_OE_PIN			BIT(20)
#define FLASH_OE_OUT 			IODIR_X(1) |= FLASH_OE_PIN
#define FLASH_OE_DIS			IOSET_X(1)  = FLASH_OE_PIN
#define FLASH_OE_EN			IOCLR_X(1)  = FLASH_OE_PIN
#endif

/*  AS Instruction Set    */
#define FLASH_WRITE_ENABLE		0x06
#define FLASH_WRITE_DISABLE		0x04
#define FLASH_READ_STATUS	    0x05
#define FLASH_WRITE_STATUS	    0x01
#define FLASH_READ_BYTES   		0x03
#define FLASH_FAST_READ_BYTES  	0x0B
#define FLASH_PAGE_PROGRAM		0x02
#define FLASH_ERASE_SECTOR		0xD8
#define FLASH_ERASE_BULK		0xC7
#define FLASH_READ_SILICON_ID	0xAB
#define FLASH_CHECK_SILICON_ID	0x9F

#define FLASH_READ_STATUS_BIT0	0


#define FLASH_PAGE_SIZE			256		/*FLASH��ҳ���*/
#define FLASH_SECTOR_SIZE		0x10000	/*FLASH���������*/	
#define FLASH_SECTOR_NUMBER_MAX	128		/*��������*/


#define FLASH_BUSY_RENEW_WRITE_NUMBER	10		/*����д����*/

#define FLASH_BUSY_STATUS_VALUE	    	0x01	/*FLASHæ״̬��ֵ*/

/*FLASHƬѡ����*/
typedef enum _e_flash_cs_ena
{
	FLASH_CS_DISABLE	= 0,
	FLASH_CS_ENABLE	= 1
	
}e_flash_cs_ena;


typedef enum _e_flash_write_ret
{
	FLASH_WRITE_OK,
	FLASH_WRITE_BUSY,
	FLASH_WRITE_ERROR
}e_flash_write_ret;

typedef enum _e_memory_work_ret
{
	MEMORY_BUSY,
	MEMORY_OK
}e_memory_work_ret;



/*ע����flashģ���ж�һ���ֽں�����
	�������:

	�������:
		
	����ֵ:
			��������
*/
typedef OTP_UINT8 (*flash_read_byte_func)(void);


/*ע����flashģ����дһ���ֽں�����
	�������:
		pdata		--������ݵ�ָ��

	�������:
		
	����ֵ:
		OK,	ERROR	������¼��ɹ���ʧ��
*/
typedef STATUS (*flash_write_byte_func)(OTP_UINT8 pdata);


/*ע����flashģ���ж�дʹ�ܺ�����
	�������:
		cs_ena	--FLASHƬѡʹ��
	�������:
		
	����ֵ:
		OK,	ERROR	������¼��ɹ���ʧ�ܡ�
*/
typedef STATUS (*flash_enable_func)(e_flash_cs_ena	cs_ena);



/*flashģ���ܵ����ݽṹ����*/
typedef struct _falsh_m25p16_info
{

	flash_read_byte_func			readfunc;		/*ע��ĵײ��FALSH һ���ֽں���*/
	flash_write_byte_func			writefunc;		/*ע��ĵײ�дFALSH һ���ֽں���*/
	flash_enable_func				enablefunc;		/*ע��ĵײ�FLASHоƬʹ�ܿ��ƺ���*/

	OTP_UINT8 					databuf[FLASH_PAGE_SIZE];/*FLASH_PAGE_SIZE������ݻ���*/

}falsh_m25p16_info;

/*��ʼ����Ϣ�ṹ����*/
typedef struct _falsh_m25p16_create_param
{
	flash_read_byte_func			readfunc;		/*ע��ĵײ��FALSH һ���ֽں���*/
	flash_write_byte_func			writefunc;		/*ע��ĵײ�дFALSH һ���ֽں���*/
	flash_enable_func				enablefunc;		/*ע��ĵײ�FLASHоƬʹ�ܿ��ƺ���*/

}falsh_m25p16_create_param;



/******************************************************************************
					��������
******************************************************************************/

/**********************************************************************
*flash_init_mx52l	--flashģ���ʼ������
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
STATUS flash_init_mx52l(const falsh_m25p16_create_param *pparam);

/**********************************************************************
*flash_read_byte	--flashģ���ָ����ַ��һ���ֽں���
*NOTE:
*
*Input:
*	pparam --��ʼ������
*	pdata    --��ȡ������ָ��
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
STATUS flash_read_byte(const OTP_UINT32 flashadd,OTP_UINT8 *pdata);

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
STATUS flash_read_page(const OTP_UINT32 flashadd,OTP_UINT8 *pdata, OTP_UINT32 len);

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
*	BUSY	--æ��
*	ERROR 	--����
*/
STATUS flash_write_page(const OTP_UINT32 flashadd,const OTP_UINT8 *pdata, OTP_UINT32 len);

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
STATUS flash_single_sector_erase(const OTP_UINT32 flashadd);

/**********************************************************************
*flash_sector_erase	--flashģ�������������
*NOTE:��ָ������
*
*Input:
*	flashadd --�����׵�ַ
*	flashadd --����ĩ��ַ
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	BUSY	--æ��
*	ERROR 	--����
*/
STATUS flash_sector_erase(const OTP_UINT32 staflashadd,const OTP_UINT32 endflashadd);



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
STATUS flash_bulk_erase(void);

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
STATUS flash_sector_copy(OTP_UINT8 dstid, OTP_UINT8 srcid);

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
STATUS flash_page_write_zero(const OTP_UINT32 pageadd);

#endif
