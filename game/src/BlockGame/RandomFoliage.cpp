#include <BlockGame/RandomFoliage.hpp>

#include <Canis/App.hpp>
#include <Canis/ConfigHelper.hpp>

namespace BlockGame
{
    namespace
    {
        Canis::ScriptConf scriptConf = {};
    }

    void RegisterRandomFoliageScript(Canis::App& _app)
    {
        REGISTER_PROPERTY(scriptConf, BlockGame::RandomFoliage, numOfFoliage);

        DEFAULT_CONFIG(scriptConf, BlockGame::RandomFoliage);

        scriptConf.DEFAULT_DRAW_INSPECTOR(BlockGame::RandomFoliage);

        _app.RegisterScript(scriptConf);
    }

    DEFAULT_UNREGISTER_SCRIPT(scriptConf, RandomFoliage)

    void RandomFoliage::Create() {}

    void RandomFoliage::Ready() 
    {
        std::vector<Canis::Entity *> objects = entity.GetComponent<Transform>().children;
        int j;

        // initial mass disable
        for(auto object : objects)
        {
            object->active = false;
        }

        // iterate through all child objects and use rand % size to choose a few random plants to turn on at runtime
        // second check for index oob safety
        for(int i = 0; i < numOfFoliage && i < objects.size() - 1; i++)
        {
            j = rand() % objects.size();
            
            // set active then erase the element to remove it from the next round's possibilities
            objects[j]->active = true;
            objects.erase(objects.begin() + j); // needs an iterator (╥﹏╥)
        }
    }

    void RandomFoliage::Destroy() {}

    void RandomFoliage::Update(float) {}
}
