#include <iostream>
#include <optional>
#include <string>
#include <fstream>
#include <map>
#include <vector>

void BasicDemo()
{
    std::optional<int> s = std::nullopt;
    std::optional<int> s1 = {};

    std::optional<std::vector<std::string>> array = {};
    std::optional<size_t> s = array->size();

    std::cout << s.value_or(0);

    if (s)
    {
        std::cout << s.value();
    }
}

std::size_t value_or(size_t* pt, size_t defaultValue)
{
    return pt == nullptr ? defaultValue : *pt;
}

class Unit
{};

using MyOptional = std::pair<int, Unit>;


auto to_int(char const* const text) -> std::optional<int>
{
    char* pos = nullptr;
    const int value = std::strtol(text, &pos, 0);

    return pos == text ? std::nullopt : std::optional<int>(value);
}

void ToIntDemo(int argc, char* argv[])
{
    const char* text = argc > 1 ? argv[1] : "42";

    if (auto oi = to_int(text))
        std::cout << "'" << text << "' is " << *oi;
    else
        std::cout << "'" << text << "' isn't a number";
}

template<typename T1,
    typename Func,
    typename Input_Type = typename T1::value_type,
    typename T2 = std::invoke_result_t<Func, Input_Type>
>
constexpr T2 operator>>(T1 input, Func f) {
    static_assert(
        std::is_invocable_v<decltype(f), Input_Type>,
        "The function passed in must take type"
        "(T1::value_type) as its argument"
        );

    if (!input) return std::nullopt;
    else return std::invoke(f, *input);
}

std::optional<std::string> read_file(const char* filename) {
    std::ifstream file{ filename };

    if (!file.is_open()) {
        return {};
    }

    std::string str((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());
    return { str };
}


std::optional<int> opt_stoi(std::string s) {
    try {
        return std::stoi(s);
    }
    catch (const std::invalid_argument& e) {
        return {};
    }
    catch (const std::out_of_range&) {
        return {};
    }
}

template <typename T>
constexpr void print(std::optional<T> val) {
    if (val) {
        std::cout << *val << '\n';
    }
    else {
        std::cerr << "Error\n";
    }
}

void MonadicDemo()
{
    auto x = read_file("exist.txt")
        >> opt_stoi
        >> [](int n) { return std::make_optional(n + 100); };
    print(x);
}

// Provide an iterator-free interface for lookups to map-like objects.
// Warning: the output value is copied into the optional.
template <typename Map, typename Key>
auto lookup(const Map& m, const Key& k)
-> std::enable_if_t<std::is_same_v<decltype(m.find(k)), typename Map::const_iterator>, std::optional<typename Map::mapped_type>>
{
    auto it = m.find(k);
    return it != m.end()
        ? std::make_optional(it->second)
        : std::nullopt;
}


void DemoMap()
{
    const std::map<int, int> squares = { {1, 1}, {2, 4}, {3, 9}, {4, 16} };

    // cleaner, no need for != end()
    if (const auto square = lookup(squares, 2))
    {
        std::cout << "Square is " << *square << '\n';
    }
    else
    {
        std::cout << "Square is unknown.\n";
    }
}

int main()
{
    std::cout << "Hello World!\n";
}