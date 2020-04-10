#include "map.h"
#include "render.h"
#include <iostream>

int main(int argc, char* args[]) {
    TMap map(20, 40);

    TCamera camera;
    camera.X = 5;
    camera.Y = 10;
    camera.W = 5;
    camera.H = 5;

    TConsoleRenderer renderer(1, map, camera);
    renderer.Flush();

    renderer.Render();
    
    int x;
    std::cin >> x;
	return 0;
}
