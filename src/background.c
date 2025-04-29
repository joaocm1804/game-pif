#include "../include/background.h"

static Texture2D background;

void InitBackground(void)
{
    background = LoadTexture("textures/background.png");
}

void DrawBackground(void){
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    int backgroundWidth = background.width;
    int backgroundHeight = background.height;
    for (int i = 0; i < screenHeight; i += backgroundHeight){
        for (int j = 0; j < screenWidth; j += backgroundWidth){
            DrawTexture(background, j, i, WHITE);  
        }
        
    }
    
}

void UnloadBackground(void)
{
    UnloadTexture(background);
}