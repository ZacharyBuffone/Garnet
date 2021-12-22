//
// Created by Zachary Buffone on 12/7/21.
//

#include "Mesh.hpp"
#include "../Rendering/Renderer.hpp"
#include <cstdlib>
#include <system_error>

namespace Garnet {

    Mesh::Mesh() {
        this->vao = this->vbo = this->ebo = -1;

        this->writable = true;

        this->vertices = std::vector<MeshVertex>();
        this->triangles = std::vector<unsigned int>();

        Rendering::Renderer::SetupMesh(*this);
    }

    Mesh::Mesh(Mesh& old, Mesh::WritableSetting writableSetting) {
        this->vao = this->vbo = this->ebo = -1;

        this->vertices = std::vector<MeshVertex>(old.vertices);
        this->triangles = std::vector<unsigned int>(old.triangles);

        switch(writableSetting) {
            case Mesh::WritableSetting::Readonly:
                this->writable = false;
                break;
            case Mesh::WritableSetting::Writable:
                this->writable = true;
                break;
            case Mesh::WritableSetting::Inherit:
                this->writable = old.writable;
                break;
        }

        Rendering::Renderer::SetupMesh(*this);
    }

    Mesh::Mesh(std::vector<MeshVertex>& vertices, std::vector<unsigned int>& triangles, bool isWritable) {
        if(triangles.size()%3 != 0)
            throw std::runtime_error("Triangle array size must be a multiple of 3.");
        this->vao = this->vbo = this->ebo = -1;

        this->writable = isWritable;

        this->vertices = std::vector<MeshVertex>(vertices);
        this->triangles = std::vector<unsigned int>(triangles);

        Rendering::Renderer::SetupMesh(*this);
    }

    void Mesh::SetVertices(const std::vector<MeshVertex>& vertices) {
        if(!writable)
            throw new std::runtime_error("Trying to modify a readonly mesh");

        this->vertices = std::vector<MeshVertex>(vertices);
    }

    void Mesh::SetTriangles(const std::vector<unsigned int>& triangles) {
        if(!writable)
            throw new std::runtime_error("Trying to modify a readonly mesh");

        this->triangles = std::vector<unsigned int>(triangles);
    }

    const std::vector<MeshVertex>& Mesh::GetVertices() const {
        return this->vertices;
    }

    const std::vector<unsigned int>& Mesh::GetTriangles() const {
        return this->triangles;
    }

    int Mesh::GetNumberOfVertices() {
        return this->vertices.size();
    }

    int Mesh::GetSizeOfTriangleArray() {
        return this->triangles.size();
    }

    int Mesh::GetNumberOfTriangles() {
        return this->triangles.size()/3;
    }

    bool Mesh::IsWritable() {
        return this->writable;
    }

}