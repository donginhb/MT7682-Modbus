#ifndef _UART2_H
#define _UART2_H

/*���ͻ���������*/
#ifndef UART2_RCV_BUFLEN
#define UART2_RCV_BUFLEN		1024
#endif
/*���ջ���������*/
#ifndef UART2_SEND_BUFLEN
#define UART2_SEND_BUFLEN		1024
#endif



/***************************************************************************
��������
***************************************************************************/
/******************************************************************************************
*uart2_init		--���ڳ�ʼ������
*--
*Input:
*	��
*Output:
*	��
*Return:
*	OK/ERROR	��ʾִ�гɹ����
*
*/
STATUS uart2_init(void);

/******************************************************************************************
*uart2_rs232_init		--���ڳ�ʼ������
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
STATUS uart2_rs232_init(uart_protocol_type prt, 
						uart_rcv_func rcv,
						uart_rcv_func opttypercv);



/*******************************************************************************
*uart2_rcv_process  ���ձ��Ĵ���������Ӧ��Э�飬�Խ��ջ������ı��Ľ��д���������
*		ע���rcv��������
*Input:
*	None
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart2_rcv_process(void);


/*******************************************************************************
*uart2_msg_send ���ͱ��Ĵ���
*Input:
*	buf		--��Ҫ���͵�����ָ��
*	buflen	--���͵����ݳ���
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart2_msg_send(const OTP_UINT8 *buf, OTP_UINT32 buflen);


#endif


