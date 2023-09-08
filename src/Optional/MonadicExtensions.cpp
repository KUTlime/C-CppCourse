#include <optional>
#include <iostream>

struct UserProfile
{
};

std::optional<UserProfile> FetchFromCache(int userId) { return std::nullopt; }
std::optional<UserProfile> FetchFromServer(int userId) { return std::nullopt; }
std::optional<int> ExtractAge(const UserProfile& profile) { return std::nullopt; }

void StepOne() {
    const int userId = 12345;
    std::optional<int> ageNext;

    std::optional<UserProfile> profile = FetchFromCache(userId);

    if (!profile)
        profile = FetchFromServer(userId);

    if (profile) {
        std::optional<int> age = ExtractAge(*profile);

        if (age)
            ageNext = *age + 1;
    }

    if (ageNext)
        std::cout << std::format("Next year, the user will be {} years old", *ageNext);
    else
        std::cout << "Failed to determine user's age.\n";
}

void StepTwo() {
    const int userId = 12345;

    const auto ageNext = FetchFromCache(userId)
        .or_else([& userId]() { return FetchFromServer(userId); })
        .and_then(ExtractAge)
        .transform([](int age) { return age + 1; });

    if (ageNext)
        std::cout << std::format("Next year, the user will be {} years old", *ageNext);
    else
        std::cout << "Failed to determine user's age.\n";
}

// 1. and_then
// works as flatmap
// takes optinal, retuns optional.
std::optional<int> divide(int a, int b) {
    if (b == 0) return std::nullopt;
    return a / b;
}

void DemoAndThen()
{
    auto result = std::optional<int>{ 20 }
        .and_then([](auto x){ return divide(x, 5); });
}

// 2. transform
// works as map
// makes non-optional functions usable in optional context.
// takes non-optional (what is expected), return optional

int GetNumber(int x)
{
    return x + 42;
}

void DemoTransform()
{
    const auto r = std::optional<int>(10)
        /*.and_then([](auto x) {return GetNumber(x);}) // error, GetNumber doesn't return optional here*/
        .transform([](auto x) { return GetNumber(x); });

    std::optional<std::optional<int>> result = std::optional<int>{ 20 }
        .and_then( [](auto x) { return divide(x, 5);})
        .transform([](auto x) { return divide(x, 5);}); // transform expects T, not optional<T>
}
