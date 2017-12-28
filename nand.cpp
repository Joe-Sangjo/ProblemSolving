//----------------------------------------------------------
//
// A simple NAND simulator
//
// Feb. 1, 2017.
//
// Jin-Soo Kim (jinsookim@skku.edu)
// Computer Systems Laboratory
// Sungkyunkwan University
// http://csl.skku.edu
//
//----------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nand.h"

struct nand_page
{
	u32 	data;
	u32 	spare;
	
};
	
struct nand_block{
	struct nand_page *page;
	int *isWritten; //1이면 쓰여졌다, 0이면 쓰여지지 않았다.
};

struct nand_block *nand_blocks;

int sizeOfBlock, sizeOfPage;
int *blockIsWritten;

int nand_init (int nblks, int npages)
{
	// initialize the NAND flash memory 
	// "blks": the total number of flash blocks
	// "npages": the number of pages per block
	// returns 0 on success
	// returns -1 on errors with printing appropriate error message

	nand_blocks = (struct nand_block *)malloc(nblks * sizeof(struct nand_block));
	blockIsWritten = (int *)malloc(nblks * sizeof(int));
	for (int i = 0; i < nblks; i++){
		blockIsWritten[i] = 0;
	}

	for (int i = 0; i < nblks; i++){
		nand_blocks[i].page = (struct nand_page *)malloc(npages * sizeof(struct nand_page));
		nand_blocks[i].isWritten = (int *)malloc(npages * sizeof(int));
		for (int j = 0; j < npages; j++){
			nand_blocks[i].isWritten[j] = 0;
		}
	}
	
	sizeOfBlock = nblks; sizeOfPage = npages;

	printf("NAND %d blocks, %d pages per block, %d pages\n", nblks, npages, nblks * npages);
	return 0;
}
	
int nand_write (int blk, int page, u32 data, u32 spare)
{
	// write "data" and "spare" into the NAND flash memory pointed to by "blk" and "page"
	// returns 0 on success
	// returns -1 on errors with printing appropriate error message

	//blk의 범위가 벗어나면,
	if (blk < 0 || blk >= sizeOfBlock){
		printf("write(%d, %d) : failed, invalid block number\n", blk, page);
		return -1;
	}

	//page의 범위가 벗어나면,
	if (page < 0 || page >= sizeOfPage){
		printf("write(%d, %d) : failed, invalid page number\n", blk, page);
		return -1;
	}

	//page가 이미 쓰여졌다면,
	if (nand_blocks[blk].isWritten[page] == 1){
		printf("write(%d, %d) : failed, the page was already written\n", blk, page);
		return -1;
	}

	//순차적으로 쓰여지지 않았다면,
	if (page > 0 && nand_blocks[blk].isWritten[page - 1] == 0){
		printf("write(%d, %d) : failed, the page is not being sequentially written\n", blk, page);
		return -1;
	}
	

	blockIsWritten[blk] = 1;
	nand_blocks[blk].isWritten[page] = 1;
	nand_blocks[blk].page[page].data = data;
	nand_blocks[blk].page[page].spare = spare;
	printf("write(%d, %d): data = 0x%.8x, spare = 0x%.8x\n", blk, page,
		nand_blocks[blk].page[page].data, nand_blocks[blk].page[page].spare);


	return 0;
}


int nand_read (int blk, int page, u32 *data, u32 *spare)
{
	// read "data" and "spare" from the NAND flash memory pointed to by "blk" and "page"
	// returns 0 on success
	// returns -1 on errors with printing appropriate error message

	//blk의 범위가 벗어나면,
	if (blk < 0 || blk >= sizeOfBlock){
		printf("read(%d, %d) : failed, invalid block number\n", blk, page);
		return -1;
	}

	//page의 범위가 벗어나면,
	if (page < 0 || page >= sizeOfPage){
		printf("read(%d, %d) : failed, invalid page number\n", blk, page);
		return -1;
	}

	//block이 쓰여지지 않았으면
	if (blockIsWritten[blk] == 0){
		printf("read(%d, %d) : failed, trying to read an empty block\n", blk, page);
		return -1;
	}

	//page가 쓰여지지 않았으면
	if (nand_blocks[blk].isWritten[page] == 0){
		printf("read(%d, %d) : failed, trying to read an empty page\n", blk, page);
		return -1;
	}

	*data = nand_blocks[blk].page[page].data;
	*spare = nand_blocks[blk].page[page].spare;
	printf("read(%d, %d) : data = 0x%.8x, spare = 0x%.8x\n", blk, page, *data, *spare);

	return 0;
}

int nand_erase (int blk)
{
	// erase the NAND flash memory block "blk"
	// returns 0 on success
	// returns -1 on errors with printing appropriate error message

	//blk의 범위
	if (blk < 0 || blk >= sizeOfBlock){
		printf("erase(%d) : failed, invalied block number\n", blk);
		return -1;
	}

	//쓰여지지 않은 블락이면
	if (blockIsWritten[blk] == 0){
		printf("erase(%d) : failed trying to erase a free block\n", blk);
		return -1;
	}

	for (int i = 0; i < sizeOfPage; i++){
		nand_blocks[blk].isWritten[i] = 0;
	}

	blockIsWritten[blk] = 0;

	printf("erase(%d) : block erased\n", blk);

	return 0;
}


int nand_blkdump (int blk)
{
	// dump the contents of the NAND flash memory block "blk" (for debugging purpose)
	// returns 0 on success
	// returns -1 on errors with printing appropriate error message
	int numOfwrittenPage;

		numOfwrittenPage = 0;
		printf("Blk		%d : ", blk);
		if (blockIsWritten[blk] == 0){
			printf("FREE\n");
			return 0;
		}

		for (int j = 0; j < sizeOfPage; j++){
			numOfwrittenPage += nand_blocks[blk].isWritten[j];
		}

		printf("Total %d page(s) written\n", numOfwrittenPage);

		for (int j = 0; j < sizeOfPage; j++){
			if (nand_blocks[blk].isWritten[j] == 1){
				printf("	Page	%d: data = 0x%.8x, spare = 0x%.8x\n", j, nand_blocks[blk].page[j].data,
					nand_blocks[blk].page[j].spare);
			}
		}






	return 0;
}

