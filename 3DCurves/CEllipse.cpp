#include <sstream>

#include "CEllipse.h"

CEllipse::CEllipse(double radiusX, double radiusY) : m_radiusX(radiusX), m_radiusY(radiusY)
{
	if (radiusX < 0 || radiusY < 0)
	{
		throw std::invalid_argument("Radius should be more then 0.");
	}
}

CPoint3D CEllipse::Get3DPoint(double t) const
{
	return CPoint3D
	{
		m_radiusX * std::cos(t),
		m_radiusY * std::sin(t),
		0.0
	};
}

CVector3D CEllipse::GetFirstDerivative(double t) const
{
	return CVector3D
	{
		-1 * m_radiusX * std::sin(t),
		m_radiusY * std::cos(t),
		0.0
	};
}

double CEllipse::GetHorizontalRadius() const noexcept
{
	return m_radiusX;
}

double CEllipse::GetVerticalRadius() const noexcept
{
	return m_radiusY;
}

std::string CEllipse::ToString() const
{
	std::stringstream sstream;

	sstream
		<< "Type curve: Ellipse" << std::endl
		<< "Horizontal Radius: " << GetHorizontalRadius() << std::endl
		<< "Vertical Radius: " << GetVerticalRadius() << std::endl;

	return sstream.str();
}