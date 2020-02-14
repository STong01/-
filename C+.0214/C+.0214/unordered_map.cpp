#include <iostream>
using namespace std;

//unordered_mpa��ģ��ʵ��
#if 0
// unordered_map�д洢����pair<K, V>�ļ�ֵ�ԣ�KΪkey�����ͣ�VΪvalue�����ͣ�HF��ϣ��������
// unordered_map��ʵ��ʱ��ֻ�轫hashbucket�еĽӿ����·�װ����
template<class K, class V, class HF = DefHashF<K>>
class unordered_map
{
	typedef pair<K, V> ValueType;
	typedef HashBucket<K, ValueType, KeyOfValue, HF> HT;
	// ͨ��key��ȡvalue�Ĳ���
	struct KeyOfValue
	{
		const K& operator()(const ValueType& data)
		{
			return data.first;
		}
	};
public:
	typename typedef HT::Iterator iterator;
public:
	unordered_map() : _ht()
	{}

	iterator begin()
	{
		return _ht.Begin();
	}

	iterator end()
	{ 
		return _ht.End();
	}

	size_t size()const
	{ 
		return _ht.Size();
	}

	bool empty()const
	{ 
		return _ht.Empty();
	}

	V& operator[](const K& key)
	{
		return (*(_ht.InsertUnique(ValueType(key, V())).first)).second;
	}

	iterator find(const K& key)
	{ 
		return _ht.Find(key); 
	}

	size_t count(const K& key)
	{ 
		return _ht.Count(key); 
	}
		
	pair<iterator, bool> insert(const ValueType& value)
	{
		return _ht.Insert(value);
	}

	iterator erase(iterator position)
	{
		return _ht.Erase(position);
	}

	size_t bucket_count()
	{ 
		return _ht.BucketCount(); 
	}
	size_t bucket_size(const K& key)
	{ 
		return _ht.BucketSize(key); 
	}

private:
	HT _ht;
};

#endif

//��ϣ��ɢ�й�ϣͰʵ��
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
			unsigned int seed = 131;
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

	// ʵ�ֵĹ�ϣͰ��key��Ψһ��
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
		Node* Insert(const V& data);

		// ɾ����ϣͰ��Ϊdata��Ԫ��(data�����ظ�)
		bool Erase(const V& data);

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