//
// Created by Zachary Buffone on 12/13/21.
//

#ifndef GARNET_ENGINE_PUBSUB_HPP
#define GARNET_ENGINE_PUBSUB_HPP

#include <vector>
#include <map>
#include <string>

namespace Garnet {

    class PubSub {
    public:
        typedef void (*FuncPtr)(void*);

    private:
        std::map<std::string, std::vector<FuncPtr>> map;
        static PubSub* instance;

        PubSub() {
            map = std::map<std::string, std::vector<FuncPtr>>();
        }
    public:
        ~PubSub() = default;
        static PubSub& GetInstance() {
            if(instance == nullptr) {
                instance = new PubSub();
            }
            return *instance;
        }

        void Subscribe(const std::string&, FuncPtr);
        void Publish(const std::string&, void*);

    };

}

#endif //GARNET_ENGINE_PUBSUB_HPP
