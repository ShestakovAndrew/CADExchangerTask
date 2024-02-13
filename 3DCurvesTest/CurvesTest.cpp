#define BOOST_TEST_MODULE CurvesTest
#include <boost/test/included/unit_test.hpp>

#include "3DCurves/CCircle.h"
#include "3DCurves/CEllipse.h"
#include "3DCurves/CHelix.h"

#include "3DCurves/CPoint3D.h"
#include "3DCurves/CVector3D.h"

BOOST_AUTO_TEST_SUITE(CurvesTest)

BOOST_AUTO_TEST_CASE(Circle)
{
	double radius = 3;
	double paramT = 5.4;
	CCircle circle(radius);

	BOOST_TEST_REQUIRE(circle.GetRadius() == radius);

	CPoint3D point3DResult
	{
		1.904078627827904,
		-2.3182934626679614,
		0.0
	};

	BOOST_TEST_REQUIRE(circle.Get3DPoint(paramT) == point3DResult);

	CVector3D vector3DResult
	{
		2.3182934626679614,
		1.904078627827904,
		0.0
	};

	BOOST_TEST_REQUIRE(circle.GetFirstDerivative(paramT) == vector3DResult);
}

BOOST_AUTO_TEST_CASE(Ellipse)
{
	double radiusX = 6.2;
	double radiusY = 2.3;

	double paramT = 9.3;

	CEllipse ellipse(radiusX, radiusY);

	BOOST_TEST_REQUIRE(ellipse.GetHorizontalRadius() == radiusX);
	BOOST_TEST_REQUIRE(ellipse.GetVerticalRadius() == radiusY);

	CPoint3D point3DResult
	{
		-6.151797017806142,
		0.2862451740662419,
		0.0
	};

	BOOST_TEST_REQUIRE(ellipse.Get3DPoint(paramT) == point3DResult);

	CVector3D vector3DResult
	{
		-0.7716174257437826,
		-2.282118248540988,
		0.0
	};

	BOOST_TEST_REQUIRE(ellipse.GetFirstDerivative(paramT) == vector3DResult);
	/*
	SECTION("must be initialized with the passed value.")
	{
		CHECK(ellipse.GetHorizontalRadius() == radiusX);
		CHECK(ellipse.GetVerticalRadius() == radiusY);
	}

	SECTION("must be get correct 3D point by t parameter.")
	{
		CPoint3D point3DResult
		{
			-6.15179701781,
			0.28624517406,
			0.0
		};

		CHECK(ellipse.Get3DPoint(paramT) == point3DResult);
	}

	SECTION("must be get correct first derivative by t parameter.")
	{
		CVector3D vector3DResult
		{
			-0.77161742574,
			-2.28211824854,
			0.0
		};

		CHECK(ellipse.GetFirstDerivative(paramT) == vector3DResult);
	}
	*/
}

BOOST_AUTO_TEST_CASE(Helix)
{
	double radius = 2;
	double step = 6.93;

	double paramT = 9.3;

	CHelix helix(radius, step);

	BOOST_TEST_REQUIRE(helix.GetRadius() == radius);
	BOOST_TEST_REQUIRE(helix.GetStep() == step);

	CPoint3D point3DResult
	{
		-1.984450650905207,
		0.2489088470141234,
		64.449
	};

	BOOST_TEST_REQUIRE(helix.Get3DPoint(paramT) == point3DResult);

	CVector3D vector3DResult
	{
		-0.2489088470141234,
		-1.984450650905207,
		6.93
	};

	BOOST_TEST_REQUIRE(helix.GetFirstDerivative(paramT) == vector3DResult);
	/*
	SECTION("must be initialized with the passed value.")
	{
		CHECK(helix.GetRadius() == radius);
		CHECK(helix.GetStep() == step);
	}

	SECTION("must be get correct 3D point by t parameter.")
	{
		CPoint3D point3DResult
		{
			-1.98445065091,
			0.24890884701,
			64.449
		};

		CHECK(helix.Get3DPoint(paramT) == point3DResult);
	}

	SECTION("must be get correct first derivative by t parameter.")
	{
		CVector3D vector3DResult
		{
			-0.24890884701,
			-1.98445065091,
			6.93
		};

		CHECK(helix.GetFirstDerivative(paramT) == vector3DResult);
	}
	*/
}

BOOST_AUTO_TEST_SUITE_END()