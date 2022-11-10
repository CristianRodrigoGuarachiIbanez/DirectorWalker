#include <string>
#include <vector>
#include <iostream>
#include <experimental/filesystem>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/types.hpp>

namespace DirectoryWalker{
    class DirWalker{
        public:
            DirWalker(std::string path, std::string type, int extention);
            ~DirWalker();
            std::vector<cv::Mat> images(){
                if(listOfImages.empty()){
                    std::cerr << "Error\n";
                    std::cerr << "vector images is empty\n";
                }else{

                    return listOfImages;
                }
                    
            }
            std::vector<std::string> directories(){
                if(listOfDirs.empty()){
                    std::cerr << "Error\n";
                    std::cerr << "vector strings is empty\n";
                }else{

                    return listOfDirs;
                }
            }

            std::vector<std::string> selectedDirectories(){
                if(selectedDirs.empty()){
                    std::cerr << "Error\n";
                    std::cerr << "vector strings is empty\n";
                }else{

                    return selectedDirs;
                }
            }

        private:
            std::vector<std::string> listOfDirs;
            std::vector<std::string> selectedDirs;
            std::vector<cv::Mat> listOfImages;
            void directorieswalker(std::string path, std::string type, int extention);
            inline cv::Mat openImage(std::string fileName);

    };
}