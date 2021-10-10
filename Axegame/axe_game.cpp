#include "raylib.h"

int main()
{
    // window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Quinton's Window");

    // circle variables
    int circle_x{200};
    int circle_y{200};
    int circle_R{25};
    int l_circle_x{circle_x - circle_R};
    int r_circle_x{circle_x + circle_R};
    int u_circle_y{circle_y - circle_R};
    int d_circle_y{circle_y + circle_R};


    // rectangle variables
    int rec_x{400};
    int rec_y{0};
    int rec_length{50};
    int direction{10};
    int l_axe_x{rec_x};
    int u_axe_y{rec_y};
    int r_axe_x{rec_x + rec_length};
    int b_axe_y{rec_y + rec_length};

    // game variable
    bool collision_with_axe = 
                            (b_axe_y >= u_circle_y) && 
                            (u_axe_y <= d_circle_y) && 
                            (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x);

    SetTargetFPS(60);
    while(WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if(collision_with_axe == true)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            // Game logic begins

            // Update variables
            l_circle_x = circle_x - circle_R;
            r_circle_x = circle_x + circle_R;
            u_circle_y = circle_y - circle_R;
            d_circle_y = circle_y + circle_R;
            l_axe_x = rec_x;
            r_axe_x = rec_x + rec_length;
            u_axe_y = rec_y;
            b_axe_y = rec_y + rec_length;

            // Update collison with axe
            collision_with_axe = 
                            (b_axe_y >= u_circle_y) && 
                            (u_axe_y <= d_circle_y) && 
                            (l_axe_x <= r_circle_x) && (r_axe_x >= l_circle_x);


            DrawCircle(circle_x, circle_y, circle_R, BLUE);
            DrawRectangle(rec_x, rec_y, rec_length, rec_length, RED);

            // Move the axe
            rec_y += direction;
            if(rec_y > height || rec_y < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }

            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }

            // Game logic ends
        }
        EndDrawing();
    }
}