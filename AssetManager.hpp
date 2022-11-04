#pragma once
#include <string>
#include <SFML/Graphics/Texture.hpp>

/*
	load texture from a file
	it will be stored in an unordered map with the <name> parameter as key
*/
void LoadTextureFromFile(std::string name, std::string filename);

/*
	get the texture from storage
	the texture MUST be loaded before using this function
*/
sf::Texture GetTexture(std::string name);