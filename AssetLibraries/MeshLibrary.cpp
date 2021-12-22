//
// Created by Zachary Buffone on 12/8/21.
//

#include "MeshLibrary.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>


namespace Garnet::AssetLibraries {

    MeshLibrary::MeshLibrary() {
        this->meshes = new std::map<std::string, Mesh*>();

    }

    MeshLibrary::~MeshLibrary() {
        delete this->meshes;
    }

    void MeshLibrary::LoadMesh(std::string path, std::string name) {
        if(!(this->meshes->find(name) == this->meshes->end()))
            throw std::runtime_error("Trying to load a mesh when mesh with name given already exists;");

        Mesh* mesh = this->CreateMeshFromFile(path);
        meshes->insert(std::pair<std::string, Mesh*>(name, mesh));
    }

    Mesh* MeshLibrary::GetMesh(std::string name) {
        return this->meshes->at(name);
    }


    Mesh* MeshLibrary::CreateMeshFromFile(std::string path) {
        auto vertices = std::vector<MeshVertex>();
        auto normalRefs = std::vector<glm::vec3>();
        auto triangles = std::vector<unsigned int>();
        auto uvRefs = std::vector<glm::vec2>();

        path = std::filesystem::current_path().append(path);

        std::ifstream stream = std::ifstream(path);

        std::string line;
        while (std::getline(stream, line)) {

            //split at ' '
            auto elements = this->SplitStringAtChar(line, ' ');

            if (elements->at(0) == "v") {
                auto vert = MeshVertex();
                vert.position = glm::vec3(
                        std::stof(elements->at(1)),
                        std::stof(elements->at(2)),
                        std::stof(elements->at(3))
                );
                vertices.push_back(vert);
            } else if (elements->at(0) == "vn") {
                auto vec = glm::vec3(
                        std::stof(elements->at(1)),
                        std::stof(elements->at(2)),
                        std::stof(elements->at(3))
                );
                normalRefs.push_back(vec);
            } else if (elements->at(0) == "vt") {
                auto uv = glm::vec2(
                        std::stof(elements->at(1)),
                        std::stof(elements->at(2))
                );
                uvRefs.push_back(uv);
            } else if (elements->at(0) == "f") {
                auto geom1 = this->SplitStringAtChar(elements->at(1), '/');
                auto geom2 = this->SplitStringAtChar(elements->at(2), '/');
                auto geom3 = this->SplitStringAtChar(elements->at(3), '/');

                auto vertIndex1 = std::stoi(geom1->at(0)) - 1;
                auto vertIndex2 = std::stoi(geom2->at(0)) - 1;
                auto vertIndex3 = std::stoi(geom3->at(0)) - 1;

                triangles.push_back(vertIndex1);
                triangles.push_back(vertIndex2);
                triangles.push_back(vertIndex3);

                auto& vert1 = vertices.at(vertIndex1);
                auto& vert2 = vertices.at(vertIndex2);
                auto& vert3 = vertices.at(vertIndex3);

                vert1.normal = glm::vec3(normalRefs.at(std::stoi(geom1->at(2)) - 1));
                vert2.normal = glm::vec3(normalRefs.at(std::stoi(geom2->at(2)) - 1));
                vert3.normal = glm::vec3(normalRefs.at(std::stoi(geom3->at(2)) - 1));

                vert1.uv = glm::vec2(uvRefs.at(std::stoi(geom1->at(1)) - 1));
                vert2.uv = glm::vec2(uvRefs.at(std::stoi(geom2->at(1)) - 1));
                vert3.uv = glm::vec2(uvRefs.at(std::stoi(geom3->at(1)) - 1));

                delete geom1;
                delete geom2;
                delete geom3;
            }

            delete elements;
        }

        ConvertToFlat(&vertices, &triangles);

        Mesh* mesh = new Mesh(vertices, triangles, false);
        return mesh;
    }

    std::vector<std::string>* MeshLibrary::SplitStringAtChar(const std::string& str, char c) {
        auto vec = new std::vector<std::string>();
        std::istringstream lineStream = std::istringstream(str);
        std::string element;
        while(getline(lineStream, element, c)) {
            vec->push_back(element);
        }

        return vec;
    }

    void MeshLibrary::ConvertToFlat(std::vector<MeshVertex>* vertices, std::vector<unsigned int>* triangles) {
        auto newVertices = std::vector<MeshVertex>();
        auto newTriangles = std::vector<unsigned int>();

        for(int i = 0; i < triangles->size() / 3; i++) {
            auto vert1 = vertices->at(triangles->at(i*3 + 0));
            auto vert2 = vertices->at(triangles->at(i*3 + 1));
            auto vert3 = vertices->at(triangles->at(i*3 + 2));
            newVertices.push_back(vert1);
            newVertices.push_back(vert2);
            newVertices.push_back(vert3);
            newTriangles.push_back(i*3 + 0);
            newTriangles.push_back(i*3 + 1);
            newTriangles.push_back(i*3 + 2);
        }

        *vertices = std::move(newVertices);
        *triangles = std::move(newTriangles);
    }

}
