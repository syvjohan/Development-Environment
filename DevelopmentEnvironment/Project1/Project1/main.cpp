#include "Defs.h"
#include "ScreenController.h"

#include <time.h>
#include <stdlib.h>

#undef main
int main(int, char**) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	srand(time(NULL));
	
	Controller::ScreenController screenController;

	return 0;
}


