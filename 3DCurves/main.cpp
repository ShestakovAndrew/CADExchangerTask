#include <numbers>

#include "CCurvesController.h"

int main(int argc, char* argv)
{
	CCurvesController curvesController(std::cout);

	curvesController.GenerateRandomCurves();

	curvesController.PrintCurvesInfo(std::numbers::pi / 4);

	return 0;
}