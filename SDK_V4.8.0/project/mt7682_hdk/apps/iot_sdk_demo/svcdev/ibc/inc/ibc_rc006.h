
#ifndef _IBC_RC006_H
#define _IBC_RC006_H

/*RC006Э��IBCģ��ʹ�õĻ������ڸ���ҵ��ģ�����ݴ��*/
#ifndef IBC_RC006_MSG_BUF_LEN
#define IBC_RC006_MSG_BUF_LEN		1024
#endif

/*rc006Э��ͷ����չЭ��ͷ����󳤶�*/
#define IBC_RC006_MSG_HEAD_LEN_MAX	30

/*������Ч��ͬ����*/
#define IBC_INVALID_SYNCID 16

typedef struct ibc_msg_rc006
{
	struct
	{
		OTP_UINT8 framflag;	/*��ʼ�ַ�*/
#ifdef OTP_LITTLE_ENDIAN
		OTP_UINT8 hlenleft:5;/*Э��ͷ�ֽ�������framflag��Э��ͷ���һ���ֽ�*/
		OTP_UINT8 ver:3;	/*Э��汾��*/
#else
		OTP_UINT8 ver:3;	/*Э��汾��*/
		OTP_UINT8 hlenleft:5;/*Э��ͷ�ֽ�������framflag��Э��ͷ���һ���ֽ�*/
#endif

		OTP_UINT16 dlenleft; /*���ݰ���̳����ֽ���������һ���ֽڿ�ʼ��У���*/
		
		OTP_UINT8 destslot;	/*Ŀ�Ĳ�λ��*/
		OTP_UINT8 destmod;	/*Ŀ��ģ���*/
		OTP_UINT8 srcslot;	/*Դ��λ��*/
		OTP_UINT8 srcmod;	/*Դģ���*/
		
		union{
				OTP_UINT16	id;	/*���к���ֵ*/
				
				/*Ϊ���к����ľ������*/
				struct{
					OTP_UINT8 win;	/*�������к�*/
					OTP_UINT8 sync;	/*ͬ����Ϣ��*/
				}OTP_PACK_ALIGN(1)p;
		}OTP_PACK_ALIGN(1)s;
		/*��Ӧ���к�*/
		union{
				OTP_UINT16	id;	/*���к���ֵ*/
				
				/*Ϊ���к����ľ������*/
				struct{
					OTP_UINT8 win;	/*�������к�*/
					OTP_UINT8 sync;	/*ͬ����Ϣ��*/
				}OTP_PACK_ALIGN(1)p;
		}OTP_PACK_ALIGN(1)sack;

	}OTP_PACK_ALIGN(1)head;	
	
	/*��������Ҳ�Ǿ���*/
	OTP_UINT8 data[];		/* !! ���������һ���ֶ�,�ҽ���head*/
	
}OTP_PACK_ALIGN(1)ibc_rc006_msg;

#define swinseq 		s.p.win
#define swinseqack 		sack.p.win
#define ssyncid 		s.p.sync
#define ssyncidack 		sack.p.sync

/*ibc_msg�ṹ��data�ֶ�����ڽṹ��ַ��ƫ����*/
#define IBC_DATA_OFFSET	((OTP_UINT32)(&((ibc_rc006_msg*)0)->data))

/*ibc_msg�ṹ��head�ֶ�����ڽṹ��ַ��ƫ����*/
#define IBC_HEAD_OFFSET	((OTP_UINT32)(&((ibc_rc006_msg*)0)->head))

/*
	V1����ͨ��Э��ͷ�̶��ֶγ���
*/
#define IBC_HEAD_LEN_V1_FIX		/*lint -save -e545 -e413 -e737*/( IBC_DATA_OFFSET - IBC_HEAD_OFFSET )/*lint -restore*/


/*

��IBC���鱨�ĵĴ������
	0x00	������Ӧ
	0x01	��֧�ֵ�Э��汾
	0x02	���Ⱥ�У��ʹ�
*/
#define IBC_PACKET_OK				0x00
#define IBC_PACKET_ERROR_VERSION	0x01
#define IBC_PACKET_ERROR_LEN_CRC	0x02


/*���ͨ����ʼ�ַ� 10010101*/
#define IBC_FRAME_FLAG		0X95

/*���ͨ�Ű汾�� 001*/
#define IBC_VERSION		0x01

/*Э��ͷȫ����Э��ͷ��hlenleft�ֶ�ֵ��ת��*/
#define IBC_HLENLEFT2HEADLEN(hlenleft) ((hlenleft)+2)
#define /*lint -save -e545 -e413*/IBC_HEADLEN2HLENLEFT(headlen) ((headlen)-2)/*lint -restore*/

/*����ȫ����Э��ͷ��dlenleft�ֶ�ֵ��ת��*/
#define IBC_DLENLEFT2DATALEN(dlenleft) ((dlenleft)+4)
#define IBC_DATALEN2DLENLEFT(datalen) ((datalen)-4)

typedef struct _ibc_last_msg_info
{
	OTP_UINT8 lsseq;	
	OTP_UINT8 lsscid;
	OTP_UINT8 lrseq;
	OTP_UINT8 lrscid;
}ibc_last_msg_info;


typedef OTP_UINT8* IBC_DATA;
typedef OTP_UINT8* IBC_MSG;



/*�����䱨�Ŀ��ʱ�򷵻�������ͣ�ʵ����IBC��Ϣͷָ��*/
typedef OTP_UINT8* IBC_PACKET;

/*ע����IBC��ģ���*/
#define IBC_INVALID_MOD		0	/*��Чģ���*/
#define IBC_MOD_ADAPTER		1	/*�����*/

/* �����ϢCRC�ֶε��ֽ��� */
#define IBC_CRC_LEN_V1	1


typedef struct _ibc_adp_info
{
	/*�����Ƿ����������أ���ҵ������*/
	BOOL	isloopback;
}ibc_adp_info;


/*
	ҵ�����ϵ�ҵ��ģ�鴦��������̻�ֶ�ҵ���̷��������ݵĺ�����
	�������:
		arg			�Զ������
		msg,		ԭʼ��Ϣ���������Ҫֱ�Ӵ�����Ϣ������������
					������ֵΪOKʱ�����ͷţ��������ͷš�
		slot,	 	���յ�����Ϣ��Դ��λ��
		prid,		���յ���Ϣ��Զ���豸��ʶ����
		opcode,		����������
		data,		������Ϣ����(Э��ľ��ɲ���)�������ͷš�
		datalen,	data����Ч���ݵĳ���
	����ֵ:
		OK,			������������msg��Ϣ���ڷ���ǰ�Ѿ��ͷ���msg,IBC�����ģ�鲻�����ͷŸ���Ϣ
		ERROR,		������û������msg��Ϣ���ڷ��غ���IBC�����ģ���ͷ�msg��Ϣ
*/
typedef STATUS (*xxx_proc_nms_msg)(OTP_VOID *arg, IBC_MSG ibcmsg,const rdev_rid* prid,OTP_UINT8 opcode,
						const OTP_UINT8 *data,OTP_UINT32 datalen, OTP_UINT8 *pack, OTP_UINT32 acklen);



/**********************************************************************************
��������
*/

/**********************************************************************************
*	��ҵ�����������̷���ͬ����Ϣ����Ӧ��Ϣ��������Ŀ�Ĳ�λ����0
*	�������:
*		arg			�����͵�ָ�룬���ڴ��ݷ�����Ҫʹ�õĺ���ָ�룬�û�����Ҫ���
*		srcmsg,		�յ���ԭʼ��Ϣ����������Ӧ��Ϣ������Ӧ���кźʹ��ں�
*		prid,		��չЭ��ͷ�е�Զ���豸��ʶ,
*					���ΪNULL����������Ϊ0��
*					������ָ����������װ��չЭ��ͷ
*		exrsp,		����Ӧ��Ϣ�о�����չ��Ӧ��
*		data,		���ɿ飬�������������롢��д���ͷţ�
*		datalen,	data����Ч���ݵĳ���
*		
*		srcslot,	ֻ�ڷ��滷�������ã���ʾ���͵�Դ��λ��
*		
*	����ֵ:
*		OK,			��Ϣ�ɹ����뷢�Ͷ���
*		ERROR,		��Ϣû�н��뷢�Ͷ���
*/
STATUS ibcadp_send(const OTP_VOID *arg,IBC_MSG srcmsg,const rdev_rid* prid,OTP_UINT8 exrsp,const OTP_UINT8 *data,OTP_UINT32 datalen);

/*********************************************************************************
*	������������ҵ��ģ��ͬ�����Ͱ����Ϣ��
*	�������:
*		arg	,�Զ�����������ݷ��ͱ���ʹ�õĺ���
*		destslot,	Ŀ�Ĳ�λ��
*		prid,		Զ���豸��ʶָ�룬ΪNULL������Ϊ0��ʱ���ʾ���͸��ֶ˵��̣��������������롢��д���ͷš�
*		opcode,		����������
*		data,		������Ϣ����(Э���еľ���)���������������롢��д���ͷš�
*					���û������Ҫ���ͣ���NULL��
*		datalen,	data����Ч���ݵĳ��ȡ����û������Ҫ���ͣ���0��
*		prcvlen,	ͬʱ�����������������������Ҫ������ɣ�����ΪNULL��
*					���ú�����ʱ��(*prcvlen)��ʾrcvbuf�ĳ��ȣ�
*					�����ȴ���0��ʱ���ʾ������ϣ���õ���Ӧ��Ϣ�ľ��ɣ�����������ɡ�
*		priority,	�������ȼ���IBC_PRIORITY_PREMIER��IBC_PRIORITY_HIGH��IBC_PRIORITY_LOW
*		timeout,	��ʱtick��,����0,ʱ��Ϊ��������������Ϣ�Ժ����𣬳�ʱʱ�䲻�������Ͷ��д���ʱ�䡣
*	�������:
*		rcvbuf,		�������ݻ�����
*					����������������ͷţ��������ڲ���д���������Ҫ������ɣ�����ΪNULL
*		prcvlen,	ͬʱ�����������������������Ҫ������ɣ�����ΪNULL��
*					�������ص�ʱ��(*prcvlen)��ʾ������ʵ�ʿ�����rcvbuf�����ݳ���
*		pexrsp,		*pexrsp��Ϊ������Ϣ�е���չ��Ӧ�֣���������߲����������pexrsp����ΪNULL
*	����ֵ:
*		OK,			ͬ�����ͳɹ������rcvbuf��Ϊ�գ������Ѿ����˷��ص����ݡ�
*		IBC_ERROR_INNER	���ݴ�����Դ�����ȴ���
*		IBC_ERROR_QUEUE_FULL ���Ͷ�����
*		IBC_ERROR_INVALID_DATA ������Ч
*		IBC_ERROR_FAILED_SENDING ����ʧ��
*		IBC_ERROR_NO_REPLY ����Ӧ
*		IBC_ERROR_BAD_REPLY ��Ӧ�����д�
*		IBC_ERROR_LOOPBACK �����˰����Ϣ���أ��Ͳ����ϲ㴫�ݷ��صı�����
*/
STATUS ibcadp_send_sync(const OTP_VOID *arg, OTP_UINT8 destslot,const rdev_rid* prid,OTP_UINT8 opcode,
							OTP_UINT8 *data,OTP_UINT32 datalen,	OTP_INT32 timeout);

/********************************************************************************
*ibc_msg_rcv_rc006 --RC006Э����ձ��Ĵ�����
*Input:
*	arg			--�Զ�����������ݷ��ͱ���ʹ�õĺ���
*	pbuf		--���յ��ı���ͷָ��	
*	len			--���յı��ĳ���
*Output:
*	None
*Return:
*	OK			--��ʾִ�гɹ�
*	ERROR		--��ʾִ�д���
*/
STATUS ibc_msg_rcv_rc006(OTP_VOID *arg,OTP_UINT8 *pbuf, OTP_UINT16 len);


/*****************************************************************************
*ibc_rc006_init		ibc��ʼ������
*
*/
OTP_VOID ibc_rc006_init(void);

#endif

