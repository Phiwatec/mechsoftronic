/////////////////////////////////////////////////////////////////////////////
/// @file
///
/// @date	Apr 27, 2015 1:02:38 PM
///
/// @author	Michael House
///
/// @brief	[see corresponding .hpp file]
///
/// @par Copyright (c) 2014 All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

#include "cute.h"
#include "test_communication_tcp_based.h"
#include "test_helper.h"

#define private public
#include "communication_tcp_based.hpp"

#include "command_processor.hpp"


using namespace std;

void testRouteLayers()
{
	CommSimple listener;
	listener.input(SET_LAYER); //command
	listener.input(4);     //length
	listener.input(0);
	listener.input(3);
	listener.input(0);
	listener.input(200);

	//command G_XY
	listener.input(G_XY);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(0);

	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(0);

	//command G_XY
	listener.input(G_XY);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(0);
	listener.input(106);
	listener.input(6);

	listener.input(0);
	listener.input(1);
	listener.input(62);
	listener.input(20);
	//command G_XY
	listener.input(G_XY);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(2);
	listener.input(18);
	listener.input(34);

	listener.input(0);
	listener.input(2);
	listener.input(230);
	listener.input(48);
	//command G_XY
	listener.input(G_XY);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(1);
	listener.input(62);
	listener.input(20);

	listener.input(0);
	listener.input(2);
	listener.input(230);
	listener.input(48);

	listener.input(START_ROUTE);
	listener.input(0);

}

void testSendCoordinates()
{
	CommSimple listener;
	//command G_XY
	listener.input(G_XY);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(0);

	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(0);

	//command G_XY
	listener.input(G_XY);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(0);
	listener.input(106);
	listener.input(6);

	listener.input(0);
	listener.input(1);
	listener.input(62);
	listener.input(20);
	//command G_XY
	listener.input(G_XY);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(2);
	listener.input(18);
	listener.input(34);

	listener.input(0);
	listener.input(2);
	listener.input(230);
	listener.input(48);
	//command G_XY
	listener.input(G_XY);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(1);
	listener.input(62);
	listener.input(20);

	listener.input(0);
	listener.input(2);
	listener.input(230);
	listener.input(48);

	listener.input(START_ROUTE);
	listener.input(0);

	//JOGZ DIR =1 STEP = 000 0000 0000 0000
	listener.input(JOG_Z);     //command
	listener.input(4);     //length
	listener.input(128);
	listener.input(52);
	listener.input(21);
	listener.input(7);
}

void testReceiver()
{
	CommSimple listener;

	//JOGZ DIR =1 STEP = 000 0000 0000 0000
	listener.input(JOG_Z);     //command
	listener.input(4);     //length
	listener.input(128);
	listener.input(52);
	listener.input(21);
	listener.input(7);

	//JOGY DIR =1 STEP = 000 0000 0000 0000
	listener.input(JOG_Y);      //command
	listener.input(4);      //length
	listener.input(128);
	listener.input(0);
	listener.input(0);
	listener.input(0);

	//JOGX DIR =1 STEP = 000 0000 0000 0000
	listener.input(JOG_X);      //command
	listener.input(4);      //length
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(5);

	//JOGXY DIR =1 STEP = 000 0000 0000 0000
	listener.input(JOG_XY); 		//command
	listener.input(8); 		//length
	listener.input(128);
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(0);

	listener.input(JOG_XY);     //command
	listener.input(8);     //length
	listener.input('h');
	listener.input('i');
	listener.input('j');
	listener.input(0);
	listener.input(0);
	listener.input(3);
	listener.input(2);
	listener.input(1);

	listener.input(SET_PW_Z);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(7);
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(3);

	listener.input(SET_PW_Y);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(3);
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(7);

	listener.input(SET_PW_X);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(1);
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(2);

	listener.input(FEED);     //command
	listener.input(4);     //length
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(5);

	listener.input(ERASE_COORD);     //command
	listener.input(0);     //length

	listener.input(ERASE_COORD);     //command
	cout<<"Erase coord command number "<<ERASE_COORD<<endl;
	listener.input(0);     //length

}
void testSendCommand()
{
	CommSimple listener;

	listener.input(SET_ACCEL);     //command
	listener.input(8);     //length
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(7);
	listener.input(0);
	listener.input(0);
	listener.input(0);
	listener.input(5);
}

void testReadByteStream()
{
	//note: after compiling test_cnc_firmware.exe is generated
	//run the exe and redirect output to capture full output
	//C:\workspace_luna\test_cnc_firmware\Debug>test_cnc_firmware.exe > output.txt
	CommSimple listener;
	printf("will try to open file\n");
    //std::fstream myfile("c:/bytestream0.txt", std::ios_base::in); //on windows systems
    std::fstream myfile("/Users/Dynames/delete_me/route_snowflake_origin2.txt", std::ios_base::in); //on MAC OS
    printf("file opened\n");
    int a;
    while (myfile >> a)
    {
        //printf("%d ", a);
        listener.input(a);
    }
    printf("exited while loop\n");
    DisplayStepCoordinate(listener.routes);

}
cute::suite make_suite_test_comm_tcp_based(){
	cute::suite s;

	//push_back tests to s

	s.push_back(CUTE(testReadByteStream));
	//s.push_back(CUTE(testRouteLayers));
	//s.push_back(CUTE(testSendCoordinates));
	//s.push_back(CUTE(testReceiver));
	//s.push_back(CUTE(testSendCommand));
	return s;
}
