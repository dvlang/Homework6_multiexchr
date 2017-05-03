#include "exchanger.h"
#include <time.h>

void exchanger::exchanging() {
	int i, dval, startaddr, numreadbytes;

	srand(device*(unsigned)time(NULL));

	while(true) {
		cout << "Device: "<< device <<" at " << sc_time_stamp() <<" is idle ...\n";
		//srand(time(NULL));
		wait(delay*30,SC_NS);
	
	//********WRITING************
	  //!!!!(UN)COMMENT ME TO ADD WRITE PROCESS IN, COMMENT WRITE PROCESS OUT TO EASILY SEE 3 READ SEMAPHORES WORKING!!!!!
		cout << "Device: "<< device <<" at " << sc_time_stamp() <<" has requested to write...\n";

		permit->lock();

		cout << "Device: "<< device <<" at " << sc_time_stamp() <<" is granted the use of memory ...\n";

		startaddr = rand() % ADDR_SPACE;

		for(i=0;i<=63;i++) {
			dval = rand() % WORD_LENGTH;
			datain = (sc_lv<WORD_LENGTH>)dval;
			addr = (sc_lv<ADDRESS>)(startaddr+i);
			cs = (sc_logic)'1';
			rwbar = (sc_logic)'0';
			wait(delay,SC_NS);

		}

		cs = (sc_logic)'Z';
		rwbar = (sc_logic)'Z';
		datain = (sc_lv<WORD_LENGTH>)"ZZZZZZZZ";
		addr = (sc_lv<ADDRESS>)"ZZZZZZZZZZ";
				
		cout << "Device: "<< device <<" wrote in the memory starting at: " << startaddr << "\n";
		cout << "Device: "<< device <<" at " << sc_time_stamp() <<" completes its exchange.\n";
		cout << "Device: "<< device <<" is done.\n";

		permit->unlock();
		 //!!!!(UN)COMMENT ME TO ADD WRITE PROCESS IN, COMMENT WRITE PROCESS OUT TO EASILY SEE 3 READ SEMAPHORES WORKING!!!!!



		//********READING************
	/*	cout << "Device: " << device << " at " << sc_time_stamp() << " has requested to read...\n";
		readpermit->wait();
	
		cout << "Device: " << device << " at " << sc_time_stamp() << " Got a read semaphore "  << "\n";
		startaddr = rand() % ADDR_SPACE;
		numreadbytes = rand() % 63;
		for (i = 0; i < numreadbytes; i++){
			addr = (sc_lv<ADDRESS>)(startaddr + i);
			cs = (sc_logic)'1';
			rwbar = (sc_logic)'1';
			cout << "Device: " << device << " reads from memory: " << dataout << endl;

			wait(delay, SC_NS);
		}

		cs = (sc_logic)'Z';
		rwbar = (sc_logic)'Z';

						
		readpermit->post();
		*/



	}
}
