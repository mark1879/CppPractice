//
//  time_practice.hpp
//  BasicKnowledge
//
//  Created by MarkWu on 2018/2/14.
//  Copyright © 2018年 Zego. All rights reserved.
//

#ifndef time_practice_h
#define time_practice_h

#include <iostream>
#include <time.h>

using namespace std;

void dsptime(const struct tm * ptm)
{
    char *pxq[]={"日","一","二","三","四","五","六"};
    cout << ptm->tm_year+1900 << "年" << ptm->tm_mon+1 << "月" << ptm->tm_mday << "日 " ;
    cout << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec <<" " ;
    cout << " 星期" <<pxq[ptm->tm_wday] << " 当年的第" << ptm->tm_yday << "天 " << endl;
    cout << "时区：" << ptm->tm_zone << endl;
    cout << "tm_isdst: " << ptm->tm_isdst << endl;
    cout << "tm_gmtoff: " << ptm->tm_gmtoff << endl;
    cout << endl;
}

void show_time()
{
    time_t nowtime;
    nowtime = time(NULL); //获取日历时间
    cout << "当前时间戳: " << nowtime << endl << endl;  //输出nowtime
    
    struct tm *local,*gm;
    local=localtime(&nowtime);  //获取当前系统时间
    dsptime(local);
    gm=gmtime(&nowtime);  //获取格林尼治时间
    dsptime(gm);
    
    // 非线程安全，已被抛弃
    cout << asctime(local) ;
    cout << ctime(&nowtime) ;
    cout << endl;
    
    // 推荐方法
    char buffer [80];
    strftime(buffer, 80, "格式化输出：%Y-%m-%d %H:%M:%S", local);
    cout << buffer << endl << endl;
}

#endif /* time_practice_h */
