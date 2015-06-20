/*
 * bootheader.h
 */

#include <stdint.h>

#ifndef __BOOTHEADER__
#define __BOOTHEADER__

#define HEAD_PADDING						(0x20)
#define MAGIC							(0x8) //ANDROID!
#define CMDLINE_SIZE   						(0x200)
#define PADDING1_SIZE						(0x800-0x254) //5AC
#define CMDLINE_END						(HEAD_PADDING+HEAD_PADDING+CMDLINE_SIZE) //super dirty workaround

struct bootheader {
	char magicword[MAGIC]; //8 Bytes
	uint32_t bzImageSize; //4 Bytes
	uint32_t bzImageOffset; //4 Bytes
	uint32_t initrdSize; //4 
	uint32_t initrdOffset; //4
	uint32_t secondSize; //4
	uint32_t secondOffset; //4
	char padding0[HEAD_PADDING]; //0x20
	char cmdline[CMDLINE_SIZE]; //0x200
	uint32_t id1; //4
	uint32_t id2; //4
	uint32_t id3; //4
	uint32_t id4; //4
	uint32_t id5; //4
	char padding1[PADDING1_SIZE]; //5AC
};

/* Sanity check for struct size */
typedef char z[(sizeof(struct bootheader) == 0x800) ? 1 : -1];

#endif
