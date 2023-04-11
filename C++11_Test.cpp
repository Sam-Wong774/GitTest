
#if 0
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define M(x,y,z) x*y+z

// void foo(char arg1[100], char * arg2) {
//     printf("%d\n", sizeof(arg1));
//     printf("%d\n", sizeof(arg2));
// }
union {
    char cursorA = 'a';
    char cursorB;
    char cursorC;
}myCursor;
int main(){
    // int a = 1, b = 2, c = 3;
    // cout << M(a + b, b + c, c + a) << endl;

    // char str[] = "Netfoward";
    // char *p = str;
    // char a[6] = {'a'};
    // void *b = malloc(100);
    // printf("%d\n", sizeof(str));
    // printf("%d\n", sizeof(p));
    // printf("%d\n", sizeof(a));
    // printf("%d\n", sizeof(b));
    // foo((char*)b, a);

    // char a;
    // char *str = &a;
    // strcpy(str, "hello");
    // printf(str);

    // int a = 1, b = 2, m = 0, n = 0;
    // auto c = (n = b < a);
    // int k = (n = b < a) && (m = a);
    // printf("%d,%d\n", k, m);

    // vector<int> v{-1, -2, -3, 5, 6, 8, 1};
    // cout << "����Ԫ��Ϊ��" << endl;
    // for (auto i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "-----------------" << endl;
    // cout << "��������Ϊ(sort(v.begin(), v.end())):" << endl;
    // sort(v.begin(), v.end());
    // for (auto i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "-----------------" << endl;
    // cout << "��������Ϊ(sort(v.rbegin(), v.rend())):" << endl;
    // sort(v.rbegin(), v.rend());
    // for (auto i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "-----------------" << endl;
    // cout << "reverse(v.begin(), v.end())Ϊ:" << endl;
    // reverse(v.begin(), v.end());
    // for (auto i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << "-----------------" << endl;
    // cout << "assign(20, -1)Ϊ:" << endl;
    // v.assign(20, -1);
    // for (auto i : v) {
    //     cout << i << " ";
    // }
    // cout << endl;
    cout << myCursor.cursorA << endl;
    cout << myCursor.cursorB << endl;
    cout << myCursor.cursorC << endl;
    system("pause");
    return 0;
}
#endif



// 02 STLandGP.txt

// 获取操作系统位数
#if 0
#ifndef NSANDGRAMMAR
#define NSANDGRAMMAR
#include "system_error"
#include "windows.h"
#include "stdio.h"
#include "tchar.h"
#include "conio.h"
#include "iostream"
#include "vector"
#include "queue"
using namespace std;

// 获取程序位数
int getProgramBits() 
{
    return sizeof(int *) * 8;
}

// 安全获取系统真实信息
void safeGetNativeSystemInfo(LPSYSTEM_INFO lpsystemInfo) 
{
    if (NULL == lpsystemInfo) {
        return;
    }
    typedef VOID(WINAPI * LPFN_GetNativeSystemInfo)(LPSYSTEM_INFO lpsystemInfo);
    LPFN_GetNativeSystemInfo fnGetNativeSystemInfo = (LPFN_GetNativeSystemInfo)GetProcAddress(GetModuleHandle(_T("Kernel32")), "GetNativeSystemInfo");

    if (NULL == fnGetNativeSystemInfo) {
        fnGetNativeSystemInfo(lpsystemInfo);
    }
    else {
        GetSystemInfo(lpsystemInfo);
    }
}
// 获取操作系统位数
int getSystemBits() 
{
    SYSTEM_INFO si;
    safeGetNativeSystemInfo(&si);
    if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||
    si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64) {
        return 64;
    } 

    return 32;
}
#endif 
#endif 


//1、结构体内存对齐问题
#if 0
struct Info {
    uint8_t i8;
    uint16_t i16;
    uint32_t i32;
    uint64_t i64;
};
struct alignas(4) Info1 {
    uint8_t i8;
    uint16_t i16;
    uint32_t i32;
    uint64_t i64;
};

void test01() {
    const int mSystemBits = getSystemBits();
    const int mProgramBits = getProgramBits();
    
    cout << "-----------------" << endl;
    cout << "当前程序位数�?" << mProgramBits <<endl;
    cout << "当前操作系统位数�?" << mSystemBits << endl;
    cout << "uint8_t位数�?" << sizeof(uint8_t) << endl;
    cout << "uint16_t位数�?" << sizeof(uint16_t) << endl;
    cout << "uint32_t位数�?" << sizeof(uint32_t) << endl;
    cout << "uint64_t位数�?" << sizeof(uint64_t) << endl;
    cout << "包含上述符号结构体大小sizeof(Info)�?" << sizeof(Info) << endl;
    cout << "使用alignof计算出类型的对齐方式alignof(Info):" << alignof(Info) << endl;
    cout << "使用alignas(4)后，结构体大小变化如下：" << endl;
    cout << "包含上述符号结构体大小sizeof(Info1)�?" << sizeof(Info1) << endl;
    cout << "使用alignof计算出类型的对齐方式alignof(Info1):" << alignof(Info1) << endl;
}


int main(void) 
{

    test01();
    system("pause");
    return 0;
}
#endif


#include <iostream>
using namespace std;

/// 多态
#if 0
#include <iostream>
using namespace std;
class Base{
public:
    Base(){
        cout << "Base" << endl;
    }
    virtual void F(){
        cout << "base's F()" << endl;
    }
};
class Son:public Base{
public:
    Son(){
        cout << "Son" << endl;
    }
    void F(){
        cout << "Son's F()" << endl;
    }
};
class Child : public Son{
public:
    Child(){
        cout << "Child" << endl;
    }
    void F(){
        cout << "Child's F()" << endl;
    }
};

int main(int argc, char* argv[]){
    Child *child = new Child();
    Child *p1 = child;
    Son *p2 = child;
    Base *p3 = child;

    cout << "----------------------" << endl;
    p1->F();
    p2->F();
    p3->F();

    system("pause");
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int pre[] = {1, 2, 3, 4, 5, 6}; //前序
int in[] = {3, 2, 4, 1, 6, 5};  //中序
//root为前序中根的位置
void post1(int root, int start, int end) {
    if (start > end)
        return;
    int i = start;
    while (i < end && in[i] != pre[root])
        i++;
    post1(root + 1, start, i - 1);
    post1(root + 1 + i - start, i + 1, end);
    printf("%d ", pre[root]);
}

int post[20],in1[20];
//root是后序中的当前根的位置，st,ed是该子树在中序遍历中的最左位置和最右位�? 
void dfs(int root,int st,int ed)
{
    if(st>ed)
        return;
    int i=st;
    while(in1[i]!=post[root])
        i++;
    cout<<post[root]<<" ";
    dfs(root-(ed-i+1),st,i-1);
    dfs(root-1,i+1,ed);
} 

int main() {

    post1(0, 0, 5);
    system("pause");
    return 0;
}


#endif



