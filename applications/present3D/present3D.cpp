/* -*-c++-*- Present3D - Copyright (C) 1999-2006 Robert Osfield 
 *
 * This software is open source and may be redistributed and/or modified under  
 * the terms of the GNU General Public License (GPL) version 2.0.
 * The full license is in LICENSE.txt file included with this distribution,.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * include LICENSE.txt for more details.
*/

#include <osg/Geometry>
#include <osg/CameraNode>
#include <osg/Texture2D>
#include <osg/AutoTransform>
#include <osg/Notify>
#include <osg/io_utils>


#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgDB/FileNameUtils>
#include <osgUtil/Optimizer>

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>

#include <OpenThreads/Thread>

#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/StateSetManipulator>

#include <osgPresentation/SlideEventHandler>
#include <osgPresentation/SlideShowConstructor>

#include "ReadShowFile.h"
#include "PointsEventHandler.h"
#include "Cluster.h"
#include "ExportHTML.h"
#include "SpellChecker.h"

#include <sstream>
#include <fstream>
#include <iostream>

#include <string.h>

#ifdef USE_SDL
    #include "SDLIntegration.h"
#endif

#if OSG_LIBRARY_STATIC

    // include the plugins we need
    USE_OSGPLUGIN(ive)
    USE_OSGPLUGIN(osg)
    USE_OSGPLUGIN(p3d)
    USE_OSGPLUGIN(paths)

    USE_OSGPLUGIN(freetype)
    USE_OSGPLUGIN(rgb)
    USE_OSGPLUGIN(png)
    USE_OSGPLUGIN(jpeg)

    USE_OSGPLUGIN(ffmpeg)
    USE_OSGPLUGIN(pdf)

    USE_OSGPLUGIN(OpenFlight)
    USE_OSGPLUGIN(obj)

    USE_OSGPLUGIN(curl)


    // include the platform specific GraphicsWindow implementation.
    USE_GRAPHICSWINDOW()

#endif

static const char* s_version = "1.4 beta";

void setViewer(osgViewer::Viewer& viewer, float width, float height, float distance)
{
    double vfov = osg::RadiansToDegrees(atan2(height/2.0f,distance)*2.0);
    // double hfov = osg::RadiansToDegrees(atan2(width/2.0f,distance)*2.0);

    viewer.getCamera()->setProjectionMatrixAsPerspective( vfov, width/height, 0.1, 1000.0);
}

#if 1

class RayFollowsMouseCallback : public osg::Drawable::EventCallback
{
    RayFollowsMouseCallback() {}

    /** do customized Event code. */
    virtual void event(osg::NodeVisitor* nv, osg::Drawable* drawable)
    {
        osg::Geometry* geometry = drawable->asGeometry();
        osgGA::EventVisitor* ev = dynamic_cast<osgGA::EventVisitor*>(nv);

        if (!ev || !geometry) return;

        osgGA::GUIActionAdapter* aa = ev->getActionAdapter();
        osgViewer::View* view = dynamic_cast<osgViewer::View*>(aa);
        if (!view) return;

        osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>(geometry->getVertexArray());
        if (!vertices) return;

        osg::Camera* camera = view->getCamera();
        osg::Matrix VP =  camera->getViewMatrix() * camera->getProjectionMatrix();

        osg::Matrix inverse_VP;
        inverse_VP.invert(VP);

        osgGA::EventQueue::Events& events = ev->getEvents();
        for(osgGA::EventQueue::Events::iterator itr = events.begin();
            itr != events.end();
            ++itr)
        {
            handle(inverse_VP, *(*itr), vertices);
        }

    }

    void handle(const osg::Matrix& inverse_VP, osgGA::GUIEventAdapter& ea, osg::Vec3Array* vertices)
    {
        osg::Vec3d start_eye(ea.getXnormalized(), ea.getYnormalized(), 0.0);
        osg::Vec3d end_eye(ea.getXnormalized(), ea.getYnormalized(), 1.0);

        osg::Vec3d start_world = start_eye * inverse_VP;
        osg::Vec3d end_world = start_eye * inverse_VP;

        osg::notify(osg::NOTICE)<<"start_world="<<start_world<<std::endl;
        osg::notify(osg::NOTICE)<<"end_world="<<end_world<<std::endl;

        (*vertices)[0] = start_world;
        (*vertices)[1] = end_world;
    }
};

class FollowMouseCallback: public osgGA::GUIEventHandler
{
    public:

        virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa, osg::Object* object, osg::NodeVisitor* nv)
        {
            osg::AutoTransform* transform = dynamic_cast<osg::AutoTransform*>(object);
            if (!transform) return false;

            switch(ea.getEventType())
            {
                case(osgGA::GUIEventAdapter::FRAME):
                //case(osgGA::GUIEventAdapter::MOVE):
                //case(osgGA::GUIEventAdapter::DRAG):
                {
                    osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);

                    transform->setNodeMask(0x0);

                    osg::notify(osg::NOTICE)<<std::endl<<"ea.getGraphicsContext()="<<ea.getGraphicsContext()<<std::endl;
                    osg::notify(osg::NOTICE)<<"ea.getWindowWidth()="<<ea.getWindowWidth()<<std::endl;
                    osg::notify(osg::NOTICE)<<"ea.getWindowHeight()="<<ea.getWindowHeight()<<std::endl;
                    osg::notify(osg::NOTICE)<<"ea.getX()="<<ea.getX()<<std::endl;
                    osg::notify(osg::NOTICE)<<"ea.getXin()="<<ea.getXmin()<<std::endl;
                    osg::notify(osg::NOTICE)<<"ea.getXmax()="<<ea.getXmax()<<std::endl;
                    osg::notify(osg::NOTICE)<<"ea.getY()="<<ea.getY()<<std::endl;
                    osg::notify(osg::NOTICE)<<"ea.getYin()="<<ea.getYmin()<<std::endl;
                    osg::notify(osg::NOTICE)<<"ea.getYmax()="<<ea.getYmax()<<std::endl;

                    osg::Camera* camera = view->getCamera();
                    osg::Matrix VP =  camera->getViewMatrix() * camera->getProjectionMatrix();

                    osg::Matrix inverse_VP;
                    inverse_VP.invert(VP);

                    osg::Vec3d start_eye(ea.getXnormalized(), ea.getYnormalized(), 0.0);
                    osg::Vec3d end_eye(ea.getXnormalized(), ea.getYnormalized(), 1.0);

                    osg::Vec3d start_world = start_eye * inverse_VP;
                    osg::Vec3d end_world = start_eye * inverse_VP;

                    osg::notify(osg::NOTICE)<<"start_world="<<start_world<<std::endl;
                    osg::notify(osg::NOTICE)<<"end_world="<<end_world<<std::endl;

                    transform->setPosition(end_world);

                    transform->setNodeMask(0xffffffff);

                    break;
                }
                case(osgGA::GUIEventAdapter::KEYDOWN):
                {
                    if (ea.getKey()=='c')
                    {
                        for(unsigned int i=0; i< transform->getNumChildren(); ++i)
                        {
                            osg::Node* node = transform->getChild(i);
                            node->setNodeMask(
                                node->getNodeMask()!=0 ?
                                0 :
                                0xffffff);
                        }
                    }
                    break;
                }
                default:
                    break;
            }
            return false;
        }

        virtual void accept(osgGA::GUIEventHandlerVisitor& v)
        {
            v.visit(*this);
        }

};

osg::Node* createCursorSubgraph(const std::string& filename, float size)
{
    osg::Geode* geode = new osg::Geode;

    size = 20.0f;

    osg::Geometry* geom = osg::createTexturedQuadGeometry(osg::Vec3(-size*0.5f,-size*0.5f,0.0f),osg::Vec3(size,0.0f,0.0f),osg::Vec3(0.0f,size,0.0f));

    osg::Image* image = osgDB::readImageFile(osgDB::findDataFile(filename));
    if (image)
    {
        osg::StateSet* stateset = geom->getOrCreateStateSet();
        stateset->setTextureAttributeAndModes(0, new osg::Texture2D(image),osg::StateAttribute::ON);
        stateset->setMode(GL_BLEND,osg::StateAttribute::ON);
        // stateset->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);
        stateset->setRenderBinDetails(1000, "DepthSortedBin");
    }

    geode->addDrawable(geom);

    osg::AutoTransform* transform = new osg::AutoTransform;
    transform->setAutoRotateMode(osg::AutoTransform::ROTATE_TO_CAMERA);
    transform->setAutoScaleToScreen(true);

    transform->addChild(geode);

    transform->setEventCallback(new FollowMouseCallback());

    return transform;

}
#else
class FollowMouseCallback: public osgGA::GUIEventHandler
{
    public:
    
        virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter&, osg::Object* object, osg::NodeVisitor*)
        {

            switch(ea.getEventType())
            {
                case(osgGA::GUIEventAdapter::MOVE):
                case(osgGA::GUIEventAdapter::DRAG):
                {
                    osg::Camera* camera = dynamic_cast<osg::Camera*>(object);
                    if (camera)
                    {
                        double x = ea.getXnormalized();
                        double y = ea.getYnormalized();

                        camera->setViewMatrix(osg::Matrixd::translate(x,y,0.0));
                    }
                    break;
                }
                case(osgGA::GUIEventAdapter::KEYDOWN):
                {
                    if (ea.getKey()=='c')
                    {
                        osg::Camera* camera = dynamic_cast<osg::Camera*>(object);
                        if (camera)
                        {
                            for(unsigned int i=0; i< camera->getNumChildren(); ++i)
                            {
                                osg::Node* node = camera->getChild(i);
                                node->setNodeMask(
                                    node->getNodeMask()!=0 ?
                                    0 :
                                    0xffffff);
                            }
                        }
                    }
                    break;
                }
                default:
                    break;
            }
            return false;
        }
                
        virtual void accept(osgGA::GUIEventHandlerVisitor& v)
        {
            v.visit(*this);
        }

};
 
osg::Node* createCursorSubgraph(const std::string& filename, float size)
{
    osg::Geode* geode = new osg::Geode;

    osg::Geometry* geom = osg::createTexturedQuadGeometry(osg::Vec3(-size*0.5f,-size*0.5f,0.0f),osg::Vec3(size,0.0f,0.0f),osg::Vec3(0.0f,size,0.0f));

    osg::Image* image = osgDB::readImageFile(osgDB::findDataFile(filename));
    if (image)
    {
        osg::StateSet* stateset = geom->getOrCreateStateSet();
        stateset->setTextureAttributeAndModes(0, new osg::Texture2D(image),osg::StateAttribute::ON);
        stateset->setMode(GL_BLEND,osg::StateAttribute::ON);
        stateset->setRenderBinDetails(1000, "DepthSortedBin");
    }
    
    geode->addDrawable(geom);
    
    osg::Camera* camera = new osg::Camera;

    // set the projection matrix
    camera->setProjectionMatrix(osg::Matrix::ortho2D(-1,1,-1,1));

    // set the view matrix    
    camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
    camera->setViewMatrix(osg::Matrix::identity());

    // only clear the depth buffer
    camera->setClearMask(GL_DEPTH_BUFFER_BIT);

    // draw subgraph after main camera view.
    camera->setRenderOrder(osg::CameraNode::NESTED_RENDER);

    camera->addChild(geode);
    
    camera->setEventCallback(new FollowMouseCallback());
    
    return camera;

}
#endif


enum P3DApplicationType
{
    VIEWER,
    MASTER,
    SLAVE
};



int main( int argc, char **argv )
{
    // use an ArgumentParser object to manage the program arguments.
    osg::ArgumentParser arguments(&argc,argv);
    
    // set up the usage document, in case we need to print out how to use this program.
    arguments.getApplicationUsage()->setApplicationName(arguments.getApplicationName());
    arguments.getApplicationUsage()->setDescription(arguments.getApplicationName()+" is the application for presenting 3D interactive slide shows.");
    arguments.getApplicationUsage()->setCommandLineUsage(arguments.getApplicationName()+" [options] filename ...");
    arguments.getApplicationUsage()->addCommandLineOption("-h or --help","Display this information");
    arguments.getApplicationUsage()->addCommandLineOption("-a","Turn auto stepping on by default");
    arguments.getApplicationUsage()->addCommandLineOption("-d <float>","Time duration in seconds between layers/slides");
    arguments.getApplicationUsage()->addCommandLineOption("-s <float> <float> <float>","width, height, distance and of the screen away from the viewer");
    arguments.getApplicationUsage()->addCommandLineOption("--viewer","Start Present3D as the viewer version.");
    arguments.getApplicationUsage()->addCommandLineOption("--authoring","Start Presen3D as the authoring version, license required.");
    arguments.getApplicationUsage()->addCommandLineOption("--master","Start Present3D as the master version, license required.");
    arguments.getApplicationUsage()->addCommandLineOption("--slave","Start Present3D as the slave version, license required.");
    arguments.getApplicationUsage()->addCommandLineOption("--publishing","Start Present3D as the publishing version, license required.");
    arguments.getApplicationUsage()->addCommandLineOption("--timeDelayOnNewSlideWithMovies","Set the time delay on new slide with movies, done to allow movie threads to get in sync with rendering thread.");
    arguments.getApplicationUsage()->addCommandLineOption("--targetFrameRate","Set the target frame rate, defaults to 80Hz.");
    arguments.getApplicationUsage()->addCommandLineOption("--version","Report the Present3D version.");
    arguments.getApplicationUsage()->addCommandLineOption("--print <filename>","Print out slides to a series of image files.");
    arguments.getApplicationUsage()->addCommandLineOption("--html <filename>","Print out slides to a series of html & image files.");
    arguments.getApplicationUsage()->addCommandLineOption("--loop","Switch on looping of presentation.");
    arguments.getApplicationUsage()->addCommandLineOption("--devices","Print the Video input capability via QuickTime and exit.");

    // add alias from xml to p3d to provide backwards compatibility for old p3d files.
    osgDB::Registry::instance()->addFileExtensionAlias("xml","p3d");

    // if user requests devices video capability.
    if (arguments.read("-devices") || arguments.read("--devices"))
    {
        // Force load QuickTime plugin, probe video capability, exit
        osgDB::readImageFile("devices.live");
        return 1;
    }


    // read any env vars from presentations before we create viewer to make sure the viewer
    // utilises these env vars
    if (p3d::readEnvVars(arguments))
    {
        osg::DisplaySettings::instance()->readEnvironmentalVariables();
    }


#ifdef USE_SDL
    SDLIntegration sdlIntegration;
    
    osg::notify(osg::INFO)<<"USE_SDL"<<std::endl;
#endif    
    
    bool doSetViewer = true;
    std::string configurationFile;

    // check env vars for configuration file
    const char* str = getenv("PRESENT3D_CONFIG_FILE");
    if (!str) str = getenv("OSG_CONFIG_FILE");
    if (str) configurationFile = str;

    // check command line parameters for configuration file.
    while (arguments.read("-c",configurationFile)) {}

    osg::Vec4 clearColor(0.0f,0.0f,0.0f,0.0f);
    
    while (arguments.read("--clear-color",clearColor[0],clearColor[1],clearColor[2],clearColor[3])) {}

    std::string filename;
    if (arguments.read("--spell-check",filename))
    {
        p3d::SpellChecker spellChecker;
        spellChecker.checkP3dXml(filename);
        return 1;
    }

    if (arguments.read("--strip-text",filename))
    {
        p3d::XmlPatcher patcher;
        // patcher.stripP3dXml(filename, osg::notify(osg::NOTICE));

        osg::ref_ptr<osgDB::XmlNode> newNode = patcher.simplifyP3dXml(filename);
        if (newNode.valid())
        {
            newNode->write(std::cout);
        }
        return 1;
    }

    std::string lhs_filename, rhs_filename;
    if (arguments.read("--merge",lhs_filename, rhs_filename))
    {
        p3d::XmlPatcher patcher;
        osg::ref_ptr<osgDB::XmlNode> newNode = patcher.mergeP3dXml(lhs_filename, rhs_filename);
        if (newNode.valid())
        {
            newNode->write(std::cout);
        }
        return 1;
    }


    // construct the viewer.
    osgViewer::Viewer viewer(arguments);
    
    // set clear colour to black by default.
    viewer.getCamera()->setClearColor(clearColor);

    if (!configurationFile.empty())
    {
        viewer.readConfiguration(configurationFile);
        doSetViewer = false;
    }
    
    // set up stereo masks
    viewer.getCamera()->setCullMask(0xffffffff);
    viewer.getCamera()->setCullMaskLeft(0x00000001);
    viewer.getCamera()->setCullMaskRight(0x00000002);   

    // set up the camera manipulators.
    {
        osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;

        keyswitchManipulator->addMatrixManipulator( '1', "Trackball", new osgGA::TrackballManipulator() );
        keyswitchManipulator->addMatrixManipulator( '2', "Flight", new osgGA::FlightManipulator() );
        keyswitchManipulator->addMatrixManipulator( '3', "Drive", new osgGA::DriveManipulator() );
        keyswitchManipulator->addMatrixManipulator( '4', "Terrain", new osgGA::TerrainManipulator() );

        std::string pathfile;
        char keyForAnimationPath = '5';
        while (arguments.read("-p",pathfile))
        {
            osgGA::AnimationPathManipulator* apm = new osgGA::AnimationPathManipulator(pathfile);
            if (apm || !apm->valid()) 
            {
                unsigned int num = keyswitchManipulator->getNumMatrixManipulators();
                keyswitchManipulator->addMatrixManipulator( keyForAnimationPath, "Path", apm );
                keyswitchManipulator->selectMatrixManipulator(num);
                ++keyForAnimationPath;
            }
        }

        viewer.setCameraManipulator( keyswitchManipulator.get() );
    }

    // add the state manipulator
    viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );

    // add the state manipulator
    viewer.addEventHandler( new osgViewer::StatsHandler() );

    viewer.addEventHandler( new osgViewer::WindowSizeHandler() );

    // neeed to address.
    // viewer.getScene()->getUpdateVisitor()->setTraversalMode(osg::NodeVisitor::TRAVERSE_ACTIVE_CHILDREN);


    const char* p3dCursor = getenv("P3D_CURSOR");
    std::string cursorFileName( p3dCursor ? p3dCursor : "");
    while (arguments.read("--cursor",cursorFileName)) {}


    while (arguments.read("--set-viewer")) { doSetViewer = true; }
    
    while (arguments.read("--no-set-viewer")) { doSetViewer = false; }
    

    // cluster related entries.
    int socketNumber=8100;
    while (arguments.read("-n",socketNumber)) {}

    float camera_fov=-1.0f;
    while (arguments.read("-f",camera_fov)) {}

    float camera_offset=45.0f;
    while (arguments.read("-o",camera_offset)) {}


    std::string exportName;
    while (arguments.read("--print",exportName)) {}

    while (arguments.read("--html",exportName)) {}

    // read any time delay argument.
    float timeDelayBetweenSlides = 1.0f;
    while (arguments.read("-d",timeDelayBetweenSlides)) {}

    bool autoSteppingActive = false;
    while (arguments.read("-a")) autoSteppingActive = true;

    bool loopPresentation = false;
    while (arguments.read("--loop")) loopPresentation = true;


    // register the slide event handler - which moves the presentation from slide to slide, layer to layer.
    osgPresentation::SlideEventHandler* seh = new osgPresentation::SlideEventHandler(&viewer);
    viewer.addEventHandler(seh);

    seh->setAutoSteppingActive(autoSteppingActive);
    seh->setTimeDelayBetweenSlides(timeDelayBetweenSlides);
    seh->setLoopPresentation(loopPresentation);

    double targetFrameRate = 80.0;
    while (arguments.read("--targetFrameRate",targetFrameRate)) {}


    // set the time delay
    float timeDelayOnNewSlideWithMovies = 0.4f;
    while (arguments.read("--timeDelayOnNewSlideWithMovies",timeDelayOnNewSlideWithMovies)) {}
    seh->setTimeDelayOnNewSlideWithMovies(timeDelayOnNewSlideWithMovies);

    // set up optimizer options
    unsigned int optimizer_options = osgUtil::Optimizer::DEFAULT_OPTIMIZATIONS;
    bool relase_and_compile = false;
    while (arguments.read("--release-and-compile")) 
    {
        relase_and_compile = true;
    }
    seh->setReleaseAndCompileOnEachNewSlide(relase_and_compile);
    if (relase_and_compile)
    {
        // make sure that imagery stays around after being applied to textures.
        viewer.getDatabasePager()->setUnrefImageDataAfterApplyPolicy(true,false);
        optimizer_options &= ~osgUtil::Optimizer::OPTIMIZE_TEXTURE_SETTINGS;
    }
// 
//     osgDB::Registry::instance()->getOrCreateDatabasePager()->setUnrefImageDataAfterApplyPolicy(true,false);
//     optimizer_options &= ~osgUtil::Optimizer::OPTIMIZE_TEXTURE_SETTINGS;
//     osg::Texture::getTextureObjectManager()->setExpiryDelay(0.0f);
//     osgDB::Registry::instance()->getOrCreateDatabasePager()->setExpiryDelay(1.0f);

    // register the handler for modifying the point size
    PointsEventHandler* peh = new PointsEventHandler;
    viewer.addEventHandler(peh);
    
    // osg::DisplaySettings::instance()->setSplitStereoAutoAjustAspectRatio(false);

    float width = osg::DisplaySettings::instance()->getScreenWidth();
    float height = osg::DisplaySettings::instance()->getScreenHeight();
    float distance = osg::DisplaySettings::instance()->getScreenDistance();
    bool sizesSpecified = false;
    while (arguments.read("-s", width, height, distance)) 
    {
        sizesSpecified = true;
        
        osg::DisplaySettings::instance()->setScreenDistance(distance);
        osg::DisplaySettings::instance()->setScreenHeight(height);
        osg::DisplaySettings::instance()->setScreenWidth(width);
    }

    std::string outputFileName;
    while(arguments.read("--output",outputFileName)) {}


    // get details on keyboard and mouse bindings used by the viewer.
    viewer.getUsage(*arguments.getApplicationUsage());

    // if user request help write it out to cout.
    if (arguments.read("-h") || arguments.read("--help"))
    {
        arguments.getApplicationUsage()->write(osg::notify(osg::NOTICE));
        return 1;
    }

    P3DApplicationType P3DApplicationType = VIEWER;

    str = getenv("PRESENT3D_TYPE");
    if (str)
    {
        if (strcmp(str,"viewer")==0) P3DApplicationType = VIEWER;
        else if (strcmp(str,"master")==0) P3DApplicationType = MASTER;
        else if (strcmp(str,"slave")==0) P3DApplicationType = SLAVE;
    }
        
    while (arguments.read("--viewer")) { P3DApplicationType = VIEWER; }
    while (arguments.read("--master")) { P3DApplicationType = MASTER; }
    while (arguments.read("--slave")) { P3DApplicationType = SLAVE; }
    
    while (arguments.read("--version"))
    {
        std::string appTypeName = "invalid";
        switch(P3DApplicationType)
        {
            case(VIEWER): appTypeName = "viewer"; break;
            case(MASTER): appTypeName = "master"; break;
            case(SLAVE): appTypeName = "slave"; break;
        }

        osg::notify(osg::NOTICE)<<std::endl;
        osg::notify(osg::NOTICE)<<"Present3D "<<appTypeName<<" version : "<<s_version<<std::endl;
        osg::notify(osg::NOTICE)<<std::endl;

        return 0;
    }

    // any option left unread are converted into errors to write out later.
    //arguments.reportRemainingOptionsAsUnrecognized();

    // report any errors if they have ocured when parsing the program aguments.
    if (arguments.errors())
    {
        arguments.writeErrorMessages(osg::notify(osg::INFO));
        return 1;
    }


    // read files name from arguments.
    p3d::FileNameList xmlFiles, normalFiles;
    if (!p3d::getFileNames(arguments, xmlFiles, normalFiles))
    {
        osg::notify(osg::NOTICE)<<std::endl;
        osg::notify(osg::NOTICE)<<"No file specified, please specify and file to load."<<std::endl;
        osg::notify(osg::NOTICE)<<std::endl;
        return 1;
    }



    bool viewerInitialized = false;
    if (!xmlFiles.empty())
    {
        osg::ref_ptr<osg::Node> holdingModel = p3d::readHoldingSlide(xmlFiles.front());

        if (holdingModel.valid())
        {
            viewer.setSceneData(holdingModel.get());

            seh->selectSlide(0);

            if (!viewerInitialized)
            {
                // pass the global stateset to the point event handler so that it can
                // alter the point size of all points in the scene.
                peh->setStateSet(viewer.getCamera()->getOrCreateStateSet());

                // create the windows and run the threads.
                viewer.realize();

                if (doSetViewer) setViewer(viewer, width, height, distance);

                viewerInitialized = true;
            }

            seh->home();

            // render a frame
            viewer.frame();
        }
    }

    osg::Timer timer;
    osg::Timer_t start_tick = timer.tick();


    osg::ref_ptr<osgDB::ReaderWriter::Options> cacheAllOption = new osgDB::ReaderWriter::Options;
    cacheAllOption->setObjectCacheHint(osgDB::ReaderWriter::Options::CACHE_ALL);
    osgDB::Registry::instance()->setOptions(cacheAllOption.get());

    // read the scene from the list of file specified commandline args.
    osg::ref_ptr<osg::Node> loadedModel = p3d::readShowFiles(arguments,cacheAllOption.get()); // osgDB::readNodeFiles(arguments, cacheAllOption.get());


    osgDB::Registry::instance()->setOptions( 0 );


    // if no model has been successfully loaded report failure.
    if (!loadedModel) 
    {
        osg::notify(osg::INFO) << arguments.getApplicationName() <<": No data loaded" << std::endl;
        return 1;
    }

    osg::Timer_t end_tick = timer.tick();

    osg::notify(osg::INFO) << "Time to load = "<<timer.delta_s(start_tick,end_tick)<<std::endl;


    if (loadedModel->getNumDescriptions()>0)
    {
        for(unsigned int i=0; i<loadedModel->getNumDescriptions(); ++i)
        {
            const std::string& desc = loadedModel->getDescription(i);
            if (desc=="loop") 
            {
                osg::notify(osg::NOTICE)<<"Enabling looping"<<std::endl;
                seh->setLoopPresentation(true);
            }
            else if (desc=="auto") 
            {
                osg::notify(osg::NOTICE)<<"Enabling auto run"<<std::endl;
                seh->setAutoSteppingActive(true);
            }
        }
    }


#if !defined(OSG_GLES2_AVAILABLE) && !defined(OSG_GL3_AVAILABLE)

    // add back in enabling of the GL_ALPHA_TEST to get around the core OSG no longer setting it by default for opaque bins.
    // the alpha test is required for the volume rendering alpha clipping to work.
    loadedModel->getOrCreateStateSet()->setMode(GL_ALPHA_TEST, osg::StateAttribute::ON);
#endif


    // optimize the scene graph, remove rendundent nodes and state etc.
    osgUtil::Optimizer optimizer;
    optimizer.optimize(loadedModel.get(), optimizer_options);

    if (!cursorFileName.empty())
    {
        osg::ref_ptr<osg::Group> group = new osg::Group;
        group->addChild(loadedModel.get());
        group->addChild(createCursorSubgraph(cursorFileName, 0.05f));
        
        loadedModel = group.get();
    }

    // set the scene to render
    viewer.setSceneData(loadedModel.get());

    if (!viewerInitialized)
    {
        // pass the global stateset to the point event handler so that it can
        // alter the point size of all points in the scene.
        peh->setStateSet(viewer.getCamera()->getOrCreateStateSet());

        // create the windows and run the threads.
        viewer.realize();

        if (doSetViewer) setViewer(viewer, width, height, distance);

        viewerInitialized = true;
    }

    if (!cursorFileName.empty())
    {
        // have to add a frame in here to avoid problems with X11 threading issue on switching off the cursor
        // not yet sure why it makes a difference, but it at least fixes the crash that would otherwise occur
        // under X11.
        viewer.frame();

        // switch off the cursor
        osgViewer::Viewer::Windows windows;
        viewer.getWindows(windows);
        for(osgViewer::Viewer::Windows::iterator itr = windows.begin();
            itr != windows.end();
            ++itr)
        {
            (*itr)->useCursor(false);
        }
    }

    // pass the model to the slide event handler so it knows which to manipulate.
    seh->set(loadedModel.get());
    seh->selectSlide(0);

    seh->home();

    if (!outputFileName.empty())
    {
        osgDB::writeNodeFile(*loadedModel,outputFileName);
        return 0;
    }
    
    osg::Timer_t startOfFrameTick = osg::Timer::instance()->tick();
    double targetFrameTime = 1.0/targetFrameRate;
    
    if (exportName.empty())
    {
        // objects for managing the broadcasting and recieving of camera packets.
        CameraPacket cp;
        Broadcaster  bc;
        Receiver     rc;
        bc.setPort(static_cast<short int>(socketNumber));
        rc.setPort(static_cast<short int>(socketNumber));

        bool masterKilled = false;
        DataConverter scratchPad(1024);

        while( !viewer.done() && !masterKilled)
        {
            // wait for all cull and draw threads to complete.
            viewer.advance();

            osg::Timer_t currentTick = osg::Timer::instance()->tick();
            double deltaTime = osg::Timer::instance()->delta_s(startOfFrameTick, currentTick);


            if (deltaTime<targetFrameTime)
            {
                OpenThreads::Thread::microSleep(static_cast<unsigned int>((targetFrameTime-deltaTime)*1000000.0));
            }

            startOfFrameTick =  osg::Timer::instance()->tick();

#if 0            
            if (kmcb)
            {
                double time = kmcb->getTime();
                viewer.getFrameStamp()->setReferenceTime(time);
            }
#endif

#ifdef USE_SDL
            sdlIntegration.update(viewer);
#endif

            if (P3DApplicationType==MASTER)
            {
                // take camera zero as the guide.
                osg::Matrix modelview(viewer.getCamera()->getViewMatrix());
                
                cp.setPacket(modelview,viewer.getFrameStamp());
                
                // cp.readEventQueue(viewer);

                scratchPad.reset();
                scratchPad.write(cp);

                scratchPad.reset();
                scratchPad.read(cp);

                bc.setBuffer(scratchPad._startPtr, scratchPad._numBytes);
                
                std::cout << "bc.sync()"<<scratchPad._numBytes<<std::endl;

                bc.sync();
            }
            else if (P3DApplicationType==SLAVE)
            {
                rc.setBuffer(scratchPad._startPtr, scratchPad._numBytes);

                rc.sync();
                
                scratchPad.reset();
                scratchPad.read(cp);
    
                // cp.writeEventQueue(viewer);

                if (cp.getMasterKilled()) 
                {
                    std::cout << "Received master killed."<<std::endl;
                    // break out of while (!done) loop since we've now want to shut down.
                    masterKilled = true;
                }
            }

            // update the scene by traversing it with the the update visitor which will
            // call all node update callbacks and animations.
            viewer.eventTraversal();

            // update the scene by traversing it with the the update visitor which will
            // call all node update callbacks and animations.
            viewer.updateTraversal();

            if (P3DApplicationType==SLAVE)
            {
                osg::Matrix modelview;
                cp.getModelView(modelview,camera_offset);

                viewer.getCamera()->setViewMatrix(modelview);
            }

            // fire off the cull and draw traversals of the scene.
            if(!masterKilled)
                viewer.renderingTraversals();
        }
    }
    else
    {
        ExportHTML::write(seh, viewer, exportName);
    }
            
    return 0;
}

