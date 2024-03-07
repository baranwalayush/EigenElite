#include "test.h"
#include "raylib.h"

using std::cout, std::endl;

void RunTest();

int main(void)
{
    Collider a(Vec2(10, 10), Vec2(100, 100), false, false, Shape::Type::Circle);
    PhysicsEngine* engine = PhysicsEngine::GetInstance();
    engine->PushPhyObject(&a);
    RunTest();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TITLE");

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        engine->UpdateObjects();
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle((int)a.GetPosition().GetX(), (int)a.GetPosition().GetY(), 10.0f, WHITE);
        EndDrawing();
        cout << a.GetPosition().GetY() << " " << a.GetPosition().GetX() << endl;
    }
    
    CloseWindow();
}

void RunTest() {
    TestEngine();
}

