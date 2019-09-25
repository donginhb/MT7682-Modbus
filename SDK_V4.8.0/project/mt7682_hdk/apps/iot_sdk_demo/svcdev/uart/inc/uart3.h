#ifndef _UART3_H
#define _UART3_H

/*���ͻ���������*/
#ifndef UART3_RCV_BUFLEN
#define UART3_RCV_BUFLEN		1024
#endif
/*���ջ���������*/
#ifndef UART3_SEND_BUFLEN
#define UART3_SEND_BUFLEN		1024
#endif

/***************************************************************************
��������
***************************************************************************/
/******************************************************************************************
*uart3_init		--���ڳ�ʼ������
*--
*Input:
*	��
*Output:
*	��
*Return:
*	OK/ERROR	��ʾִ�гɹ����
*
*/
STATUS uart3_init(void);

/******************************************************************************************
*uart3_rs232_init		--���ڳ�ʼ������
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
STATUS uart3_rs232_init(uart_protocol_type prt, 
						uart_rcv_func rcv,
						uart_rcv_func opttypercv);



/*******************************************************************************
*uart3_rcv_process  ���ձ��Ĵ���������Ӧ��Э�飬�Խ��ջ������ı��Ľ��д���������
*		ע���rcv��������
*Input:
*	None
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart3_rcv_process(void);


/*******************************************************************************
*uart3_msg_send ���ͱ��Ĵ���
*Input:
*	buf		--��Ҫ���͵�����ָ��
*	buflen	--���͵����ݳ���
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart3_msg_send(const OTP_UINT8 *buf, OTP_UINT32 buflen);


#endif


