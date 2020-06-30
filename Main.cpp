#include "CPath.h"

int main(){
	CPath* path = new CPath;
	path->start();
	path->engageUser();
	delete path;
	_CrtDumpMemoryLeaks();
}