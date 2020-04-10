#include "map.h"
#include "render.h"
#include <iostream>

int main(int argc, char* args[]) {
    TMap map(20, 40, 5, 5);

    TConsoleRenderer renderer(1, map);
    renderer.Flush();

    renderer.Render();
    
    int x;
    std::cin >> x;
	return 0;
}
