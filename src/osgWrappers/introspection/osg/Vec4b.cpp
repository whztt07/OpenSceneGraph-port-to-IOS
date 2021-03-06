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

#include <osg/Vec4b>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

#include <osg/io_utils>
	
TYPE_NAME_ALIAS(signed char, osg::Vec4b::value_type)

BEGIN_VALUE_REFLECTOR(osg::Vec4b)
	I_ReaderWriter(osgIntrospection::StdReaderWriter<reflected_type>);	// user-defined
	I_Comparator(osgIntrospection::PartialOrderComparator<reflected_type>);	// user-defined
	I_DeclaringFile("osg/Vec4b");
	I_Constructor0(____Vec4b,
	               "",
	               "");
	I_Constructor4(IN, osg::Vec4b::value_type, x, IN, osg::Vec4b::value_type, y, IN, osg::Vec4b::value_type, z, IN, osg::Vec4b::value_type, w,
	               ____Vec4b__value_type__value_type__value_type__value_type,
	               "",
	               "");
	I_Method0(osg::Vec4b::value_type *, ptr,
	          Properties::NON_VIRTUAL,
	          __value_type_P1__ptr,
	          "",
	          "");
	I_Method0(const osg::Vec4b::value_type *, ptr,
	          Properties::NON_VIRTUAL,
	          __C5_value_type_P1__ptr,
	          "",
	          "");
	I_Method4(void, set, IN, osg::Vec4b::value_type, x, IN, osg::Vec4b::value_type, y, IN, osg::Vec4b::value_type, z, IN, osg::Vec4b::value_type, w,
	          Properties::NON_VIRTUAL,
	          __void__set__value_type__value_type__value_type__value_type,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type &, x,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__x,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type &, y,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__y,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type &, z,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__z,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type &, w,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__w,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type, x,
	          Properties::NON_VIRTUAL,
	          __value_type__x,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type, y,
	          Properties::NON_VIRTUAL,
	          __value_type__y,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type, z,
	          Properties::NON_VIRTUAL,
	          __value_type__z,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type, w,
	          Properties::NON_VIRTUAL,
	          __value_type__w,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type &, r,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__r,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type &, g,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__g,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type &, b,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__b,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type &, a,
	          Properties::NON_VIRTUAL,
	          __value_type_R1__a,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type, r,
	          Properties::NON_VIRTUAL,
	          __value_type__r,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type, g,
	          Properties::NON_VIRTUAL,
	          __value_type__g,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type, b,
	          Properties::NON_VIRTUAL,
	          __value_type__b,
	          "",
	          "");
	I_Method0(osg::Vec4b::value_type, a,
	          Properties::NON_VIRTUAL,
	          __value_type__a,
	          "",
	          "");
END_REFLECTOR

