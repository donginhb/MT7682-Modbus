#ifndef _TYPE_COMMON_H
#define _TYPE_COMMON_H

typedef	void			OTP_VOID;
typedef char     		OTP_CHAR;	/* ����֤�Ƿ��з��ţ�
										ʵ���ϣ���PPC��ARM������charΪ�޷��ţ�
												�ڷ��滷����charΪ�з��� */
typedef signed char     OTP_INT8;	/* �з���8λ */
typedef unsigned char   OTP_UINT8;	/* �޷���8λ */
typedef signed short    OTP_INT16;	/* �з���16λ */
typedef unsigned short  OTP_UINT16;	/* �޷���16λ */
typedef signed int		OTP_INT32;	/* �з���32λ */
typedef unsigned int	OTP_UINT32;	/* �޷���32λ */

/*�붨�����long����ֲ����Խӣ���ʽ˵������Ϊ32λ*/
typedef signed long     OTP_LONG32;	/* �з���32λ */
typedef unsigned long   OTP_ULONG32;	/* �޷���32λ */
typedef	signed long long 	OTP_INT64;	/* �з���64λ */
typedef	unsigned long long OTP_UINT64;	/* �޷���64λ */

/* 8λ�Ĵ������� */
typedef volatile OTP_UINT8 OTP_REG8;

/* ָ�� */
typedef unsigned int	OTP_INSTRUCT;


/* �ֲ�������ֲ��������η� */
#ifndef LOCAL
#define LOCAL			static
#endif

#ifndef IMPORT
#define IMPORT			extern
#endif


/* OK ERROR �� STATUS һ��ʹ��*/
#ifndef STATUS
#define STATUS int /*��VXWORKS����һ��*/
#endif
#ifndef OK
#define OK				0
#endif
#ifndef ERROR
#define ERROR			(-1)
#endif

/* TRUE FALSE �� BOOL һ��ʹ��*/
#ifndef BOOL
#define BOOL int	/*��VXWORKS����һ��*/
#endif
#ifndef FALSE
#define FALSE			0
#endif
#ifndef TRUE
#define TRUE			1
#endif

#ifndef ENABLE
#define ENABLE			1
#endif
#ifndef DISABLE
#define DISABLE			0
#endif

#ifndef NULL
#define NULL 0L
#endif

/*����λ����*/
#define   BIT(n)  (1 << (n))

#define MCU_EXC_ERROR 

#endif /* _TYPE_COMMON_H */

