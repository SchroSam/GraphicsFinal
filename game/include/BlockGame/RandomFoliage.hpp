#pragma once

#include <Canis/Entity.hpp>

namespace Canis
{
    class App;
}

namespace BlockGame
{
    class RandomFoliage : public Canis::ScriptableEntity
    {
    public:
        static constexpr const char* ScriptName = "BlockGame::RandomFoliage";

        explicit RandomFoliage(Canis::Entity& _entity) : Canis::ScriptableEntity(_entity) {}

        int numOfFoliage;

        void Create() override;
        void Ready() override;
        void Destroy() override;
        void Update(float _dt) override;
    };

    void RegisterRandomFoliageScript(Canis::App& _app);
    void UnRegisterRandomFoliageScript(Canis::App& _app);
}
