#include "Mesh.h"


Mesh::Mesh(
	float* vertices, unsigned int size,
	unsigned int* indices, unsigned int count,
	const std::string& shaderPath, const std::string& texturePath
) : 
	verticesData(vertices), indicesData(indices),
	vbo(vertices, size), ibo(indices, count),
	layout(),
	shader(shaderPath), texture(texturePath)
{
	layout.Push<float>(2);
	layout.Push<float>(2);
	vao.AddBuffer(vbo, layout);
	BindTexture();

}

void Mesh::BindTexture() {
	shader.Bind();
	texture.Bind();
	shader.SetUniform1i("u_Texture", 0);
}

void Mesh::Draw(Renderer& renderer)
{
	renderer.Draw(vao, ibo, shader);
}
