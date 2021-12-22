//
// Created by Zachary Buffone on 12/8/21.
//

#ifndef GARNET_ENGINE_MESHLIBRARY_HPP
#define GARNET_ENGINE_MESHLIBRARY_HPP

#include <map>
#include "../DataStructures/Mesh.hpp"
#include <vector>
#include <string>

namespace Garnet::AssetLibraries {

    class MeshLibrary {
    private:
        std::map<std::string, Mesh *>* meshes;

        std::vector<std::string>* SplitStringAtChar(const std::string& str, char c);
        Mesh* CreateMeshFromFile(std::string);
        void ConvertToFlat(std::vector<MeshVertex>*, std::vector<unsigned int>*);
    public:
        MeshLibrary();
        ~MeshLibrary();

        void LoadMesh(std::string, std::string);
        Mesh* GetMesh(std::string);

    };

}

#endif //GARNET_ENGINE_MESHLIBRARY_HPP
