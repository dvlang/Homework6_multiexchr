#include "multiExchanger.h"

int sc_main(int argc, char* argv[])
{
	multiExchanger EXC_TB ("EXC_Instance");

	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("dataExchange");
		sc_trace(VCDFile, EXC_TB.databusin, "inb");
		sc_trace(VCDFile, EXC_TB.databusout, "oub");
		sc_trace(VCDFile, EXC_TB.addrbus, "adb");
		sc_trace(VCDFile, EXC_TB.cs1, "cs1");
		sc_trace(VCDFile, EXC_TB.cs2, "cs2");
		sc_trace(VCDFile, EXC_TB.cs3, "cs3");
		sc_trace(VCDFile, EXC_TB.cs4, "cs4");
		sc_trace(VCDFile, EXC_TB.rwbar1, "rwb1");
		sc_trace(VCDFile, EXC_TB.rwbar2, "rwb2");
		sc_trace(VCDFile, EXC_TB.rwbar3, "rwb3");
		sc_trace(VCDFile, EXC_TB.rwbar4, "rwb4");
	sc_start(10000,SC_NS);
	return 0;
}


