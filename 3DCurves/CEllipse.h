#pragma once
#include "ICurve3D.h"

class CEllipse : public ICurve3D
{
public:
	CEllipse() = default;
	CEllipse(double radiusX, double radiusY);

	CPoint3D Get3DPoint(double t) const override;
	CVector3D GetFirstDerivative(double t) const override;

	double GetHorizontalRadius() const noexcept;
	double GetVerticalRadius() const noexcept;

private:
	double m_radiusX;
	double m_radiusY;
};

