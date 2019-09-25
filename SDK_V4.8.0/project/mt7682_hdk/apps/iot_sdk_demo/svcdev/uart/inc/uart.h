#ifndef _UART_H
#define _UART_H


/*�˿ں�*/
enum
{
	UART1_ID = 0,
	UART2_ID = 1,
	UART3_ID = 2,	
	UARTIDMAX = 3,
};

#if  (UART1_REMAP_MODE == 0)
#define 	UART1_PORT 		PORTA	/*TXD1�Ƕ˿�PA*/
#define 	UART1_TXD_PIN 		9		/*TXD1������PA9*/
#define 	UART1_RXD_PIN	 	10		/*RXD1������PA10*/
#else
#define 	UART1_PORT 		PORTB	/*TXD1�Ƕ˿�PB*/
#define 	UART1_TXD_PIN 		6		/*TXD1������PB6*/
#define 	UART1_RXD_PIN	 	7		/*RXD1������PB7*/
#endif

#if  (UART2_REMAP_MODE == 0)
#define 	UART2_PORT 		PORTA	/*TXD2�Ƕ˿�PA*/
#define 	UART2_TXD_PIN 		2		/*TXD2������PA2*/
#define 	UART2_RXD_PIN	 	3		/*RXD2������PA3*/
#else
#define 	UART2_PORT 		PORTD	/*TXD2�Ƕ˿�PD*/
#define 	UART2_TXD_PIN 		5		/*TXD2������PD5*/
#define 	UART2_RXD_PIN	 	6		/*RXD2������PD6*/
#endif

#if  (UART3_REMAP_MODE == 0)
#define 	UART3_PORT 		PORTB	/*TXD3�Ƕ˿�PB*/
#define 	UART3_TXD_PIN 		10		/*TXD3������PB10*/
#define 	UART3_RXD_PIN	 	11		/*RXD3������PB11*/
#elif  (UART3_REMAP_MODE == 1)
#define 	UART3_PORT 		PORTC	/*TXD3�Ƕ˿�PC*/
#define 	UART3_TXD_PIN 		10		/*TXD3������PC10*/
#define 	UART3_RXD_PIN	 	11		/*RXD3������PC11*/
#elif  (UART3_REMAP_MODE == 3)
#define 	UART3_PORT 		PORTD	/*TXD3�Ƕ˿�PD*/
#define 	UART3_TXD_PIN 		8		/*TXD3������PD8*/
#define 	UART3_RXD_PIN	 	9		/*RXD3������PD9*/
#endif

/*�����ʶ���*/
enum
{
	UART_BAUD_300 		= 300,
	UART_BAUD_600 		= 600,
	UART_BAUD_1200 		= 1200,
	UART_BAUD_2400 		= 2400,
	UART_BAUD_4800 		= 4800,
	UART_BAUD_9600 		= 9600,
	UART_BAUD_14400 	= 14400,
	UART_BAUD_19200 	= 19200,
	UART_BAUD_38400		= 38400,
	UART_BAUD_57600		= 57600,
	UART_BAUD_115200	= 115200,
};

/*��������λ����*/
enum
{
	UART_DATAB_5BIT		= 5,
	UART_DATAB_6BIT		= 6,
	UART_DATAB_7BIT		= 7,
	UART_DATAB_8BIT		= 8,
	UART_DATAB_9BIT		= 9,	
};

/*����ֹͣλ*/
enum
{
	UART_STOPB_1BIT = 1,
	UART_STOPB_2BIT = 2,
};

/*У��*/
enum
{
	UART_PARITY_NONE,
	UART_PARITY_ODD,
	UART_PARITY_EVEN,
	UART_PARITY_FONE,
	UART_PARITY_FZERO,
};

#define UART_VALID_UID(id) ((id)<UARTIDMAX)
#define UART_VALID_BARD(baud) (((baud) >= UART_BAUD_300)&&((baud)<= UART_BAUD_115200))
#define UART_VALID_DATAB(datab) (((datab) >= UART_DATAB_5BIT) && ((datab) <= UART_DATAB_9BIT))
#define UART_VALID_STOPB(stopb) (((stopb) >= UART_STOPB_1BIT) && ((stopb) <= UART_STOPB_2BIT))
#define UART_VALID_PARITY(parity) ((parity) <= UART_PARITY_FZERO)

/*����˿�����ָ��ĺϷ���*/
#define UART_VALID_PCFG(pcfg) ((pcfg)&&UART_VALID_BARD(pcfg->baud) \
	&&UART_VALID_DATAB(pcfg->datab)&&UART_VALID_STOPB(pcfg->stopb)	\
	&&UART_VALID_PARITY(pcfg->parity))

/*���ݼĴ���*/
#define UXDR(ureg) 			((ureg)->DR)
#define UXDR_SET(ureg, val) 	((ureg)->DR = (val))

/*״̬�Ĵ���*/
#define UXSR(ureg) 			((ureg)->SR)

/*�����ʼĴ���*/
#define UXBRR(ureg) 			((ureg)->BRR)

/*���ƼĴ���1����������λ,У��λ,���ͽ���ʹ��,�ж�ʹ��*/
#define UXCR1(ureg) 			((ureg)->CR1)

/*���ƼĴ���2������ֹͣλ,*/
#define UXCR2(ureg) 			((ureg)->CR2)

/*���ƼĴ���3�����ð�˫��ģʽʹ��,*/
#define UXCR3(ureg) 			((ureg)->CR3)

/*����ʱ���Ԥ��Ƶ�Ĵ���������Prescalerֵ*/
#define UXGTPR(ureg) 		((ureg)->GTPR)


#define UART_RCV_TEMPBUF_LEN	256



/*���巢�ͺͽ�������ʱʹ�õ�Э������*/
typedef enum _uart_protocol_type
{
	UART_PRTTYPE_002,
	UART_PRTTYPE_004,
	UART_PRTTYPE_006,
	UART_PRTTYPE_CONSOLE,
	UART_PRTTYPE_OPTTYPE,	
	UART_PRTTYPE_INVALID,
}uart_protocol_type;

/*ע��Ľ��մ���������*/
/****************************************************************************
*arg:  �����Զ������,���ﶨ��Ϊ
*
*
*/
typedef STATUS (*uart_rcv_func)(OTP_VOID *arg, uart_protocol_type prt, OTP_UINT8 *pbuf, OTP_UINT16 len, OTP_UINT8 version);


#ifdef INCLUDE_OPTTYPE

/*��Ҫͨ��ibc�洢��ͷ����*/
typedef struct S_OPTTYPE_PAYLOAD_STRUCT
{
#ifdef OTP_LITTLE_ENDIAN

	OTP_UINT8	typeClass:7;	/*��������*/
	OTP_UINT8	reserved_1:1;	/*У��λ,������*/

	OTP_UINT8	typeHigh:4;		/*��������*/
	OTP_UINT8	reserved_2:4;	/*У��λ,������*/
	
	OTP_UINT8	typeLow:4;		/*��������*/
	OTP_UINT8	reserved_3:4;	/*У��λ,������*/

	
#else 							/*wangzaizhong  20081201 �޸�*/
	OTP_UINT8	reserved_1:1;	/*У��λ,������*/
	OTP_UINT8	typeClass:7;	/*��������*/

	OTP_UINT8	reserved_2:4;	/*У��λ,������*/
	OTP_UINT8	typeHigh:4;		/*��������*/	
	
	OTP_UINT8	reserved_3:4;	/*У��λ,������*/
	OTP_UINT8	typeLow:4;		/*��������*/
	
#endif

}OTP_PACK_ALIGN(1)S_OPTTYPE_PAYLOAD;



#define		UART_OPTTYPE_SLOT_POS			0
#define		UART_OPTTYPE_IDENTYFY_POS		1
#define		UART_OPTTYPE_LEN_POS			2
#define		UART_OPTTYPE_DATA_POS			5
#define		UART_OPTTYPE_EXTIDENTIFY_POS	8
#define		UART_OPTTYPE_EXTDENTIFY_LEN		15

#define		UART_OPTTYPE_LEN_EXCLUDE_BYTE	3
#define		UART_OPTTYPE_SLOT_MASK			0xf
#define		UART_OPTTYPE_LEN_MASK			0x3f

#define		UART_OPTTYPE_IDENTIFY			0xfe
#define		UART_OPTTYPE_LEN_DEFAULT		0x05

#define		UART_OPTTYPE_DATA_LEN			22	/*֧��4����*/
typedef struct _uart_opttype_buf
{
	OTP_UINT8				data[UART_OPTTYPE_DATA_LEN];
	OTP_UINT8				len;
	OTP_UINT8				ucnt;
	OTP_UINT32		 		rtime;	
	uart_rcv_func			rcv;	/*���ձ��Ĵ�����*/	
}OTP_PACK_ALIGN(1)uart_opttype_buf;

#endif

/*���崮�ڴ����һЩ��־*/
typedef struct _uart_buf_flag
{
	OTP_UINT8 rsvd:7;
	OTP_UINT8 bufof:1;/*�ݴ�����*/
}OTP_PACK_ALIGN(1)uart_buf_flag;


/*�ݴ滺����*/
typedef struct _uart_rcv_tempbuf
{
	OTP_UINT16	pinput; 	/*���ջ��������ָ��ֵ*/
	OTP_UINT16	poutput;	/*���ջ��������ָ��ֵ*/
	OTP_UINT8	buf[UART_RCV_TEMPBUF_LEN];
}OTP_PACK_ALIGN(1)uart_rcv_tempbuf;

/*���մ�������*/
typedef struct _uart_rcv_procbuf
{
	OTP_UINT16	outcnt;		/*������ֽ���*/
	OTP_UINT16	pktlen;		/*Э�鱨�ĵĳ���*/
	OTP_UINT16	datalen;	/*�������ĳ���*/
	OTP_UINT8	*pdata;		/*������ָ��*/
	uart_rcv_func	rcv;	/*���ձ��Ĵ�����*/
}OTP_PACK_ALIGN(1)uart_rcv_procbuf;


typedef struct _uart_rcv_info
{
	OTP_UINT32		rtime;	/*����ʱ�䶨�壬��¼�ϴ��ֽڽ���ʱ��*/
	uart_buf_flag   	flag;
	uart_rcv_tempbuf 	rtbuf;	/*�ݴ滺������Ϣ*/
	uart_rcv_procbuf 	rproc;	/*���Ĵ�������*/
	OTP_UINT16		errpkt;		/*���մ����ļ���*/
#ifdef INCLUDE_OPTTYPE
	uart_opttype_buf	opttype;
#endif	
}uart_rcv_info;

/*���ջ�����*/


/*���ͻ�����*/
typedef struct _uart_send_info
{
	BOOL		sending;	/*��ʾ�Ƿ�ʼ���ͻ���������*/
	OTP_UINT16 	pinput;		/*���ջ��������ָ��ֵ;��Χ0~datalen-1*/
	OTP_UINT16 	poutput;	/*���ջ��������ָ��ֵ;��Χ0~datalen-1*/
	OTP_UINT16	datalen;	/*�������ĳ���*/
	OTP_UINT8	*pdata;		/*������ָ��*/
	uart_buf_flag   flag;
}uart_send_info;


/*�ӿ��������ݽṹ*/
typedef struct _uart_config_struct
{
	OTP_UINT32 baud; /*������*/
	OTP_UINT8 datab;	/*����λ����Чֵ:5,6,7,8*/
	OTP_UINT8 stopb;	/*ֹͣλ��1������2��,����ֵΪ2������databΪ5ʱ��ʾ1.5��ֹͣλ*/
	OTP_UINT8 parity;	/*0--��У�飬1--��У�飬2--żУ�飬3--ǿ��Ϊ1��4--ǿ��Ϊ0*/
}uart_config_struct;



/*��ʼ��uart�˿�ʹ�õ����ݽṹ*/
typedef struct _uart_init_param
{
	uart_config_struct  cfg;	/*�ӿ�����*/
	uart_protocol_type	prt;/*���պͷ��ͱ������õ�Э������*/
	uart_rcv_func		rcv; /*ע��Ľ��մ�����*/
}uart_init_param;



typedef struct _uart_info
{
	uart_protocol_type prt;
	uart_rcv_info 	rinfo;
	uart_send_info	sinfo;
	OTP_VOID	*arg;		/*�Զ���ָ��*/
}uart_info;

/*rc002Э�鴦����*/
#define UART_RC002DELIMITER_POS		0	/*������ڱ����е�λ��*/
#define UART_RC002VERMARK_POS			1	/*Э��汾��ʶ��λ��*/
#define UART_RC002PKT_LENORTYPE_POS	2	/*���ĳ��Ȼ��豸�����ֽ�*/
#define UART_RC002PKT_LEN_LOW_POS	3	/*���ĳ��ȵ��ֽ�*/
#define UART_RC002PKT_RMC_LEN_LOW_POS	4	/*Эת��ʽ���ĳ��ȵ��ֽ�*/
#define UART_RC002PKT_RMC_LEN_HIH_POS	5	/*Эת��ʽ���ĳ��ȸ��ֽ�*/

/*rc006Э�鴦����*/
#define UART_RC006_DELIMITER	0x95
#define	UART_RC006_HLENLEFT		10
#define UART_RC006_VER			0x01
#define UART_RC006_HEADLEN		12

#define UART_RC006DELIMITER_POS		0/*������ڱ����е�λ��*/
#define UART_RC006DVERLEN_POS		1/*Э��汾��Э��ͷ���ȵ�λ��*/
#define UART_RC006PKTLEN_HI_POS		2/*���ĳ��ȸ��ֽ�*/
#define UART_RC006PKTLEN_LOW_POS	3/*���ĳ��ȵ��ֽ�*/

#define UART_RC006PKTLEN_MIN	8/*������С����*/

/*rc006���İ汾��Э��ͷʣ�೤�ȣ�С�˶���*/
typedef struct _uart_rc006_verlen
{
#ifdef OTP_LITTLE_ENDIAN
	OTP_UINT8 hlenleft:5;/*Э��ͷ�ֽ�������framflag��Э��ͷ���һ���ֽ�*/
	OTP_UINT8 ver:3;	/*Э��汾��*/
#else
	OTP_UINT8 ver:3;	/*Э��汾��*/
	OTP_UINT8 hlenleft:5;/*Э��ͷ�ֽ�������framflag��Э��ͷ���һ���ֽ�*/
#endif
}OTP_PACK_ALIGN(1)uart_rc006_verlen;

#define UART_RCV_TIMEOUT	100	/*50ms*/



extern STATUS svc_uart_send_enable(OTP_UINT8 uid);
extern STATUS svc_uart_send_disable(OTP_UINT8 uid);




/*****************************************************************************
			��������
*****************************************************************************/


/******************************************************************************************
*uart_init		--���ڳ�ʼ������
*--
*Input:
*	uid		--���ںţ��Ϸ�ֵΪ0����1
*	pcfg	--���ڵĳ�ʼ������
*Output:
*	��
*Return:
*	OK/ERROR	��ʾִ�гɹ����
*
*/
STATUS uart_port_init(OTP_UINT8 uid,const  uart_config_struct *pcfg);


/****************************************************************************
* --uart_interrupt() UART0�жϷ������
* Input:
*	uid --���ڱ��
*	pinfo --������Ϣ����ṹָ��
*Output:
*	None
*Return:
*	None
*/
OTP_VOID uart_interrupt(OTP_UINT8 uid, uart_info *pinfo);


/*******************************************************************************
*uart_rcv_process  ���ձ��Ĵ���������Ӧ��Э�飬�Խ��ջ������ı��Ľ��д���������
*		ע���rcv��������
*Input:
*	prt		--���Ĵ���ʹ�õ�Э�飬����Э�����ͽ��б��Ľ��գ�
*	prinfo	--���ջ����������Ϣָ�룻
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart_rcv_process(OTP_VOID *arg, uart_protocol_type prt, uart_rcv_info *prinfo);


/*******************************************************************************
*uart_msg_send ���ͱ��Ĵ���
*Input:
*	uid		--�������ݵ�URAT�˿ں�
*	pinfo 	--������Ϣ����ṹָ��
*	buf		--��Ҫ���͵�����ָ��
*	buflen	--���͵����ݳ���
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart_msg_send(OTP_UINT8 uid, uart_info *pinfo,const  OTP_UINT8 *buf, OTP_UINT32 buflen);




#endif


