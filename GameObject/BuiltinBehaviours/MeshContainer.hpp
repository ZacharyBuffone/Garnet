//
// Created by Zachary Buffone on 12/21/21.
//

#ifndef GARNET_ENGINE_MESHCONTAINER_HPP
#define GARNET_ENGINE_MESHCONTAINER_HPP

#include "../../DataStructures/Mesh.hpp"
#include "../GameObject.hpp"

namespace Garnet {

    class MeshContainer : public Behaviour {
    private:
        Mesh* mesh;
    public:
        explicit MeshContainer(GameObject* o);
        ~MeshContainer();
        void SetMesh(Mesh*);
        void CopySetMesh(Mesh*);
        Mesh* GetMesh() const;
    };

}

#endif //GARNET_ENGINE_MESHCONTAINER_HPP
