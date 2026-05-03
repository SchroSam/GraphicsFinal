#include <BlockGame/FireTest.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <Canis/AssetManager.hpp>
#include <string>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterTestFireScript(Canis::App& _app)
    {
        // REGISTER_PROPERTY(scriptConf, BlockGame::TestFire, hideObject);

        DEFAULT_CONFIG(scriptConf, BlockGame::TestFire);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::TestFire);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, TestFire)

    void TestFire::Create() {}

    void TestFire::Ready() {}

    void TestFire::Destroy() {}

    void TestFire::Update(float _dt) 
    {

        // Fire Texture logic
        static float timer = 0.0f;
        static float maxTimer = 0.05f;
        static int fireNum = 1;
        static i32 textureId = AssetManager::LoadTexture("assets/textures/fire_textures/fire_1.png");

        timer += _dt;

        if(timer >= maxTimer)
        {
            timer = 0.0f;
            
            // fancy increment and comparison in one line
            if(++fireNum > 31)
                fireNum = 1;

            textureId = AssetManager::LoadTexture("assets/textures/fire_textures/fire_" + std::to_string(fireNum) + ".png");

            entity.GetComponent<Material>().materialFields.SetTexture("albedoFireMap", textureId);

        }

    }
}
