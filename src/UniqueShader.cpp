#include "UniqueShader.h"

namespace glpp {

UniqueShader::UniqueShader()
    : _id{glCreateProgram()}
{
}

UniqueShader::~UniqueShader()
{
    glDeleteProgram(_id);
}

UniqueShader::UniqueShader(UniqueShader&& rhs) noexcept
    : _id{rhs._id}
{
    rhs._id = decltype(rhs._id){};
}

UniqueShader& UniqueShader::operator=(UniqueShader&& rhs) noexcept
{
    if (&rhs != this) {
        _id     = rhs._id;
        rhs._id = decltype(rhs._id){};
    }
    return *this;
}

} // namespace glpp