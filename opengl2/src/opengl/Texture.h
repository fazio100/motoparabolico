#pragma once

#include "Renderer.h"

class Texture {
private:
	unsigned int m_RendererID;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
	std::string m_FilePath;

	void Load();

public:

	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	void SetPath(const std::string& newPath);

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

};