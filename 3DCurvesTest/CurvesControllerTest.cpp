#include <numbers>
#include <boost/test/unit_test.hpp>

#include "3DCurves/CCurvesController.h"

BOOST_AUTO_TEST_SUITE(CurvesControllerTest)

BOOST_AUTO_TEST_CASE(GetCountCurves)
{
	std::stringstream output;
	CCurvesController controller(output);

	BOOST_TEST_REQUIRE(controller.GetCountCurves() == 0);

	controller.GenerateRandomCurves();

	BOOST_TEST_REQUIRE(controller.GetCountCurves() != 0);
}

BOOST_AUTO_TEST_CASE(PrintCurvesInfo)
{
	std::stringstream output;
	CCurvesController controller(output);
	std::string messageInvalid = "Generate curves before print information.\n";

	controller.PrintCurvesInfo(std::numbers::pi);
	BOOST_TEST_REQUIRE(output.str() == messageInvalid);
}

BOOST_AUTO_TEST_SUITE_END()