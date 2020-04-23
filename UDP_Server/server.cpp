#include <iostream>
#include <enet/enet.h>

using namespace std;

int main()
{
	if (enet_initialize() != 0)
	{
		fprintf(stderr, "Error initializing enet.\n");
		return EXIT_FAILURE;
	}

	ENetAddress address;
	ENetHost* server;

	// bind the server to default localhost and port 1234
	address.host = ENET_HOST_ANY;
	address.port = 1234;

	server = enet_host_create(&address, // the address to bind the server to
		32,		// allow up to 32 connections
		2,		// allow up to 2 channels
		0,		// assume any amount of incoming bandwidth
		0);		// assume any amount of outgoing bandwidth

	if (server == NULL)
	{
		fprintf(stderr, "Error creating enet server host.\n");
		return EXIT_FAILURE;
	}


	enet_host_destroy(server);
	
	enet_deinitialize();
}