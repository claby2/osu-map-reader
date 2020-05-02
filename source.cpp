#include <SDL2/SDL.h>
#include <vector>
#include <chrono>
#include "readmap.cpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int OBJECT_SIZE = 30;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

void init() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    gWindow = SDL_CreateWindow("osu! Map Reader", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
}

void close() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    SDL_Quit();
}

int main(int argc, char* args[]) {
    init();

    bool quit = false;
    SDL_Event event;

    std::vector<hitObject> hitObjects;
    std::string fileLocation = "";
    hitObjects = getHitObjects(fileLocation);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    int currentIndex = -1;

    while(!quit) {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);

        if(currentIndex + 1 <= hitObjects.size()) {
            if(hitObjects[currentIndex + 1].time <= elapsedTime) {
                SDL_RenderClear(gRenderer);
                hitObject object = hitObjects[currentIndex + 1];
                SDL_Rect rect = {
                    object.x - (OBJECT_SIZE / 2),
                    object.y - (OBJECT_SIZE / 2),
                    OBJECT_SIZE,
                    OBJECT_SIZE
                };
                currentIndex++;
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderDrawRect(gRenderer, &rect);
            }
        }

        SDL_RenderPresent(gRenderer);
    }

    close();

}