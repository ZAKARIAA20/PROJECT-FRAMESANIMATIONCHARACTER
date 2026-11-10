#include "Player.h"



int main() {
    InitWindow(1000, 600, "Grim Reaper Game");
    SetTargetFPS(60);

    

    Player myPlayer;
    myPlayer.Initidle2();
     

                        

    while (!WindowShouldClose()) {
        BeginDrawing();
        myPlayer.Animate();

      
       
        myPlayer.move();
        

        if (IsKeyPressed(KEY_SPACE) && !myPlayer.isattacking) {
            myPlayer.Initiattack();
            myPlayer.isattacking = true;
        }

       

        
        ClearBackground(WHITE);

        

        DrawText("Arrows: move | SPACE: attack ", 10, 10, 20, BLACK);
        myPlayer.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}