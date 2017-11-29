template<class T>
struct smart_ptr{
    T* ptr;
    smart_ptr(T* ptr): ptr(ptr){}

    ~smart_ptr(){
        delete ptr; //pubicじゃないと消せないよ
    }
    //何も書かないとデフォルトデストラクタが読み込まれる
    //virtualつけないと子クラスまで消せないよ
    //~smart_ptr(){}
};

int main(){

    smart_ptr<int> ptr(new int(5));

}
