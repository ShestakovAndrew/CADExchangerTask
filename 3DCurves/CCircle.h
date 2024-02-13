#pragma once
#include "ICurve3D.h"

class CCircle : public ICurve3D
{
public:
	CCircle() = default;
	CCircle(double radius);

	CPoint3D Get3DPoint(double t) const override;
	CVector3D GetFirstDerivative(double t) const override;

	double GetRadius() const noexcept;

private:
	double m_radius;
};

