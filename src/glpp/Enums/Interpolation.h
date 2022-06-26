#pragma once

#include <glad/glad.h>

namespace glpp {

enum class Interpolation : GLint {
    NearestNeighbour   = GL_NEAREST,
    Linear             = GL_LINEAR,
    LinearMipmapLinear = GL_LINEAR_MIPMAP_LINEAR,
};

} // namespace glpp
