/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2006 Robert Osfield 
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/


#include <osgUtil/LineSegmentIntersector>

#include <osg/Geometry>
#include <osg/Notify>
#include <osg/io_utils>
#include <osg/TriangleFunctor>
#include <osg/KdTree>
#include <osg/Timer>

using namespace osgUtil;

namespace LineSegmentIntersectorUtils
{

    struct TriangleIntersection
    {
        TriangleIntersection(unsigned int index, const osg::Vec3& normal, float r1, const osg::Vec3* v1, float r2, const osg::Vec3* v2, float r3, const osg::Vec3* v3):
            _index(index),
            _normal(normal),
            _r1(r1),
            _v1(v1),        
            _r2(r2),
            _v2(v2),        
            _r3(r3),
            _v3(v3) {}

        unsigned int        _index;
        const osg::Vec3     _normal;
        float               _r1;
        const osg::Vec3*    _v1;        
        float               _r2;
        const osg::Vec3*    _v2;        
        float               _r3;
        const osg::Vec3*    _v3;
        
    protected:
    
        TriangleIntersection& operator = (const TriangleIntersection&) { return *this; }
    };

    typedef std::multimap<float,TriangleIntersection> TriangleIntersections;

    struct TriangleIntersector
    {
        osg::Vec3   _s;
        osg::Vec3   _d;
        float       _length;

        int         _index;
        float       _ratio;
        bool        _hit;

        TriangleIntersections _intersections;

        TriangleIntersector()
        {
            _length = 0.0f;
            _index = 0;
            _ratio = 0.0f;
            _hit = false;
        }

        void set(const osg::Vec3d& start, osg::Vec3d& end, float ratio=FLT_MAX)
        {
            _hit=false;
            _index = 0;
            _ratio = ratio;

            _s = start;
            _d = end - start;
            _length = _d.length();
            _d /= _length;
        }

        inline void operator () (const osg::Vec3& v1,const osg::Vec3& v2,const osg::Vec3& v3, bool treatVertexDataAsTemporary)
        {
            ++_index;

            if (v1==v2 || v2==v3 || v1==v3) return;

            osg::Vec3 v12 = v2-v1;
            osg::Vec3 n12 = v12^_d;
            float ds12 = (_s-v1)*n12;
            float d312 = (v3-v1)*n12;
            if (d312>=0.0f)
            {
                if (ds12<0.0f) return;
                if (ds12>d312) return;
            }
            else                     // d312 < 0
            {
                if (ds12>0.0f) return;
                if (ds12<d312) return;
            }

            osg::Vec3 v23 = v3-v2;
            osg::Vec3 n23 = v23^_d;
            float ds23 = (_s-v2)*n23;
            float d123 = (v1-v2)*n23;
            if (d123>=0.0f)
            {
                if (ds23<0.0f) return;
                if (ds23>d123) return;
            }
            else                     // d123 < 0
            {
                if (ds23>0.0f) return;
                if (ds23<d123) return;
            }

            osg::Vec3 v31 = v1-v3;
            osg::Vec3 n31 = v31^_d;
            float ds31 = (_s-v3)*n31;
            float d231 = (v2-v3)*n31;
            if (d231>=0.0f)
            {
                if (ds31<0.0f) return;
                if (ds31>d231) return;
            }
            else                     // d231 < 0
            {
                if (ds31>0.0f) return;
                if (ds31<d231) return;
            }


            float r3;
            if (ds12==0.0f) r3=0.0f;
            else if (d312!=0.0f) r3 = ds12/d312;
            else return; // the triangle and the line must be parallel intersection.

            float r1;
            if (ds23==0.0f) r1=0.0f;
            else if (d123!=0.0f) r1 = ds23/d123;
            else return; // the triangle and the line must be parallel intersection.

            float r2;
            if (ds31==0.0f) r2=0.0f;
            else if (d231!=0.0f) r2 = ds31/d231;
            else return; // the triangle and the line must be parallel intersection.

            float total_r = (r1+r2+r3);
            if (total_r!=1.0f)
            {
                if (total_r==0.0f) return; // the triangle and the line must be parallel intersection.
                float inv_total_r = 1.0f/total_r;
                r1 *= inv_total_r;
                r2 *= inv_total_r;
                r3 *= inv_total_r;
            }

            osg::Vec3 in = v1*r1+v2*r2+v3*r3;
            if (!in.valid())
            {
                OSG_WARN<<"Warning:: Picked up error in TriangleIntersect"<<std::endl;
                OSG_WARN<<"   ("<<v1<<",\t"<<v2<<",\t"<<v3<<")"<<std::endl;
                OSG_WARN<<"   ("<<r1<<",\t"<<r2<<",\t"<<r3<<")"<<std::endl;
                return;
            }

            float d = (in-_s)*_d;

            if (d<0.0f) return;
            if (d>_length) return;

            osg::Vec3 normal = v12^v23;
            normal.normalize();

            float r = d/_length;


            if (treatVertexDataAsTemporary)
            {
                _intersections.insert(std::pair<const float,TriangleIntersection>(r,TriangleIntersection(_index-1,normal,r1,0,r2,0,r3,0)));
            }
            else
            {
                _intersections.insert(std::pair<const float,TriangleIntersection>(r,TriangleIntersection(_index-1,normal,r1,&v1,r2,&v2,r3,&v3)));
            }
            _hit = true;

        }

    };

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  LineSegmentIntersector
//

LineSegmentIntersector::LineSegmentIntersector(const osg::Vec3d& start, const osg::Vec3d& end):
    _parent(0),
    _start(start),
    _end(end)
{
}

LineSegmentIntersector::LineSegmentIntersector(CoordinateFrame cf, const osg::Vec3d& start, const osg::Vec3d& end):
    Intersector(cf),
    _parent(0),
    _start(start),
    _end(end)
{
}

LineSegmentIntersector::LineSegmentIntersector(CoordinateFrame cf, double x, double y):
    Intersector(cf),
    _parent(0)
{
    switch(cf)
    {
        case WINDOW : _start.set(x,y,0.0); _end.set(x,y,1.0); break;
        case PROJECTION : _start.set(x,y,-1.0); _end.set(x,y,1.0); break;
        case VIEW : _start.set(x,y,0.0); _end.set(x,y,1.0); break;
        case MODEL : _start.set(x,y,0.0); _end.set(x,y,1.0); break;
    }
}

Intersector* LineSegmentIntersector::clone(osgUtil::IntersectionVisitor& iv)
{
    if (_coordinateFrame==MODEL && iv.getModelMatrix()==0)
    {
        osg::ref_ptr<LineSegmentIntersector> lsi = new LineSegmentIntersector(_start, _end);
        lsi->_parent = this;
        return lsi.release();
    }

    // compute the matrix that takes this Intersector from its CoordinateFrame into the local MODEL coordinate frame
    // that geometry in the scene graph will always be in.
    osg::Matrix matrix;
    switch (_coordinateFrame)
    {
        case(WINDOW): 
            if (iv.getWindowMatrix()) matrix.preMult( *iv.getWindowMatrix() );
            if (iv.getProjectionMatrix()) matrix.preMult( *iv.getProjectionMatrix() );
            if (iv.getViewMatrix()) matrix.preMult( *iv.getViewMatrix() );
            if (iv.getModelMatrix()) matrix.preMult( *iv.getModelMatrix() );
            break;
        case(PROJECTION): 
            if (iv.getProjectionMatrix()) matrix.preMult( *iv.getProjectionMatrix() );
            if (iv.getViewMatrix()) matrix.preMult( *iv.getViewMatrix() );
            if (iv.getModelMatrix()) matrix.preMult( *iv.getModelMatrix() );
            break;
        case(VIEW): 
            if (iv.getViewMatrix()) matrix.preMult( *iv.getViewMatrix() );
            if (iv.getModelMatrix()) matrix.preMult( *iv.getModelMatrix() );
            break;
        case(MODEL):
            if (iv.getModelMatrix()) matrix = *iv.getModelMatrix();
            break;
    }

    osg::Matrix inverse;
    inverse.invert(matrix);

    osg::ref_ptr<LineSegmentIntersector> lsi = new LineSegmentIntersector(_start * inverse, _end * inverse);
    lsi->_parent = this;
    return lsi.release();
}

bool LineSegmentIntersector::enter(const osg::Node& node)
{
    return !node.isCullingActive() || intersects( node.getBound() );
}

void LineSegmentIntersector::leave()
{
    // do nothing
}

void LineSegmentIntersector::intersect(osgUtil::IntersectionVisitor& iv, osg::Drawable* drawable)
{
    osg::Vec3d s(_start), e(_end);    
    if ( !intersectAndClip( s, e, drawable->getBound() ) ) return;

    if (iv.getDoDummyTraversal()) return;

    osg::KdTree* kdTree = iv.getUseKdTreeWhenAvailable() ? dynamic_cast<osg::KdTree*>(drawable->getShape()) : 0;
    if (kdTree)
    {
        osg::KdTree::LineSegmentIntersections intersections;
        intersections.reserve(4);
        if (kdTree->intersect(s,e,intersections))
        {
            // OSG_NOTICE<<"Got KdTree intersections"<<std::endl;
            for(osg::KdTree::LineSegmentIntersections::iterator itr = intersections.begin();
                itr != intersections.end();
                ++itr)
            {
                osg::KdTree::LineSegmentIntersection& lsi = *(itr);
                
                // get ratio in s,e range
                double ratio = lsi.ratio;

                // remap ratio into _start, _end range
                double remap_ratio = ((s-_start).length() + ratio * (e-s).length() )/(_end-_start).length();


                Intersection hit;
                hit.ratio = remap_ratio;
                hit.matrix = iv.getModelMatrix();
                hit.nodePath = iv.getNodePath();
                hit.drawable = drawable;
                hit.primitiveIndex = lsi.primitiveIndex;

                hit.localIntersectionPoint = _start*(1.0-remap_ratio) + _end*remap_ratio;
                
                // OSG_NOTICE<<"KdTree: ratio="<<hit.ratio<<" ("<<hit.localIntersectionPoint<<")"<<std::endl;
                
                hit.localIntersectionNormal = lsi.intersectionNormal;
                
                hit.indexList.reserve(3);
                hit.ratioList.reserve(3);
                if (lsi.r0!=0.0f) 
                {
                    hit.indexList.push_back(lsi.p0);
                    hit.ratioList.push_back(lsi.r0);
                }
                
                if (lsi.r1!=0.0f) 
                {
                    hit.indexList.push_back(lsi.p1);
                    hit.ratioList.push_back(lsi.r1);
                }

                if (lsi.r2!=0.0f) 
                {
                    hit.indexList.push_back(lsi.p2);
                    hit.ratioList.push_back(lsi.r2);
                }

                insertIntersection(hit);
            }
        }
        
        return;
    }

    osg::TriangleFunctor<LineSegmentIntersectorUtils::TriangleIntersector> ti;
    ti.set(s,e);
    drawable->accept(ti);

    if (ti._hit)
    {
        osg::Geometry* geometry = drawable->asGeometry();

        for(LineSegmentIntersectorUtils::TriangleIntersections::iterator thitr = ti._intersections.begin();
            thitr != ti._intersections.end();
            ++thitr)
        {

            // get ratio in s,e range
            double ratio = thitr->first;

            // remap ratio into _start, _end range
            double remap_ratio = ((s-_start).length() + ratio * (e-s).length() )/(_end-_start).length();

            LineSegmentIntersectorUtils::TriangleIntersection& triHit = thitr->second;

            Intersection hit;
            hit.ratio = remap_ratio;
            hit.matrix = iv.getModelMatrix();
            hit.nodePath = iv.getNodePath();
            hit.drawable = drawable;
            hit.primitiveIndex = triHit._index;

            hit.localIntersectionPoint = _start*(1.0-remap_ratio) + _end*remap_ratio;

            // OSG_NOTICE<<"Conventional: ratio="<<hit.ratio<<" ("<<hit.localIntersectionPoint<<")"<<std::endl;

            hit.localIntersectionNormal = triHit._normal;

            if (geometry)
            {
                osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>(geometry->getVertexArray());
                if (vertices)
                {
                    osg::Vec3* first = &(vertices->front());
                    if (triHit._v1)
                    {
                        hit.indexList.push_back(triHit._v1-first);
                        hit.ratioList.push_back(triHit._r1);
                    }
                    if (triHit._v2)
                    {
                        hit.indexList.push_back(triHit._v2-first);
                        hit.ratioList.push_back(triHit._r2);
                    }
                    if (triHit._v3)
                    {
                        hit.indexList.push_back(triHit._v3-first);
                        hit.ratioList.push_back(triHit._r3);
                    }
                }
            }
            
            insertIntersection(hit);

        }
    }
}

void LineSegmentIntersector::reset()
{
    Intersector::reset();
    
    _intersections.clear();
}

bool LineSegmentIntersector::intersects(const osg::BoundingSphere& bs)
{
    // if bs not valid then return true based on the assumption that an invalid sphere is yet to be defined.
    if (!bs.valid()) return true; 

    osg::Vec3d sm = _start - bs._center;
    double c = sm.length2()-bs._radius*bs._radius;
    if (c<0.0) return true;

    osg::Vec3d se = _end-_start;
    double a = se.length2();
    double b = (sm*se)*2.0;
    double d = b*b-4.0*a*c;

    if (d<0.0) return false;

    d = sqrt(d);

    double div = 1.0/(2.0*a);

    double r1 = (-b-d)*div;
    double r2 = (-b+d)*div;

    if (r1<=0.0 && r2<=0.0) return false;

    if (r1>=1.0 && r2>=1.0) return false;

    // passed all the rejection tests so line must intersect bounding sphere, return true.
    return true;
}

bool LineSegmentIntersector::intersectAndClip(osg::Vec3d& s, osg::Vec3d& e,const osg::BoundingBox& bbInput)
{
    osg::Vec3d bb_min(bbInput._min);
    osg::Vec3d bb_max(bbInput._max);

#if 1
    double epsilon = 1e-4;
    bb_min.x() -= epsilon;
    bb_min.y() -= epsilon;
    bb_min.z() -= epsilon;
    bb_max.x() += epsilon;
    bb_max.y() += epsilon;
    bb_max.z() += epsilon;
#endif

    // compate s and e against the xMin to xMax range of bb.
    if (s.x()<=e.x())
    {

        // trivial reject of segment wholely outside.
        if (e.x()<bb_min.x()) return false;
        if (s.x()>bb_max.x()) return false;

        if (s.x()<bb_min.x())
        {
            // clip s to xMin.
            s = s+(e-s)*(bb_min.x()-s.x())/(e.x()-s.x());
        }

        if (e.x()>bb_max.x())
        {
            // clip e to xMax.
            e = s+(e-s)*(bb_max.x()-s.x())/(e.x()-s.x());
        }
    }
    else
    {
        if (s.x()<bb_min.x()) return false;
        if (e.x()>bb_max.x()) return false;

        if (e.x()<bb_min.x())
        {
            // clip s to xMin.
            e = s+(e-s)*(bb_min.x()-s.x())/(e.x()-s.x());
        }

        if (s.x()>bb_max.x())
        {
            // clip e to xMax.
            s = s+(e-s)*(bb_max.x()-s.x())/(e.x()-s.x());
        }
    }

    // compate s and e against the yMin to yMax range of bb.
    if (s.y()<=e.y())
    {

        // trivial reject of segment wholely outside.
        if (e.y()<bb_min.y()) return false;
        if (s.y()>bb_max.y()) return false;

        if (s.y()<bb_min.y())
        {
            // clip s to yMin.
            s = s+(e-s)*(bb_min.y()-s.y())/(e.y()-s.y());
        }

        if (e.y()>bb_max.y())
        {
            // clip e to yMax.
            e = s+(e-s)*(bb_max.y()-s.y())/(e.y()-s.y());
        }
    }
    else
    {
        if (s.y()<bb_min.y()) return false;
        if (e.y()>bb_max.y()) return false;

        if (e.y()<bb_min.y())
        {
            // clip s to yMin.
            e = s+(e-s)*(bb_min.y()-s.y())/(e.y()-s.y());
        }

        if (s.y()>bb_max.y())
        {
            // clip e to yMax.
            s = s+(e-s)*(bb_max.y()-s.y())/(e.y()-s.y());
        }
    }

    // compate s and e against the zMin to zMax range of bb.
    if (s.z()<=e.z())
    {

        // trivial reject of segment wholely outside.
        if (e.z()<bb_min.z()) return false;
        if (s.z()>bb_max.z()) return false;

        if (s.z()<bb_min.z())
        {
            // clip s to zMin.
            s = s+(e-s)*(bb_min.z()-s.z())/(e.z()-s.z());
        }

        if (e.z()>bb_max.z())
        {
            // clip e to zMax.
            e = s+(e-s)*(bb_max.z()-s.z())/(e.z()-s.z());
        }
    }
    else
    {
        if (s.z()<bb_min.z()) return false;
        if (e.z()>bb_max.z()) return false;

        if (e.z()<bb_min.z())
        {
            // clip s to zMin.
            e = s+(e-s)*(bb_min.z()-s.z())/(e.z()-s.z());
        }

        if (s.z()>bb_max.z())
        {
            // clip e to zMax.
            s = s+(e-s)*(bb_max.z()-s.z())/(e.z()-s.z());
        }
    }
    
    // OSG_NOTICE<<"clampped segment "<<s<<" "<<e<<std::endl;
    
    // if (s==e) return false;

    return true;
}
