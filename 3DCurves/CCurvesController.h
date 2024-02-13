#pragma once
#include <vector>
#include <memory>

#include "CCircle.h"
#include "ICurve3D.h"

namespace
{
	enum class CurveType
	{
		CIRCLE = 0,
		ELLIPSE,
		HELIX
	};
}

class CCurvesController
{
public:
	CCurvesController(std::ostream& output);

	void GenerateRandomCurves();
	size_t GetCountCurves() const noexcept;
	void PrintCircleCurvesInfo() const noexcept;
	void PrintCurvesPointAndDerivative(double t) const noexcept;
	void PrintSumRadiiCurvesCircle() const noexcept;
	void SortCircleCurves() noexcept;

private:
	std::ostream& m_output;
	std::vector<std::shared_ptr<ICurve3D>> m_curves;
	std::vector<std::shared_ptr<CCircle>> m_circleCurves;
	double m_sumRadiiCurvesCircle;
};

