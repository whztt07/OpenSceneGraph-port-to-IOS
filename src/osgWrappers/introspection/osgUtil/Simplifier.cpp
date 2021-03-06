// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/Geode>
#include <osg/Geometry>
#include <osgUtil/Simplifier>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< unsigned int >, osgUtil::Simplifier::IndexList)

BEGIN_OBJECT_REFLECTOR(osgUtil::Simplifier)
	I_DeclaringFile("osgUtil/Simplifier");
	I_BaseType(osg::NodeVisitor);
	I_ConstructorWithDefaults3(IN, double, sampleRatio, 1.0, IN, double, maximumError, FLT_MAX, IN, double, maximumLength, 0.0,
	                           ____Simplifier__double__double__double,
	                           "",
	                           "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the library name/namespapce of the visitor's. ",
	          "Should be defined by derived classes. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the visitor's class type. ",
	          "Should be defined by derived classes. ");
	I_Method1(void, setSampleRatio, IN, float, sampleRatio,
	          Properties::NON_VIRTUAL,
	          __void__setSampleRatio__float,
	          "",
	          "");
	I_Method0(float, getSampleRatio,
	          Properties::NON_VIRTUAL,
	          __float__getSampleRatio,
	          "",
	          "");
	I_Method1(void, setMaximumError, IN, float, error,
	          Properties::NON_VIRTUAL,
	          __void__setMaximumError__float,
	          "Set the maximum point error that all point removals must be less than to permit removal of a point. ",
	          "Note, Only used when down sampling. i.e. sampleRatio < 1.0 ");
	I_Method0(float, getMaximumError,
	          Properties::NON_VIRTUAL,
	          __float__getMaximumError,
	          "",
	          "");
	I_Method1(void, setMaximumLength, IN, float, length,
	          Properties::NON_VIRTUAL,
	          __void__setMaximumLength__float,
	          "Set the maximum length target that all edges must be shorted than. ",
	          "Note, Only used when up sampling i.e. sampleRatio > 1.0. ");
	I_Method0(float, getMaximumLength,
	          Properties::NON_VIRTUAL,
	          __float__getMaximumLength,
	          "",
	          "");
	I_Method1(void, setDoTriStrip, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setDoTriStrip__bool,
	          "",
	          "");
	I_Method0(bool, getDoTriStrip,
	          Properties::NON_VIRTUAL,
	          __bool__getDoTriStrip,
	          "",
	          "");
	I_Method1(void, setSmoothing, IN, bool, on,
	          Properties::NON_VIRTUAL,
	          __void__setSmoothing__bool,
	          "",
	          "");
	I_Method0(bool, getSmoothing,
	          Properties::NON_VIRTUAL,
	          __bool__getSmoothing,
	          "",
	          "");
	I_Method1(void, setContinueSimplificationCallback, IN, osgUtil::Simplifier::ContinueSimplificationCallback *, cb,
	          Properties::NON_VIRTUAL,
	          __void__setContinueSimplificationCallback__ContinueSimplificationCallback_P1,
	          "",
	          "");
	I_Method0(osgUtil::Simplifier::ContinueSimplificationCallback *, getContinueSimplificationCallback,
	          Properties::NON_VIRTUAL,
	          __ContinueSimplificationCallback_P1__getContinueSimplificationCallback,
	          "",
	          "");
	I_Method0(const osgUtil::Simplifier::ContinueSimplificationCallback *, getContinueSimplificationCallback,
	          Properties::NON_VIRTUAL,
	          __C5_ContinueSimplificationCallback_P1__getContinueSimplificationCallback,
	          "",
	          "");
	I_Method3(bool, continueSimplification, IN, float, nextError, IN, unsigned int, numOriginalPrimitives, IN, unsigned int, numRemainingPrimitives,
	          Properties::NON_VIRTUAL,
	          __bool__continueSimplification__float__unsigned_int__unsigned_int,
	          "",
	          "");
	I_Method3(bool, continueSimplificationImplementation, IN, float, nextError, IN, unsigned int, numOriginalPrimitives, IN, unsigned int, numRemainingPrimitives,
	          Properties::VIRTUAL,
	          __bool__continueSimplificationImplementation__float__unsigned_int__unsigned_int,
	          "",
	          "");
	I_Method1(void, apply, IN, osg::Geode &, geode,
	          Properties::VIRTUAL,
	          __void__apply__osg_Geode_R1,
	          "",
	          "");
	I_Method1(void, simplify, IN, osg::Geometry &, geometry,
	          Properties::NON_VIRTUAL,
	          __void__simplify__osg_Geometry_R1,
	          "simply the geometry. ",
	          "");
	I_Method2(void, simplify, IN, osg::Geometry &, geometry, IN, const osgUtil::Simplifier::IndexList &, protectedPoints,
	          Properties::NON_VIRTUAL,
	          __void__simplify__osg_Geometry_R1__C5_IndexList_R1,
	          "a list of point indices ",
	          "simply the geometry, whilst protecting key points from being modified. ");
	I_SimpleProperty(osgUtil::Simplifier::ContinueSimplificationCallback *, ContinueSimplificationCallback, 
	                 __ContinueSimplificationCallback_P1__getContinueSimplificationCallback, 
	                 __void__setContinueSimplificationCallback__ContinueSimplificationCallback_P1);
	I_SimpleProperty(bool, DoTriStrip, 
	                 __bool__getDoTriStrip, 
	                 __void__setDoTriStrip__bool);
	I_SimpleProperty(float, MaximumError, 
	                 __float__getMaximumError, 
	                 __void__setMaximumError__float);
	I_SimpleProperty(float, MaximumLength, 
	                 __float__getMaximumLength, 
	                 __void__setMaximumLength__float);
	I_SimpleProperty(float, SampleRatio, 
	                 __float__getSampleRatio, 
	                 __void__setSampleRatio__float);
	I_SimpleProperty(bool, Smoothing, 
	                 __bool__getSmoothing, 
	                 __void__setSmoothing__bool);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgUtil::Simplifier::ContinueSimplificationCallback)
	I_DeclaringFile("osgUtil/Simplifier");
	I_BaseType(osg::Referenced);
	I_Constructor0(____ContinueSimplificationCallback,
	               "",
	               "");
	I_Method4(bool, continueSimplification, IN, const osgUtil::Simplifier &, simplifier, IN, float, nextError, IN, unsigned int, numOriginalPrimitives, IN, unsigned int, numRemainingPrimitives,
	          Properties::VIRTUAL,
	          __bool__continueSimplification__C5_Simplifier_R1__float__unsigned_int__unsigned_int,
	          "return true if mesh should be continued to be simplified, return false to stop simplification. ",
	          "");
END_REFLECTOR

