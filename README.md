# -Shared_ptr-String-
⽤⾃定义的智能指针Shared_ptr类来管理⾃定义的String类
使用C++11中的模板定义shared_ptr模板类，使其能够作为智能指针指向任意的类，自定
义int * 变量作为引用计数，指针增加时引用计数加一，释放时减一并且析构指向的资源；
自定义String类通过char *来保存字符串，重载运算符与定义构造函数实现string类功能
