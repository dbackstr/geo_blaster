/*******************************************************************************************
*
*   raylib - Simple Game template
*
*   <Game title>
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014-2019 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

///
///   Space Strategy Game,
///   Adapted from simple game template by Dallin Backstrom - 2019
///
///   Space strategy game DD proposal and requirments
///   -run on android and desktop
///   -feature online vs play and vs play against a bot
///   -feature a UI that scales to the screen size and aspect ratio
///   > pixel-independant screen elements
///   > layouts for 16:9, 4:3, 9:16;
///   > gameplay feild handled with orthographc camera and render-to-texture solution
///   > Full resolution hud text, ect.
///   > HiDPI auto-detect scaling
///   -Menu allowing for login, salt and hash passwords? (SECONDARY FEATURE)
///   -Gameplay screen
///   > veiwport showing the feild of play (2d) that can be scrolled and zoomed
///   > HUD showing information like ability cooldown times and health
///   > Visibility radius inside the viewport
///   > GAMEPLAY SUMMARY:
// the player controlls a fleet of ships. they can move the fleet by right-click.
// the objective is to destroy the enemy fleet. fleets have an armour rating and
// equiped weapons. weapons have a defined range, rate of fire, energy cost, and
// cooldown time/spin up time. if a player can see another player, they might fire
// a weapon on their opponent's fleet. every time a weapon hits, which may be multiple
// times for certain weapon types, roll a d20 against the armour rating of the other fleet.
// a roll above the armour rating does full damage, less the flat reduction of the armour
// rating (1 point for every two armour rating above 8; 12 is +2, 14 is +3 and so on)
// a roll below the armour rating has it's damage divided by two for every point it missed
// the amrour rating by, then has the flat reduction applied. i.e., if a player fires a
// laser cannon and rolls a 13 to hit against a fleet with 14 armour, first, the damage would be
// divided by (2*1), then have 3 subtracted from it.
// all fleets have a scout ship ability on a fixed cooldown that allows them to reveal part
// of the playing feild. the fleet also has a radius of vision around it. A fleet
// running at full power can move at full speed. A fleet in low power mode moves at
// one third speed and cannot fire weapons without powering up, but is only able to
// be detected at half the normal distance.

#include "raylib.h"

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

typedef struct Triangle {
  Vector2 a;
  Vector2 b;
  Vector2 c;
} Triangle;

typedef struct Fleet {
int id;
Vector2 pos;   // position of the center of the fleet
Vector2 face;  // orientation;
Vector2 speed;
Triangle hitbox;

int hitpoint;
int ac;       // armour rating
float maxsp;  // max speed
float thrust; // rate of acceleration

bool power; // if the fleet is in low power mode
int ab1; // cooldown timer for ailities
int ab2; // second ability
int ab3; // third ability

Color colour;
} Fleet;

//------------------------------------------------------------------------------
// helper functions for structs
//------------------------------------------------------------------------------

bool CheckCollisionLines(Vector2 u1, Vector2 u2, Vector2 v1, Vector2 v2){
  bool collide = false;

  float au = u2.y - u1.y;
  float bu = u1.x - u2.x;

  

  if (){

  }

  return collide;
}

bool CheckCollisionTriangles(Triangle tri1, Triangle tri2 ) {

  return collide;
}

//------------------------------------------------------------------------------
// helper functions for the main game loop
//------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization (Note windowTitle is unused on Android)
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "simple game  -  blaster game");

    GameScreen currentScreen = LOGO;

    // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;          // Useful to count frames

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here!
                framesCounter++;    // Count frames


            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {
                case LOGO:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                    DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

                } break;
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("BLASTER GAME", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER to CONTINUE to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

                } break;
                case GAMEPLAY:
                {
                    // TODO: Draw GAMEPLAY screen here!




                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
