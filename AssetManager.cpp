#include "AssetManager.hpp"
#include <iostream>
#include <unordered_map>

// assets' relative path
const std::string RESOURCES_PATH = "resources/";
// texture storage (key: texture's name; value: texture)
// TODO: we might have to use shared pointers to avoid managing the lifetime of textures
std::unordered_map<std::string, sf::Texture> textures;

/*
	load texture from a file
	it will be stored in an unordered map with the <name> parameter as key
*/
void LoadTextureFromFile(std::string name, std::string filename) {
	if(!textures[name].loadFromFile(RESOURCES_PATH + filename))
		std::cout << "Could not load texture: " << filename << std::endl;
}

/*
	get the texture from storage
	the texture MUST be loaded before using this function
*/
sf::Texture GetTexture(std::string name) {
	return textures[name];
}