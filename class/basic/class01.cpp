#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    explicit Person(string name) : m_name(name), m_age(18), m_height(165), m_weight(50) {}
    void introduce()
    {
        cout << "名前は" << m_name << endl;
        cout << m_age << endl;
    }
    void reachBirthday()
    {
        m_age++;
    }
    ~Person()
    {
        cout << "hoge" << endl;
    }
    string m_name;
    int m_age;
    double m_height, m_weight;
};

int main()
{
    Person one("hoge");
    one.introduce();
    one.reachBirthday();
    one.introduce();
    one.m_name = "太郎";
    one.m_age = 18;
    one.m_height = 1.711;
    one.m_weight = 62.41;
    one.introduce();
    one.reachBirthday();
    one.introduce();
}
