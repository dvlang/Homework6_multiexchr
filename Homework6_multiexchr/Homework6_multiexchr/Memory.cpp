#include "Memory.h"

void Memory::meminit() {
	int i;
	for(i=0;i<ADDR_SPACE;i++) {
		mem[i] = i;
	}
}

void Memory::memwrite() {
	int ad;
	//if((sc_logic)cs=='1') { //replaced by if below
	//if (((sc_logic)cs1 == '1') || ((sc_logic)cs2 == '1')|| ((sc_logic)cs3 == '1')|| ((sc_logic)cs4 == '1')) {
		//if((sc_logic)rwbar=='0') { //replaced by if below
		if (((sc_logic)rwbar1 == '0')&& ((sc_logic)cs1 == '1')) {
			ad = (sc_uint<ADDRESS>)addr1;
			mem[ad] = datain1;
		}
		else if (((sc_logic)rwbar2 == '0') && ((sc_logic)cs2 == '1')) {
				ad = (sc_uint<ADDRESS>)addr2;
				mem[ad] = datain2;
		}
		else if (((sc_logic)rwbar3 == '0') && ((sc_logic)cs3 == '1')) {
			ad = (sc_uint<ADDRESS>)addr3;
			mem[ad] = datain3;
		}
		else if (((sc_logic)rwbar4 == '0') && ((sc_logic)cs4 == '1')) {
			ad = (sc_uint<ADDRESS>)addr4;
			mem[ad] = datain4;
		}

	//}
}

void Memory::memread() {
	int ad;
	//if ((sc_logic)cs=='1') {//replaced by if below
	//if (((sc_logic)cs1 == '1') || ((sc_logic)cs2 == '1') || ((sc_logic)cs3 == '1') || ((sc_logic)cs4 == '1')) {
		//if((sc_logic)rwbar=='1') {//replaced by if below
		if (((sc_logic)rwbar1 == '1') && ((sc_logic)cs1 == '1')) {
			ad=sc_uint<ADDRESS>(addr1);
			dataout1=sc_uint<ADDRESS>(mem[ad]);
		}
		if (((sc_logic)rwbar1 == '1') && ((sc_logic)cs2 == '1')) {
			ad = sc_uint<ADDRESS>(addr2);
			dataout2 = sc_uint<ADDRESS>(mem[ad]);
		}
		if (((sc_logic)rwbar1 == '1') && ((sc_logic)cs3 == '1')) {
			ad = sc_uint<ADDRESS>(addr3);
			dataout3 = sc_uint<ADDRESS>(mem[ad]);
		}
		if (((sc_logic)rwbar1 == '1') && ((sc_logic)cs4 == '1')) {
			ad = sc_uint<ADDRESS>(addr4);
			dataout4 = sc_uint<ADDRESS>(mem[ad]);
		}
	//}
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
