#include "map.h"
#include "render.h"
#include <iostream>

int main(int argc, char* args[]) {
    TMap map(20, 40, 5, 5);
    TConsoleRenderer renderer(1, map);

    while (true) {
        renderer.Flush();
        renderer.Render();
    
        char x;
        std::cin >> x;
        if (x == 'q') {
            break;
        } else {
           map.GetPlayer().Move(x);
        }
    }

	return 0;
}
