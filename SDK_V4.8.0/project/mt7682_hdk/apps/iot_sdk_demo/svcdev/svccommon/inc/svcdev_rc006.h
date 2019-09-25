#ifndef _SVCDEV_COMMON_RC006_H
#define _SVCDEV_COMMON_RC006_H

/*����svcdev ֧�ֵ�ͬʱ���ж���*/
#define SVCDEV_INT_NUM_MAX	5
/*panwei 2011-9-1*/
/*ҵ�����̵������׶�*/
typedef enum svcdev_startup_stage
{
	svcdevs_init,			/*ҵ���̳�ʼ���׶�*/
	svcdevs_int_waiting,	/*�Ѿ������жϣ��ȴ��ж���Ϣ*/
	svcdevs_cfgdone_waiting,/*�Ѿ�����IBC_INTCOMMON_CFGREQUEST�ж���Ϣ���ȴ����ûָ�������Ϣ��
							ֻҪ�õ���Ӧ�ô������������ã������̾�Ӧ�������ûָ�������Ϣ*/
	svcdevs_working		/*Ӧ�ô������������õĵ����յ������ûָ�������Ϣ��
							�����ǲ��������������õ����Ѿ��������̷���IBC_INTCOMMON_CARDREADY�ж���Ӧ*/
}svcdev_startup_stage;

/* �����ṩ������ж��źŵĽӿں��� */
extern STATUS svc_clear_hardware_int(void);
/* �����ṩ�������ж��źŵĽӿں��� */
extern STATUS svc_set_hardware_int(void);

/*
 PARAMETERS���� - As follow����:
*		pack	--	��Ӧ���������õ�buf��ַ
*		acklen	--	��Ӧ�������õ�buf����		
*		plen	--	��������ʵ�ʳ���
* RETURN����ֵ:
*
*		OK 		--	��Ӧ����ɹ�
*		ERROR 	--	��Ӧ����ʧ��,���쳣
*/
typedef STATUS (*int_pack_func)(OTP_UINT8 inttype, OTP_UINT8 *pack, OTP_UINT32 acklen, OTP_UINT32 *plen);


enum
{
	SVCDEV_INT_START,
	SVCDEV_INT_CFGREQUEST,			/*��������*/
	SVCDEV_INT_CMFFAILED,			/*����ִ�д���*/
	SVCDEV_INT_RDEVURGENT,			/*Զ���豸�����澯*/
	SVCDEV_INT_RDEVDISAPPER,		/*�¹��豸��ʧ*/
	SVCDEV_INT_CARDREADY,			/*ҵ����׼���ã���ʾ�����Ѿ�׼���ã��˵����Ѿ����ڹ���״̬*/
	SVCDEV_INT_REQ_TRANSMIT,		/*:ҵ�����������´����ļ�*/
};

/*�����ж���������ݽṹ*/
typedef struct _svcdev_int_info
{
	BOOL			isexist;	/*�ж��Ƿ����*/
	int_pack_func 	intpack;	/**/
	OTP_UINT8		type;
}svcdev_int_info;

/*panwei 2012-7-19*/
#define DERIVE_PRODUCT_NAME_MAXLEN	50		/*�������ƣ����50�ֽ�)*/

/*�����������ֲ�������֡*/
typedef struct _svcdev_derive_query_info
{
	OTP_UINT8  resByte;			/*�������̶�Ϊ0x00*/
	OTP_UINT8  proNameLen;		/*�������Ƴ���*/
	OTP_UINT8  proName[];		/*�������ƣ����50�ֽ�)*/
}OTP_PACK_ALIGN(1)svcdev_derive_query_info;

/*�����������ֲ�����Ӧ֡*/
typedef struct _svcdev_derive_query_ack_info
{
	OTP_UINT16 devt;			/*��Ʒ�豸����*/
	OTP_UINT8  resByte;			/*�������̶�Ϊ0x80*/
	OTP_UINT8  proNameLen;		/*�������Ƴ���*/
	OTP_UINT8  proName[];		/*�������ƣ����50�ֽ�)*/
}OTP_PACK_ALIGN(1)svcdev_derive_query_ack_info;

#define CLEAR_HARDWARE_INT		svc_clear_hardware_int()
#define SET_HARDWARE_INT		svc_set_hardware_int()


#define SVCDEV_CONFIG_DONE_WAITTIME	300000 /*��λΪ����*/

 /*Ӳ��λ����*/
 STATUS ResetSystem(HTMR htmr, OTP_UINT32 uarg);

 /*panwei 2011-3-10 ��λ����*/
 STATUS SoftResetSystem(HTMR htmr, OTP_UINT32 uarg);
#endif
