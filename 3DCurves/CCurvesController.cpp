#include <random>
#include <unordered_map>

#include "CCurvesController.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CHelix.h"

void CCurvesController::GenerateRandomCurves()
{
	if (m_curves.size() != 0)
	{
		m_curves.clear();
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> randomCountCurvesDist(1, 10);
	std::uniform_int_distribution<> randomCurvesTypeDist(0, 2);
	std::uniform_real_distribution<double> randomRadiusDist(0, 20);
	std::uniform_real_distribution<double> randomStepDist(0, 15);

	for (size_t i = 0; i < randomCountCurvesDist(gen); i++)
	{
		switch (static_cast<CCurvesController::CurveType>(randomCurvesTypeDist(gen)))
		{
			case CCurvesController::CurveType::CIRCLE:
			{
				m_curves.push_back(std::make_shared<CCircle>
					(randomRadiusDist(gen))
				);
				break;
			}
			case CCurvesController::CurveType::ELLIPSE:
			{
				m_curves.push_back(std::make_shared<CEllipse>
					(randomRadiusDist(gen), randomRadiusDist(gen))
				);
				break;
			}
			case CCurvesController::CurveType::HELIX:
			{
				m_curves.push_back(std::make_shared<CHelix>
					(randomRadiusDist(gen), randomStepDist(gen))
				);
				break;
			}
			default:
			{
				m_curves.push_back(std::make_shared<CCircle>
					(randomRadiusDist(gen))
				);
			}
		}
	}
}

size_t CCurvesController::GetCountCurves() const noexcept
{
	return m_curves.size();
}
