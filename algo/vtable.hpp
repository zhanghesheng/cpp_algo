//
// Created by Bruce on 2018/10/2.
//

#ifndef EXCEMPLE_VTABLE_HPP
#define EXCEMPLE_VTABLE_HPP

#include <stdio.h>
#include <iostream>

typedef void(*Func)(void);
class Vbase{
public:

    virtual void f(){
        printf("Vbase::f()\n");
    }

    virtual void g(){
        printf("Vbase::g()\n");
    }

    virtual void k(){
        printf("Vbase::k()\n");
    }

    virtual void fun1(Func func1){
        func1();
    }
};

void Vtest(){
//    Vbase base;
//    std::cout << "虚函数表地址：" << (int*)(&base) << std::endl;
//    std::cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&base) << std::endl;
//    std::cout << "虚函数表 — 第二个函数地址：" << (int*)*(int*)(&base + 1) << std::endl;
//    std::cout << "虚函数表 — 第三个函数地址：" << (int*)*(int*)(&base + 2) << std::endl;
//    std::cout << "虚函数表 — 第四个函数地址：" << (int*)*(int*)(&base + 3) << std::endl;
//    base.fun1((Func)((int*)*(int*)(&base)));
    //    Func func =  (Func)*((int*)*(int*)(&base)+0);
//    base.func();
};
#endif //EXCEMPLE_VTABLE_HPP
