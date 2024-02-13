#include <random>
#include <unordered_map>

#include "CCurvesController.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CHelix.h"

CCurvesController::CCurvesController(std::ostream& output) 
	: m_output(output)
	, m_sumRadiiCurvesCircle(0)
{
}

void CCurvesController::GenerateRandomCurves()
{
	Reset();

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> randomCountCurvesDist(1, 300);
	std::uniform_int_distribution<> randomCurvesTypeDist(0, 2);
	std::uniform_real_distribution<double> randomRadiusDist(0, 20);
	std::uniform_real_distribution<double> randomStepDist(0, 15);

	for (size_t i = 0; i < randomCountCurvesDist(gen); i++)
	{
		switch (static_cast<CurveType>(randomCurvesTypeDist(gen)))
		{
			case CurveType::CIRCLE:
			{
				m_curves.push_back(std::make_shared<CCircle>
					(randomRadiusDist(gen))
				);
				m_circleCurves.emplace_back(
					std::dynamic_pointer_cast<CCircle>(m_curves.back())
				);
				m_sumRadiiCurvesCircle += m_circleCurves.back()->GetRadius();
				break;
			}
			case CurveType::ELLIPSE:
			{
				m_curves.push_back(std::make_shared<CEllipse>
					(randomRadiusDist(gen), randomRadiusDist(gen))
				);
				break;
			}
			case CurveType::HELIX:
			{
				m_curves.push_back(std::make_shared<CHelix>
					(randomRadiusDist(gen), randomStepDist(gen))
				);
				break;
			}
			default:
			{
				throw std::logic_error("Error create random curve.");
			}
		}
	}
}

size_t CCurvesController::GetCountCurves() const noexcept
{
	return m_curves.size();
}

void CCurvesController::PrintCircleCurvesInfo() const noexcept
{
	if (m_circleCurves.size() == 0)
	{
		m_output << "No circles curves for print information." << std::endl;
		return;
	}

	for (auto const& circleCurve : m_circleCurves)
	{
		m_output << circleCurve->ToString() << std::endl;
	}
}

void CCurvesController::PrintCurvesPointAndDerivative(double t) const noexcept
{
	if (m_curves.size() == 0)
	{
		m_output << "Generate curves before print information." << std::endl;
		return;
	}

	for (auto const& curve : m_curves)
	{
		m_output 
			<< curve->ToString()
			<< "Parameter t: " << t << std::endl
			<< "Coordinate of point: " << curve->Get3DPoint(t) << std::endl
			<< "First Derivative: " << curve->GetFirstDerivative(t) << std::endl << std::endl;
	}
}

void CCurvesController::PrintSumRadiiCurvesCircle() const noexcept
{
	m_output << "Sum of radii of circle curves: " << m_sumRadiiCurvesCircle << std::endl;
}

void CCurvesController::SortCircleCurves() noexcept
{
	std::sort(m_circleCurves.begin(), m_circleCurves.end(), 
		[](auto const& lh, auto const& rh)
		{
			return lh->GetRadius() < rh->GetRadius();
		}
	);
}

void CCurvesController::Reset() noexcept
{
	m_curves.clear();
	m_circleCurves.clear();
	m_sumRadiiCurvesCircle = 0;
}
