#pragma once
#include "ICurve3D.h"

class CHelix : public ICurve3D
{
public:
	CHelix() = default;
	CHelix(double radius, double step);

	CPoint3D Get3DPoint(double t) const override;
	CVector3D GetFirstDerivative(double t) const override;

	double GetRadius() const noexcept;
	double GetStep() const noexcept;

private:
	double m_radius;
	double m_step;
};

