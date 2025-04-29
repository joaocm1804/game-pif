
#include "raylib.h"
#include "background.h"
#include "resource_dir.h"

int main ()
{

	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI); //Faz com que o jogo rode em alta definição e com Vsync

	int screenHeight = 800;
	int screenWidth = 1280;

	InitWindow(screenWidth, screenHeight, "Across The Bullets");
	SetTargetFPS(60);	// Set the target frames per second


	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("assets");

	InitBackground();
	Texture ruhtra = LoadTexture("textures/Ruhtra.png"); //carrega a textura do player



	//ajuste do boneco a proporção da tela
	float porcentagem_ocupada = 0.1f;
	float escalay = (screenHeight*porcentagem_ocupada)/ruhtra.height;
	float escalax = (screenWidth*porcentagem_ocupada)/ruhtra.width;
	float escala = (escalax < escalay) ? escalax : escalay;

	// game loop
	while (!WindowShouldClose())
	{
		BeginDrawing();

			ClearBackground(BLACK); //Limpa o fundo da tela
			DrawBackground(); //desenha o fundo

			DrawTextureEx(ruhtra, (Vector2){400, 200}, 0.0f, escala, WHITE); //desenha o boneco na tela
		

		EndDrawing(); //termina o frame e se prepara para o próximo
	}

	UnloadBackground(); //descarrega a textura do fundo
	UnloadTexture(ruhtra);//limpa a textura do player

	CloseWindow();
	return 0;
}
