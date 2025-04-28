
#include "raylib.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	int screenHeight = 800;
	int screenWidth = 1280;

	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Across The Bullets");

	SetTargetFPS(60);	// Set the target frames per second
	

	
	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("assets");

	// Load a texture from the resources directory
	Texture ruhtra = LoadTexture("textures/Ruhtra.png");

	float porcentagem_ocupada = 0.1f;
	float escalay = (screenHeight*porcentagem_ocupada)/ruhtra.height; //faz ficar proporcional ao tamanho da tela
	float escalax = (screenWidth*porcentagem_ocupada)/ruhtra.width;
	float escala = (escalax < escalay) ? escalax : escalay;

	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw our texture to the screen
		DrawTextureEx(ruhtra, (Vector2){400, 200}, 0.0f, escala, WHITE);
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(ruhtra);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
