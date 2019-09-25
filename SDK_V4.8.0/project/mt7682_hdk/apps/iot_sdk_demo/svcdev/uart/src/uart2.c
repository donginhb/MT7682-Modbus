/****************************************************************
	Copyright(C), 1999-2004 Raisecom, Inc.
	filename: uart2.c������0���������ļ�
	Author	: qiaoqiangguo
	version	: 1.0
	date	: 2008/6/21
	Others	:
        THIS DOCUMENT IS GENERATED BY TORNADO TOOLS refgen.exe
        EXAMPLE:
        ->torVars.bat
        ->refgen -mg -out doc uart2.c
        ->cd doc
        ->htmllink
*****************************************************************/
#include "otpconfig.h"

#ifdef INCLUDE_UART2 

#include "string.h"
#include "macro_common.h"
#include "stm32f10x.h"
#include "misc.h"
#include "uart.h"
#include "uart2.h"
#include "ibc.h"

OTP_UINT8	g_uart2_rcv_buf[UART2_RCV_BUFLEN];
OTP_UINT8	g_uart2_send_buf[UART2_SEND_BUFLEN];
uart_info 	g_uart2_info;

#ifdef	INCLUDE_OPPOSITE_COMM
comm_source_info g_uart2_comm_src_info;
#endif

/*****************************************************************************
** Function name:		USART2_IRQHandler
**
** Descriptions:		UART2 interrupt handler
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void USART2_IRQHandler(void) 
{
	uart_interrupt(UART2_ID, &g_uart2_info);
}

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
STATUS uart2_init(void)
{
	uart_config_struct cfg = UART2_CFG_PARA;
	NVIC_InitTypeDef NVIC_InitStructure;  
	memset(&NVIC_InitStructure,0,sizeof(NVIC_InitStructure));
	
	/*���ô��ڳ�ʼ���������ô���*/
	if(uart_port_init(UART2_ID, &cfg) != OK)
	{
		return ERROR;
	}

	 /* Enable the uart2 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = (OTP_UINT8)USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = UART2_Preemption_Priority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = UART2_Sub_Priority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = Enable;
	NVIC_Init(&NVIC_InitStructure);
	
	return OK;
}

/******************************************************************************************
*uart2_rs232_init		--���ڳ�ʼ������
*--
*Input:
*	prt	--Э������
*	rcv --��Ϣ���պ���
*	opttypercv --��ͷ������д��Ϣ���պ���
*Output:
*	��
*Return:
*	OK/ERROR	��ʾִ�гɹ����
*
*/
STATUS uart2_rs232_init(uart_protocol_type prt, 
						uart_rcv_func rcv,
						uart_rcv_func opttypercv)
{

	/*�����ݽṹ*/
	memset(&g_uart2_info, 0, sizeof(g_uart2_info));

	/*��¼���Ĵ���Э��*/
	g_uart2_info.prt = prt;
	/*��¼���ձ��Ĵ�������*/
	g_uart2_info.rinfo.rproc.rcv = rcv;

#ifdef INCLUDE_OPTTYPE
	g_uart2_info.rinfo.opttype.rcv = opttypercv;
#else
	NO_USE(opttypercv);
#endif

#ifdef INCLUDE_OPPOSITE_COMM
	/*��Ӧ��Ϣ�ķ��ͺ���*/
	g_uart2_comm_src_info.send = (xxx_msg_send)uart2_msg_send;
	g_uart2_comm_src_info.comm_obj = comm_to_uart2;
	g_uart2_info.arg = &g_uart2_comm_src_info;
#else
	g_uart2_info.arg = (OTP_VOID *)uart2_msg_send;
#endif

	/*���պͷ���ָ��ִ����Ӧ�Ļ�����*/
	g_uart2_info.rinfo.rproc.pdata = g_uart2_rcv_buf;
	g_uart2_info.rinfo.rproc.datalen = UART2_RCV_BUFLEN;
	g_uart2_info.sinfo.pdata = g_uart2_send_buf;
	g_uart2_info.sinfo.datalen = UART2_SEND_BUFLEN;

	return OK;
}

/*******************************************************************************
*uart2_rcv_process  ���ձ��Ĵ�����������Ӧ��Э�飬�Խ��ջ������ı��Ľ��д�����������
*		ע���rcv����������
*Input:
*	uid		--uart�Ķ˿ںţ���ΧΪ0��1������û��ʲô�ã�����ȥ��
*	prt		--���Ĵ���ʹ�õ�Э�飬����Э�����ͽ��б��Ľ��գ�
*	prinfo	--���ջ����������Ϣָ�룻
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart2_rcv_process(void)
{
	return uart_rcv_process(g_uart2_info.arg, g_uart2_info.prt, &g_uart2_info.rinfo);
}


/*******************************************************************************
*uart2_msg_send ���ͱ��Ĵ���
*Input:
*	psinfo	--���ͻ�����ָ�룬���ڴ�ŷ��͵���Ϣ��
*	buf		--��Ҫ���͵�����ָ��
*	buflen	--���͵����ݳ���
*Output:
*	None	
*Return:
*	OK/ERROR����ʾִ�гɹ���ʧ��
*/
STATUS uart2_msg_send(const OTP_UINT8 *buf, OTP_UINT32 buflen)
{
	/*�������*/
	if(buf == NULL)
	{
		MCU_EXC_ERROR;
		return ERROR;
	}
	if(buflen == 0)
	{
		MCU_EXC_ERROR;
		return ERROR;
	}
	
	if(uart_msg_send(UART2_ID, &g_uart2_info, buf, buflen) != OK)
	{
		MCU_EXC_ERROR;
		return ERROR;
	}
	
	return OK;
}


#endif
