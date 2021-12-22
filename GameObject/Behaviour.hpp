//
// Created by Zachary Buffone on 12/7/21.
//

#ifndef GARNET_ENGINE_BEHAVIOUR_HPP
#define GARNET_ENGINE_BEHAVIOUR_HPP

#include "GameObject.hpp"


namespace Garnet {
    class GameObject;

    class Behaviour {
    protected:
        GameObject* gameObject;

    public:
        Behaviour(GameObject*);
        ~Behaviour();

        virtual void Initialize();
        virtual void Update();

        GameObject* GetGameObject() const;


    };

}


#endif //GARNET_ENGINE_BEHAVIOUR_HPP
