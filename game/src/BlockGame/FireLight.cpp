#include <BlockGame/FireLight.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterFireLightScript(Canis::App& _app)
    {
        // REGISTER_PROPERTY(scriptConf, BlockGame::FireLight, exampleProperty);

        DEFAULT_CONFIG(scriptConf, BlockGame::FireLight);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::FireLight);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, FireLight)

    void FireLight::Create() {}

    void FireLight::Ready() {}

    void FireLight::Destroy() {}

    void FireLight::Update(float) {

       PointLight& light = entity.GetComponent<PointLight>();

        light.intensity = light.intensity + ((float)(rand() % 30) / 100.0f) - 0.1f;

        if(light.intensity < 0.1f)
            light.intensity = 0.1f;
        else if(light.intensity > 0.6f)
            light.intensity = 0.6f;

    }
}
