#include <iostream>
#include <format>

namespace Demo
{
    using namespace std;

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

	bool DoSomeDangerousOperation(const unique_ptr<MyNaiveThread> & thread)
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

int main()
{
    using namespace Demo;
    auto result = SumWithSmartPointers(make_unique<int>(2), make_unique<int>(3));
    std::cout << *result << std::endl;

	/*auto myClassPointer = std::make_unique<MyNaiveThread>(new MyNaiveThread()); // You can't call new with make_unique*/
	/*MyNaiveThread myNaiveThread();
	auto validUseOfMakeUnique = std::make_unique<MyNaiveThread>(myNaiveThread); // not OK */

	auto validUseOfMakeUnique = std::make_unique<MyNaiveThread>(MyNaiveThread()); // OK
	std::cout << (*validUseOfMakeUnique).GetInstanceId() << std::endl;

	auto anotherValidUse = std::make_unique<MyNaiveThread>(); // OK, temporary object
	std::cout << (*anotherValidUse).GetInstanceId() << std::endl;

	auto myClassPointer = std::unique_ptr<MyNaiveThread>(new MyNaiveThread());
	DoSomeWork(std::move(myClassPointer)); // no constant reference, so I have to move
}
