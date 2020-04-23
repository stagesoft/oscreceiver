//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// Stage Lab SysQ OSC receiver class source file
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

#include "oscreceiver_class.h"

////////////////////////////////////////////
// Initializing static class members


////////////////////////////////////////////
OscReceiver::OscReceiver( int port, const char* oscRoute )
                        : oscPort(port), oscAddress(oscRoute)
{
    // OSC UDP Listener
    udpListener = new UdpListeningReceiveSocket(
            IpEndpointName( IpEndpointName::ANY_ADDRESS, oscPort ),
            this );

    // Set and detach our threaded checker loop
	std::thread runnerThread( & OscReceiver::threadedRun, this );
	runnerThread.detach();

}

////////////////////////////////////////////
OscReceiver::~OscReceiver( void )
{

}

////////////////////////////////////////////
void OscReceiver::threadedRun ( void )
{
    std::cout << endl << endl << "OSC object ready & listening at port " << oscPort << " address " << oscAddress << endl << endl;
    udpListener->Run();
} 

////////////////////////////////////////////
void OscReceiver::setOscAddress( std::string address )
{
    oscAddress = address;
}

////////////////////////////////////////////
std::string OscReceiver::getOscAddress( void )
{
    return oscAddress;
}
