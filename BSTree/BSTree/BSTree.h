#ifndef BSTREE_H
#define BSTREE_H
using namespace std;
//二叉查找树的节点结构
template<typename T>
struct BSNode
{
	BSNode(T t)
		:value(t), lchild(nullptr), rchild(nullptr) {};
	BSNode() = default;
	T value;
	BSNode<T>*lchild;
	BSNode<T>*rchild;
	BSNode<T>*parent;
};

//二叉查找树类
template<typename T>
class BSTree
{
public:
	BSTree();
	~BSTree();

	void preOrder();//前序遍历二叉树
	void inOrder();//中序遍历二叉树
	void postOrder();//后序遍历二叉树
	void layerOrder();//层次遍历二叉树

	BSNode<T>*search_recursion(T key);//递归地进行查找
	BSNode<T>*search_Iterator(T key);//迭代地进行查找

	T search_minimun();//查找最小元素
	T search_maximun();//查找最大元素

	BSNode<T>*successor(BSNode<T>*x);//查找指定节点的后继节点
	BSNode<T>*predecessor(BSNode<T>*x);//查找指定节点的前驱节点

	void insert(T key);//插入指定值节点
	void remove(T key);//删除指定值节点
	void destory();//销毁二叉树
	void print();//打印二叉树
private:
	BSNode<T>*root;//根节点

	BSNode<T>*search(BSNode<T>*&p, T key);
	void remove(BSNode<T>*&p, T key);
	void preOrder(BSNode<T>*p);
	void inOrder(BSNode<T>*p);
	void postOrder(BSNode<T>*p);
	T search_minimun(BSNode<T>*p);
	T search_maximun(BSNode<T>*p);
	void destory(BSNode<T>*&p);
};

//默认构造函数
template<typename T>
BSTree<T>::BSTree()
	:root(nullptr) {};
//析构函数
template<typename T>
BSTree<T>::~BSTree()
{
	destory(root);
};
//插入函数
template<typename T>
void BSTree<T>::insert(T key)
{
	BSNode<T>*pparent = nullptr;
	BSNode<T>*pnode = root;

	while (pnode!=nullptr)	//寻找合适的插入位置
	{
		pparent = pnode;
		if (key > pnode->value)
			pnode = pnode->rchild;
		else if (key < pnode->value)
			pnode = pnode->lchild;
		else
			break;
	}
	pnode = new BSNode<T>(key);
	if (pparent == nullptr)//如果是空树
	{
		root = pnode;//则新节点为根
	}
	else
	{
		if (key > pparent->value)
		{
			pparent->rchild = pnode;//否则新节点为其父节点的右孩
		}
		else
			pparent->lchild = pnode;//或左孩
	}
	pnode->parent = pparent;//指明新节点的父节点
};

//查找指定元素的节点（非递归）
template<typename T>
BSNode<T>*BSTree<T>::search_Iterator(T key)
{
	BSNode<T>*pnode = root;
	while (pnode != nullptr)
	{
		if (key == pnode->value)//找到
			return pnode;
		if (key > pnode->value)//关键字比节点值大，在节点右子树查找
			pnode = pnode->rchild;
		else
			pnode = pnode->lchild;//关键字比节点值小，在节点左子树查找
	}
	return nullptr;
};

//查找指定元素的节点（递归）
template<typename T>
BSNode<T>* BSTree<T>::search_recursion(T key)
{
	return search(root, key);
};

//递归查找的类内部实现
template<typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>*&pnode, T key)
{
	if (pnode == nullptr)
		return nullptr;
	if (pnode->value == key)
		return pnode;
	if (key > pnode->value)
		return search(pnode->rchild, key);
	else
		return search(pnode->lchild, key);
};

//删除指定节点
template<typename T>
void BSTree<T>::remove(T key)
{
	remove(root, key);
};

//删除指定节点的内部使用函数
template<typename T>
void BSTree<T>::remove(BSNode<T>*&pnode, T key)
{
	if (pnode != nullptr)
	{
		if (pnode->value == key)
		{
			BSNode<T>*pdel = nullptr;
			if (pnode->lchild == nullptr || pnode->rchild == nullptr)
				pdel = pnode;
			else
				pdel = predecessor(pnode);
			BSNode<T>*pchild = nullptr;
			if (pdel->lchild != nullptr)
				pchild = pdel->lchild;
			else
				pchild = pdel->rchild;
			if (pchild != nullptr)
				pchild->parent = pdel->parent;
			if (pdel->parent == nullptr)
				root = pchild;
			else if (pdel->parent->lchild == pdel)
			{
				pdel->parent->lchild = pchild;
			}
			else
			{
				pdel->parent->rchild = pchild;
			}
			if (pnode->value != pdel->value)
				pnode->value = pdel->value;
			delete pdel;
		}
		//进行递归删除
		else if (key > pnode->value)
		{
			remove(pnode->rchild, key);
		}
		else remove(pnode->lchild, key);
	}
};

//返回前驱
template<typename T>
BSNode<T>*BSTree<T>::predecessor(BSNode<T>*pnode)
{
	if (pnode->lchild != nullptr)
	{
		pnode = pnode->lchild;
		while (pnode->rchild!=nullptr)
		{
			pnode = pnode->rchild;
		}
		return pnode;
	}
	BSNode<T>*pparent = pnode->parent;
	while (pparent != nullptr&&pparent->lchild == pnode)
	{
		pnode = pparent;
		pparent = pparent->parent;
	}
	return pparent;
};

//返回后继
template<typename T>
BSNode<T>*BSTree<T>::successor(BSNode<T>*pnode)
{
	if (pnode->rchild != nullptr)
	{
		pnode = pnode->rchild;
		while (pnode->lchild != nullptr)
		{
			pnode = pnode->lchild;
		}
		return pnode;
	}
	BSNode<T>*pparent = pnode->parent;
	while (pparent!=nullptr&&pparent->rchild==pnode)
	{
		pnode = pparent;
		pparent = pparent->parent;
	}
	return pparent;
};
//先序遍历
template<typename T>
void BSTree<T>::preOrder()
{
	preOrder(root);
};
template<typename T>
void BSTree<T>::preOrder(BSNode<T>*p)
{
	if (p != nullptr)
	{
		cout << p->value << endl;
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
};
//中序遍历
template<typename T>
void BSTree<T>::inOrder()
{
	inOrder(root);
};
template<typename T>
void BSTree<T>::inOrder(BSNode<T>*p)
{
	if (p != nullptr)
	{
		inOrder(p->lchild);
		cout << p->value << endl;
		inOrder(p->rchild);
	}
};
//后序遍历
template<typename T>
void BSTree<T>::postOrder()
{
	postOrder(root);
};
template<typename T>
void BSTree<T>::postOrder(BSNode<T>*p)
{
	if (p != nullptr)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->value << endl;
	}
};
//寻找最小元素
template<typename T>
T BSTree<T>::search_minimun()
{
	return search_minimun(root);
};
template<typename T>
T BSTree<T>::search_minimun(BSNode<T>*p)
{
	if (p->lchild != nullptr)
		return search_minimun(p->lchild);
	return p->value;
};
//寻找最大元素
template<typename T>
T BSTree<T>::search_maximun()
{
	return search_maximun(root);
};
template<typename T>
T BSTree<T>::search_maximun(BSNode<T>*p)
{
	if (p->rchild != nullptr)
		return search_maximun(p->rchild);
	return p->value;
};

//销毁二叉树
template<typename T>
void BSTree<T>::destory()
{
	destory(root);
};
template<typename T>
void BSTree<T>::destory(BSNode<T>*&p)
{
	if (p != nullptr)
	{
		if (p->lchild != nullptr)
			destory(p->lchild);
		if (p->rchild != nullptr)
			destory(p->rchild);
		delete p;
		p = nullptr;
	}
};

#endif // !BSTREE_H

