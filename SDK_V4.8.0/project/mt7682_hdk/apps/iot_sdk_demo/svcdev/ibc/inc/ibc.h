#ifndef _IBC_H
#define _IBC_H

typedef STATUS (*xxx_msg_send)(OTP_UINT8 *pbur, OTP_UINT32 sendlen);

/*�ӻ�����ĶԶ�ͨ��ģ��������*/
/*lijingfang 2009/02/03*/
/*����ͨ�Ŷ���*/
typedef	enum	_comm_object
{
	comm_to_uart1,	
	comm_to_uart2,	
	comm_to_uart3
}comm_object;

/*����ͨ����Դ�������Ϣ*/
typedef	struct _comm_source_info
{
	xxx_msg_send	send;	/*��Ϣ��Ӧ�ķ��ͺ���*/
	comm_object		comm_obj;	/*ͨ�Ŷ���*/
}comm_source_info;


/*****************************************************************************
*ibc_init_all		ibc��ʼ������
*Input:
*     protocol  -- ibcʹ�õ�Э������
*	uartid	--ibcʹ�õĴ��ڱ�ţ�0��1��
**Output:
*	None
*Return:
*	OK			--��ʾִ�гɹ�
*	ERROR		--��ʾִ�д���
*/
STATUS ibc_init_all(uart_protocol_type protocol, OTP_UINT8 uartid);


#endif

