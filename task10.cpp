#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int main(){
    //合并两个字符串
    string s1, s2, s;
    cout << "please input two strings: ";
    cin >> s1 >> s2;
    s = s1 + s2;
    cout << "the concatenated string: " << s << endl;

    //先初始化为1、2、3 再从键盘输入10个数存入v1 并输出
    vector<int> v1 = {1, 2, 3};
    cout << "please input 10 integer to vector: ";
    for(int i = 0; i < 10; i++){
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    cout << "the elements in v1: ";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    //从键盘输入10个字符串，存入v2并输出
    vector<string> v2;
    cout << "please input 10 strings to vector: ";
    for(int i = 0; i < 10; i++){
        string tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }
    cout << "the elements in v2: ";
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;
    
    //创建l1 从键盘输入10个数字存入l1 并输出
    list<int> l1;
    list<int> ::iterator li;
    cout << "please input 10 integer to list: ";
    for(int i = 0; i < 10; i++){
        int tmp;
        cin >> tmp;
        l1.push_back(tmp);
    }
    cout << "the elements in l1: ";
    for(li = l1.begin(); li != l1.end(); li++){
        cout << *li << " ";
    }
    cout << endl;

    // 创建_set 添加10次一样的字符串hello 并输出
    set<string> _set;
    for(int i = 0; i < 10; i++){
        _set.insert("hello");
    }
    cout << "the elements in _set: ";
    for(set<string> ::iterator si = _set.begin(); si != _set.end(); si++){
        cout<< *si << " ";
    }
    cout << endl;

    // 创建一个map，存入一些记录并输出
    map<string, int> m1;
    m1["math"] = 80;
    m1["English"] = 100;
    m1["science"] = 70;
    
    for(map<string, int>::iterator mi = m1.begin(); mi != m1.end(); mi++){
        cout << mi->first << ":" << mi->second << " ";
    }
    cout << endl;

    return 0;
}