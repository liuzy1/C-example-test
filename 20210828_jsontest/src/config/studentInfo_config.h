#include "CJsonObject.hpp"

#ifndef M_CONFIG_H
#define M_CONFIG_H

namespace config
{

#define JSON_STRING_INFO                "info"
struct info_config
{
    std::string name;
    int year;
    int id;
    double chinese;
    double math;
    std::string home_path;
    int flag_pass;
};

class student_info_config
{
public:
    student_info_config() = default;
    virtual ~student_info_config() {}

    student_info_config(const student_info_config&) = delete;
    student_info_config& operator=(const student_info_config&) = delete;

    bool load_info_config(const std::string& config_file, CxxJson::CJsonObject& json_object);
    void get_info_config(info_config& config);
protected:
    CxxJson::CJsonObject m_json_object;
};

}

#endif