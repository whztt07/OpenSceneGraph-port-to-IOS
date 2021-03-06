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

#include <osg/CopyOp>
#include <osg/Matrixd>
#include <osg/Node>
#include <osg/Object>
#include <osgGA/NodeTrackerManipulator>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgGA::NodeTrackerManipulator::TrackerMode)
	I_DeclaringFile("osgGA/NodeTrackerManipulator");
	I_EnumLabel(osgGA::NodeTrackerManipulator::NODE_CENTER);
	I_EnumLabel(osgGA::NodeTrackerManipulator::NODE_CENTER_AND_AZIM);
	I_EnumLabel(osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osgGA::NodeTrackerManipulator::RotationMode)
	I_DeclaringFile("osgGA/NodeTrackerManipulator");
	I_EnumLabel(osgGA::NodeTrackerManipulator::TRACKBALL);
	I_EnumLabel(osgGA::NodeTrackerManipulator::ELEVATION_AZIM);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osg::observer_ptr< osg::Node > >, osgGA::NodeTrackerManipulator::ObserverNodePath)

BEGIN_OBJECT_REFLECTOR(osgGA::NodeTrackerManipulator)
	I_DeclaringFile("osgGA/NodeTrackerManipulator");
	I_BaseType(osgGA::OrbitManipulator);
	I_ConstructorWithDefaults1(IN, int, flags, osgGA::StandardManipulator::DEFAULT_SETTINGS,
	                           Properties::NON_EXPLICIT,
	                           ____NodeTrackerManipulator__int,
	                           "",
	                           "");
	I_ConstructorWithDefaults2(IN, const osgGA::NodeTrackerManipulator &, om, , IN, const osg::CopyOp &, copyOp, osg::CopyOp::SHALLOW_COPY,
	                           ____NodeTrackerManipulator__C5_NodeTrackerManipulator_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setTrackNodePath, IN, const osg::NodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNodePath__C5_osg_NodePath_R1,
	          "",
	          "");
	I_Method1(void, setTrackNodePath, IN, const osgGA::NodeTrackerManipulator::ObserverNodePath &, nodePath,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNodePath__C5_ObserverNodePath_R1,
	          "",
	          "");
	I_Method0(osgGA::NodeTrackerManipulator::ObserverNodePath &, getTrackNodePath,
	          Properties::NON_VIRTUAL,
	          __ObserverNodePath_R1__getTrackNodePath,
	          "",
	          "");
	I_Method1(void, setTrackNode, IN, osg::Node *, node,
	          Properties::NON_VIRTUAL,
	          __void__setTrackNode__osg_Node_P1,
	          "",
	          "");
	I_Method0(osg::Node *, getTrackNode,
	          Properties::NON_VIRTUAL,
	          __osg_Node_P1__getTrackNode,
	          "",
	          "");
	I_Method0(const osg::Node *, getTrackNode,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Node_P1__getTrackNode,
	          "",
	          "");
	I_Method1(void, setTrackerMode, IN, osgGA::NodeTrackerManipulator::TrackerMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setTrackerMode__TrackerMode,
	          "",
	          "");
	I_Method0(osgGA::NodeTrackerManipulator::TrackerMode, getTrackerMode,
	          Properties::NON_VIRTUAL,
	          __TrackerMode__getTrackerMode,
	          "",
	          "");
	I_Method1(void, setRotationMode, IN, osgGA::NodeTrackerManipulator::RotationMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setRotationMode__RotationMode,
	          "",
	          "");
	I_Method0(osgGA::NodeTrackerManipulator::RotationMode, getRotationMode,
	          Properties::NON_VIRTUAL,
	          __RotationMode__getRotationMode,
	          "",
	          "");
	I_Method1(void, setByMatrix, IN, const osg::Matrixd &, matrix,
	          Properties::VIRTUAL,
	          __void__setByMatrix__C5_osg_Matrixd_R1,
	          "set the position of the matrix manipulator using a 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getMatrix,
	          "get the position of the manipulator as 4x4 Matrix. ",
	          "");
	I_Method0(osg::Matrixd, getInverseMatrix,
	          Properties::VIRTUAL,
	          __osg_Matrixd__getInverseMatrix,
	          "get the position of the manipulator as a inverse matrix of the manipulator, typically used as a model view matrix. ",
	          "");
	I_Method1(void, setNode, IN, osg::Node *, x,
	          Properties::VIRTUAL,
	          __void__setNode__osg_Node_P1,
	          "Attach a node to the manipulator, automatically detaching any previously attached node. ",
	          "setNode(NULL) detaches previous nodes. May be ignored by manipulators which do not require a reference model. ");
	I_Method0(void, computeHomePosition,
	          Properties::VIRTUAL,
	          __void__computeHomePosition,
	          "",
	          "");
	I_ProtectedMethod3(bool, performMovementLeftMouseButton, IN, const double, eventTimeDelta, IN, const double, dx, IN, const double, dy,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__performMovementLeftMouseButton__C5_double__C5_double__C5_double,
	                   "",
	                   "");
	I_ProtectedMethod3(bool, performMovementMiddleMouseButton, IN, const double, eventTimeDelta, IN, const double, dx, IN, const double, dy,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__performMovementMiddleMouseButton__C5_double__C5_double__C5_double,
	                   "",
	                   "");
	I_ProtectedMethod3(bool, performMovementRightMouseButton, IN, const double, eventTimeDelta, IN, const double, dx, IN, const double, dy,
	                   Properties::VIRTUAL,
	                   Properties::NON_CONST,
	                   __bool__performMovementRightMouseButton__C5_double__C5_double__C5_double,
	                   "",
	                   "");
	I_ProtectedMethod0(osg::NodePath, getNodePath,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __osg_NodePath__getNodePath,
	                   "",
	                   "");
	I_ProtectedMethod0(bool, validateNodePath,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __bool__validateNodePath,
	                   "",
	                   "");
	I_ProtectedMethod1(void, computeNodeWorldToLocal, IN, osg::Matrixd &, worldToLocal,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeNodeWorldToLocal__osg_Matrixd_R1,
	                   "",
	                   "");
	I_ProtectedMethod1(void, computeNodeLocalToWorld, IN, osg::Matrixd &, localToWorld,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeNodeLocalToWorld__osg_Matrixd_R1,
	                   "",
	                   "");
	I_ProtectedMethod2(void, computeNodeCenterAndRotation, IN, osg::Vec3d &, center, IN, osg::Quat &, rotation,
	                   Properties::NON_VIRTUAL,
	                   Properties::CONST,
	                   __void__computeNodeCenterAndRotation__osg_Vec3d_R1__osg_Quat_R1,
	                   "",
	                   "");
	I_ProtectedMethod3(void, computePosition, IN, const osg::Vec3d &, eye, IN, const osg::Vec3d &, lv, IN, const osg::Vec3d &, up,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __void__computePosition__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1__C5_osg_Vec3d_R1,
	                   "",
	                   "");
	I_SimpleProperty(const osg::Matrixd &, ByMatrix, 
	                 0, 
	                 __void__setByMatrix__C5_osg_Matrixd_R1);
	I_SimpleProperty(osg::Matrixd, InverseMatrix, 
	                 __osg_Matrixd__getInverseMatrix, 
	                 0);
	I_SimpleProperty(osg::Matrixd, Matrix, 
	                 __osg_Matrixd__getMatrix, 
	                 0);
	I_SimpleProperty(osg::Node *, Node, 
	                 0, 
	                 __void__setNode__osg_Node_P1);
	I_SimpleProperty(osgGA::NodeTrackerManipulator::RotationMode, RotationMode, 
	                 __RotationMode__getRotationMode, 
	                 __void__setRotationMode__RotationMode);
	I_SimpleProperty(osg::Node *, TrackNode, 
	                 __osg_Node_P1__getTrackNode, 
	                 __void__setTrackNode__osg_Node_P1);
	I_SimpleProperty(osgGA::NodeTrackerManipulator::ObserverNodePath &, TrackNodePath, 
	                 __ObserverNodePath_R1__getTrackNodePath, 
	                 0);
	I_SimpleProperty(osgGA::NodeTrackerManipulator::TrackerMode, TrackerMode, 
	                 __TrackerMode__getTrackerMode, 
	                 __void__setTrackerMode__TrackerMode);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osg::observer_ptr< osg::Node >)
	I_DeclaringFile("osg/observer_ptr");
	I_Constructor0(____observer_ptr,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osg::Node > &, rp,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__C5_ref_ptrT1_T__R1,
	               "Create a observer_ptr from a ref_ptr. ",
	               "");
	I_Constructor1(IN, osg::Node *, rp,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__T_P1,
	               "Create a observer_ptr from a raw pointer. ",
	               "For compatibility; the result might not be lockable. ");
	I_Constructor1(IN, const osg::observer_ptr< osg::Node > &, wp,
	               Properties::NON_EXPLICIT,
	               ____observer_ptr__C5_observer_ptr_R1,
	               "",
	               "");
	I_Method1(bool, lock, IN, osg::ref_ptr< osg::Node > &, rptr,
	          Properties::NON_VIRTUAL,
	          __bool__lock__ref_ptrT1_T__R1,
	          "Assign the observer_ptr to a ref_ptr. ",
	          "The ref_ptr will be valid if the referenced object hasn't been deleted and has a ref count > 0. ");
	I_Method0(osg::Node *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_SimpleProperty(osg::Node *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::observer_ptr< osg::Node > >)

