#include "Memory.h"
#include "exchanger.h"

SC_MODULE(multiExchanger)
{
	sc_signal_rv<WORD_LENGTH> databusin, databusout;
	sc_signal_rv<ADDRESS> addrbus;
	sc_signal_resolved cs1, cs2, cs3, cs4, rwbar1, rwbar2, rwbar3, rwbar4;

	sc_mutex memBusses;

	exchanger* EXC1;
	exchanger* EXC2;
	exchanger* EXC3;
	exchanger* EXC4;

	Memory* MEM;
	
	void resetting();
	void clocking();
	void displaying();
	
	SC_CTOR(multiExchanger)
	{
		EXC1 = new exchanger("EXC1_Instance", 1, 10); 
			EXC1->cs(cs1);
			EXC1->rwbar(rwbar1);
			EXC1->datain(databusin);
			EXC1->dataout(databusout);
			EXC1->addr(addrbus);
			EXC1->permit=&memBusses;  // Pass mutex reference

		EXC2 = new exchanger("EXC2_Instance", 2,20);
			EXC2->cs(cs2);
			EXC2->rwbar(rwbar2);
			EXC2->datain(databusin);
			EXC2->dataout(databusout);
			EXC2->addr(addrbus);
			EXC2->permit=&memBusses;  // Pass mutex reference
		EXC3 = new exchanger("EXC3_Instance", 3, 30);
			EXC3->cs(cs3);
			EXC3->rwbar(rwbar3);
			EXC3->datain(databusin);
			EXC3->dataout(databusout);
			EXC3->addr(addrbus);
			EXC3->permit = &memBusses;  // Pass mutex reference
		EXC4 = new exchanger("EXC4_Instance", 4,40);
			EXC4->cs(cs4);
			EXC4->rwbar(rwbar4);
			EXC4->datain(databusin);
			EXC4->dataout(databusout);
			EXC4->addr(addrbus);
			EXC4->permit = &memBusses;  // Pass mutex reference
			

		MEM = new Memory("MEM_Instance");
			//(*MEM) (addrbus, databusin, databusout, cs, rwbar);
			(*MEM) (addrbus, databusin, databusout, cs1, cs2, cs3, cs4, rwbar1, rwbar2, rwbar3, rwbar4);
	}
};
 