#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
    FILE *stream;
    char buf[1024];
    int cnt = 0;
    istringstream istr;
    int pid;
    string a, b, name;
    name = argv[1];
    memset(buf, '\0', sizeof(buf));
    // grep process name
    string grep = "ps -e|grep " + name;
    const char* c = grep.c_str();
    stream = popen(c, "r");
    fread(buf, sizeof(char), sizeof(buf), stream);
    istr.str(buf);
    // get pid
    while(1) {
        istr >> pid >> a >> b >> name;
        if (name == "block") break;
    }
    // cat it's ctx
    string cat = "cat /proc/", pids, ctx = "/ctx";
    while(1) {
        memset(buf, '\0', sizeof(buf));
        stringstream ss;
        ss << pid;
        ss >> pids;
        string comd = cat + pids + ctx;
        const char* c = comd.c_str();
        stream = popen(c, "r");
        fread(buf, sizeof(char), sizeof(buf), stream);
        pclose(stream);
        ss.clear();
        ss << buf;
        int ctx_value;
        ss >> ctx_value >> ctx_value;
        printf("\rpid: %d ctx: %d", pid, ctx_value);
    }
    return 0;
}
