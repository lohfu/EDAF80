#include "interpolation.hpp"

glm::vec3
interpolation::evalLERP(glm::vec3 const& p0, glm::vec3 const& p1, float const x)
{
	return glm::vec3(p0 + (p1 - p0) * x);
}

glm::vec3
interpolation::evalCatmullRom(glm::vec3 const& p0, glm::vec3 const& p1,
                              glm::vec3 const& p2, glm::vec3 const& p3,
                              float const t, float const x)
{
	float x2 = x * x;
	float x3 = x2 * x;

	return glm::vec3(
		p0 * (-t * x + 2 * t * x2 - t * x3)
		+ p1 * (1 + (t - 3) * x2 + (2 - t) * x3)
		+ p2 * (t * x + (3 - 2 * t) * x2 + (t - 2) * x3)
		+ p3 * (-t * x2 + t * x3)
	);
}
