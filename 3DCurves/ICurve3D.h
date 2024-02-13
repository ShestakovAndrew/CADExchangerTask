#pragma once
#include "CPoint3D.h"
#include "CVector3D.h"

class ICurve3D
{
public:
	virtual ~ICurve3D() = default;

	virtual CPoint3D Get3DPoint(double t) const = 0;
	virtual CVector3D GetFirstDerivative(double t) const = 0;
};

