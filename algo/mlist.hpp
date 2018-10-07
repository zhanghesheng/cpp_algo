//
// Created by Bruce on 2018/10/5.
//

#ifndef EXCEMPLE_MLIST_HPP
#define EXCEMPLE_MLIST_HPP
#include <sys/types.h>

//单链表的处理
namespace bruce{
    template<typename T>
    struct Node{
        T data;
        struct Node*next;

        Node(T data) : data(data) {

        }
    };
    template <typename N>
    class List{
    public:

        List():header(nullptr),trail(nullptr),lenght(0) {
        }

        bool isEmpty(){
            if(header == nullptr || trail == nullptr){
                return true;
            }
            return false;

        }
        Node<N> *searchNode(const N &data){
            Node<N> *tempNode = nullptr;
            Node<N> *p = this->header;
            while (p){
                if(p->data == data){
                    tempNode = p;
                    break;
                } else{
                    p = p->next;
                }
            }
            return tempNode;
        };

        Node<N> *searchNodeWithPosition(const int i){


        }
        void pushNodeToTrail (const N &data){
            // 生成新的节点
            Node<N> *node = new Node<N>(data);
            node->data = data;
            node->next = nullptr;
            if(isEmpty()){
                this->header = node;
                this->trail = node;
            } else{
                this->trail->next = node;
                this->trail = node;
            }
        }

        Node<N> *pop(){

        }
        N popFront (){
            if(isEmpty()){
                return 0;
            }

            Node<N> *node = header;
            N data = node->data;
            header = node->next;
            if(header == trail){
                trail = nullptr;
            } else{
                node->next = nullptr;
            }
            delete node;
            return data;
        }
        // 链表的逆置（反转操作）
        void reserveList(){
            if (isEmpty() || this->header == this->trail){// 如果链表为空或是仅有一个节点则不反转
                return;
            }
            Node<N> *pNode = this->header;
            Node<N> *pPrev = nullptr;
            this->trail = pNode;
            while (pNode != nullptr){
                // 缓存下一个节点
                Node<N> *pNext = pNode->next;
                //反转指向前驱节点
                pNode->next = pPrev;
                this->header = pNode;
                // 前驱节点改为当前的节点
                pPrev = pNode;
                // 指向剩余的链表结构
                pNode = pNext;
            }
        }

        // 在特定的节点进行反转
        Node<N> * reverseList(Node<N> *node){
            if (!node){
                return nullptr;
            }

            Node<N> *pNode = node->next->next;
            Node<N> *pPre = node->next;
            Node<N> *tempNode = pNode;
            while(pNode){
                Node<N> *pNext = pNode->next;
                pNode->next = pPre;
                pPre = pNode;
                tempNode = pNode;
                pNode = pNext;
            }
            node->next->next = nullptr;
            return tempNode;

        }

        // 通过快慢指针操作获取中间节点
        Node<N> *getSlowNode(){
            if(isEmpty()){
                return nullptr;
            }
            if(this->header == this->trail){
                return this->header;
            }

            Node<N> *slow = this->header;
            Node<N> *fast = this->header;
            while(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        Node<N> *reverseListBySlowNode(){
            Node<N> *node = getSlowNode();
            return reverseList(node);
        }

        // 判断链表是否为回文
        bool islistpalindrome(){
            Node<N> *slow = reverseListBySlowNode();
            Node<N> *leftNode = this->header;
            bool res = true;
            while (slow){
                std::cout << "slow value = " << slow->data << std::endl;
                if(slow->data == leftNode->data){
                    slow = slow->next;
                    leftNode = leftNode->next;
                } else{
                    res = false;
                    break;
                }
            }
            return res;

        }


        Node<N> *getHeader() const {
            return header;
        }

        void description(){
            if (isEmpty()){
                return;
            }
            Node<N> *pNode = this->header;
            while(pNode){
                std::cout << "node value = " << pNode->data << std::endl;
                pNode = pNode->next;
            }
        }
        
    private:
        Node<N> *header;// 头结点
        Node<N> *trail;// 尾节点
        int lenght;// 链表的个数
    };
}

#endif //EXCEMPLE_MLIST_HPP
