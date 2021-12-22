cmake_minimum_required(VERSION 3.21)
project(Garnet_Engine CXX)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_H /opt/homebrew/Cellar/glfw/3.3.5/include/GLFW)
set(MOLTENVK_H /opt/homebrew/Caskroom/vulkan-sdk/1.2.162.1/MoltenVK/include/MoltenVK)
set(VULKAN_H /opt/homebrew/Caskroom/vulkan-sdk/1.2.162.1/MoltenVK/include/vulkan)
include_directories(${GLFW_H} ${MOLTENVK_H} ${VULKAN_H})


set(MOLTENVK_LINK /opt/homebrew/Caskroom/vulkan-sdk/1.2.162.1/MoltenVK/dylib/macOS/libMoltenVK.dylib)
set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.3.5/lib/libglfw.3.3.dylib)
link_libraries(${MOLTENVK_LINK} ${GLFW_LINK})


#TEST
include_directories(GarnetEngineTest /usr/local/Cellar/glm/0.9.9.8/include/glm)
add_executable(GarnetEngineTest main.cpp DataStructures/Mesh.cpp DataStructures/Mesh.hpp Mathf.hpp GameObject/GameObject.cpp GameObject/GameObject.hpp GameObject/Behaviour.cpp GameObject/Behaviour.hpp GameObject/BuiltinBehaviours/MeshRenderer.cpp GameObject/BuiltinBehaviours/MeshRenderer.hpp Rendering/Renderer.cpp Rendering/Renderer.hpp GarnetEngine.cpp GarnetEngine.hpp Scene.cpp Scene.hpp Navigation/Navigation.cpp Navigation/Navigation.hpp Navigation/NavGraph.cpp Navigation/NavGraph.hpp Navigation/NavNode.cpp Navigation/NavNode.hpp Navigation/NavConnection.cpp Navigation/NavConnection.hpp AssetLibraries/MeshLibrary.cpp AssetLibraries/MeshLibrary.hpp GameObject/BuiltinBehaviours/Camera.cpp GameObject/BuiltinBehaviours/Camera.hpp DataStructures/Material.cpp DataStructures/Material.hpp GameObject/Drawable.hpp AssetLibraries/ShaderLibrary.cpp AssetLibraries/ShaderLibrary.hpp DataStructures/Shader.cpp DataStructures/Shader.hpp PubSub.cpp PubSub.hpp Input.cpp Input.hpp GameObject/BuiltinBehaviours/SimpleMovementController.cpp GameObject/BuiltinBehaviours/SimpleMovementController.hpp Time.cpp Time.hpp UI/UI.cpp UI/UI.hpp UI/UIObject.cpp UI/UIObject.hpp UI/UIBehaviour.cpp UI/UIBehaviour.hpp UI/BuiltinBehaviours/ImageRenderer.cpp UI/BuiltinBehaviours/ImageRenderer.hpp stb_image.h AssetLibraries/TextureLibrary.cpp AssetLibraries/TextureLibrary.hpp DataStructures/Texture.cpp DataStructures/Texture.hpp GameObject/BuiltinBehaviours/ConstantRotation.cpp GameObject/BuiltinBehaviours/ConstantRotation.hpp Physics/Raycasting.cpp Physics/Raycasting.hpp GameObject/BuiltinBehaviours/MeshContainer.cpp GameObject/BuiltinBehaviours/MeshContainer.hpp)
target_link_libraries(GarnetEngineTest "-framework OpenGL")


#LIBRARY
