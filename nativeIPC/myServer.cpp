#include "server.h"

int nativeIBinderService(int argc, char *argv[])
{
    sp<ProcessState> proc(ProcessState::self());
    //get service manager
    sp<IServiceManager> sm = defaultServiceManager();

    //Register a service with the SERVICE_NAME
    sm->addService(String16(SERVICE_NAME),new demo_api::DemoAPI());
    ALOGE("%s service is starting.....",SERVICE_NAME);
    //Start Service
    ProcessState::self()->startThreadPool();
    //Loop for waiting for request
    IPCThreadState::self()->joinThreadPool();

    return 0;
}
#if 0
thread nativeIBinderServiceInit(int argc, char *argv[])
{
    sp<ProcessState> proc(ProcessState::self());
    //get service manager
    sp<IServiceManager> sm = defaultServiceManager();

    //Register a service with the SERVICE_NAME
    sm->addService(String16(SERVICE_NAME),new demo_api::DemoAPI());
    ALOGE("%s service is starting.....",SERVICE_NAME);
    //Start Service
    ProcessState::self()->startThreadPool();

    return ProcessState::self();
}

int nativeIBinderServiceThread(thread)
{
 
	
    //Loop for waiting for request
    //IPCThreadState::self()->joinThreadPool();
	thread->joinThreadPool();

    return 0;
}
#endif