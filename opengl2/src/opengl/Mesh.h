#pragma once
#include "Shader.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"
#include "Texture.h"
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"

#define NO_TEXTURE ""

class Mesh
{
public:
	//std::vector<float> verticesData;
	float* verticesData;
	//std::vector<unsigned int> indicesData;
	unsigned int* indicesData;
	VertexBuffer vbo;
	VertexArray vao;
	IndexBuffer ibo;
	VertexBufferLayout layout;
	Shader shader;
	Texture texture;

	Mesh(float*, unsigned int, unsigned int*, unsigned int, const std::string&, const std::string&);
	
	void BindTexture();

	void Draw(Renderer& renderer);

};

