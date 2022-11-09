# Directory Walker 

This is a simple implementation of a programm test in Linux 18, which collects all file names inside a directory. Once collected, the file names could be sorted according to a extension, if desiered. 

```cpp
    DirWalker dirWalker("paht/to/file", ".png", 4);
```

This implementation does not only gather the file names in a given directory, in case it is a png or jpg file, they would be automatically opened and saved into a vector. This could be recovered by calling the method **getListOfImages()**

```cpp
    std::vector<cv::Mat> images = dirWalker.getListOfImages();
```

## Dependencies 

In order to run this implemtation, the header file <experimental/filesystem> part of the filesyste library is used [for more information click here](https://en.cppreference.com/w/cpp/header/experimental/filesystem).

Consequently, the cpp file should be linked with **-lstdc++fs**  at compilation time.

The OpenCV Library should also be installed und liked.

## Run

The implementation can be as follows compiled:

First of all, navigate into the directory ./directoryWalker/. Then, compile the cpp file with the following commad:

        g++ std=c++17 main.cpp dirWalker.cpp -o dirWalker -lstdc++fs `pkg-config --cflags --libs opencv`

Lastly, the modul could be executed by using the command ./dirWalker on the Terminal