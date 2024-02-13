#include "CCircle.h"

CCircle::CCircle(double radius) : m_radius(radius)
{
	if (radius < 0)
	{
		throw std::invalid_argument("Radius should be more then 0.");
	}
}

CPoint3D CCircle::Get3DPoint(double t) const
{
	return CPoint3D
	{
		m_radius * std::cos(t),
		m_radius * std::sin(t),
		0.0
	};
}

CVector3D CCircle::GetFirstDerivative(double t) const
{
	return CVector3D
	{
		-1 * m_radius * std::sin(t),
		m_radius * std::cos(t),
		0.0
	};
}

double CCircle::GetRadius() const noexcept
{
	return m_radius;
}
