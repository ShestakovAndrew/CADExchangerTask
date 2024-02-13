#pragma once
#include <vector>
#include <memory>

#include "ICurve3D.h"

class CCurvesController
{
public:
	CCurvesController(std::ostream& output);

	void GenerateRandomCurves();
	size_t GetCountCurves() const noexcept;
	void PrintCurvesInfo(double t) const noexcept;

private:
	enum class CurveType
	{
		CIRCLE = 0,
		ELLIPSE,
		HELIX
	};

	std::ostream& m_output;
	std::vector<std::shared_ptr<ICurve3D>> m_curves;
};

