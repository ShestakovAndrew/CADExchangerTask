#pragma once
#include <iostream>
#include <format>

class CVector3D final
{
public:
	CVector3D() = default;
	CVector3D(double x, double y, double z)
		: m_x(x)
		, m_y(y)
		, m_z(z)
	{
	}

	bool friend operator==(CVector3D const& p1, CVector3D const& p2)
	{
		return (p1.m_x == p2.m_x) && (p1.m_y == p2.m_y) && (p1.m_z == p2.m_z);
	}

	bool friend operator!=(CVector3D const& p1, CVector3D const& p2)
	{
		return !(p1 == p2);
	}

	std::ostream friend& operator<<(std::ostream& stream, CVector3D const& point)
	{
		stream << std::format("x: {}, y: {}, z: {}", point.m_x, point.m_y, point.m_z);
		return stream;
	}

private:
	double m_x, m_y, m_z;
};