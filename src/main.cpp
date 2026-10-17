#include<iostream>
#include"core/contentManager.hpp"
#include"file/fileContentRepository.hpp"
#include "error/fileError.hpp"

int main(int argc, char** args)
{
    try
    {
        FileContentRepository repo(args[1]);
    
        ContentManager manager(&repo);

        manager.addLine("   bla bla");
        manager.addLine("bla bla");
        manager.addLine("bla bla");
        manager.setLine(0, "nowa linia 1");
        manager.saveData();
        const auto& lines = manager.getLines();
        for(size_t i = 0; i < lines.size(); ++i)
        {
            std::cout<<i + 1<<' '<<lines[i]<<'\n';
        }
    }
    catch(FileError err)
    {
        std::cout<<err.what();
    }
    return 0;
}