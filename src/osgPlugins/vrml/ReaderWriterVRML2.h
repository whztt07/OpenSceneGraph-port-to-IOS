// -*-c++-*-

/*
 *
 * VRML2 file converter for OpenSceneGraph.
 *
 * authors : Jan Ciger (jan.ciger@gmail.com),
 *           Tolga Abaci (tolga.abaci@gmail.com),
 *           Bruno Herbelin (bruno.herbelin@gmail.com)
 *
 *           (c) VRlab EPFL, Switzerland, 2004-2006
 *
 *           Gino van den Bergen, DTECTA (gino@dtecta.com)
 *           Xiangxian Wang (xiangxianwang@yahoo.com.cn)
 *
 */

#include <string>
#include <map>

#include <osg/Node>
#include <osg/Geometry>

#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgDB/FileNameUtils>
#include <osgDB/FileUtils>


namespace openvrml
{
    class node;
}

class QuadricKey
{
public:
    QuadricKey(float height, float radius, unsigned bottom, unsigned side, unsigned top)
        : m_height(height)
        , m_radius(radius)
        , m_flags(bottom | (side << 1) | (top << 2))
    {}

    bool operator<(const QuadricKey& rhs) const
    {
        return m_height < rhs.m_height ||
               (m_height == rhs.m_height && (m_radius < rhs.m_radius ||
                                            (m_radius == rhs.m_radius && m_flags < rhs.m_flags)));
    }

private:
    float m_height;
    float m_radius;
    unsigned m_flags;
};




/**
 * OpenSceneGraph plugin wrapper/converter.
 */
class ReaderWriterVRML2
    : public osgDB::ReaderWriter
{
public:
    ReaderWriterVRML2()
    {
        supportsExtension("wrl","VRML format");
    }

    virtual const char* className() const { return "VRML2 Reader/Writer"; }


    virtual ReadResult readNode(const std::string&, const osgDB::Options *options) const;
    // virtual ReadResult readNode(std::istream& fin, const osgDB::Options* options) const;

private:
    typedef std::map<float, osg::ref_ptr<osg::Geometry> > SphereLibrary;
    typedef std::map<osg::Vec3, osg::ref_ptr<osg::Geometry> > BoxLibrary;
    typedef std::map<QuadricKey, osg::ref_ptr<osg::Geometry> > ConeLibrary;
    typedef std::map<QuadricKey, osg::ref_ptr<osg::Geometry> > CylinderLibrary;

    osg::ref_ptr<osg::Node> convertFromVRML(openvrml::node *obj) const;


    osg::ref_ptr<osg::Geometry> convertVRML97IndexedFaceSet(openvrml::node *vrml_ifs) const;
    osg::ref_ptr<osg::Geometry> convertVRML97IndexedLineSet(openvrml::node *vrml_ifs) const;
    osg::ref_ptr<osg::Geometry> convertVRML97Box(openvrml::node* vrml_box) const;
    osg::ref_ptr<osg::Geometry> convertVRML97Sphere(openvrml::node* vrml_sphere) const;
    osg::ref_ptr<osg::Geometry> convertVRML97Cone(openvrml::node* vrml_cone) const;
    osg::ref_ptr<osg::Geometry> convertVRML97Cylinder(openvrml::node* vrml_cylinder) const;

    mutable BoxLibrary m_boxLibrary;
    mutable SphereLibrary m_sphereLibrary;
    mutable ConeLibrary m_coneLibrary;
    mutable CylinderLibrary m_cylinderLibrary;
};
