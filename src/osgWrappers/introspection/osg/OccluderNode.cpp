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

#include <osg/BoundingSphere>
#include <osg/ConvexPlanarOccluder>
#include <osg/CopyOp>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/OccluderNode>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::OccluderNode)
	I_DeclaringFile("osg/OccluderNode");
	I_BaseType(osg::Group);
	I_Constructor0(____OccluderNode,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::OccluderNode &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____OccluderNode__C5_OccluderNode_R1__C5_CopyOp_R1,
	                           "Copy constructor using CopyOp to manage deep vs shallow copy. ",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "clone an object of the same type as the node. ",
	          "");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "return a clone of a node, with Object* return type. ",
	          "");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "return true if this and obj are of the same kind of object. ",
	          "");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the node's class type. ",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the node's library. ",
	          "");
	I_Method1(void, accept, IN, osg::NodeVisitor &, nv,
	          Properties::VIRTUAL,
	          __void__accept__osg_NodeVisitor_R1,
	          "Visitor Pattern : calls the apply method of a NodeVisitor with this node's type. ",
	          "");
	I_Method1(void, setOccluder, IN, osg::ConvexPlanarOccluder *, occluder,
	          Properties::NON_VIRTUAL,
	          __void__setOccluder__ConvexPlanarOccluder_P1,
	          "Attach a ConvexPlanarOccluder to an OccluderNode. ",
	          "");
	I_Method0(osg::ConvexPlanarOccluder *, getOccluder,
	          Properties::NON_VIRTUAL,
	          __ConvexPlanarOccluder_P1__getOccluder,
	          "Get the ConvexPlanarOccluder* attached to a OccluderNode. ",
	          "");
	I_Method0(const osg::ConvexPlanarOccluder *, getOccluder,
	          Properties::NON_VIRTUAL,
	          __C5_ConvexPlanarOccluder_P1__getOccluder,
	          "Get the const ConvexPlanarOccluder* attached to a OccluderNode. ",
	          "");
	I_Method0(osg::BoundingSphere, computeBound,
	          Properties::VIRTUAL,
	          __BoundingSphere__computeBound,
	          "Overrides Group's computeBound. ",
	          "");
	I_SimpleProperty(osg::ConvexPlanarOccluder *, Occluder, 
	                 __ConvexPlanarOccluder_P1__getOccluder, 
	                 __void__setOccluder__ConvexPlanarOccluder_P1);
END_REFLECTOR

