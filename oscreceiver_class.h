//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// Stage Lab SysQ OSC receiver class header file
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

#ifndef OSCRECEIVER_CLASS_H
#define OSCRECEIVER_CLASS_H

#include <iostream>
#include <thread>
#include "./oscpack/osc/OscPacketListener.h"
#include "./oscpack/osc/OscReceivedElements.h"
#include "./oscpack/ip/UdpSocket.h"
#include "./oscpack/ip/IpEndpointName.h"

//////////////////////////////////////////////////////////
// Preprocessor definitions
#define PORT 7000

using namespace std;

class OscReceiver : public osc::OscPacketListener 
{
    public:
        OscReceiver( int port = 7000, const char* oscRoute = "/master" );
        ~OscReceiver( void );

        UdpListeningReceiveSocket *udpListener;

        void setOscAddress( std::string address );
        std::string getOscAddress( void );

    protected:

        inline virtual void ProcessMessage( const osc::ReceivedMessage& /*m*/ , 
                                            const IpEndpointName& /*remoteEndpoint*/ ) {};

        void threadedRun( void );

        int oscPort;
        std::string oscAddress;

};


#endif // OSCRECEIVER_CLASS_H