Authoring_Tools_4_product_tagging
=================================
qt folder - GUI for Training - Developed completely for Face Recognition
          - Creates the Eigen, Fisher and lbph recognizers
          - Also has frame based mode for testing the recognizers
          
src folder - commandline based training testing and video generation
             for face recognition and object detection
    #facerec.cpp - all functionalities object/face included
                 - use ./facerec -h for usage
    #collect_samples.cpp - collect training images for use in facerec.cpp
    #vid2img.cpp - converts a video to corresponding bunch of images
    #obj_det.cpp - for training on PASCAL Dataset
    #obj_detect.cpp - for creating a xml annotation file used in creating datastream of the video
    #face.cpp - face detection fucntions created as a header file - new version
    #main.cpp - integration of the all the functionalities and commandline decoding
    #other cpp files - support and test files

include folder - all header files

scripts folder - bash scripts and matlab scripts which helps in cropping images and renaming files

docs folder - documentation like project proposal, timeline etc

lib folder - cmake created library path

bin folder - executables

build folder - make and other cmake files and object files

mike_cook_comcast - files related to branch off project with comcast



    
    
