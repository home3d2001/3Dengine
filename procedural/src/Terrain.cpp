/**
 * @module  Terrain
 * @brief	Terrain procedural generation. This terrain is generated by using a normal
 *          plane with the indicated number of vertices, and offseting the height by
 *          using an octave perlin noise function
 *
 * @author	Roberto Cano (http://www.robertocano.es)
 */
#include "Terrain.hpp"
#include <glm/glm.hpp>
#include "Asset3DTransform.hpp"
#include "Logging.hpp"
#include "MathUtils.hpp"
#include "ProceduralUtils.hpp"

using namespace Logging;
using namespace Procedural;
using namespace MathUtils;

Terrain::Terrain(float width, float depth, float height, uint32_t slice, const glm::vec3 &color, uint32_t numVertsWidth,
                 uint32_t numVertsDepth, uint32_t numOctaves, float persistence)
    : _width(width)
    , _depth(depth)
    , _height(height)
    , _slice(slice)
    , _color(color)
    , _numVertsWidth(numVertsWidth)
    , _numVertsDepth(numVertsDepth)
{
    float minHeight = _height;
    uint32_t nData = 0;

    AppendBentPlane(*this, _width, _depth, 0.0f, 0.0f, 0.0f, _numVertsWidth, _numVertsDepth);

    /* Now modify the height according to the octave perlin noise function */
    Asset3D::VertexData *data = &_asset->_vertexData[0];

    for (uint32_t i = 0; i < numVertsWidth; ++i) {
        for (uint32_t j = 0; j < numVertsDepth; ++j) {
            /* Generate the vertex height */
            data[nData].vertex.y =
                (float)(Perlin::Octave(i / (float)_numVertsWidth, (float)_slice, j / (float)_numVertsDepth, numOctaves, persistence) *
                        _height);
            if (data[nData].vertex.y < minHeight) {
                minHeight = data[nData].vertex.y;
            }
            nData++;
        }
    }

    /* Adjust the height to the minimum value and
     * readjust the normals */
    nData = 0;
    for (uint32_t i = 0; i < numVertsWidth; ++i) {
        for (uint32_t j = 0; j < numVertsDepth; ++j) {
            data[nData++].vertex.y -= minHeight;
        }
    }

    Asset3DTransform::RecalculateNormals(*this);
    Asset3DTransform::SetUniqueMaterialFromColor(*this, _color);
}
