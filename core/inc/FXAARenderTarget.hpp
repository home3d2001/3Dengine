/**
 * @class	FXAARenderTarget
 * @brief	A render target allows to render objects to it instead of
 *          to the main screen. The target can then be blitted onto the
 *          screen
 *
 *          The FXAA render target applies Fast Aproximate Anti-Aliasing
 *          from Timothy Lottes paper at Nvidia
 *
 * @author	Roberto Cano (http://www.robertocano.es)
 */
#pragma once

#include "RenderTarget.hpp"

class FXAARenderTarget : public RenderTarget
{
	public:
        static FXAARenderTarget *New();
        static void Delete(FXAARenderTarget *target);

        virtual ~FXAARenderTarget() {}

        virtual bool init(uint32_t width, uint32_t height) = 0;
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual void clear() = 0;
        virtual bool blit(uint32_t dstX, uint32_t dstY, uint32_t width, uint32_t height) = 0;
};
