/* Copyright Statement:
 *
 * (C) 2005-2016  MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. ("MediaTek") and/or its licensors.
 * Without the prior written permission of MediaTek and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 * You may only use, reproduce, modify, or distribute (as applicable) MediaTek Software
 * if you have agreed to and been bound by the applicable license agreement with
 * MediaTek ("License Agreement") and been granted explicit permission to do so within
 * the License Agreement ("Permitted User").  If you are not a Permitted User,
 * please cease any access or use of MediaTek Software immediately.
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT MEDIATEK SOFTWARE RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES
 * ARE PROVIDED TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

#ifndef __G113I_UART_H__
#define __G113I_UART_H__


#ifdef __cplusplus
extern "C" {
#endif


/* --------------- ----------UART 1--����ģ��----------------------------*/
/* ---------------------UART 1 ������ʼ��--------------*/
//#define VFIFO_SIZE (256)
#define VFIFO_SIZE (1024)		/*DMA �����С����ͬʱ�õ����ա�����*/
#define SEND_THRESHOLD_SIZE (80)
#define RECEIVE_THRESHOLD_SIZE (250)
#define RECEIVE_ALERT_SIZE (50)
#define UART_PROMPT_INFO "\r\n\r\nPlease input data to this UART1  port and watch it's output:\r\n"
#define UART_PROMPT_INFO_SIZE sizeof(UART_PROMPT_INFO)

#define UART_SUCCESS_INFO "example project test success.\n"
#define UART_SUCCESS_INFO_SIZE sizeof(UART_SUCCESS_INFO)

#define  UART_RCV_TEMPBUF_LEN (4096)
/* ---------------------UART 1 ������ʼ������--------------*/


/* --------------- ----------UART 2--����ģ��----------------------------*/
/* ---------------------UART 2 ������ʼ��--------------*/
//#define VFIFO_SIZE (256)
#define UART2_VFIFO_SIZE (1024)		/*DMA �����С����ͬʱ�õ����ա�����*/
#define UART2_SEND_THRESHOLD_SIZE (80)
#define UART2_RECEIVE_THRESHOLD_SIZE (250)
#define UART2_RECEIVE_ALERT_SIZE (50)
#define UART2_PROMPT_INFO "\r\n\r\nPlease input data to this UART2  port and watch it's output:\r\n"
#define UART2_PROMPT_INFO_SIZE sizeof(UART2_PROMPT_INFO)

#define UART2_SUCCESS_INFO "example project test success.\n"
#define UART2_SUCCESS_INFO_SIZE sizeof(UART2_SUCCESS_INFO)

#define  UART2_RCV_TEMPBUF_LEN (4096)
/* ---------------------UART 2 ������ʼ������--------------*/












void uart1_init(void);
void uart2_init(void);

#ifdef __cplusplus
}
#endif

#endif //__SYS_INIT_H__

