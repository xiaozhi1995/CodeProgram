#include<iostream>
using namespace std;
//深拷贝：
//class String
//{
//public:
//  //缺省构造
//  String(char *string="")
//      :_str(new char[strlen(string)+1])
//  {
//      strcpy(_str, string);
//  }
//  //如果不写拷贝构造函数或赋值构造函数，系统默认值拷贝，为浅拷贝
//  //初始化列表，如果不写，如果是基本类型，则初始化为随机值，自定义类型则调构造函数
//  String(const String& s)
//      :_str(new char[strlen(s._str)+1])
//  {
//      strcpy(_str, s._str);
//  }
// 
//  String&   operator = (const String& s)
//  {
//      if(this!=&s)
//      {
//        delete[] _str;//不会为空，无需判断，字符串最少“”
//        _str = new char[strlen(s._str) + 1];
//        strcpy(_str, s._str);
//       }
//      return *this;
//  }
//  ~String()
//  {
//      delete[] _str;
//  }
//  void Display()
//  {
//      cout << _str << endl;
//  }
//private:
//  char* _str;
//};
//class  String
//{
//  //通过调用默认构造函数写拷贝构造和赋值操作符重载
//public:
//  String(char* string = "")
//      :_string(new char[strlen(string) + 1])
//  {
//      strcpy(_string, string);
//  }
//  String(String& s)
//      :_string(NULL)//需设置指针为空，否则销毁时指针随机值会崩毁
//  {
//      String tmp(s._string);
//      //利用tmp出作用域调析构函数，销毁开辟内存，本函数不需要
//      swap(_string, s._string);//必须两个操作数类型一致，所以形参参数不应const
//  }
//  String& operator=(String s)//利用拷贝构造赋值
//  {
//      //不需要判断this==&s,此处是拷贝构造s，地址肯定不同
//      swap(_string, s._string);
//      return *this;
//      //利用s析构函数销毁*this原来开辟的_string指针的指向
//  }
////  String& operator=(const String& s)
////  {
////    if (this != &s)
////    {
////        String tmp(s);
////        swap(_string, tmp._string);
////    }
////    return *this;
////    }
////}
//两种方式赋值操作符重载
//  ~String()
//  {
//      if (_string)
//          delete[] _string;
//  }
//  void Display()
//  {
//      cout << _string << endl;
//  }
//private:
//  char* _string;
//};
 
 
//浅拷贝
//class String
//{
//  //静态变量，此方法只限制拷贝构造对象所指指针一处
//public:
//  String(char* string = "")
//      :_string(new char[strlen(string) + 1])
//  {
//      sCount = 1;
//      strcpy(_string, string);
//  }
//  String(const String& s)
//      :_string(s._string)//初始化列表不能是静态变量
//  {
//      sCount = ++sCount;
//  }
//  String& operator=(const String& s)
//  {
//      //只能面对一个相同成员指针才可用，无需定义赋值重载
//  }
//  ~String()
//  {
//      if (--sCount == 0)
//      {
//          delete[] _string;
//      }
//      //cout << sCount << endl;
//  }
//  void Display()
//  {
//      cout << _string << endl;
//      //cout << sCount << endl;
//  }
//private:
//  char* _string;
//  static int  sCount;
//};
//int String::sCount = 0;
//class String
//{
//  //每个对象定义一个存储所指同一个指针的对象个数
//public:
//  String(char* string="")
//      :_string(new char[strlen(string)+1]),
//      sCount(new int(1))
//  {
//      strcpy(_string, string);
//  }
//  String(const String& s)
//      :_string(s._string),
//      sCount(s.sCount)
//  {
//      ++(*sCount);
//  }
//  String& operator=(const String& s)
//  {
//      if (this != &s)
//      {
//          Delete(*this);
//          _string = s._string;
//          sCount = s.sCount;
//          ++(*sCount);
//      }
//      return *this;
//  }
//  void Delete(String& s)
//  {
//      if (--(*s.sCount) == 0)
//      {
//          delete sCount;
//          delete[] _string;
//      }
//  }
//  ~String()
//  {
//      Delete(*this);
//  }
//  void Display()
//  {
//      cout << _string << endl;
//  }
//private:
//  char* _string;
//  int *sCount;
//};
//class String
//{
//  //给前面多开辟4个字节存储所指同一个成员指针的对象
//public:
//  String(char* str = "")
//      :_str(new char[strlen(str) + 5])
//  {
//      *((int *)_str) = 1;
//      _str = _str + 4;
//      strcpy(_str, str);
//  }
//  String(const String& s)
//      :_str(s._str)
//  {
//      ++(*((int *)(_str-4)));
//  }
//  String& operator=(const String& s)
//  {
//      if (this != &s)
//      {
//            Delete(*this);
//          _str = s._str;
//          ++(*((int *)(_str-4)));
//      }
//      return  *this;
//  }
//  ~String()
//  {
//      cout << *((int*)(_str - 4)) << endl;
//      Delete(*this);
//        
//  }
//  void Delete(String& s)
//  {
//      if (--(*(int *)(_str-4))== 0)
//      {
//          _str -= 4;
//          delete[]  _str;
//      }
//  }
//  void Display()
//  {
//      cout << _str << endl;
//      cout << *(int*)(_str - 4) << endl;
//
//  }
//private:
//  char* _str;
//};
void Test1()
{
     
    String s1("abcdef");
    s1.Display();
    String s2(s1);
    s2.Display();
    String s3("abc");
    s3.Display();
    s3 = s1;
    s3.Display();
}
int main()
{
    Test1();
    system("pause");
    return 0;
}