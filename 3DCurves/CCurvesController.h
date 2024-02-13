#pragma once
#include <vector>
#include <memory>

#include "ICurve3D.h"

class CCurvesController
{
public:
	CCurvesController() = default;

	void GenerateRandomCurves();
	size_t GetCountCurves() const noexcept;

private:
	enum class CurveType
	{
		CIRCLE = 0,
		ELLIPSE,
		HELIX
	};

	std::vector<std::shared_ptr<ICurve3D>> m_curves;
};

