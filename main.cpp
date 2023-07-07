#include "src/include/game.hpp"
void initiliaze(){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_ShowCursor(SDL_DISABLE);
    IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG);
    int button_sprites_size[2] = {2, 1};
    //int pos[2] = {100, 100};
    cursor_img.init(scale_surface(IMG_Load("assets/Spritesheets/cursor.png"), 2));
    //playersprite.init(IMG_Load("assets/Spritesheets/card.png"), pos, size, 1, 8);
    button_sprites.init(scale_surface(IMG_Load("assets/Spritesheets/buttons.png")), button_sprites_size);
    clicksound.init("assets/Audio/click.wav");
}
void mainloop() {
    framestart = SDL_GetTicks();
    SDL_RenderClear(renderer);
    button_state = SDL_GetMouseState(&mouse_pos[0], &mouse_pos[1]);
    keyboard_state = SDL_GetKeyboardState(NULL);
    mousepos = {mouse_pos[0], mouse_pos[1]};
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            playing = false;
        }
    }
    //playersprite.update();
    cursor_img.blit(mouse_pos);
    SDL_RenderPresent(renderer);
    frametime = SDL_GetTicks()-framestart;
    if (framedelay > frametime){
        SDL_Delay(framedelay - frametime);
    }
}
int main(int argc, char* args[]){
    initiliaze();
    emscripten_set_main_loop(mainloop, -1, 1);
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    return 0;
}