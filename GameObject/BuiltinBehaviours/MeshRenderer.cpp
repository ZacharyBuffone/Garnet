//
// Created by Zachary Buffone on 12/7/21.
//

#include "MeshRenderer.hpp"
#include "../../GarnetEngine.hpp"

namespace Garnet {
    MeshRenderer::MeshRenderer(GameObject* o) : Behaviour(o) {
        this->material = nullptr;
    }

    void MeshRenderer::Update() {}

    void MeshRenderer::Draw() {
        Rendering::Renderer::DrawMeshRenderer(*this, *(this->gameObject->GetBehaviour<MeshContainer>()));
    }

    void MeshRenderer::SetMaterial(Material *mat) {
        this->material = mat;
    }

    Material *MeshRenderer::GetMaterial() const {
        return this->material;
    }

    MeshRenderer::~MeshRenderer() = default;

}
