//
// Created by Zachary Buffone on 12/21/21.
//

#include "MeshContainer.hpp"

namespace Garnet {

    MeshContainer::MeshContainer(GameObject* o) : Behaviour(o) {
        this->mesh = nullptr;
    }

    MeshContainer::~MeshContainer() = default;

    void MeshContainer::SetMesh(Mesh *m) {
        this->mesh = m;
    }

    Mesh* MeshContainer::GetMesh() const {
        return this->mesh;
    }

    void MeshContainer::CopySetMesh(Mesh *m) {
        this->mesh = new Mesh(*m);
    }

}