//
//  notes.cpp
//  C++learning
//
//  Created by 王育玲 on 2023/3/7.
//

/*
 线型容器：
 向量：尾端高效增删     push_back/pop_back
      可以使用下标 -- 随机迭代器
 双端队列：首尾两端都可以实现高效增删     push_front/pop_front       push_back/pop_back
         可以使用下标   -- 随机迭代器
 列表：  任意位置都可以实现高效增删     push_front/pop_front       push_back/pop_back
        不可以使用下标  -- 没有随机迭代器

 适配器容器：
 栈： 后进先出
        底层容器缺省值为deque，也可以使用vector/list/自定义容器

 队列：先进先出
           底层容器缺省值为deque，也可以使用list
           但是不能使用vector，vector没有提供pop_front函数
 优先队列:  优者先出 (默认大者为优)
                   底层容器缺省值为vector, 也可以使用deque
                   但是不能使用list    --  -- 没有随机迭代器（排序时使用）
                  比较器类型缺省为less<T>，大者为优。也可以使用greater<T>，小者为优

 --------------------------------------------------------------------------------------------------
 第四阶段：24次课
 1~6：  ubuntu 
 7~24:  windows

 16~17:  sql模块
             windows下安装mysql5.7
             配置Qt中Mysql驱动
 23~24：安装、配置opencv

 */
