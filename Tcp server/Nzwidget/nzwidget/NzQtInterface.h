/*
 * NzQtInterface.h
 *
 *  Created on: Oct 31, 2011
 *      Author: gerardo
 */
#ifndef NZQTINTERFACE_H_
#define NZQTINTERFACE_H_

#include <stdint.h>

class NzQtInterface
{
public:
    static bool QTInit(int & argc, char ** & argv, int designWidth=0, int designHeight=0);
    static void getOidDevice(char * oidDeviceString, int size);

    static void setLocalVideo(int x, int y, int width, int height);
    static void sendIIRF(uint32_t code);
    static void shutdown();

    static const char * getAppName();

    static void perfTest(bool start);

    static int getWidth();
    static int getHeight();

    static int getDesignWidth();
    static int getDesignHeight();

    static const char * getUrl();
    static const char * getUrlParms();
};

#endif /* NZQTINTERFACE_H_ */
