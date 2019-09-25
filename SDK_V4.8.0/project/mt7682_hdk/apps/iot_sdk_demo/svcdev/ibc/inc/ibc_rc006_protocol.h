#ifndef _IBC_RC006_PROTOCOL_H
#define _IBC_RC006_PROTOCOL_H
#include "memory_map.h"	/*panwei 2011-3-7*/

/*

����֡�еĲ���������:
	0x01	��ѯ				����֧��
	0x02	����				������ʱ֧��
	0x03	����				������ʱ֧��
	0x04	��ѯ�汾��			����֧��
	0x05	��̫����������		��̫��������֧��
	0x06	��̫���������ò�ѯ	��̫��������֧��
	0x07	�������ò�ѯ		����֧��
	0x08	���ñ��Ļ���		����֧��
	0x09	ȡ�����Ļ���		����֧��
	0x0A	�豸��λ��ѯ		����֧��
	0x0B	�жϴ���			����֧��
	0x0C	ҵ�������ý���		����֧��
	0x0D	����Զ���豸��ʶ	PCM֧��
	0x0E	ɾ��Զ���豸��ʶ	PCM֧��
	0x10	ҵ������������		����֧��
	0x11	ҵ����Ӳ��λ		����֧��
	0x12	ҵ������λ
	0x13	��ȡCPU���ڴ�ʹ����
	0x14	ҵ�����ļ���������
	0x15	���������ļ�
	0x16	��������ļ�
	0x17	����ת�����ɣ�����Э��ͷ����Ӧ��Ϣ�ľ�����ΪԶ��ȫ����
	0x18	���͸�Զ�˵�ͬ����Ϣ���ֶ˵��̵ȴ�Զ������Ӧ�Ժ��ٷ���Ӧ��Ϣ��������
	0x19	�����¹��豸�ĸ澯�ж�		PCM֧��
	0x1A	�ر��¹��豸�ĸ澯�ж�		PCM֧��
	0x1B	��ѯ�¹��豸�б����Ӽ���	PCM֧��
	0x1C	ֹͣ�¹��豸ͨ��			PCM֧��
	0x1D	�����¹��豸ͨ��			PCM֧��
	0x1E	��ѯ�豸������Ϣ			�汾��ѯ����ǿ����
	0x1F	��ѯҵ���̵��ڴ���Ϣ
	0x20	�޸�ҵ���̵��ڴ���Ϣ
	0x21	����ͬ������		RC3000-15������֮��ʹ��
	0x22	����ͬ��			RC3000-15������֮��ʹ��
	0x23	ҵ����ϵͳ����		����ROTPƽ̨��ҵ����֧�֣�ʵ���Ȳ�������ϵͳ��ص�����
	0x24	��չ����			����չ����ʱ֧�֣���OPCOM3500E-STM4��ʹ��
	0x25	dxc�����л���Ϣ		��rc3000-15�����������л������Ϣ�Ĵ���

	0x30~0x35	PCM֧�֣��������˷����¹��豸

	0x70	Ӳ�����Ա���	����Ӳ�����ŵ��ڲ�����
		
*/

#define IBC_OPCODE_QUERY			0x01
#define IBC_OPCODE_CONFIG			0x02
#define IBC_OPCODE_COMMAND			0x03
#define IBC_OPCODE_QUERY_VER		0x04
#define IBC_OPCODE_BANDWIDTH_CFG 	0x05
#define IBC_OPCODE_QUERY_BANDWIDTH 	0x06
#define IBC_OPCODE_REVERSE_CFG		0x07
#define IBC_OPCODE_LOOPBACK_SET		0x08
#define IBC_OPCODE_LOOPBACK_CANCEL	0x09
#define IBC_OPCODE_RDEV_PRESENCE	0x0A
#define IBC_OPCODE_INTERRUPT		0x0B
#define IBC_OPCODE_CONFIG_DONE		0x0C
#define IBC_OPCODE_ADD_DEVICEID		0x0D
#define IBC_OPCODE_DEL_DEVICEID		0x0E
#define IBC_OPCODE_HEART_BEAT		0x10
#define IBC_OPCODE_RESET_HARD		0x11
#define IBC_OPCODE_RESET_SOFT		0x12
#define IBC_OPCODE_QUERY_CPU_MEM	0x13
#define IBC_OPCODE_SVC_FILE_MANAGE	0x14
#define IBC_OPCODE_SAVE_STARTUP_CONFIG	0x15
#define IBC_OPCODE_ERASE_STARTUP_CONFIG	0x16
#define IBC_OPCODE_FORWARD_PAYLOAD	0x17
#define IBC_OPCODE_SYNC_REMOTE_MSG	0x18
#define IBC_OPCODE_STARTUP_DEV_ALM_INT	0x19
#define IBC_OPCODE_STOP_DEV_ALM_INT	0x1A
#define IBC_OPCODE_QUERY_DEV_LIST	0x1B
#define IBC_OPCODE_STOP_DEV_COMM	0x1C
#define IBC_OPCODE_STARTUP_DEV_COMM	0x1D
#define IBC_OPCODE_QUERY_DEVINFO	0x1E
#define IBC_OPCODE_QUERY_MEMINFO	0x1F
#define IBC_OPCODE_MODIFY_MEMINFO	0x20
#define IBC_OPCODE_REQ_CONFIG_SYNC	0x21
#define IBC_OPCODE_CONIFG_SYNC		0x22
#define IBC_OPCODE_SYS_CMD			0x23
#define IBC_OPCODE_EXT_CONFIG		0x24
#define IBC_OPCODE_DXCSWITCH		0x25
#define IBC_OPCODE_QUERY_MFINFO		0x29
#define IBC_OPCODE_DERIVE_HANDSHAKE		0x2e
#define IBC_OPCODE_DEV_DEBUG		0x71
/*

��Ӧ֡�е���չ��Ӧ�ֽڣ�

	0x00	������Ӧ
	0x01	���ر���
	0x02	��֧�ֵ�Э��汾
	0x03	���Ⱥ�У��ʹ�
	0x04	�������������룬���̲�֧�ֻ��ڵ�ǰ�׶β�����
	0x05	�����������
	0x06	�豸����λ�������̲������������豸��λ��Ϣ���Ժ�Ҳ�����ã�
	0x07	ת����Ϣʧ��
	0x08  	Զ���豸�����¼�
	0x09	�������ݴ���
	0x0a	����ִ�д���
*/
#define IBC_EXRSP_OK				0x00
#define IBC_EXRSP_LOOPBACK			0x01
#define IBC_EXRSP_ERROR_VERSION		0x02
#define IBC_EXRSP_ERROR_LEN_CRC		0x03
#define IBC_EXRSP_SKIP_OPCODE		0x04
#define IBC_EXRSP_ERROR_OPCODE		0x05
#define IBC_EXRSP_ERROR_DISAPPEAR	0x06
#define IBC_EXRSP_ERROR_FORWARDING	0x07
#define IBC_EXRSP_RDEV_URGENCE		0x08
#define IBC_EXRSP_PAYLOAD_ERROR		0x09
#define IBC_EXRSP_OP_ERROR			0x0a
#define IBC_EXRSP_OPERATING			0x0b
#define IBC_EXRSP_SKIP_CMD			0x0c
#define IBC_EXRSP_ERROR_NOT_MATCH 	0x0e

/*
	�������֣�����ֻ����һ��OK����������ҵ��ģ�����ʵ������Լ�����
	ҵ��ģ��Ҳ���Բ�ʹ�øö��壬��ȫ�Լ�Э�����壬����ֻ��Ϊ�˷���
*/
#define IBC_OPREPLY_OK				0x00

/*�����ж�����
	BIT 0: �������ã���λ��1��ʾ������������
	BIT 1: ����ִ�д��󣬴�λ��1��ʾ����ִ�д�"�ж���Ӧ��Ϣ"��Ϊִ�д���ı���
	BIT 2: Զ���豸�����澯����ҵ���̶�Ӧ��Զ���豸�����˽����澯��
		   Զ���豸�ı�ʶ��"�ж���Ӧ��Ϣ"�У���ʽ��"�豸��λ��ѯ"��Զ���豸��ʶһ��
	BIT 3: �¹��豸��ʧ��������ҵ�����¹��豸��ʧ�������¹����ͨ��"�¹��豸��ѯ"��á�
	BIT 4: ҵ����׼���ã���ʾ�����Ѿ�׼���ã��˵����Ѿ����ڹ���״̬��
	       Ӧ����ҵ���������·����õĳ��ϣ���ҵ���̱�����Ϊ��ģʽ������ҵ�����������
	BIT 5:ҵ�����������´����ļ�����λ��1��ʾҵ���̴����ļ�ʧ�ܣ���Ҫ���´����ļ���
		   "�ж���Ӧ��Ϣ"��ΪҪ���صĲ������͡��ļ����ͺͱ��������ֽڡ�
			
	˽���ж����Ͱ���bit����,������ҵ����ص��ж����ͣ����豸�����澯�ȣ��ɾ����豸��ͨ�Ź��������
	ֻ��˽���ж�����Ϊ��0ʱ���ű���������ҵ����ص��ж����͡�
*/
#define IBC_INTCOMMON_CFGREQUEST		((OTP_UINT16)(0x0001<<0))
#define IBC_INTCOMMON_CMDFIAIED			((OTP_UINT16)(0x0001<<1))
#define IBC_INTCOMMON_RDEV_URGENCE		((OTP_UINT16)(0x0001<<2))
#define IBC_INTCOMMON_RDEV_DISAPPEAR	((OTP_UINT16)(0x0001<<3))
#define IBC_INTCOMMON_CARDREADY			((OTP_UINT16)(0x0001<<4))
#define IBC_INTCOMMON_REQUEST_TRANSMIT	((OTP_UINT16)(0x0001<<5))


/*��Ӧ���еı����ֽڵĹ̶�ֵ*/
#define IBC_CMDACK_RESERVE	0x80

/*ibc_payload_xxxϵ�нṹ��,data�ֶ�����ڽṹ��ַ��ƫ����*/
#define IBC_PAYLOAD_DATA_OFFSET(name)	((OTP_UINT32)(&((ibc_payload_##name*)0)->data))


/********************** RC004���ͨ�ŵĹ�������********************/

/* RC004���ͨ��֡ͷ�ֽ�, ��������֡ͷ */
/* ��PDH/RCMS���豸��Ϊ0x55,  ��PCM���豸��Ϊ0xAA */
#define IBC_RC004_FRAME_HEADER_CHAR1		0x55
#define IBC_RC004_FRAME_HEADER_CHAR2		0xAA
#define IBC_RC004_FRAME_HEADER_LEN			0x02

/*RC004����֡�еĲ���������:
	0x01	��ѯ
	0x02	����
	0x03	����
	0x04	��ѯ�汾��
	0x05	��̫����������		��̫��������֧��
	0x06	��̫���������ò�ѯ	��̫��������֧��
*/
#define IBC_RC004_OPCODE_QUERY				0x01
#define IBC_RC004_OPCODE_CONFIG				0x02
#define IBC_RC004_OPCODE_COMMAND			0x03
#define IBC_RC004_OPCODE_QUERY_VER			0x04
#define IBC_RC004_OPCODE_BANDWIDTH_CFG 		0x05
#define IBC_RC004_OPCODE_QUERY_BANDWIDTH 	0x06

/*RC004Э�鹫�����ֵķ���֡ IBC_OPCODE_PUBLIC_004 */
typedef struct ibc_payload_004_public
{
	OTP_UINT8 frameHeader;  /* 004Э�����ʼ�ַ� */
	OTP_UINT8 frameLen;     /* 004Э��Ĳ�����Ϣ֡���� */
	OTP_UINT8 deviceId;     /* 004Э���豸ID*/
	OTP_UINT8 opcode;		/* 004Э��Ĳ���������*/
	OTP_UINT8 data[];		/* ������Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_004_public;

/*RC004���ͨѶ����Ӧ֡�����ָ�ʽ*/
/*һ��ΪPDH/RCMS���豸������Ӧ֡��ʽΪ:
  Start_Char��0x55����Pkg_Length��Device_Type, [Operate_Inf], Sum��*/
typedef struct ibc_payload_frame1_004_ack
{
	OTP_UINT8 frameHeader;  /* 004Э�����ʼ�ַ� */
	OTP_UINT8 frameLen;     /* 004Э��Ĳ�����Ϣ֡���� */
	OTP_UINT8 devt;     	/* 004Э���豸����*/
	OTP_UINT8 data[];		/* ������Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_frame1_004_ack;

/*һ��ΪPCM�豸������Ӧ֡��ʽΪ:
  Start_Char(0xAA)��Pkg_Length��Device_ID, Operate_Code, DeviceType��[Operate_ID, Operate_Inf]��Sum*/
typedef struct ibc_payload_frame2_004_ack
{
	OTP_UINT8 frameHeader;  /* 004Э�����ʼ�ַ� */
	OTP_UINT8 frameLen;     /* 004Э��Ĳ�����Ϣ֡���� */
	OTP_UINT8 deviceId;     /* 004Э���豸ID*/
	OTP_UINT8 opcode;		/* 004Э��Ĳ���������*/
	OTP_UINT8 devt;			/* 004Э���е�ģ������*/
	OTP_UINT8 data[];		/* ������Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_frame2_004_ack;

/* ���İ��ͨѶЭ�鱨�ĳ���*/
#define IBC_PAYLOAD_PROTOCOL_MAX_LEN	4096

/************************* ���ɲ��ֵĹ�����ʽ **********************/

/*	��ѯ����֡ IBC_OPCODE_QUERY */
typedef struct ibc_payload_query
{
	OTP_UINT16 	devt;		/*�豸����*/
	OTP_UINT8 	reserve;	/*����*/
	OTP_UINT8 	command;	/*������(1)*/
	OTP_UINT8 	data[];		/*��ѯ��Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_query;

/*	��ѯ��Ӧ֡ */
typedef struct ibc_payload_query_ack
{
	OTP_UINT16 devt;		/*ģ������*/
	OTP_UINT8 reserve;		/*�������̶�ΪIBC_CMDACK_RESERVE*/
	OTP_UINT8 commandack;	/*��Ӧ������*/
	OTP_UINT8 data[];		/*�����ض��ֽڿ飨0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_query_ack;


/***************************************************************************/


/*	���÷���֡ IBC_OPCODE_CONFIG */
typedef struct ibc_payload_config
{
	OTP_UINT16 	devt;		/*�豸����*/
	OTP_UINT8 	reserve;	/*����*/
	OTP_UINT8 	command;	/*������(1)*/
	OTP_UINT8 	data[];	/*������Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_config;

/*	���÷���֡ ��004Զ���豸�İ汾*/
typedef struct ibc_payload_config_004
{
	OTP_UINT8 type004;		/*�忨���ͣ�1��*/
	OTP_UINT8 data[];		/*��004Э��һ�µ������ֽڣ�0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_config_004;

/*	���÷���֡ ��002Զ���豸�İ汾*/
typedef struct ibc_payload_config_002
{
	OTP_UINT8 data[1];		/*����002���ģ����Ȳ�Ϊ0*/
}OTP_PACK_ALIGN(1) ibc_payload_config_002;


/*	������Ӧ֡ */
typedef struct ibc_payload_config_ack
{
	OTP_UINT16 devt;		/*ģ������(2)*/
	OTP_UINT8 reserve;		/*�������̶�ΪIBC_CMDACK_RESERVE*/
	OTP_UINT8 commandack;	/*��Ӧ������*/
	OTP_UINT8  opreply;		/*��������ֽ�(1)*/
	OTP_UINT8 data[];		/*������Ӧ��Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_config_ack;

/*	������Ӧ֡��Զ���豸�İ汾 */
typedef struct ibc_payload_config_rdev_ack
{
	OTP_UINT8 data[1];		/*"������Ӧ��Ϣ��"�Ǿֶ˵��̸����Լ���ʵ������ģ�
							ͨ�������Ӧ�ò����ڡ�
							����ֶ˵��̲��õȴ��豸����Ӧ��Ϣ�Ժ�Ÿ������̻�
							��Ӧ��Ϣ�Ļ������п�����"������Ӧ��Ϣ��"�м����豸
							���صľ��ɡ�*/
}OTP_PACK_ALIGN(1) ibc_payload_config_rdev_ack;


/***************************************************************************/




/*	�����֡ IBC_OPCODE_COMMAND*/
typedef struct ibc_payload_command
{
	OTP_UINT16 	devt;		/*�豸����*/
	OTP_UINT8 	reserve;	/*����*/
	OTP_UINT8 	command;	/*������(1)*/
	OTP_UINT8 data[];		/*������Ϣ(0~n)*/
}OTP_PACK_ALIGN(1) ibc_payload_command;

/*	�����֡ ��004Զ���豸�İ汾*/
typedef struct ibc_payload_command_004
{
	OTP_UINT8 type004;		/*�忨���ͣ�1��*/
	OTP_UINT8 data[];		/*��004Э��һ�µ������ֽڣ�0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_command_004;



/*	������Ӧ֡ */
typedef struct ibc_payload_command_ack
{
	OTP_UINT16 devt;		/*ģ������(2)*/
	OTP_UINT8 reserve;		/*�������̶�ΪIBC_CMDACK_RESERVE*/
	OTP_UINT8 commandack;	/*��Ӧ������*/
	OTP_UINT8  opreply;		/*��������ֽ�(1)*/
	OTP_UINT8 data[];		/*������Ӧ��Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_command_ack;

/*	������Ӧ֡��Զ���豸�İ汾 */
typedef struct ibc_payload_command_rdev_ack
{
	OTP_UINT8 data[1];		/*"������Ӧ��Ϣ��"�Ǿֶ˵��̸����Լ���ʵ������ģ�
							ͨ�������Ӧ�ò����ڡ�
							����ֶ˵��̲��õȴ��豸����Ӧ��Ϣ�Ժ�Ÿ������̻�
							��Ӧ��Ϣ�Ļ������п�����"������Ӧ��Ϣ��"�м����豸
							���صľ��ɡ�*/
}OTP_PACK_ALIGN(1) ibc_payload_command_rdev_ack;



/***************************************************************************/


/*	��ѯ�汾�ŷ���֡ IBC_OPCODE_QUERY_VER*/



/*	��ѯ�汾����Ӧ֡ */
typedef struct ibc_payload_query_ver_ack
{
	/* wangjiong add 2006-10-17: ������devt�����ĵ��͸����忨��ʵ�ֱ���һ�� */
	OTP_UINT16 	devt;		/*ģ������*/
	
	OTP_UINT8	softver;	/*����汾*/
	OTP_UINT8	hardver;	/*Ӳ���汾*/
	OTP_UINT8	firmver;	/*�̼��汾*/
}OTP_PACK_ALIGN(1) ibc_payload_query_ver_ack;


/***************************************************************************/


/*	�������÷���֡ IBC_OPCODE_BANDWIDTH_CFG ֻ�и�004Զ���豸�İ汾*/
typedef struct ibc_payload_bandwidth_004
{
	OTP_UINT8 type004;		/*�忨���ͣ�1��*/
	OTP_UINT8 data[];		/*��004Э��һ�µ������ֽڣ�0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_bandwidth_004;


/*	����������Ӧ֡ */
typedef struct ibc_payload_bandwidth_rdev_ack
{
	OTP_UINT8 data[1];		/*"����������Ӧ��Ϣ��"�Ǿֶ˵��̸����Լ���ʵ������ģ�
							ͨ�������Ӧ�ò����ڡ�
							����ֶ˵��̲��õȴ��豸����Ӧ��Ϣ�Ժ�Ÿ������̻�
							��Ӧ��Ϣ�Ļ������п�����"������Ӧ��Ϣ��"�м����豸
							���صľ��ɡ�*/
}OTP_PACK_ALIGN(1) ibc_payload_bandwidth_rdev_ack;


/***************************************************************************/

/*	��̫���������ò�ѯ����֡ IBC_OPCODE_QUERY_BANDWIDTH ֻ�и�004Զ���豸�İ汾*/



/*	����������Ӧ֡ */
typedef struct ibc_payload_query_bandwidth_rdev_ack
{
	OTP_UINT8 data[1];		/*"�����ѯ��Ӧ��Ϣ��"�Ǿֶ˵��̸����Լ���ʵ������ġ�*/
}OTP_PACK_ALIGN(1) ibc_payload_query_bandwidth_rdev_ack;


/***************************************************************************/



/*	�������ò�ѯ����֡ IBC_OPCODE_REVERSE_CFG */



/*	�������ò�ѯ��Ӧ֡ */
typedef struct ibc_payload_reverse_cfg_ack
{
	OTP_UINT16 devt;		/*ģ������(2)*/
	OTP_UINT8 data[];		/*������Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_reverse_cfg_ack;

/* �������ò�ѯ��Ӧ֡���ɵ���󳤶�*/
#define IBC_PAYLOAD_REVERSE_CFG_ACK_MAX_LEN	4096



/***************************************************************************/


/*	���ñ��Ļ��ط���֡ IBC_OPCODE_LOOPBACK_SET */


/*	���ñ��Ļ�����Ӧ֡ */



/***************************************************************************/



/*	ȡ�����Ļ��ط���֡ IBC_OPCODE_LOOPBACK_CANCEL*/


/*	ȡ�����Ļ�����Ӧ֡ */



/***************************************************************************/



/*	�豸��λ��ѯ����֡ IBC_OPCODE_RDEV_PRESENCE*/



/*	�豸��λ��ѯ��Ӧ֡ */
typedef struct ibc_payload_rdev_presence_ack
{
	OTP_UINT16	presencenum;/*��λ�豸������2��*/
	rdev_rid	rids[];	/*Զ���豸��ʶ(0~n)*/
}OTP_PACK_ALIGN(1) ibc_payload_rdev_presence_ack;
/* �豸��λ��ѯ��Ӧ֡���ɵ���󳤶�*/
#define IBC_PAYLOAD_RDEV_PRESENCE_ACK_MAX_LEN	2048



/***************************************************************************/



/*	�жϴ�����֡ IBC_OPCODE_INTERRUPT*/



/*	�жϴ�����Ӧ֡ */
typedef struct ibc_payload_interrupt_ack
{
	OTP_UINT16 	devt;		/*ģ������*/
	OTP_UINT16 	intcommon;	/*�����ж�����, IBC_INTCOMMON_CFGREQUEST��*/
	OTP_UINT8 	intprivate;	/*˽���ж�����, ��Ϊ0ʱ��ʾ��˽���жϣ���Ҫ���ݸ�ҵ��ģ�鴦��*/
	OTP_UINT8 data[];		/*�ж���Ӧ��Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_interrupt_ack;
/* �жϴ�����Ӧ֡���ɵ���󳤶�*/
#define IBC_PAYLOAD_INTERRUPT_ACK_MAX_LEN	2048


/***************************************************************************/



/*	���ý�������֡ IBC_OPCODE_CONFIG_DONE */



/*	���ý�����Ӧ֡ */



/***************************************************************************/


/*�����¹��豸��ÿ����ʶ*/
typedef struct rdev_add_item
{
	OTP_UINT16	devt;			/*�豸���ͣ�Ϊdev_typeö��ֵ*/
	OTP_UINT8 	channel;		/*�¹��豸��Ӧ��ͨ����,0��ʾĬ��ͨ��*/
	OTP_UINT8	devid;			/*�豸ID���ֲ�����*/
}OTP_PACK_ALIGN(1)rdev_add_item;/*����Ϊ�����ģ�������ͨ�Žṹ����*/

/*	����Զ���豸��ʶ����֡ IBC_OPCODE_ADD_DEVICEID */
typedef struct ibc_payload_add_device
{
	OTP_UINT8		hop;		/*��������ȻҪ������Ϣ��������һ��*/
	rdev_add_item 	items[1];	/*�豸��ʶ�����飬��ȻҪ������Ϣ��������һ��*/
}OTP_PACK_ALIGN(1) ibc_payload_add_device;


/*	����Զ���豸��ʶ��Ӧ֡ */



/***************************************************************************/



/*ɾ���¹��豸��ÿ����ʶ*/
typedef struct rdev_del_item
{
	OTP_UINT16	devt;			/*�豸���ͣ�Ϊdev_typeö��ֵ*/
	OTP_UINT8 	channel;		/*�¹��豸��Ӧ��ͨ����,0��ʾĬ��ͨ��*/
	OTP_UINT8	devid;			/*�豸ID���ֲ�����*/
}OTP_PACK_ALIGN(1)rdev_del_item;/*����Ϊ�����ģ�������ͨ�Žṹ����*/

/*	ɾ��Զ���豸��ʶ����֡ IBC_OPCODE_DEL_DEVICEID */
typedef struct ibc_payload_del_device
{
	OTP_UINT8		hop;		/*��������ȻҪ������Ϣ��������һ��*/
	rdev_del_item 	items[1];	/*�豸��ʶ�����飬��ȻҪ������Ϣ��������һ��*/
}OTP_PACK_ALIGN(1) ibc_payload_del_device;


/*	ɾ��Զ���豸��ʶ��Ӧ֡ */



/***************************************************************************/



/*	���������֡ IBC_OPCODE_HEART_BEAT */



/*	����������Ӧ֡ */



/***************************************************************************/



/*	Ӳ��λ����֡ IBC_OPCODE_RESET_HARD */


/*	Ӳ��λ��Ӧ֡ */


/***************************************************************************/


/*	��λ����֡ IBC_OPCODE_RESET_SOFT */



/*	��λ��Ӧ֡ */



/***************************************************************************/




/*	��ȡCPU���ڴ�ʹ���ʷ���֡ IBC_OPCODE_QUERY_CPU_MEM */



/*	��ȡCPU���ڴ�ʹ������Ӧ֡ */
typedef struct ibc_payload_query_cpu_mem_ack
{
	OTP_UINT16 	devt;		/*�豸����*/
	OTP_UINT8 	cpurate;	/*CPUʹ����*/
	OTP_UINT8 	memrate;	/*�ڴ�ʹ����*/
}OTP_PACK_ALIGN(1) ibc_payload_query_cpu_mem_ack;


/***************************************************************************/



/*	ҵ�����ļ����������֡ IBC_OPCODE_SVC_FILE_MANAGE */
typedef struct _ibc_payload_svcfile_manage
{
	OTP_UINT16 	devt;		/*ģ������(2)*/
	OTP_UINT8 	reserve;	/*�������̶�Ϊ0x00 (1)*/
	OTP_UINT8 	command;	/*������(1)*/
	OTP_UINT8 	fileType;	/*�ļ�����(1)*/
	OTP_UINT8 	data[];	/*�����ֽڿ飨n��*/
}OTP_PACK_ALIGN(1) ibc_payload_svcfile_manage;

/*	ҵ�����ļ�����������Ӧ֡ IBC_OPCODE_SVC_FILE_MANAGE */
typedef struct _ibc_payload_svcfile_manage_ack
{
	OTP_UINT8 	reserve;	/*�������̶�ΪIBC_CMDACK_RESERVE*/
	OTP_UINT8 	commandack;	/*��Ӧ������(1)*/
	OTP_UINT8 	data[];		/*��Ӧ�ֽڿ飨n��*/
}OTP_PACK_ALIGN(1) ibc_payload_svcfile_manage_ack;

/*	ҵ�����ļ�������������ع����С����ؽ����ķ����ֽڿ鶨�� */
typedef struct _ibc_payload_svcfile_manage_loaddata
{
	OTP_UINT8 	sessionID;		/**/
	OTP_UINT16 	serialNumber;	/*��� (2)*/
	OTP_UINT16	dataLen;		/*�ļ��ֽڿ鳤��(2)*/
	OTP_UINT8 	info[];			/*�ļ��ֽڿ飨n��*/
}OTP_PACK_ALIGN(1) ibc_payload_svcfile_manage_loaddata;

typedef struct _ibc_payload_svcfile_manage_mcu_loaddata
{
	OTP_UINT32	address;		/*��Ϣ������Ŀ�ĵ�ַ (4)*/	
	OTP_UINT8 	info[];			/*�ļ��ֽڿ飨n��*/
}OTP_PACK_ALIGN(1) ibc_payload_svcfile_manage_mcu_loaddata;

/*	ҵ�����ļ�������������ؿ�ʼ��Ӧ����Ϣ���� */
typedef struct _ibc_payload_svcfile_manage_start_ack
{
	OTP_UINT8 	sessionID;	/**/
	OTP_UINT16 	ibcMaxLen;	/*�����Ϣ����󳤶�(2)*/
	OTP_UINT32 	fileLen;		/*�ļ��ܳ���(4)*/
}OTP_PACK_ALIGN(1) ibc_payload_svcfile_manage_start_ack;

/*	ҵ�����ļ���������� 	��ʼ���ء���ʼ�ϴ���ɾ���ļ��ķ�����Ϣ���� */
typedef struct _ibc_payload_svcfile_manage_loaddata_start_info
{
	OTP_UINT32 	fileLen;			/*�ļ��ֳ���(4)*/
	OTP_UINT8 	filename[];		/*�ļ�����n��*/
}OTP_PACK_ALIGN(1) ibc_payload_svcfile_manage_loaddata_start_info;


#define FILE_DOWNLOAD_MCU_IBC_MAX_LEN	260		/* ���ͨѶ�ļ�������󳤶�*/
#define FILE_DOWNLOAD_FPGA_IBC_MAX_LEN	256		/* ���ͨѶ�ļ�������󳤶�*/
#define FILE_DOWNLOAD_ADDRESS_SIZE		4		/* (����Ŀ�ĵ�ַ���)*/
#define FILE_DOWNLOAD_DATA_MIN_LEN		FILE_DOWNLOAD_ADDRESS_SIZE		/* (����Ŀ�ĵ�ַ)���ͨѶ�ļ�������Ч���˵���С����*/
#define FILE_DOWNLOAD_SESSION_ID			0x2A	/* �ļ�����sessionID*/
#define FILE_DOWNLOAD_FILE_MAX_LEN		0		/* �ļ��ܳ���*/
#define FILE_DOWNLOAD_FLASH_ADDRESS		0x08002000		/* ����Ŀ��FLASH��ַ*/



/* ҵ�����ļ����������� */
#define IBC_FILE_CMD_NULL					0x00	/* �ļ�����Ϊ��*/
#define IBC_FILE_CMD_DOWNLOAD_START		0x01	/* �ļ���ʼ����*/
#define IBC_FILE_CMD_DOWNLOADING			0x02	/* �ļ����ع�����*/
#define IBC_FILE_CMD_DOWNLOAD_END		0x03	/* �ļ����ؽ���*/
#define IBC_FILE_CMD_UPLOAD_START			0x04	/* �ļ���ʼ�ϴ�*/
#define IBC_FILE_CMD_UPLOADING			0x05	/* �ļ��ϴ�������*/
#define IBC_FILE_CMD_UPLOAD_END			0x06	/* �ļ��ϴ�����*/
#define IBC_FILE_CMD_DELETE_FILE			0x07	/* �ļ�ɾ���ļ�*/
#define IBC_FILE_CMD_QUERY_RESULT			0x08	/* �ļ���ѯ���*/

/* ҵ�����ļ�����*/
#define IBC_FILE_TYPE_NULL					0x00	/* �����ļ�Ϊ��*/
#define IBC_FILE_TYPE_FPGAUPDATE			0x01	/* ����fpga�ļ�*/
#define IBC_FILE_TYPE_SYSUPDATE			0x02	/* ����ϵͳ���*/
#define IBC_FILE_TYPE_STARTUP_CFG			0x03	/* ���������ļ�*/
#define IBC_FILE_TYPE_COMMON_FILE			0x04	/* ��ͨ�ļ���ȫ·���ļ���*/
#define IBC_FILE_TYPE_BOOTROM				0x05	/* ����bootrom�ļ�*/
#define IBC_FILE_TYPE_FPGA2UPDATE			0x06	/* ����fpga2�ļ�*/
#define IBC_FILE_TYPE_FILELIST				0x07	/* ��ȡ�ļ��б�*/
#define IBC_FILE_TYPE_MCUUPDATE			0x08	/* ����MCU�ļ�*/

/* ҵ�����ļ���ѯ���*/
#define IBC_FILE_RESULT_SUCCESS			0x00	/* �ļ������ɹ�*/
#define IBC_FILE_RESULT_UNSUCCESS			0x01	/* �ļ�����ʧ��*/
#define IBC_FILE_RESULT_WR_FLASH_ERROR	0x04	/* дflash����*/
#define IBC_FILE_RESULT_FILE_TYPE_ERROR	0x05	/* ��Ч���ļ�����*/
#define IBC_FILE_RESULT_SESSIONID_ERROR	0x0F	/* sessionid��ƥ��*/
#define IBC_FILE_RESULT_NUMBER_ERROR		0x10	/* �ļ������кŲ�ƥ��*/
#define IBC_FILE_RESULT_CRC8_ERROR		0x13	/* CRC8У���*/


/*�����ļ�����*/
typedef enum _e_ibc_fileload_type
{
	IBC_NULL_FILE		= 0,
	IBC_HEX_FILE		= 1,
	IBC_BIN_FILE 		= 2
	
}e_ibc_fileload_type;

/*�����ļ�����*/
typedef enum _e_ibc_fileload_device_type
{
	IBC_NULL_DEVICE	= 0,
	IBC_MCU_DEVICE	= 1,
	IBC_FPGA_DEVICE	= 2
	
}e_ibc_fileload_device_type;

/*ibc_file_downlaod_process	--�ļ����ش�����
*Input:
*	filetype		--�ļ�����
*	devicetype	--�豸����
*	command	--��������
*	pdata		--��������ָ��
*	length		--���ݳ���
*Output:
*	��
*Return:
*	OK 		--��ȷ
*	ERROR 	--����
*/
typedef STATUS (* ibc_file_downlaod_process)(	OTP_UINT16 file_type,
							OTP_UINT16 device_type,
							OTP_UINT16 command_code,
							OTP_UINT8* pdata,
							OTP_UINT32 length);


/*�ļ����ع���ͨ�ñ�������*/
typedef struct ibc_payload_svcfile_manage_loaddata_global_info
{
	OTP_UINT16 	serialNumber;		/*����֡���(2)*/
	OTP_UINT8	FileType;			/*�ļ�����(1)*/
	OTP_UINT8	QueryResult;		/*��������Ӧ��(1)*/	
}OTP_PACK_ALIGN(1) ibc_payload_svcfile_manage_loaddata_global_info;



/***************************************************************************/


/*	�����������÷���֡ IBC_OPCODE_SAVE_STARTUP_CONFIG */



/*	��������������Ӧ֡ */


/***************************************************************************/


/*	����������÷���֡ IBC_OPCODE_ERASE_STARTUP_CONFIG */



/*	�������������Ӧ֡ */


/***************************************************************************/


/*	�����¹��豸�ĸ澯�жϷ���֡ IBC_OPCODE_STARTUP_DEV_ALM_INT */



/*	�����¹��豸�ĸ澯�ж���Ӧ֡ */


/***************************************************************************/


/*	�ر��¹��豸�ĸ澯�жϷ���֡ IBC_OPCODE_STOP_DEV_ALM_INT */


/*	�ر��¹��豸�ĸ澯�ж���Ӧ֡ */



/***************************************************************************/


/*	��ѯ�¹��豸�б����Ӽ�������֡ IBC_OPCODE_QUERY_DEV_LIST */



/*	��ѯ�¹��豸�б����Ӽ�����Ӧ֡ */
typedef struct ibc_payload_query_dev_list_ack
{
	OTP_UINT8	devicenum;	  /* �¹��豸����,Ϊ0ʱ��ʾû���¹��豸�����ֽ� */
	rdev_rid_item	rids[];	  /*�¹��豸�б�(0~n)*/
}OTP_PACK_ALIGN(1) ibc_payload_query_dev_list_ack;
/* �¹��豸��ѯ��Ӧ֡���ɵ���󳤶�*/
#define IBC_PAYLOAD_RDEV_LIST_ACK_MAX_LEN	2048


/***************************************************************************/


/*	ֹͣ�¹��豸ͨ������ IBC_OPCODE_STOP_DEV_COMM */


/*	ֹͣ�¹��豸ͨ��������Ӧ֡ */



/***************************************************************************/


/*	�����¹��豸ͨ������ IBC_OPCODE_STARTUP_DEV_COMM */



/*	�����¹��豸ͨ��������Ӧ֡ */



/***************************************************************************/

/*	��ѯ�豸������Ϣ����֡ IBC_OPCODE_QUERY_DEVINFO*/


/* xujingru-2007-12-21 �޸��˹̼��汾��λ���壬С�汾ռ��һ���ֽ�
   ����ҵ���̰汾�ķ�Χ˵��:
   1������汾:
      ���屾:1-15;���ܰ汾:0-63;bug�汾��:0-63
   2���̼��汾:
      ��汾:1-15;С�汾:0-255;
   3��Ӳ���汾:
      ��汾:1-15;С�汾:0-9*/
/*	��ѯ�豸������Ϣ��Ӧ֡ 

	����汾��Ϣbitλ����(����bootrom��rotp������汾)
	Bit15~Bit12	XX:���汾��,��ʾ���ϵͳ�����ش��������Ӳ�������ش����;
	Bit11~Bit6	YY:���ܰ汾��,��ʾ����������Ե����ӻ��߸Ľ�;
	Bit5~Bit0	ZZ:BUG�汾��,��ʾ��XX�汾��ʶ�½��е�bug�޸ĵĴ���;

	�̼��汾��Ϣbitλ����(����FPGA��CPLD��)
	Bit15~Bit12	����
	Bit15~Bit8  ��汾���壬��ʾ�̻�������빦�ܷ����ش��������Ӳ�������ش������
				���߲��ܱ������¼��ݣ��ñ�ʶ����̻����������ش�������
				��ʾ���֣���1��ʼ��	
	Bit7~Bit0	С�汾���壬��ʾһ�㹦�����Ե���������bug���޸ģ�
				�ñ�ʶ����̻���������һ�㹦�����Ե���������bug���޸ģ�
				��ʾ���֣���0��ʼ��
	
	Ӳ���汾��Ϣbitλ����
	Bit15~Bit12	����
	Bit11~Bit8  ��汾���壬ȡֵ��ΧΪ"0001"��"1111"��"0000"��ֹʹ�ã�
	-----------------------------------------------------------------			
				��汾�Ķ����Ʊ����Ӧ��
				����	�汾
				0000	��ֹʹ��
				0001	A
				0010	B
				0011	C
				0100	D
				0101	E
				0110	F
				0111	G
				1000	H
				1001	I
				1010	J
				1011	K
				1100	L
				1101	M
				1110	N
				1111	O
	------------------------------------------------------------------
	Bit7~Bit4	����
	Bit3~Bit0	С�汾���壬ȡֵ��ΧΪ"0000"��"1001"��"1010"��"1111"��ֹʹ��
	------------------------------------------------------------------
				С�汾�Ķ����Ʊ����Ӧ��				
				����	�汾
				0000	0
				0001	1
				0010	2
				0011	3
				0100	4
				0101	5
				0110	6
				0111	7
				1000	8
				1001	9
	------------------------------------------------------------------

	����ı���ʱ���ַ��� : Mon  data year time eg: Dec  6 2006 14:26:31

	�̼�������ʱ��:	�����2000��1��1��0ʱ0��0��
	bitλ����:
	
	Bit31~Bit26	year:2000��ʼ����;
	Bit25~Bit22	month:1~12;
	Bit21~Bit17	day:1~31;
	
	Bit16~Bit12	hour:0~23;
	Bit11~Bit6	minute:0~59;
	Bit5~Bit0	second:0~59;
	
*/

typedef struct ibc_payload_query_devinfo_ack
{
	OTP_UINT16 	devt;		/*ģ������*/	
	OTP_UINT16 	devtext;	/*ģ��������չ����ͨ�����Լ����壬ȱʡΪ0*/

	/*��������Ϣ*/
	OTP_UINT16	bootromver;	/*bootrom�汾*/
	OTP_UINT16	rotpver;	/*rotp�汾*/
	OTP_UINT16	softver;	/*����汾*/
	OTP_UINT8	softtime[32];	/* ����ʱ����ַ���*/

	OTP_UINT16	hardver;	/*Ӳ���汾*/
	
	/*�̼������Ϣ������cpld��fpga���û����ȱʡ��0*/
	OTP_UINT8	firmwarecount;	/* �̼�����Ŀ */
	
	OTP_UINT16	descriptionlen;	/* ������Ϣ���� */
	
	struct firmware{
		OTP_UINT8	type;	/* 0 : cpld ,   1 : fpga ,	2:unknow; */
		OTP_UINT16	ver;	/*�汾*/
		OTP_UINT32	time;	/*����ʱ��,�����1970��1��1��0ʱ0��0�������*/
	} OTP_PACK_ALIGN(1)firmware[];

}OTP_PACK_ALIGN(1) ibc_payload_query_devinfo_ack;
/* ��ѯ�豸������Ϣ��Ӧ֡���ɵ���󳤶�*/
#define IBC_PAYLOAD_QUERY_DEVINFO_ACK_MAX_LEN	1024

/***************************************************************************/

/*	��ѯ�豸���ڴ���Ϣ����֡ IBC_OPCODE_QUERY_MEMINFO*/
typedef struct ibc_payload_query_meminfo
{
	OTP_UINT32 adrs;		/* address to display (if 0, display next block */
    OTP_UINT16 nunits;		/* number of units to print (if 0, use default) */
    OTP_UINT8 width; 		/* width of displaying unit (1, 2, 4, 8) */
}OTP_PACK_ALIGN(1) ibc_payload_query_meminfo;

/*	��ѯ�豸���ڴ���Ϣ��Ӧ֡ */
typedef struct ibc_payload_query_meminfo_ack
{
	OTP_UINT16 memlength;		/*��Ϣ������*/
	OTP_UINT8 meminfo[];		/*�ڴ���Ϣ��*/
}OTP_PACK_ALIGN(1) ibc_payload_query_meminfo_ack;

/*	�޸��豸���ڴ���Ϣ����֡ IBC_OPCODE_MODIFY_MEMINFO */
typedef struct ibc_payload_modify_meminfo
{
	OTP_UINT32 adrs;		/* address to display (if 0, display next block */
    OTP_UINT8  width; 		/* width of displaying unit (1, 2, 4, 8) */
   	OTP_UINT32 value;		/* value of modifing memory */
}OTP_PACK_ALIGN(1) ibc_payload_modify_meminfo;

/*	�޸��豸���ڴ���Ϣ��Ӧ֡ */
typedef struct ibc_payload_modify_meminfo_ack
{
	OTP_UINT16 memlength;		/*��Ϣ������*/
	OTP_UINT8 meminfo[];		/*�ڴ���Ϣ��*/
}OTP_PACK_ALIGN(1) ibc_payload_modify_meminfo_ack;

/* ��ѯ���޸��豸���ڴ���Ϣ��Ӧ֡���ɵ���󳤶�*/
#define IBC_PAYLOAD_MEMINFO_ACK_MAX_LEN	1024

/***************************************************************************/
/*	����ͬ������֡ IBC_OPCODE_CONIFG_SYNC */
typedef struct ibc_payload_config_sync
{
	OTP_UINT16 	devt;		/*�豸����*/
	OTP_UINT8 	reserve;	/*����*/
	OTP_UINT8 	command;	/*������(1)*/
	OTP_UINT8 	data[];	/*������Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_config_sync;

/*	����ͬ����Ӧ֡ */
typedef struct ibc_payload_config_sync_ack
{
	OTP_UINT16 devt;		/*ģ������(2)*/
	OTP_UINT8 reserve;		/*�������̶�ΪIBC_CMDACK_RESERVE*/
	OTP_UINT8 commandack;	/*��Ӧ������*/
	OTP_UINT8  opreply;		/*��������ֽ�(1)*/
	OTP_UINT8 data[];		/*������Ӧ��Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_config_sync_ack;


/***************************************************************************/

/*	����ͬ��������֡ IBC_OPCODE_REQ_CONFIG_SYNC */
typedef struct ibc_payload_req_config_sync
{
	OTP_UINT16 	devt;		/*�豸����*/
	OTP_UINT8 	reserve;	/*����*/
	OTP_UINT8 	command;	/*������(1)*/
	OTP_UINT8 	data[];	/*������Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_req_config_sync;



/*	����ͬ��������Ӧ֡ */
typedef struct ibc_payload_req_config_sync_ack
{
	OTP_UINT16 devt;		/*ģ������(2)*/
	OTP_UINT8 reserve;		/*�������̶�ΪIBC_CMDACK_RESERVE*/
	OTP_UINT8 commandack;	/*��Ӧ������*/
	OTP_UINT8  opreply;		/*��������ֽ�(1)*/
	OTP_UINT8 data[];		/*������Ӧ��Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_req_config_sync_ack;


/***************************************************************************/


/*	�����֡ IBC_OPCODE_SYS_CMD*/
typedef struct ibc_payload_sys_cmd
{
	OTP_UINT16 	devt;		/*�豸����*/
	OTP_UINT8 	reserve;	/*����*/
	OTP_UINT8 	command;	/*������(1)*/
	OTP_UINT8 data[];		/*������Ϣ(0~n)*/
}OTP_PACK_ALIGN(1) ibc_payload_sys_cmd;


/*	������Ӧ֡ */
typedef struct ibc_payload_sys_cmd_ack
{
	OTP_UINT16 devt;		/*ģ������(2)*/
	OTP_UINT8 reserve;		/*�������̶�ΪIBC_CMDACK_RESERVE*/
	OTP_UINT8 commandack;	/*��Ӧ������*/
	OTP_UINT8  opreply;		/*��������ֽ�(1)*/
	OTP_UINT8 data[];		/*������Ӧ��Ϣ��0~n��*/
}OTP_PACK_ALIGN(1) ibc_payload_sys_cmd_ack;

/* ҵ����ϵͳ������ */
#define IBC_SYS_CMD_PATCH_LOAD_MODULE	0x01	/* ����ģ�� */
#define IBC_SYS_CMD_LKUP_SYMBOL			0x02	/* ���ҷ��Ŷ�Ӧ��ַ */
#define IBC_SYS_CMD_LKADDR_ENTRY		0x03	/* ���ҵ�ַ��Ӧ���� */
#define IBC_SYS_CMD_PATCH_FUNCTION		0x04	/* �������� */
#define IBC_SYS_CMD_NO_PATCH_FUNCTION	0x05	/* ȡ���������� */
#define IBC_SYS_CMD_PATCH_ENTRY			0x06	/* ��ַ���� */
#define IBC_SYS_CMD_NO_PATCH_ENTRY		0x07	/* ȡ����ַ���� */
#define IBC_SYS_CMD_SHOW_PATCH			0x08	/* ��ʾ������Ϣ */

#endif
