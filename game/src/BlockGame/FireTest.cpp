#include <BlockGame/FireTest.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>
#include <Canis/AssetManager.hpp>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterTestFireScript(Canis::App& _app)
    {
        REGISTER_PROPERTY(scriptConf, BlockGame::TestFire, hideObject);

        DEFAULT_CONFIG(scriptConf, BlockGame::TestFire);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::TestFire);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, TestFire)

    void TestFire::Create() {}

    void TestFire::Ready() {
        if (hideObject)
            hideObject->Destroy();
        
        i32 textureId = AssetManager::LoadTexture("assets/textures/fire_textures/fire_1.png");
        i32 materialId = entity.GetComponent<Material>().materialId;
        //MaterialAsset* material = AssetManager::GetMaterial(materialId);
        //material->albedoId = textureId;
        entity.GetComponent<Material>().materialFields.SetTexture("albedoFireMap", textureId);
    }

    void TestFire::Destroy() {}

    void TestFire::Update(float) {}
}
