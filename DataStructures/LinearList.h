#include <cstdlib>
#define MAX_LENGTH 100

// 顺序表，顺序存储
template<typename elemType>
class SequenceList
{
private:
    elemType *elem_base;    // 顺序表的基地址
    int length;             // 顺序表的长度
public:
    // 构造函数，用于初始化顺序表
    SequenceList()
    {
        elemType *new_array = (elemType *) malloc(MAX_LENGTH * sizeof(elemType));
        if (new_array == NULL)
        {
            throw "malloc申请空间失败";
            this->length = -1;
        }
        else
        {
            this->elem_base = new_array;
            this->length = 0;
        }
    };
    // 获取元素，根据下标index获取
    elemType& getElem(int index)
    {
        if (index >= 1 || index < 0)
        {
            throw "getElem下标非法";
        }
        else
        {
            return this->elem_base[index];
        }
    };
    // 查找元素，查找元素e，返回对应下标，未找到返回-1
    int searchElem(elemType e)
    {
        // 顺序查找
        for (int i = 0; i < this->length; i++)
        {
            if (e == this->elem_base[i])
            {
                // 找到直接返回下标
                return i;
            }
        }

        // 没找到，返回-1
        return -1;
    };
    // 插入元素，将元素e插入顺序表，插在下标为pos的位置
    void insertElem(elemType e, int pos)
    {
        if (pos > this->length || pos < 0)
        {
            throw "getElem下标非法";
        }

        if (this->length == MAX_LENGTH)
        {
            throw "无法插入，长度已达上限";
        }

        // 先将待插入位置及其后面的元素后移，此处i代表的是每次移动复制的目标位置
        for (int i = this->length; i > pos; i--)
        {
            this->elem_base[i] = this->elem_base[i-1];
        }
        // 将待插入元素放到目标位置
        this->elem_base[pos] = e;
        this->length++;
    };
    // 删除元素，删除下标为index的元素，正常删除返回0，否则返回-1
    int deleteElem(int index)
    {
        if (index > this->length || index < 0)
        {
            throw "getElem下标非法";
        }

        if (this->length == 0)
        {
            throw "顺序表为空，无法删除元素";
        }

        // 直接覆盖，将待删除位置后面的元素前移，此处i代表的是每次移动复制的源位置
        for (int i = index+1; i < this->length; i++)
        {
            this->elem_base[i-1] = this->elem_base[i];
        }

        this->length--;
    }
};





