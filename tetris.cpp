#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t d8;
typedef int16_t d16;
typedef int32_t d32;
typedef float f32;
typedef double f64;

//define board sizes (2 extra rows for loading of tetriminos)
#define WIDTH 10
#define HEIGHT 22
#define VISIBLE_HEIGHT 20

//create struct for tetriminos
struct Tetrimino{
    const u8 *data;
    const d32 side; //assume square
};

inline Tetrimino tetrimino(const u8 *data, d32 side){
    return {data, side};
}

const u8 tetrino_1[]={
    0,0,0,0,
    1,1,1,1,
    0,0,0,0,
    0,0,0,0
};

const u8 tetrino_2[]={
    2,2,
    2,2
};

const u8 tetrino_3[]={
    0,0,0,
    3,3,3,
    0,3,0
};

const Tetrimino TETRIMINOS[] = {
    tetrimino(tetrino_1, 4),
    tetrimino(tetrino_2, 2),
    tetrimino(tetrino_3, 3)
};

enum Game_Phase{
    GAME_PHASE_PLAY
};

//create struct for piece state
struct Piece_State{
    u8 tetrinoIndex;
    d32 offsetRow;
    d32 offsetCol;
    d32 rotation;
};

//create struct for game state
struct Game_State{
    u8 board[WIDTH * HEIGHT];
    Piece_State piece;
    Game_Phase phase;
};

inline u8 getMatrix(const u8 *values, d32 width, d32 row, d32 col){
    d32 index = row * width + col;
    return values[index];
}

void updateGamePlay(Game_State *game){
}

void updateGame(Game_State *game){
    switch(game->phase){
        case GAME_PHASE_PLAY:
            return updateGamePlay(game);
            break; 
    }
}

int main (){
    printf("Hello World!");
    return 0;
}