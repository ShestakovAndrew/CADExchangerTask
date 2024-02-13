#include <numbers>
#include <sstream>

#include "CHelix.h"
#include "CPoint3D.h"

CHelix::CHelix(double radius, double step) : m_radius(radius), m_step(step)
{
	if (radius < 0)
	{
		throw std::invalid_argument("Radius should be more then 0.");
	}
}

CPoint3D CHelix::Get3DPoint(double t) const
{
	return CPoint3D
	{
		m_radius * std::cos(t),
		m_radius * std::sin(t),
		m_step * t
	};
}

CVector3D CHelix::GetFirstDerivative(double t) const
{
	return CVector3D
	{
		-1 * m_radius * std::sin(t),
		m_radius * std::cos(t),
		m_step
	};
}

double CHelix::GetRadius() const noexcept
{
	return m_radius;
}

double CHelix::GetStep() const noexcept
{
	return m_step;
}

std::string CHelix::ToString() const
{
	std::stringstream sstream;

	sstream
		<< "Type curve: Helix" << std::endl
		<< "Radius: " << GetRadius() << std::endl
		<< "Step: " << GetStep() << std::endl;

	return sstream.str();
}
