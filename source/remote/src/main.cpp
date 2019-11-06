#include "arduino_serial.h"
#include <string.h>
#include <iostream>

#define PORT "/dev/ttyACM0"

using namespace std;

int main() {

    int fd = serialport_init(PORT, 9600);
    string str;

    while (1) {
        
        cin >> str;
        
        if ("OFF" == str)
            break;

        serialport_write(fd, str.c_str());

        char buf[20];
        int r = serialport_read_until(fd, buf, '\0', 20, 1);
        cout << buf << endl;
        bzero(buf, 20);
    }

    serialport_flush(fd);
    serialport_close(fd);

    return 0;
}