#ifndef _UART_COMMON_H
#define _UART_COMMON_H


/********************************************************************************************************************/
/********************************************************************************************************************/

#define UART_RCV_TEMPBUF_LEN	256


/*�˿ں�*/
enum
{
	UART1_ID = 0,
	UART2_ID = 1,
	UART3_ID = 2,	
	UARTIDMAX = 3,
};


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
typedef STATUS (*uart_rcv_func)(OTP_VOID *arg, uart_protocol_type prt, OTP_UINT8 *pbuf, OTP_UINT16 datalen, OTP_UINT8 funcversion);


/*���崮�ڴ����һЩ��־*/
typedef struct _uart_buf_flag
{
	OTP_UINT8 rsvd:7;
	OTP_UINT8 bufof:1;/*�ݴ�����*/
}uart_buf_flag;


/*�ݴ滺����*/
typedef struct _uart_rcv_tempbuf
{
	OTP_UINT16	pinput; 	/*���ջ��������ָ��ֵ*/
	OTP_UINT16	poutput;	/*���ջ��������ָ��ֵ*/
	OTP_UINT8	buf[UART_RCV_TEMPBUF_LEN];
}uart_rcv_tempbuf;

/*���մ�������*/
typedef struct _uart_rcv_procbuf
{
	OTP_UINT16	outcnt;		/*������ֽ���*/
	OTP_UINT16	pktlen;		/*Э�鱨�ĵĳ���*/
	OTP_UINT16	datalen;	/*�������ĳ���*/
	OTP_UINT8	*pdata;		/*������ָ��*/
	uart_rcv_func	rcv;	/*���ձ��Ĵ�����*/
}uart_rcv_procbuf;


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



typedef struct _uart_info
{
	uart_protocol_type prt;
	uart_rcv_info 	rinfo;
	uart_send_info	sinfo;
	OTP_VOID	*arg;		/*�Զ���ָ��*/
}uart_info;



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
}uart_rc006_verlen;

#define UART_RCV_TIMEOUT	100	/*50ms*/



/*****************************************************************************
			��������
*****************************************************************************/

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

/********************************************************************************************************************/
/********************************************************************************************************************/


#endif

