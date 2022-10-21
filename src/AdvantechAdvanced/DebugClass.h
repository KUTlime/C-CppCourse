#include <iostream>
#include <string>
#include <vector>
#ifndef _DebugClass_H
#define _DebugClass_H
namespace Advantech
{
	class InAdvantechNamespace {};
	namespace Utilities
	{
		class DebugClass
		{
		private:
			int i;
		public:
			DebugClass();
			DebugClass(int i);
			DebugClass(const DebugClass&);
			DebugClass(const DebugClass&&);
			DebugClass& operator=(const DebugClass&);
			DebugClass& operator=(DebugClass&&) noexcept;
			operator std::string() const;
			operator std::vector<DebugClass>() const;
			operator bool() const;
			int GetIValue() const;
			void SetIValue(int i);
			friend std::ostream& operator<< (std::ostream& out, const Advantech::Utilities::DebugClass& debugClass);

			~DebugClass();
		};
		class MemoryLeak {
		private:
			int x;
			int y;
		public:
			MemoryLeak(int i, int j) : x(i), y(j) {
				std::cout << "Iteration " << i << std::endl;
			};
		};
		class NotSoSmartPointer {
		private:
			DebugClass* pointerToReference;
		public:
			NotSoSmartPointer(int instanceId);
			~NotSoSmartPointer();
		};
	}
	inline namespace Router
	{
		class Firmaware
		{
			
		};
	}
}

namespace Advantech::Product
{
	class SomeProduct{};
}
#endif // !_DebugClass

std::ostream& operator<< (std::ostream& out, Advantech::Utilities::DebugClass & debugClass);
