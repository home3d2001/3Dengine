/**
 * @class	TextConsole
 * @brief	Implements an on-screen text console. It provides printf-like capabilities
 *          to print text to a render target. It allows to choose the color, the font type
 *          and the font size.
 *
 * @author	Roberto Cano (http://www.robertocano.es)
 */
#pragma once

#include <glm/glm.hpp>
#include "TrueTypeFont.hpp"
#include "FontRenderer.hpp"
#include "RenderTarget.hpp"

class TextConsole
{
	public:
        bool init(std::string &fontPath, uint32_t fontSize, glm::vec4 &color,
                  uint32_t width, uint32_t height);

        void clear();
        int gprintf(const char *format, ...);
        void blit();

    private:
        uint32_t     _consoleWidth;
        uint32_t     _consoleHeight;
        uint32_t     _fontSize;
        uint32_t     _xPos, _yPos;
        glm::vec4    _fontColor;
        RenderTarget *_renderTarget;
        TrueTypeFont *_font;
        FontRenderer *_fontRenderer;
};