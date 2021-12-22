//
// Created by Zachary Buffone on 12/7/21.
//

#ifndef GARNET_ENGINE_MESHRENDERER_HPP
#define GARNET_ENGINE_MESHRENDERER_HPP


#include "../Behaviour.hpp"
#include "../../DataStructures/Mesh.hpp"
#include "../GameObject.hpp"
#include "../Drawable.hpp"
#include "../../DataStructures/Material.hpp"

namespace Garnet {

    class MeshRenderer : public Behaviour, public Drawable {
    private:
        Material* material;

    public:
        explicit MeshRenderer(GameObject*);
        ~MeshRenderer();

        void Update() override;

        void SetMaterial(Material* mat);
        Material* GetMaterial() const;

        void Draw() override;
    };

}


#endif //GARNET_ENGINE_MESHRENDERER_HPP
