#include<iostream>
using namespace std;
//�����
//class String
//{
//public:
//  //ȱʡ����
//  String(char *string="")
//      :_str(new char[strlen(string)+1])
//  {
//      strcpy(_str, string);
//  }
//  //�����д�������캯����ֵ���캯����ϵͳĬ��ֵ������Ϊǳ����
//  //��ʼ���б������д������ǻ������ͣ����ʼ��Ϊ���ֵ���Զ�������������캯��
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
//        delete[] _str;//����Ϊ�գ������жϣ��ַ������١���
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
//  //ͨ������Ĭ�Ϲ��캯��д��������͸�ֵ����������
//public:
//  String(char* string = "")
//      :_string(new char[strlen(string) + 1])
//  {
//      strcpy(_string, string);
//  }
//  String(String& s)
//      :_string(NULL)//������ָ��Ϊ�գ���������ʱָ�����ֵ�����
//  {
//      String tmp(s._string);
//      //����tmp����������������������ٿ����ڴ棬����������Ҫ
//      swap(_string, s._string);//������������������һ�£������ββ�����Ӧconst
//  }
//  String& operator=(String s)//���ÿ������츳ֵ
//  {
//      //����Ҫ�ж�this==&s,�˴��ǿ�������s����ַ�϶���ͬ
//      swap(_string, s._string);
//      return *this;
//      //����s������������*thisԭ�����ٵ�_stringָ���ָ��
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
//���ַ�ʽ��ֵ����������
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
 
 
//ǳ����
//class String
//{
//  //��̬�������˷���ֻ���ƿ������������ָָ��һ��
//public:
//  String(char* string = "")
//      :_string(new char[strlen(string) + 1])
//  {
//      sCount = 1;
//      strcpy(_string, string);
//  }
//  String(const String& s)
//      :_string(s._string)//��ʼ���б����Ǿ�̬����
//  {
//      sCount = ++sCount;
//  }
//  String& operator=(const String& s)
//  {
//      //ֻ�����һ����ͬ��Աָ��ſ��ã����趨�帳ֵ����
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
//  //ÿ��������һ���洢��ָͬһ��ָ��Ķ������
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
//  //��ǰ��࿪��4���ֽڴ洢��ָͬһ����Աָ��Ķ���
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