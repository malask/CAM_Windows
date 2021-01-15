/******************************************************************************
 *
 * Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
 ******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "xparameters.h"
#include "platform.h"
#include "xil_printf.h"
#include "xllfifo.h"
#include "xscone_engine.h"
#include "xstatus.h"

typedef enum {
	CLEAR = 0,
	UPSCAN = 1,
	DOWNSCAN = 2,
	PROPAGATE = 3,
	INTERSECTION = 4
} scone_ops;

#define MASK_CMD 0x3FC

XScone_engine_Config *scone_ip_cfg;
XScone_engine scone_ip;

void print_status(XScone_engine *ip) {
	printf("Idle %d Ready %d\r\n",XScone_engine_IsIdle(ip),XScone_engine_IsReady(ip));
	return;
}



int main()
{
	XLlFifo_Config *fifo_cfg;
	XLlFifo fifo_ip;

	int Status;
	int i;
	//int Error;
	Status = XST_SUCCESS;
	u32 cmd;

	init_platform();

	print("Hello World\n\r");

	scone_ip_cfg = XScone_engine_LookupConfig(XPAR_SCONE_ENGINE_0_DEVICE_ID);

	if (!scone_ip_cfg) {
		printf("No config found for %d\r\n", XPAR_SCONE_ENGINE_0_DEVICE_ID);
		return XST_FAILURE;
	}

	if (XScone_engine_CfgInitialize(&scone_ip, scone_ip_cfg) != XST_SUCCESS) {
		printf("Error en la inicialización");
	}

	/* Initialize the Device Configuration Interface driver */
	fifo_cfg = XLlFfio_LookupConfig(XPAR_AXI_FIFO_0_DEVICE_ID);
	if (!fifo_cfg) {
		xil_printf("No config found for FIFO %d\r\n", XPAR_AXI_FIFO_0_DEVICE_ID);
		return XST_FAILURE;
	}

	/*
	 * This is where the virtual address would be used, this example
	 * uses physical address.
	 */
	Status = XLlFifo_CfgInitialize(&fifo_ip, fifo_cfg, fifo_cfg->BaseAddress);
	if (Status != XST_SUCCESS) {
		xil_printf("Initialization failed\n\r");
		return Status;
	}

	printf("---clear--\n");

	cmd = 1;

	XScone_engine_Set_entry_V(&scone_ip,cmd);
	XScone_engine_Set_op(&scone_ip,CLEAR);


	XScone_engine_Start(&scone_ip);

	while (!XScone_engine_IsIdle(&scone_ip));
	print_status(&scone_ip);


	printf("---upscan--\n");

	cmd = (127<<2) & MASK_CMD; // (entry,op)

	XScone_engine_Set_entry_V(&scone_ip,cmd);
	XScone_engine_Set_op(&scone_ip,UPSCAN);

	print_status(&scone_ip);

	XScone_engine_Start(&scone_ip);


	while (!XScone_engine_IsIdle(&scone_ip));

	print_status(&scone_ip);

	printf("Bye!\n");


	printf("---propagate--\n");

	cmd = 1;

	XScone_engine_Set_entry_V(&scone_ip,cmd);
	XScone_engine_Set_op(&scone_ip,PROPAGATE);

	print_status(&scone_ip);

	XScone_engine_Start(&scone_ip);

	print_status(&scone_ip);

	while (!XScone_engine_IsIdle(&scone_ip));

	print_status(&scone_ip);

	printf("Bye!\n");


	printf("---downscan--\n");

	cmd = (8<<2) & MASK_CMD;

	XScone_engine_Set_entry_V(&scone_ip,cmd);
	XScone_engine_Set_op(&scone_ip,DOWNSCAN);

	print_status(&scone_ip);

	XScone_engine_Start(&scone_ip);

	print_status(&scone_ip);

	while (!XScone_engine_IsIdle(&scone_ip));

	print_status(&scone_ip);

	printf("Bye!\n");


	printf("---INTERSECTION--\n");

	cmd = 6;

	XScone_engine_Set_entry_V(&scone_ip,cmd);
	XScone_engine_Set_op(&scone_ip,INTERSECTION);

	print_status(&scone_ip);

	XScone_engine_Start(&scone_ip);

	print_status(&scone_ip);

	while (!XScone_engine_IsIdle(&scone_ip));

	print_status(&scone_ip);

	printf("Bye!\n");

	printf("---clear--\n");

	cmd = 1;

	XScone_engine_Set_entry_V(&scone_ip,cmd);
	XScone_engine_Set_op(&scone_ip,CLEAR);

	print_status(&scone_ip);

	XScone_engine_Start(&scone_ip);

	print_status(&scone_ip);

	while (!XScone_engine_IsIdle(&scone_ip));

	print_status(&scone_ip);

	printf("Bye!\n");

	unsigned int fifodata;
	unsigned char emptythreshold = 5;

	XLlFifo_IntDisable(&fifo_ip, XLLF_INT_ALL_MASK);
	XLlFifo_IntEnable(&fifo_ip, XLLF_INT_RFPE_MASK);

		emptythreshold = 5;

		while (emptythreshold >0)
		{
			fifodata = XLlFifo_RxGetWord(&fifo_ip);
			u32 intstatus = XLlFifo_Status(&fifo_ip);
			unsigned char *word;
			word = (unsigned char *)&fifodata;
			printf("FIFO [%d] [%d] [%d] [%d]\n\r",word[0],word[1],word[2],word[3]);
			if (intstatus & XLLF_INT_RFPE_MASK) {
				printf("Almost empty %d\r\n",emptythreshold);
				emptythreshold--;

			}
		}

//	for (i = 0; i < 128; i++) {
//		printf("Len FIFO %d\n",XLlFifo_RxGetWord(&fifo_ip));
//	}
	printf("Bye!\n");

	cleanup_platform();
	return 0;
}
