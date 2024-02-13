#include <numbers>

#include "CCurvesController.h"

int main(int argc, char* argv)
{
	CCurvesController curvesController(std::cout);

	curvesController.GenerateRandomCurves();
	
	curvesController.PrintCurvesPointAndDerivative(std::numbers::pi / 4);

	curvesController.PrintCircleCurvesInfo();
	curvesController.SortCircleCurves();
	curvesController.PrintCircleCurvesInfo();

	return 0;
}