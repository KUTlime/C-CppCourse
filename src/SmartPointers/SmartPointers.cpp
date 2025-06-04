#include <iostream>
#include <format>

namespace Demo
{
	using namespace std;

	int* SumWithPointers(int* a, int* b) { return new int(*a + *b); }

	unique_ptr<int> SumWithSmartPointers(const unique_ptr<int>& a, const unique_ptr<int>& b)
	{
		return make_unique<int>(*a + *b);
	}

	class MyNaiveThread
	{
	public:
		MyNaiveThread() : instanceId(rand()) { cout << format("Creating instance {}\n", instanceId); };
		~MyNaiveThread() { cout << format("Deleting instance {}\n", instanceId) << endl; };
		int GetInstanceId() { return instanceId; };
	private:
		int instanceId;
	};

	bool DoSomeDangerousOperation(const unique_ptr<MyNaiveThread>& thread)
	{
		cout << "Do something dangerous" << endl;
		throw exception();
	};

	void DoSomeWork(unique_ptr<MyNaiveThread> thread)
	{
		cout << "Do some work." << endl;
		try
		{
			cout << DoSomeDangerousOperation(thread);
		}
		catch (const std::exception&)
		{
			cout << "Application crash. Ideally, all resources should be cleared now." << std::endl;
		}
	}
}

namespace MyOwnNaive
{

	template <typename T>
	class UniquePtr {
	private:
		T* ptr;

	public:
		// Constructor
		explicit UniquePtr(T* p = nullptr) : ptr(p) {}

		// Destructor
		~UniquePtr() {
			delete ptr;
		}

		// Delete copy constructor and copy assignment to ensure unique ownership
		UniquePtr(const UniquePtr&) = delete;
		UniquePtr& operator=(const UniquePtr&) = delete;

		// Move constructor
		UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
			other.ptr = nullptr;
		}

		// Move assignment
		UniquePtr& operator=(UniquePtr&& other) noexcept {
			if (this != &other) {
				delete ptr;
				ptr = other.ptr;
				other.ptr = nullptr;
			}
			return *this;
		}

		// Overload dereference and arrow operators
		T& operator*() const { return *ptr; }
		T* operator->() const { return ptr; }

		// Check if the pointer is valid
		bool isValid() const { return ptr != nullptr; }
	};
}
int main()
{
	using namespace Demo;
	auto result = SumWithSmartPointers(make_unique<int>(2), make_unique<int>(3));
	std::cout << *result << std::endl;

	//auto myClassPointer = std::make_unique<MyNaiveThread>(new MyNaiveThread()); // You can't call new with make_unique*/
	/*MyNaiveThread myNaiveThread();
	auto validUseOfMakeUnique = std::make_unique<MyNaiveThread>(myNaiveThread); // not OK */

	auto validUseOfMakeUnique = std::make_unique<MyNaiveThread>(MyNaiveThread()); // OK
	std::cout << (*validUseOfMakeUnique).GetInstanceId() << std::endl;

	auto anotherValidUse = std::make_unique<MyNaiveThread>(); // OK, temporary object
	std::cout << (*anotherValidUse).GetInstanceId() << std::endl;

	auto myClassPointer = std::unique_ptr<MyNaiveThread>(new MyNaiveThread());
	DoSomeWork(std::move(myClassPointer)); // no constant reference, so I have to move

	DoSomeDangerousOperation(validUseOfMakeUnique); // no need to call move constructor

	MyOwnNaive::UniquePtr<int> p(new int(42));
	std::cout << "Value: " << *p << std::endl;

	MyOwnNaive::UniquePtr<int> q = std::move(p);  // Transferring ownership
	if (!p.isValid()) {
		std::cout << "p is now null." << std::endl;
	}

	std::cout << "q's Value: " << *q << std::endl;
	return 0;
}
