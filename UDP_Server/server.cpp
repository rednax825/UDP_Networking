#include <iostream>
#include <enet/enet.h>

using namespace std;

int main()
{
	if (enet_initialize() != 0)
	{
		cout << "error in enet init" << endl;
		return EXIT_FAILURE;
	}

	enet_deinitialize();
}