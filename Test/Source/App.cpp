#include "test.h"
#include "raylib.h"

using std::cout, std::endl;

void RunTest();

int main(void)
{
    Collider a(Vec2(1, 1), Vec2(100, 100), true, true, Shape::Type::Circle);
    Collider b(Vec2(1, 1), Vec2(200, 100), true, true, Shape::Type::Circle);
    PhysicsEngine* engine = PhysicsEngine::GetInstance();
    engine->SetGravity(0.0, 1.0);
    engine->PushPhyObject(&a);
    engine->PushPhyObject(&b);
    RunTest();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TITLE");

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        engine->Simulate();
        BeginDrawing();
        ClearBackground(BLACK);
        for (i32 i = 0; i < 2; i++) {
            DrawCircle((int)engine->GetPhysicsObject(i)->GetPosition().GetX(),
                    (int)engine->GetPhysicsObject(i)->GetPosition().GetY(), 10.0f, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();
}

void RunTest() {
    TestEngine();
}

