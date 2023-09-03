#include <iostream>
#include <vector>
#include <variant>
#include <string>

union S
{
    std::string str;
    std::vector<int> vec;
    ~S() { } // what to delete here?
};

void TroublesWithUnions()
{
    S s = { "Hello, world" };
    // at this point, reading from s.vec is undefined behavior
    std::cout << "s.str = " << s.str << '\n';

    // you have to call destructor of the contained objects!
    s.str.~basic_string<char>();

    // and a constructor!
    new (&s.vec) std::vector<int>;

    // now, s.vec is the active member of the union
    s.vec.push_back(10);
    std::cout << s.vec.size() << '\n';

    // another destructor
    s.vec.~vector<int>();
}

void SeeAboutVariant()
{
    std::variant<std::string, int> data; // Question: What value will be in data?
    data = "Hello there!"; // I can assign a string here.
    data = 2;               // or an int...

    std::variant<std::string, int> data2;
    data2 = 2;               // The order does not matter.
    data2 = "Hello there!";


    std::variant<std::string, int> data3;
    data3 = "Hello there!";
    std::string test = std::get<std::string>(data3); // it is safe (but totally wrong) to use get here.
    std::cout << test;
    data3 = 2;
    std::cout << std::get<int>(data3);

    std::variant<std::string, int> data4;
    data4 = "Hello there!";
    std::cout << std::get<int>(data3); // see what happens here

    data4.index(); // we can use this and try if, but still bad
    if (data4.index() == 0)
    {
        // clunky
    }

    if (auto value = std::get_if<std::string>(&data4))
    {
        auto test2 = *value;
        // better, get_if return nullptr if the value isn't there.
        // but still kinda clunky, complicated, not really functional...
        // ...so let's start seriously...
    }
}

struct SampleVisitor
{
    // Functional object overload
    void operator()(int i) const {
        std::cout << "int: " << i << "\n";
    }
    void operator()(float f) const {
        std::cout << "float: " << f << "\n";
    }
    void operator()(const std::string& s) const {
        std::cout << "string: " << s << "\n";
    }
};

void UseVisitor()
{
    std::variant<int, float, std::string> intFloatString;
    static_assert(std::variant_size_v<decltype(intFloatString)> == 3);

    // default initialized to the first alternative, should be 0
    std::visit(SampleVisitor{}, intFloatString); // <-- Best functional approach

    // Recap

    // index will show the currently used 'type'
    std::cout << "index = " << intFloatString.index() << std::endl;
    intFloatString = 100.0f;
    std::cout << "index = " << intFloatString.index() << std::endl;
    intFloatString = "hello super world";
    std::cout << "index = " << intFloatString.index() << std::endl;

    // try with get_if (a different approach)
    if (const auto intPtr(std::get_if<int>(&intFloatString)); intPtr)
        std::cout << "int!" << *intPtr << "\n";
    else if (const auto floatPtr(std::get_if<float>(&intFloatString)); floatPtr)
        std::cout << "float!" << *floatPtr << "\n";

    if (std::holds_alternative<int>(intFloatString))
        std::cout << "the variant holds an int!\n";
    else if (std::holds_alternative<float>(intFloatString))
        std::cout << "the variant holds a float\n";
    else if (std::holds_alternative<std::string>(intFloatString))
        std::cout << "the variant holds a string\n";

    // try/catch and bad_variant_access
    try
    {
        auto f = std::get<float>(intFloatString);
        std::cout << "float! " << f << "\n";
    }
    catch (std::bad_variant_access&)
    {
        std::cout << "our variant doesn't hold float at this moment...\n";
    }

    // visit:
    std::visit(SampleVisitor{}, intFloatString);
    intFloatString = 10;
    std::visit(SampleVisitor{}, intFloatString);
    intFloatString = 10.0f;
    std::visit(SampleVisitor{}, intFloatString);

    /* Output
        int: 0
        index = 0
        index = 1
        allocating 18 bytes
        index = 2
        the variant holds a string
        our variant doesn't hold float at this moment...
        string: hello super world
        global op delete called
        int: 10
        float: 10
    */
}

void Creation()
{
    // default initialization: (type has to has a default ctor)
    std::variant<int, float> intFloat;
    std::cout << intFloat.index() << ", value " << std::get<int>(intFloat) << "\n";

    // monostate for default initialization:
    class NotSimple
    {
    public:
        NotSimple(int, float) { }
    };

    // std::variant<NotSimple, int> cannotInit; // error, no default constructor on NotSimple
    std::variant<std::monostate, NotSimple, int> okInit;
    std::cout << okInit.index() << "\n";

    // std::monostate can be used as the first alternative to bypass missing default constructor

    // pass a value:
    std::variant<int, float, std::string> intFloatString{ 10.5f };
    std::cout << intFloatString.index() << ", value " << std::get<float>(intFloatString) << "\n";

    // ambiguity
    // double might convert to float or int, so the compiler cannot decide

    //std::variant<int, float, std::string> intFloatString { 10.5 };

    // ambiguity resolved by in_place
    std::variant<long, float, std::string> longFloatString{ std::in_place_index<1>, 7.6 }; // double!
    std::cout << longFloatString.index() << ", value " << std::get<float>(longFloatString) << "\n";

    // in_place for complex types
    std::variant<std::vector<int>, std::string> vecStr{ std::in_place_index<0>, { 0, 1, 2, 3 } };
    std::cout << vecStr.index() << ", vector size " << std::get<std::vector<int>>(vecStr).size() << "\n";

    // copy-initialize from other variant:
    std::variant<int, float> intFloatSecond{ intFloat };
    std::cout << intFloatSecond.index() << ", value " << std::get<int>(intFloatSecond) << "\n";
}

void ValueUpdate()
{
    std::variant<int, float, std::string> intFloatString{ "Hello" };

    intFloatString = 10; // we're now an int

    intFloatString.emplace<2>(std::string("Hello")); // we're now string again

    // std::get returns a reference, so you can change the value:
    std::get<std::string>(intFloatString) += std::string(" World");

    intFloatString = 10.1f;
    if (auto pFloat = std::get_if<float>(&intFloatString); pFloat)
        *pFloat *= 2.0f;
}

void LifeTime()
{
    std::variant<std::string, int> v{ "Hello A Quite Long String" };
    // v allocates some memory for the string
    v = 10; // we call destructor for the string!
    // no memory leak
    
    class MyType
    {
    public:
        MyType() { std::cout << "MyType::MyType\n"; }
        ~MyType() { std::cout << "MyType::~MyType\n"; }
    };

    class OtherType
    {
    public:
        OtherType() { std::cout << "OtherType::OtherType\n"; }
        OtherType(const OtherType&) {
            std::cout << "OtherType::OtherType(const OtherType&)\n";
        }
        ~OtherType() { std::cout << "OtherType::~OtherType\n"; }
    };
    
    std::variant<MyType, OtherType> v1;
    v1 = OtherType();
}

void VisitorUse()
{
    // a generic lambda:
    auto PrintVisitor = [](const auto& t) { std::cout << t << "\n"; };

    std::variant<int, float, std::string> intFloatString{ "Hello" };
    std::visit(PrintVisitor, intFloatString);

    auto TwiceMoreVisitor = [](auto& t) { t *= 2; };

    std::variant<int, float> intFloat{ 20.4f };
    std::visit(PrintVisitor, intFloat);
    std::visit(TwiceMoreVisitor, intFloat);
    std::visit(PrintVisitor, intFloat);

    // Visitor with state
    struct MultiplyVisitor
    {
        float mFactor;

        MultiplyVisitor(float factor) : mFactor(factor) { }

        void operator()(int& i) const {
            i *= static_cast<int>(mFactor);
        }

        void operator()(float& f) const {
            f *= mFactor;
        }

        void operator()(std::string&) const {
            // nothing to do here...
        }
    };

    std::visit(MultiplyVisitor(0.5f), intFloat);
    std::visit(PrintVisitor, intFloat);
}

// Let's throw some template magic to be able to write all lambdas together...
template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;
// Creates a struct that inherits all given lambdas and uses their Ts::operator()
// to able to pass it down to std::visit

void LambdaVisitor()
{
    std::variant<int, float, std::string> intFloatString{ "Hello" };
    
    std::visit(overload{
        [](int& i) { i *= 2; },
        [](float& f) { f *= 2.0f; },
        [](std::string& s) { s = s + s; }
        }, intFloatString);
    
    std::visit([](const auto& t) { std::cout << t << "\n"; }, intFloatString);
    // prints: "HelloHello"

    // Do you have a headache already? ;)
}

void Memory()
{
    std::cout << "sizeof string: "
        << sizeof(std::string) << "\n";

    std::cout << "sizeof variant<int, string>: "
        << sizeof(std::variant<int, std::string>) << "\n";

    std::cout << "sizeof variant<int, float>: "
        << sizeof(std::variant<int, float>) << "\n";

    std::cout << "sizeof variant<int, double>: "
        << sizeof(std::variant<int, double>) << "\n";
}

void VariantAndException()
{
    class ThrowingClass
    {
    public:
        explicit ThrowingClass(int i) { if (i == 0) throw int(10); }
        operator int() { throw int(10); }
    };

    std::variant<int, ThrowingClass> v;

    // change the value:
    try
    {
        v = ThrowingClass(0);
    }
    catch (...)
    {
        std::cout << "catch(...)\n";
        // We keep the old state!
        std::cout << v.valueless_by_exception() << "\n";
        std::cout << std::get<int>(v) << "\n";
        // An exception occured before the old state has been terminated
        // (a call of destructor for int).
    }

    // inside emplace
    try
    {
        v.emplace<0>(ThrowingClass(10)); // calls the operator int
    }
    catch (...)
    {
        std::cout << "catch(...)\n";
        // The old state was destroyed, so we're not in invalid state!
        std::cout << v.valueless_by_exception() << "\n";
        // The exception occured after the old state has been terminated.
    }
}

int main()
{
    std::cin.get();
}