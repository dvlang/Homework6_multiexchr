#include "Memory.h"

void Memory::meminit() {
	int i;
	for(i=0;i<ADDR_SPACE;i++) {
		mem[i] = i;
	}
}

void Memory::memwrite() {
	int ad;
	//if((sc_logic)cs=='1') {
	if (((sc_logic)cs1 == '1') || ((sc_logic)cs2 == '1')|| ((sc_logic)cs3 == '1')|| ((sc_logic)cs4 == '1')) {
		//if((sc_logic)rwbar=='0') {
		if (((sc_logic)rwbar1 == '1') || ((sc_logic)rwbar2 == '1') || ((sc_logic)rwbar3 == '1') || ((sc_logic)rwbar4 == '1')) {
			ad=(sc_uint<ADDRESS>)addr;
			mem[ad] = datain;
		}
	}
}

void Memory::memread() {
	int ad;
	//if ((sc_logic)cs=='1') {
	if (((sc_logic)cs1 == '1') || ((sc_logic)cs2 == '1') || ((sc_logic)cs3 == '1') || ((sc_logic)cs4 == '1')) {
		//if((sc_logic)rwbar=='1') {
		if (((sc_logic)rwbar1 == '1') || ((sc_logic)rwbar2 == '1') || ((sc_logic)rwbar3 == '1') || ((sc_logic)rwbar4 == '1')) {
			ad=sc_uint<ADDRESS>(addr);
			dataout=sc_uint<ADDRESS>(mem[ad]);
		}
	}
}

void Memory::memdump() {
	int i;
	sc_lv<WORD_LENGTH> data;
	ofstream out ("memout.txt");
	wait(2000,SC_NS);
	for (i=0;i<ADDR_SPACE;i++) {
		data=mem[i];
		out << i <<":\t" << data << "\n";
	}
}
