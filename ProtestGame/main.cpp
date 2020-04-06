#include "map.h"
#include "render.h"
#include <iostream>

int main(int argc, char* args[]) {
    TMap map;

    TConsoleRenderer renderer(2, map);
    renderer.Flush();
    renderer.Render();
    
	return 0;
}
