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

#include <osg/BufferObject>
#include <osg/CopyOp>
#include <osg/Object>
#include <osg/PrimitiveSet>
#include <osg/State>
#include <osg/Vec2>
#include <osg/Vec2d>
#include <osg/Vec3>
#include <osg/Vec3d>
#include <osg/Vec4>
#include <osg/Vec4d>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(osg::VectorGLsizei, osg::DrawArrayLengths::vector_type)

BEGIN_OBJECT_REFLECTOR(osg::DrawArrays)
	I_DeclaringFile("osg/PrimitiveSet");
	I_BaseType(osg::PrimitiveSet);
	I_ConstructorWithDefaults1(IN, GLenum, mode, 0,
	                           Properties::NON_EXPLICIT,
	                           ____DrawArrays__GLenum,
	                           "",
	                           "");
	I_ConstructorWithDefaults4(IN, GLenum, mode, , IN, GLint, first, , IN, GLsizei, count, , IN, int, numInstances, 0,
	                           ____DrawArrays__GLenum__GLint__GLsizei__int,
	                           "",
	                           "");
	I_ConstructorWithDefaults2(IN, const osg::DrawArrays &, da, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____DrawArrays__C5_DrawArrays_R1__C5_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, x,
	          Properties::VIRTUAL,
	          __Object_P1__clone__C5_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_Object_P1,
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
	I_Method3(void, set, IN, GLenum, mode, IN, GLint, first, IN, GLsizei, count,
	          Properties::NON_VIRTUAL,
	          __void__set__GLenum__GLint__GLsizei,
	          "",
	          "");
	I_Method1(void, setFirst, IN, GLint, first,
	          Properties::NON_VIRTUAL,
	          __void__setFirst__GLint,
	          "",
	          "");
	I_Method0(GLint, getFirst,
	          Properties::NON_VIRTUAL,
	          __GLint__getFirst,
	          "",
	          "");
	I_Method1(void, setCount, IN, GLsizei, count,
	          Properties::NON_VIRTUAL,
	          __void__setCount__GLsizei,
	          "",
	          "");
	I_Method0(GLsizei, getCount,
	          Properties::NON_VIRTUAL,
	          __GLsizei__getCount,
	          "",
	          "");
	I_Method2(void, draw, IN, osg::State &, state, IN, bool, useVertexBufferObjects,
	          Properties::VIRTUAL,
	          __void__draw__State_R1__bool,
	          "",
	          "");
	I_Method1(void, accept, IN, osg::PrimitiveFunctor &, functor,
	          Properties::VIRTUAL,
	          __void__accept__PrimitiveFunctor_R1,
	          "",
	          "");
	I_Method1(void, accept, IN, osg::PrimitiveIndexFunctor &, functor,
	          Properties::VIRTUAL,
	          __void__accept__PrimitiveIndexFunctor_R1,
	          "",
	          "");
	I_Method0(unsigned int, getNumIndices,
	          Properties::VIRTUAL,
	          __unsigned_int__getNumIndices,
	          "",
	          "");
	I_Method1(unsigned int, index, IN, unsigned int, pos,
	          Properties::VIRTUAL,
	          __unsigned_int__index__unsigned_int,
	          "",
	          "");
	I_Method1(void, offsetIndices, IN, int, offset,
	          Properties::VIRTUAL,
	          __void__offsetIndices__int,
	          "",
	          "");
	I_SimpleProperty(GLsizei, Count, 
	                 __GLsizei__getCount, 
	                 __void__setCount__GLsizei);
	I_SimpleProperty(GLint, First, 
	                 __GLint__getFirst, 
	                 __void__setFirst__GLint);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::DrawElements)
	I_DeclaringFile("osg/PrimitiveSet");
	I_BaseType(osg::PrimitiveSet);
	I_ConstructorWithDefaults3(IN, osg::PrimitiveSet::Type, primType, osg::PrimitiveSet::PrimitiveType, IN, GLenum, mode, 0, IN, int, numInstances, 0,
	                           ____DrawElements__Type__GLenum__int,
	                           "",
	                           "");
	I_ConstructorWithDefaults2(IN, const osg::DrawElements &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____DrawElements__C5_DrawElements_R1__C5_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::DrawElements *, getDrawElements,
	          Properties::VIRTUAL,
	          __DrawElements_P1__getDrawElements,
	          "",
	          "");
	I_Method0(const osg::DrawElements *, getDrawElements,
	          Properties::VIRTUAL,
	          __C5_DrawElements_P1__getDrawElements,
	          "",
	          "");
	I_Method1(void, setElementBufferObject, IN, osg::ElementBufferObject *, ebo,
	          Properties::NON_VIRTUAL,
	          __void__setElementBufferObject__osg_ElementBufferObject_P1,
	          "Set the ElementBufferObject. ",
	          "");
	I_Method0(osg::ElementBufferObject *, getElementBufferObject,
	          Properties::NON_VIRTUAL,
	          __osg_ElementBufferObject_P1__getElementBufferObject,
	          "Get the ElementBufferObject. ",
	          "If no EBO is assigned returns NULL ");
	I_Method0(const osg::ElementBufferObject *, getElementBufferObject,
	          Properties::NON_VIRTUAL,
	          __C5_osg_ElementBufferObject_P1__getElementBufferObject,
	          "Get the const ElementBufferObject. ",
	          "If no EBO is assigned returns NULL ");
	I_Method1(void, reserveElements, IN, unsigned int, numIndices,
	          Properties::PURE_VIRTUAL,
	          __void__reserveElements__unsigned_int,
	          "",
	          "");
	I_Method2(void, setElement, IN, unsigned, int, IN, unsigned, int,
	          Properties::PURE_VIRTUAL,
	          __void__setElement__unsigned__unsigned,
	          "",
	          "");
	I_Method1(unsigned int, getElement, IN, unsigned, int,
	          Properties::PURE_VIRTUAL,
	          __unsigned_int__getElement__unsigned,
	          "",
	          "");
	I_Method1(void, addElement, IN, unsigned, int,
	          Properties::PURE_VIRTUAL,
	          __void__addElement__unsigned,
	          "",
	          "");
	I_SimpleProperty(osg::DrawElements *, DrawElements, 
	                 __DrawElements_P1__getDrawElements, 
	                 0);
	I_SimpleProperty(osg::ElementBufferObject *, ElementBufferObject, 
	                 __osg_ElementBufferObject_P1__getElementBufferObject, 
	                 __void__setElementBufferObject__osg_ElementBufferObject_P1);
END_REFLECTOR

TYPE_NAME_ALIAS(osg::VectorGLubyte, osg::DrawElementsUByte::vector_type)

TYPE_NAME_ALIAS(osg::VectorGLuint, osg::DrawElementsUInt::vector_type)

TYPE_NAME_ALIAS(osg::VectorGLushort, osg::DrawElementsUShort::vector_type)

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::PrimitiveFunctor)
	I_DeclaringFile("osg/PrimitiveSet");
	I_Constructor0(____PrimitiveFunctor,
	               "",
	               "");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec2 *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec2_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function. ");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec3 *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec3_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function. ");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec4 *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec4_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function. ");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec2d *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec2d_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function. ");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec3d *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec3d_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function. ");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec4d *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec4d_P1,
	          "Sets the array of vertices used to describe the primitives. ",
	          "Somehow mimics the OpenGL glVertexPointer() function. ");
	I_Method3(void, drawArrays, IN, GLenum, mode, IN, GLint, first, IN, GLsizei, count,
	          Properties::PURE_VIRTUAL,
	          __void__drawArrays__GLenum__GLint__GLsizei,
	          "Mimics the OpenGL glDrawArrays() function. ",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLubyte *, indices,
	          Properties::PURE_VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLubyte_P1,
	          "Mimics the OpenGL glDrawElements() function. ",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLushort *, indices,
	          Properties::PURE_VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLushort_P1,
	          "Mimics the OpenGL glDrawElements() function. ",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLuint *, indices,
	          Properties::PURE_VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLuint_P1,
	          "Mimics the OpenGL glDrawElements() function. ",
	          "");
	I_Method1(void, begin, IN, GLenum, mode,
	          Properties::PURE_VIRTUAL,
	          __void__begin__GLenum,
	          "Mimics the OpenGL glBegin() function. ",
	          "");
	I_Method1(void, vertex, IN, const osg::Vec2 &, vert,
	          Properties::PURE_VIRTUAL,
	          __void__vertex__C5_Vec2_R1,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method1(void, vertex, IN, const osg::Vec3 &, vert,
	          Properties::PURE_VIRTUAL,
	          __void__vertex__C5_Vec3_R1,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method1(void, vertex, IN, const osg::Vec4 &, vert,
	          Properties::PURE_VIRTUAL,
	          __void__vertex__C5_Vec4_R1,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method2(void, vertex, IN, float, x, IN, float, y,
	          Properties::PURE_VIRTUAL,
	          __void__vertex__float__float,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method3(void, vertex, IN, float, x, IN, float, y, IN, float, z,
	          Properties::PURE_VIRTUAL,
	          __void__vertex__float__float__float,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method4(void, vertex, IN, float, x, IN, float, y, IN, float, z, IN, float, w,
	          Properties::PURE_VIRTUAL,
	          __void__vertex__float__float__float__float,
	          "Mimics the OpenGL glVertex() \"family of functions\". ",
	          "");
	I_Method0(void, end,
	          Properties::PURE_VIRTUAL,
	          __void__end,
	          "Mimics the OpenGL glEnd() function. ",
	          "");
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::PrimitiveIndexFunctor)
	I_DeclaringFile("osg/PrimitiveSet");
	I_Constructor0(____PrimitiveIndexFunctor,
	               "",
	               "");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec2 *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec2_P1,
	          "",
	          "");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec3 *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec3_P1,
	          "",
	          "");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec4 *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec4_P1,
	          "",
	          "");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec2d *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec2d_P1,
	          "",
	          "");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec3d *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec3d_P1,
	          "",
	          "");
	I_Method2(void, setVertexArray, IN, unsigned int, count, IN, const osg::Vec4d *, vertices,
	          Properties::PURE_VIRTUAL,
	          __void__setVertexArray__unsigned_int__C5_Vec4d_P1,
	          "",
	          "");
	I_Method3(void, drawArrays, IN, GLenum, mode, IN, GLint, first, IN, GLsizei, count,
	          Properties::PURE_VIRTUAL,
	          __void__drawArrays__GLenum__GLint__GLsizei,
	          "",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLubyte *, indices,
	          Properties::PURE_VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLubyte_P1,
	          "",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLushort *, indices,
	          Properties::PURE_VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLushort_P1,
	          "",
	          "");
	I_Method3(void, drawElements, IN, GLenum, mode, IN, GLsizei, count, IN, const GLuint *, indices,
	          Properties::PURE_VIRTUAL,
	          __void__drawElements__GLenum__GLsizei__C5_GLuint_P1,
	          "",
	          "");
	I_Method1(void, begin, IN, GLenum, mode,
	          Properties::PURE_VIRTUAL,
	          __void__begin__GLenum,
	          "",
	          "");
	I_Method1(void, vertex, IN, unsigned int, pos,
	          Properties::PURE_VIRTUAL,
	          __void__vertex__unsigned_int,
	          "",
	          "");
	I_Method0(void, end,
	          Properties::PURE_VIRTUAL,
	          __void__end,
	          "",
	          "");
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::PrimitiveSet::Type)
	I_DeclaringFile("osg/PrimitiveSet");
	I_EnumLabel(osg::PrimitiveSet::PrimitiveType);
	I_EnumLabel(osg::PrimitiveSet::DrawArraysPrimitiveType);
	I_EnumLabel(osg::PrimitiveSet::DrawArrayLengthsPrimitiveType);
	I_EnumLabel(osg::PrimitiveSet::DrawElementsUBytePrimitiveType);
	I_EnumLabel(osg::PrimitiveSet::DrawElementsUShortPrimitiveType);
	I_EnumLabel(osg::PrimitiveSet::DrawElementsUIntPrimitiveType);
END_REFLECTOR

BEGIN_ENUM_REFLECTOR(osg::PrimitiveSet::Mode)
	I_DeclaringFile("osg/PrimitiveSet");
	I_EnumLabel(osg::PrimitiveSet::POINTS);
	I_EnumLabel(osg::PrimitiveSet::LINES);
	I_EnumLabel(osg::PrimitiveSet::LINE_STRIP);
	I_EnumLabel(osg::PrimitiveSet::LINE_LOOP);
	I_EnumLabel(osg::PrimitiveSet::TRIANGLES);
	I_EnumLabel(osg::PrimitiveSet::TRIANGLE_STRIP);
	I_EnumLabel(osg::PrimitiveSet::TRIANGLE_FAN);
	I_EnumLabel(osg::PrimitiveSet::QUADS);
	I_EnumLabel(osg::PrimitiveSet::QUAD_STRIP);
	I_EnumLabel(osg::PrimitiveSet::POLYGON);
	I_EnumLabel(osg::PrimitiveSet::LINES_ADJACENCY);
	I_EnumLabel(osg::PrimitiveSet::LINE_STRIP_ADJACENCY);
	I_EnumLabel(osg::PrimitiveSet::TRIANGLES_ADJACENCY);
	I_EnumLabel(osg::PrimitiveSet::TRIANGLE_STRIP_ADJACENCY);
END_REFLECTOR

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osg::PrimitiveSet)
	I_DeclaringFile("osg/PrimitiveSet");
	I_BaseType(osg::BufferData);
	I_ConstructorWithDefaults3(IN, osg::PrimitiveSet::Type, primType, osg::PrimitiveSet::PrimitiveType, IN, GLenum, mode, 0, IN, int, numInstances, 0,
	                           ____PrimitiveSet__Type__GLenum__int,
	                           "",
	                           "");
	I_ConstructorWithDefaults2(IN, const osg::PrimitiveSet &, prim, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____PrimitiveSet__C5_PrimitiveSet_R1__C5_CopyOp_R1,
	                           "",
	                           "");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_Object_P1,
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
	I_Method0(osg::PrimitiveSet::Type, getType,
	          Properties::NON_VIRTUAL,
	          __Type__getType,
	          "",
	          "");
	I_Method0(const GLvoid *, getDataPointer,
	          Properties::VIRTUAL,
	          __C5_GLvoid_P1__getDataPointer,
	          "",
	          "");
	I_Method0(unsigned int, getTotalDataSize,
	          Properties::VIRTUAL,
	          __unsigned_int__getTotalDataSize,
	          "",
	          "");
	I_Method0(bool, supportsBufferObject,
	          Properties::VIRTUAL,
	          __bool__supportsBufferObject,
	          "",
	          "");
	I_Method0(osg::DrawElements *, getDrawElements,
	          Properties::VIRTUAL,
	          __DrawElements_P1__getDrawElements,
	          "",
	          "");
	I_Method0(const osg::DrawElements *, getDrawElements,
	          Properties::VIRTUAL,
	          __C5_DrawElements_P1__getDrawElements,
	          "",
	          "");
	I_Method1(void, setNumInstances, IN, int, n,
	          Properties::NON_VIRTUAL,
	          __void__setNumInstances__int,
	          "",
	          "");
	I_Method0(int, getNumInstances,
	          Properties::NON_VIRTUAL,
	          __int__getNumInstances,
	          "",
	          "");
	I_Method1(void, setMode, IN, GLenum, mode,
	          Properties::NON_VIRTUAL,
	          __void__setMode__GLenum,
	          "",
	          "");
	I_Method0(GLenum, getMode,
	          Properties::NON_VIRTUAL,
	          __GLenum__getMode,
	          "",
	          "");
	I_Method2(void, draw, IN, osg::State &, state, IN, bool, useVertexBufferObjects,
	          Properties::PURE_VIRTUAL,
	          __void__draw__State_R1__bool,
	          "",
	          "");
	I_Method1(void, accept, IN, osg::PrimitiveFunctor &, functor,
	          Properties::PURE_VIRTUAL,
	          __void__accept__PrimitiveFunctor_R1,
	          "",
	          "");
	I_Method1(void, accept, IN, osg::PrimitiveIndexFunctor &, functor,
	          Properties::PURE_VIRTUAL,
	          __void__accept__PrimitiveIndexFunctor_R1,
	          "",
	          "");
	I_Method1(unsigned int, index, IN, unsigned int, pos,
	          Properties::PURE_VIRTUAL,
	          __unsigned_int__index__unsigned_int,
	          "",
	          "");
	I_Method0(unsigned int, getNumIndices,
	          Properties::PURE_VIRTUAL,
	          __unsigned_int__getNumIndices,
	          "",
	          "");
	I_Method1(void, offsetIndices, IN, int, offset,
	          Properties::PURE_VIRTUAL,
	          __void__offsetIndices__int,
	          "",
	          "");
	I_Method0(unsigned int, getNumPrimitives,
	          Properties::VIRTUAL,
	          __unsigned_int__getNumPrimitives,
	          "",
	          "");
	I_Method0(void, computeRange,
	          Properties::VIRTUAL,
	          __void__computeRange,
	          "",
	          "");
	I_SimpleProperty(const GLvoid *, DataPointer, 
	                 __C5_GLvoid_P1__getDataPointer, 
	                 0);
	I_SimpleProperty(osg::DrawElements *, DrawElements, 
	                 __DrawElements_P1__getDrawElements, 
	                 0);
	I_SimpleProperty(GLenum, Mode, 
	                 __GLenum__getMode, 
	                 __void__setMode__GLenum);
	I_SimpleProperty(int, NumInstances, 
	                 0, 
	                 __void__setNumInstances__int);
	I_SimpleProperty(unsigned int, TotalDataSize, 
	                 __unsigned_int__getTotalDataSize, 
	                 0);
	I_SimpleProperty(osg::PrimitiveSet::Type, Type, 
	                 __Type__getType, 
	                 0);
END_REFLECTOR

