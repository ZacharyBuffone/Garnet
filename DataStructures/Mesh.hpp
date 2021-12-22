//
// Created by Zachary Buffone on 12/7/21.
//

#ifndef GARNET_ENGINE_MESH_HPP
#define GARNET_ENGINE_MESH_HPP

#include <glm.hpp>
#include <vector>

namespace Garnet {

    struct MeshVertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;
        glm::vec3 color;

    };

    class Mesh {
    public:
        enum WritableSetting { Readonly, Writable, Inherit };
    private:
        std::vector<MeshVertex> vertices;
        std::vector<unsigned int> triangles;

        bool writable;

    public:
        unsigned int vao, vbo, ebo;

        Mesh();
        Mesh(Mesh&, WritableSetting = WritableSetting::Inherit);
        Mesh(std::vector<MeshVertex>&, std::vector<unsigned int>&, bool = true);

        void SetVertices(const std::vector<MeshVertex>&);
        void SetTriangles(const std::vector<unsigned int>&);

        const std::vector<MeshVertex>& GetVertices() const;
        const std::vector<unsigned int>& GetTriangles() const;

        int GetNumberOfVertices();
        int GetSizeOfTriangleArray();
        int GetNumberOfTriangles();

        bool IsWritable();

    };

}


#endif //GARNET_ENGINE_MESH_HPP
