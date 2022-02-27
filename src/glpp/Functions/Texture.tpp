#include <glpp/check_errors.h>
#include <glpp/internal/assert_is_bound.h>
#include <glpp/raw.h>

namespace glpp {

// ---
// --- Functions for UniqueTexture
// ---

template<TextureKind Texture_Kind>
void bind_texture(const internal::UniqueTexture<Texture_Kind>& texture)
{
    bind_texture<Texture_Kind>(*texture);
}

template<TextureKind Texture_Kind>
void set_minification_filter(const internal::UniqueTexture<Texture_Kind>& texture, Interpolation interpolation)
{
    set_minification_filter<Texture_Kind>(*texture, interpolation);
}

template<TextureKind Texture_Kind>
void set_magnification_filter(const internal::UniqueTexture<Texture_Kind>& texture, Interpolation interpolation)
{
    set_magnification_filter<Texture_Kind>(*texture, interpolation);
}

template<TextureKind Texture_Kind>
void set_wrap(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap)
{
    set_wrap<Texture_Kind>(*texture, wrap);
}

template<TextureKind Texture_Kind>
void set_horizontal_wrap(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap)
{
    set_horizontal_wrap<Texture_Kind>(*texture, wrap);
}

template<TextureKind Texture_Kind>
void set_vertical_wrap(const internal::UniqueTexture<Texture_Kind>& texture, Wrap wrap)
{
    set_vertical_wrap<Texture_Kind>(*texture, wrap);
}

// ---
// --- Functions for raw texture id
// ---

template<TextureKind Texture_Kind>
void bind_texture(GLuint texture_id)
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_minification_filter(GLuint texture_id, Interpolation interpolation)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its minification filter");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, raw(interpolation));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_magnification_filter(GLuint texture_id, Interpolation interpolation)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its magnification filter");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, raw(interpolation));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_wrap_2D(GLuint texture_id, Wrap wrap)
{
    set_horizontal_wrap<Texture_Kind>(texture_id, wrap);
    set_vertical_wrap<Texture_Kind>(texture_id, wrap);
}

template<TextureKind Texture_Kind>
void set_horizontal_wrap(GLuint texture_id, Wrap wrap)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its wrap mode");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, raw(wrap));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void set_vertical_wrap(GLuint texture_id, Wrap wrap)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its wrap mode");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, raw(wrap));
    glpp_check_errors();
}

template<TextureKind Texture_Kind>
void texture_image(GLuint texture_id, InternalFormat internal_format, GLsizei width, GLsizei height, Channels channels, TexelDataType storage_type, const void* data)
{
    internal::assert_is_bound(GL_TEXTURE_BINDING_2D, static_cast<GLint>(texture_id),
                              "You must bind the texture before setting its image");
    glTexImage2D(GL_TEXTURE_2D, 0, raw(internal_format), width, height, 0, raw(channels), raw(storage_type), data);
    glpp_check_errors();
}

} // namespace glpp
