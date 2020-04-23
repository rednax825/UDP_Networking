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
	
	ENetHost* client;

	client = enet_host_create(NULL, // create a client host
		1,		// allow only 1 outgoing connection
		2,		// allow up to 2 channels
		0,		// assume any amount of incoming bandwidth
		0);		// assume any amount of outgoing bandwidth

	if (client == NULL)
	{
		fprintf(stderr, "Error creating enet client.\n");
	}


	enet_host_destroy(client);

	enet_deinitialize();
}
