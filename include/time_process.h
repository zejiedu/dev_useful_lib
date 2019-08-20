#ifndef TIME_PROCESS
#define TIME_PROCESS

#include <string>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <iostream>

//
//typedef long time_t

/*
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}
 */

//time_stamp 返回自纪元 Epoch（1970-01-01 00:00:00 UTC）起经过的时间，以秒为单位。
//协调世界时，又称世界统一时间、世界标准时间、国际协调时间，简称UTC。
time_t get_time_stamp(){
    return time(nullptr);
}
//该返回一个表示当地时间的字符串指针
char* get_local_time_str()
{
   auto t= time(nullptr); 
   return ctime(&t);
}


typedef tm tm;

tm to_local_time(time_t t){
    return *localtime( &t );
}

tm to_utc_time(time_t t){
    return *gmtime( &t );
}

char * to_tm_str(tm * t){
    return asctime(t);
}

char * to_tm_str(tm t){
    return asctime(&t);
}
time_t to_time_stamp(struct tm *timeptr){
    return mktime(timeptr);
}
 
std::string get_date_str(tm* info){
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d", info);
    std::string str = buffer;
    return buffer;
}

std::string get_time_str(tm* info){
    char buffer[80];
    strftime(buffer, 80, "%H:%M:%S", info);
    std::string str = buffer;
    return buffer;
}



 
class Timer {
public:
 
    Timer(std::string name = "Timer:"):_name(name) {
        reset();
    }    
 
    //启动计时    
    inline void reset() {
        _start_time = std::chrono::steady_clock::now();
    }
 
    /**
    * 结束计时
    * @return 返回ms数
    */
    inline double elapsed() {
        _end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = _end_time-_start_time;        
        return diff.count()*1000;
    }
 
    
    std::string log(const std::string &tip=" "){
        return _name + ":"+tip+" elapsed ->" + std::to_string(elapsed()) + "ms" ;        
    }

    std::string log_and_reset(const std::string &tip){
        return _name + ":"+tip+" elapsed ->" + std::to_string(elapsed()) + "ms" ;   
        reset();
    }

    ~Timer(){
        std::cerr<< (_name + " has  elapsed ->" + std::to_string(elapsed()) + "ms")<<std::endl ;  
    }  
 
private:
    std::chrono::steady_clock::time_point _start_time;
    std::chrono::steady_clock::time_point _end_time;
    std::string _name;
}; // timer





#endif