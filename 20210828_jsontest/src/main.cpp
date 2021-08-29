#include <unistd.h>
#include <signal.h>
#include <thread>
#include "studentInfo_config.h"
std::unique_ptr<config::student_info_config> g_config_object;
std::string g_configure_file_path;
int main(int argc, char**argv)
{
    if(argc < 3)
    {
        printf("configure file path param hasn't been set\n");
        return -1;
    }
    else if (std::string(argv[1]) == "-config")
    {
        g_configure_file_path = std::string(argv[2]);
         printf("configure file path:%s\n",g_configure_file_path.c_str());
    }

    CxxJson::CJsonObject json_object;
    g_config_object = std::make_unique<config::student_info_config>();
    g_config_object->load_info_config(g_configure_file_path, json_object);
    config::info_config config_option;
    g_config_object->get_info_config(config_option);
    return 0;
}