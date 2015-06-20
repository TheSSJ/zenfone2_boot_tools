/*
 * bootheader.h
 */

#include <stdint.h>

#ifndef __BOOTHEADER__
#define __BOOTHEADER__

#define HEAD_PADDING						(0x40) /* Common Android Intel Image, correct */

#define CMDLINE_SIZE   						(0x200) //correct
#define PADDING1_SIZE						(0x800-0x254) //5AC
#define BOOTSTUBSTACK_SIZE					(0x0) //there seems to be none
#define CMDLINE_END						(HEAD_PADDING+CMDLINE_SIZE)

struct bootheader {
	char padding0[HEAD_PADDING]; //0x40
	char cmdline[CMDLINE_SIZE]; //0x200
	uint32_t bzImageSize; //4 bytes
	uint32_t initrdSize; //4
	uint32_t SPIUARTSuppression; //4
	uint32_t SPIType; //4
	uint32_t secondSize; //4
	char padding1[PADDING1_SIZE]; //5AC
	//char bootstubStack[BOOTSTUBSTACK_SIZE];
};

/* Sanity check for struct size */
typedef char z[(sizeof(struct bootheader) == 0x800) ? 1 : -1];

#endif
