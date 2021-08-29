
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "studentInfo_config.h"

namespace config
{
bool student_info_config::load_info_config(const std::string& config_file, CxxJson::CJsonObject& json_object)
{
    bool result = false;
    unsigned long file_size = -1;
    struct stat statbuff;
    if (stat(config_file.c_str(), &statbuff) < 0)
    {
        printf("stat info config json file failed\n");
        return false;
    }
    else
    {
        file_size = statbuff.st_size;
    }
    int fd = open(config_file.c_str(), O_RDONLY);
    if (fd > 0)
    {
        char *p_data_buf = new char[file_size];
        int ret = read(fd, p_data_buf, file_size);
        if (ret > 0)
        {
            m_json_object.Parse(p_data_buf);
            json_object = m_json_object;
            result = true;
        }
        else
        {
            printf("read info config json file failed\n");
        }
        close(fd);
        delete[] p_data_buf;
    }
    else
    {
        printf("open info config json file failed\n");
    }

    return result;
}

void student_info_config::get_info_config(info_config& config)
{
    config.name                 = m_json_object[JSON_STRING_INFO]["name"].StringValue();
    config.year                 = m_json_object[JSON_STRING_INFO]["year"].IntValue();
    config.id                   = m_json_object[JSON_STRING_INFO]["id"].IntValue();
    config.chinese              = m_json_object[JSON_STRING_INFO]["chinese"].DoubleValue();
    config.math                 = m_json_object[JSON_STRING_INFO]["match"].DoubleValue();
    config.home_path            = m_json_object[JSON_STRING_INFO]["home_path"].StringValue();
    config.flag_pass            = m_json_object[JSON_STRING_INFO]["flag_pass"].IntValue();
}

} 