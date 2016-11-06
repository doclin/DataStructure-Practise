#include <iostream>
#include "../stack/stack.h"                            // 没有Qt开发环境，将此处换成个人定义类

template <class Type> struct BTNode{
    BTNode *left;
    Type data;
    BTNode *right;
    BTNode(Type x){
        data=x;
        left=right=NULL;
    }
};

template <class Type> class PostOrder;

template <class Type> class BinaryTree{
private:
    BTNode<Type> *root;
    friend class PostOrder<Type>;
public:
    BinaryTree(BTNode<Type>*t){root=t;}
};

//Base class for BT Iterator
template <class Type> class TreeIterator {
protected:
    const BinaryTree <Type> & T; //BT
    const BTNode<Type> *current;
public:
    TreeIterator ( const BinaryTree <Type> & BT )
              : T (BT), current (NULL) { }
    virtual ~TreeIterator ( ) { }
    virtual void First ( ) = 0;
    virtual void operator ++ ( ) = 0;
    operator bool(){return current!=NULL;}
    const Type operator()()const{
        if(current)
            return current->data;
        return (Type)0;
    }
};



template <class Type> struct StkNode {
//Stack node definition
    const BTNode <Type> *Node;  //Node Address
    int PopTime;                                        //Counter
    StkNode (const BTNode <Type> *N = NULL ) : Node (N), PopTime (0) { }
};


template <class Type> class PostOrder : public TreeIterator <Type> {
    bool renew;
public:
    PostOrder ( const BinaryTree <Type> & BT ): TreeIterator<Type>::TreeIterator(BT){renew=false;} // 编译不过，模板类继承出现问题，进行了修改
    ~PostOrder ( ) { }
    void First ( );
    //Seek to the first node in postorder traversal
    void operator ++ ( );
    //Seek to the successor
protected:
    Stack < StkNode<Type> > st;     //Active record stack
};

template <class Type>
void PostOrder<Type>::First(){
    TreeIterator<Type>::current = TreeIterator<Type>::T.root;
    st.clear();
    renew=true;
    operator++();
}

template <class Type>
void PostOrder<Type>::operator ++(){
    if(!renew && TreeIterator<Type>::current==TreeIterator<Type>::T.root && st.is_empty()){
        TreeIterator<Type>::current=NULL;
        return;
    }
    renew = false;
    const BTNode<Type> *p = TreeIterator<Type>::T.root;                                   // p为判断是否执行向左移动循环的flag，与题目原意有出入
    StkNode<Type> w;
    do{
        while(TreeIterator<Type>::current == p and TreeIterator<Type>::current != NULL )  // 向左移动到底
        {
            StkNode<Type> n(TreeIterator<Type>::current);
            st.push(n);
            p = TreeIterator<Type>::current = TreeIterator<Type>::current -> left;
        }
        w = st.pop();                                                                     // 第一次出栈
        TreeIterator<Type>::current = w.Node;
        w.PopTime++;                                                                      // 记录++
        if(w.PopTime==1)                                                                  // 判断出栈次数
        {
            st.push(w);                                                                   // 第二次入栈
            if(TreeIterator<Type>::current->right == NULL)                                // 右节点空直接弹出，结束
            {
                w = st.pop();
                TreeIterator<Type>::current = w.Node;
                break;
            }
            else                                                                          // 否则遍历右节点
            {
                TreeIterator<Type>::current = TreeIterator<Type>::current -> right;
                p = TreeIterator<Type>::current;
            }
        }
        if(w.PopTime==2)
            break;
    }
    while( TreeIterator<Type>::current || !st.is_empty( ));                                // 判断条件有改动
}

int main(){
    BTNode<int> *p = new BTNode<int>(6);
    p->left = new BTNode<int>(4);
    p->right = new BTNode<int>(10);
    p->left->left = new BTNode<int>(2);
    p->right->left = new BTNode<int>(8);
    p->right->right = new BTNode<int>(12);
    BinaryTree<int> T(p);
    PostOrder<int> it(T);
    for(it.First();it;++it){
        std::cout << it() << std::endl;     //2,4,8,12,10,6
    }
}

/*
         6
      4    10
    2     8 12
*/