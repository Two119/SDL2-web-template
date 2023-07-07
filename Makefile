all:
	em++ main.cpp -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='['png']' -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 --preload-file src --preload-file assets -o index.js -std=c++20
