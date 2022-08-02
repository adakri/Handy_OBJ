#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>

//Function for loading shaders (fragment/vertex) from files

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

#endif