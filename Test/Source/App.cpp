#include "test.h"
#include "raylib.h"

using std::cout, std::endl;

void RunTest();

class App {
        PhysicsEngine* m_Engine;
        static i32 m_Fps;
    public:
        App() {
            InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "TITLE");
            SetTargetFPS(m_Fps);
            m_Engine = PhysicsEngine::GetInstance();
        }

        void Add(Collider* theCollider) {
            m_Engine->PushPhyObject(theCollider);
        }

        void Update() {
            while (!WindowShouldClose()) {
                m_Engine->Simulate();
                BeginDrawing();
                ClearBackground(BLACK);
                for (i32 i = 0; i < m_Engine->GetSize(); i++) {
                    DrawCircle((int)m_Engine->GetPhysicsObject(i)->GetPosition().GetX(),
                            (int)m_Engine->GetPhysicsObject(i)->GetPosition().GetY(), 10.0f,
                            Color{(unsigned char)(10 * (i * 10)), 0, 255, 255});
                }
                EndDrawing();
            }
            CloseWindow();
        }


};
i32 App::m_Fps = CURR_FPS;

i32 main(void)
{
    RunTest();
    Collider a(Vec2(4, 0), Vec2(100, 100), false, true, Shape::Type::Circle);
    Collider b(Vec2(-1, 1), Vec2(200, 100), false, true, Shape::Type::Circle);
    Collider c(Vec2(-1, 1), Vec2(300, 300), false, true, Shape::Type::Circle);
    Collider d(Vec2(-1, 1), Vec2(300, 400), false, true, Shape::Type::Circle);
    Collider e(Vec2(-1, 1), Vec2(300, 500), false, true, Shape::Type::Circle);

    App app;
    app.Add(&a);
    app.Add(&b);
    app.Add(&c);
    app.Add(&d);
    app.Add(&e);

    app.Update();

    return 0;
}

void RunTest() {
    TestVec2<i32>();
}

