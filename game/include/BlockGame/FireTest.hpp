#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}

namespace BlockGame
{
    class TestFire : public Canis::ScriptableEntity
    {
    public:
        static constexpr const char* ScriptName = "BlockGame::FireTest";

        Canis::Entity* hideObject = nullptr;

        explicit TestFire(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;
    };

    void RegisterTestFireScript(Canis::App& _app);
    void UnRegisterTestFireScript(Canis::App& _app);
}
