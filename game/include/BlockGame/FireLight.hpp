#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}

namespace BlockGame
{
    class FireLight : public Canis::ScriptableEntity
    {
    public:
        static constexpr const char* ScriptName = "BlockGame::FireLight";

        explicit FireLight(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;
    };

    void RegisterFireLightScript(Canis::App& _app);
    void UnRegisterFireLightScript(Canis::App& _app);
}
