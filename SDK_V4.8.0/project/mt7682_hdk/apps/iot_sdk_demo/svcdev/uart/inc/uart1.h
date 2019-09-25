#ifndef _UART1_H
#define _UART1_H


/*���ջ��峤��*/
#ifndef UART1_RCV_BUFLEN
#define UART1_RCV_BUFLEN		1024
#endif
/*���ͻ��峤��*/
#ifndef UART1_SEND_BUFLEN
#define UART1_SEND_BUFLEN		1024
#endif



/***************************************************************************
��������
***************************************************************************/

/******************************************************************************************
*uart1_rs232_init		--���ڳ�ʼ������
*--
*Input:
*	prt	--Э������
*	rcv --��Ϣ���պ���
*Output:
*	��
*Return:
*	OK/ERROR	��ʾִ�гɹ����
*
*/
STATUS uart1_rs232_init(uart_protocol_type prt, 
							uart_rcv_func rcv,
							uart_rcv_func opttypercv);

/*******************************************************************************
*uart1_rcv_process  ���ձ��Ĵ���������Ӧ��Э�飬�Խ��ջ������ı��Ľ��д���������
*		ע���rcv��������
*Input:
*	None
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart1_rcv_process(void);


/*******************************************************************************
*uart1_msg_send ���ͱ��Ĵ���
*Input:
*	psinfo	--���ͻ�����ָ�룬���ڴ�ŷ��͵���Ϣ��
*	buf		--��Ҫ���͵�����ָ��
*	buflen	--���͵����ݳ���
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart1_msg_send(const OTP_UINT8 *buf, OTP_UINT32 buflen);


#endif

