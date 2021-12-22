//
// Created by Zachary Buffone on 12/13/21.
//

#include "PubSub.hpp"

namespace Garnet {

    void Garnet::PubSub::Subscribe(const std::string& key, FuncPtr fp) {
        if (map.find(key) != map.end())
            map.insert(std::pair<std::string, std::vector<FuncPtr>>(key, std::vector<FuncPtr>()));

        map.at(key).push_back(fp);
    }

    void PubSub::Publish(const std::string& key, void *voidPtr) {
        auto& funcVector = map.at(key);
        for(auto& funcPtr : funcVector) {
            (*funcPtr)(voidPtr);
        }
    }

}
