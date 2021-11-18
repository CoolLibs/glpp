#pragma once

#include <glad/glad.h>
#include <glpp/Enums/Interpolation.h>
#include <glpp/Enums/Wrap.h>

namespace glpp {

inline GLint raw(Interpolation interpolation)
{
    return static_cast<GLint>(interpolation);
}

inline GLint raw(Wrap wrap)
{
    return static_cast<GLint>(wrap);
}

} // namespace glpp
