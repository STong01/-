#include <iostream>
using namespace std;

namespace OpenHash
{
	template<class T>
	class HashFunc
	{
	public:
		size_t operator()(const T& val)
		{
			return val;
		}
	};

	template<>
	class HashFunc<string>
	{
	public:
		size_t operator()(const string& s)
		{
			const char* str = s.c_str();
			unsigned int seed = 131; // 31 131 1313 13131 131313
			unsigned int hash = 0;
			while (*str)
			{
				hash = hash * seed + (*str++);
			}

			return hash;
		}
	};

	template<class V>
	struct HashBucketNode
	{
		HashBucketNode(const V& data)
		: _pNext(nullptr), _data(data)
		{}
		HashBucketNode<V>* _pNext;
		V _data;
	};

	// ������ʵ�ֵĹ�ϣͰ��key��Ψһ��
	template<class V, class HF = HashFunc<V>>
	class HashBucket
	{
		typedef HashBucketNode<V> Node;
		typedef Node* PNode;

		typedef HashBucket<V, HF> Self;

	public:
		HashBucket(size_t capacity)
			: _table(GetNextPrime(capacity))
			, _size(0)
		{}

		~HashBucket()
		{
			Clear();
		}

		// ��ϣͰ�е�Ԫ�ز����ظ�
		Node* Insert(const V& data)
		{

			HashBucket* cur = data;
			while (cur != NULL)
			{
				if (key == cur->key)
					return cur;
				cur = cur->next;
			}
			return NULL;
		}

		// ɾ����ϣͰ��Ϊdata��Ԫ��(data�����ظ�)
		bool Erase(const V& data)
		{
			
		}

		Node* Find(const V& data);

		size_t Size()const
		{
			return _size;
		}

		bool Empty()const
		{
			return 0 == _size;
		}

		void Clear();

		size_t BucketCount()const
		{
			return _table.capacity();
		}

		void Swap(Self& ht)
		{
			_table.swap(ht._table);
			swap(_size, ht._size);
		}

	private:
		size_t HashFunc(const V& data)
		{
			return HF()(data) % _table.capacity();
		}

		void CheckCapacity();

	private:
		vector<Node*> _table;
		size_t _size;      // ��ϣ������ЧԪ�صĸ���
	};
}

int main()
{

	system("pause");
	return 0;
}