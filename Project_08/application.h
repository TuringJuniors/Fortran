#ifndef APPLICATION
#define APPLICATION

class application
{
    public:
    
    bool userResponse;
    
    void notify(bool thiefDetected);
    
    void waitUserResponse(int time);

    void emergencyCall();
 
};

#endif