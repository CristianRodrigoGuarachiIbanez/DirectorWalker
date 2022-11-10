#include "dirWalker.h"
namespace dw = DirectoryWalker;

dw::DirWalker::DirWalker(std::string path, std::string type, int extension){
    directorieswalker(path, type, extension);
}

dw::DirWalker::~DirWalker(){
    listOfDirs.clear();
    listOfImages.clear();

}

void dw::DirWalker::directorieswalker(std::string path, std::string type, int extension){
    cv::Mat image;
    std::string fileName, ext;
    //const std::experimental::filesystem::path path{"./"};
    for (const auto & entry : std::experimental::filesystem::directory_iterator(path)){
            fileName = entry.path().string();
            ext = fileName.substr(fileName.length() - extension, fileName.length());
            if(ext.compare(type)==0){
                this->selectedDirs.push_back(fileName);
                // std::cout << " Dir -> "<<fileName  << " size -> " << listOfDirs.size() << std::endl;
                if(type.compare(".png")==0 || type.compare(".jpg")==0){
                    this->listOfImages.push_back(openImage(fileName));   
                }
            }else{
                this->listOfDirs.push_back(fileName);
            }
    }   

}
inline cv::Mat dw::DirWalker::openImage(std::string fileName){
    cv::Mat image = cv::imread(fileName, cv::IMREAD_COLOR);
    if(image.empty()){
        std::cerr << "Error\n";
        std::cerr << "Cannot Read Image\n";
    }else{
        return image;
    }
}