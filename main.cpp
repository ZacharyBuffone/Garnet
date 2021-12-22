#include <iostream>
#include <glfw3.h>

#include "GarnetEngine.hpp"
#include "Scene.hpp"
#include "GameObject/GameObject.hpp"
#include "GameObject/BuiltinBehaviours/MeshRenderer.hpp"
#include "GameObject/BuiltinBehaviours/Camera.hpp"
#include "DataStructures/Material.hpp"
#include "GameObject/BuiltinBehaviours/SimpleMovementController.hpp"
#include "GameObject/BuiltinBehaviours/ConstantRotation.hpp"
#include "GameObject/BuiltinBehaviours/MeshContainer.hpp"


int main() {

    //initialization
    Garnet::GarnetEngine::Initialize();
    Garnet::GarnetEngine& garnetEngine = Garnet::GarnetEngine::GetEngine();

    auto* scene = new Garnet::Scene();
    garnetEngine.SetCurrentScene(scene);

    //load asset
    garnetEngine.GetMeshLibrary().LoadMesh("House.obj", "House");
    garnetEngine.GetMeshLibrary().LoadMesh("Cube.obj", "Cube");
    garnetEngine.GetMeshLibrary().LoadMesh("Sphere.obj", "Sphere");
    garnetEngine.GetMeshLibrary().LoadMesh("Snowman.obj", "Snowman");
    garnetEngine.GetShaderLibrary().LoadShader("Shaders/NormColor.vs", "Shaders/NormColor.fs", "NormColor");
    garnetEngine.GetShaderLibrary().LoadShader("Shaders/SimpleTexture.vs", "Shaders/SimpleTexture.fs", "SimpleTexture");
    garnetEngine.GetTextureLibrary().LoadTexture("test.png", "Test");

    //create materials
    auto* mat = new Garnet::Material(garnetEngine.GetShaderLibrary().GetShader("SimpleTexture"));
    mat->AddTextureProperty("MainTex", Garnet::MaterialPropertyType::tex2d, garnetEngine.GetTextureLibrary().GetTexture("Test"));

    //create objects and behaviours
    //House *******************
    Garnet::GameObject* house = new Garnet::GameObject("House");
    scene->AddGameObject(house);
    house->SetScale(glm::vec3(1.f, 1.f, 1.f));

    house->AddBehaviour<Garnet::MeshContainer>()->SetMesh(garnetEngine.GetMeshLibrary().GetMesh("House"));
    house->AddBehaviour<Garnet::MeshRenderer>()->SetMaterial(mat);

    //Snowman *******************
    Garnet::GameObject* snowman = new Garnet::GameObject("Snowman");
    scene->AddGameObject(snowman);
    house->SetScale(glm::vec3(1.f, 1.f, 1.f));
    house->SetPosition(glm::vec3(-10.f, 0.f, 0.f));

    snowman->AddBehaviour<Garnet::MeshContainer>()->SetMesh(garnetEngine.GetMeshLibrary().GetMesh("Snowman"));
    snowman->AddBehaviour<Garnet::MeshRenderer>()->SetMaterial(mat);

    /*
    Garnet::GameObject* CubeParent = new Garnet::GameObject("Cube Parent");
    scene->AddGameObject(CubeParent);
    CubeParent->SetPosition(glm::vec3(-5.f, 0.f, 0.f));

    Garnet::GameObject* Cube = new Garnet::GameObject("Cube");
    scene->AddGameObject(Cube);
    Cube->SetScale(glm::vec3(2.5f, 2.5f, 2.5f));
    Cube->SetPosition(glm::vec3(5.f, 0.f, 0.f));
    Cube->SetParent(CubeParent);

    auto mr1 = Cube->AddBehaviour<Garnet::MeshRenderer>();
    mr1->SetMesh(garnetEngine.GetMeshLibrary().GetMesh("Cube"));
    mr1->SetMaterial(mat);
    */

    //sphere *******************
    Garnet::GameObject* Sphere = new Garnet::GameObject("Sphere");
    scene->AddGameObject(Sphere);
    Sphere->SetScale(glm::vec3(2.5f, 2.5f, 2.5f));
    Sphere->SetPosition(glm::vec3(-5.f, 0.f, 0.f));

    Sphere->AddBehaviour<Garnet::MeshContainer>()->SetMesh(garnetEngine.GetMeshLibrary().GetMesh("Sphere"));
    Sphere->AddBehaviour<Garnet::MeshRenderer>()->SetMaterial(mat);
    Sphere->AddBehaviour<Garnet::ConstantRotation>()->Speed(glm::vec3(0.f, 5.f, 0.f));

    //camera *******************
    Garnet::GameObject* cameraObject = new Garnet::GameObject("Main Camera");
    scene->AddGameObject(cameraObject);
    cameraObject->SetPosition(glm::vec3(0.0f, 0.0f, 0.0f));

    auto* camera = cameraObject->AddBehaviour<Garnet::Camera>();
    camera->SetFOV(90.0f);
    camera->SetNearClipping(.1f);
    camera->SetFarClipping(500.0f);

    cameraObject->AddBehaviour<Garnet::SimpleMovementController>();

    //start the engine
    garnetEngine.Start();

    /*
     *  ***************************
     *  Engine is in game loop here
     *  ***************************
     */

    //terminate it when it stops
    Garnet::GarnetEngine::Terminate();

    return 0;
}
