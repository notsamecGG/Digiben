#include "frame.hpp"

class Renderer
{
public:
    Renderer() 
     : frames({Frame(), Frame()}) { }
    
    void render(std::string& input) 
    {
        frames[0].render(input); 
    }
    void swap()
    {
        clear();
        frames[1].render();

        std::reverse(std::begin(frames), std::end(frames));
    }
    
    void clear() { frames[0].clear(); }

private:
    unsigned int width, heihgt; // width in chars, height in lines

    Frame frames[2];
    // Frame actualFrame;
    // Frame newFrame;
};