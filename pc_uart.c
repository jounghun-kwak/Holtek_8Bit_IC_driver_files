/*
 *  pc_uart.h
 *
 *  Created on: 2022. 7. 01
 *  Author: jaden
 *  Chip : HT66F2390
 *  e-mail : jaden@pacificcentury.co.kr
*/

#include "HT66F2390.h"
#include "pc_uart.h"


/************************Circle Queue***********************/
#define MAX_QUEUE_SIZE        120
typedef struct
{
    uint16 front, rear;
    uint8 queue[MAX_QUEUE_SIZE];
} QueueType;
typedef enum
{
	SUCCESS,
	ERROR
}ErrorStatus;

static QueueType RxuartQueue;

typedef enum {QUEUE_SUCCESS = 0, QUWUW_ERROR = !QUEUE_SUCCESS} QueueStatus;

static void Init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

static uint16 is_empty(QueueType* q)
{
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

static uint16 is_full(QueueType* q)
{
    if((q->rear + 1)%MAX_QUEUE_SIZE == q->front)
        return 1;
    else
        return 0;
}

static QueueStatus enqueue(QueueType* q, uint8 item)
{	
    
    if(is_full(q) == 1)
		return QUWUW_ERROR;
        
	q->rear= (q->rear+ 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
	return QUEUE_SUCCESS;
}

static QueueStatus dequeue(QueueType* q, uint8 *item)
{
	if(is_empty(q))
		return QUWUW_ERROR;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	*item = q->queue[q->front];
	return QUEUE_SUCCESS;
}

static ErrorStatus rxuart_putchar(const uint8 ascii)
{
	if(enqueue(&RxuartQueue,ascii) == QUEUE_SUCCESS)
		return SUCCESS;
	else
		return ERROR;
}

static ErrorStatus rxuart_getchar(uint8 *data)
{
	if(dequeue(&RxuartQueue,data) == QUEUE_SUCCESS)
		return SUCCESS;
	else
		return ERROR;
}
/*************************End Queue*************************/
#define fH 8000000
#define broud 9600
void uart_init(void)
{
	_wdtc = 0B10101111;
	_pas1 = 0B11000000;
	_u0cr1 = 0B10000000;
	_u0cr2 = 0B11100100;
	_brg0 = fH/((uint32)16 * broud) - 1;
	_mf5e = 1;
	_ur0e = 1;
	_emi = 1;
	
	Init_queue(&RxuartQueue);
	return;	
}
uint8 txBuffer, rxBuffer[MAX_QUEUE_SIZE];

void __attribute((interrupt(0x3C))) UART_ISR(void)
{

	while(!_rxif0);
	rxuart_putchar(_txr_rxr0);
	_ur0f = 0;
}

void uart_send_data(uint8 tx_data)
{
	_txr_rxr0 = tx_data;
	while(!_txif0);
}
void uart_send_str(uint8 *tx_str)
{
	while(*tx_str)
	{
		uart_send_data(*tx_str);
		tx_str++;	
	}	
}
int uart_receive(void)
{
	int len = 0;
	int i ;
	while(!is_empty(&RxuartQueue))
	{
		rxuart_getchar(&rxBuffer[len]);
		len++;	
	}
	
	for(i = 0; i< len; i++)
	{
		uart_send_data(rxBuffer[i]);
	}

}
void Delayms(uint16 del)
{
	uint16 i;
	for(i = 0; i < del ; i++) GCC_DELAY(2000);
}
