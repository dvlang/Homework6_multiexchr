#include <systemc.h>
#include <iostream>

#define WORD_LENGTH 8 
#define ADDRESS 10 
#define ADDR_SPACE 1024
 
SC_MODULE (Memory) {
	sc_in_rv <ADDRESS> addr;
	sc_in_rv <WORD_LENGTH> datain;
	sc_out_rv <WORD_LENGTH> dataout;
	//sc_in_resolved cs, rwbar;
	sc_in_resolved cs1, cs2, cs3, cs4, rwbar1, rwbar2, rwbar3, rwbar4;

	sc_uint <WORD_LENGTH> mem [ADDR_SPACE];

	void meminit ();
	void memread ();
	void memwrite ();
	void memdump ();

	SC_CTOR(Memory) {
		SC_THREAD (meminit);
		SC_METHOD (memread);
			//sensitive << addr << cs << rwbar;
			sensitive << addr << cs1<< cs2<< cs3<< cs4 << rwbar1 << rwbar2 << rwbar3 << rwbar4;

		SC_METHOD (memwrite);
			//sensitive << addr << datain << cs << rwbar;
			sensitive << addr << cs1 << cs2 << cs3 << cs4 << rwbar1 << rwbar2 << rwbar3 << rwbar4;
		SC_THREAD (memdump);
	}
};
