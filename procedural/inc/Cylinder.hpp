/**
 * @module  Cylinder
 * @brief	Cylinder procedural generation
 *
 * @author	Roberto Cano (http://www.robertocano.es)
 */
#pragma once

#include <stdint.h>
#include "Model3D.hpp"

namespace Procedural
{
/**
 * Cylinder class to generate a cube with axis aligned planes
 */
class Cylinder : public Model3D
{
  public:
    /**
     * Constructor
     *
     * @param numSides  Number of sides of the cylinder. Minimum is 4 sides, which
     *                  would yield a cube
     * @param color     Color for the default material
     */
    Cylinder(uint32_t numSides = 4, const glm::vec3 &color = glm::vec3(1.0f, 1.0f, 1.0f));
};
};
